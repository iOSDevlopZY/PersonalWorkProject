//
//  XMPPHelper.m
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/14.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "XMPPHelper.h"
#import "GCDAsyncSocket.h"
#import "XMPP.h"
#import "XMPPLogging.h"
#import "XMPPReconnect.h"
#import "XMPPCapabilitiesCoreDataStorage.h"
#import "XMPPRosterCoreDataStorage.h"
#import "XMPPvCardAvatarModule.h"
#import "XMPPvCardCoreDataStorage.h"
#import "DesEncrypt.h"
#import "WebMainService.h"
#import "XMPPRoom.h"

#import "DDLog.h"
#import "DDTTYLogger.h"

#import <CFNetwork/CFNetwork.h>

@interface XMPPHelper ()
- (void)goOnline;
- (void)goOffline;
@property(nonatomic,strong)NSString *myJID;
@property(nonatomic,strong)NSString *myPassword;

@end

@implementation XMPPHelper
@synthesize xmppStream;
@synthesize xmppReconnect;
@synthesize xmppRoster;
@synthesize xmppRosterStorage;
@synthesize xmppvCardTempModule;
@synthesize xmppvCardAvatarModule;
@synthesize xmppCapabilities;
@synthesize xmppCapabilitiesStorage;
@synthesize xmppRoom;


#pragma mark - 单例模式
static XMPPHelper *__onetimeClass;
+ (XMPPHelper *)sharedInstance {
static dispatch_once_t oneToken;

    dispatch_once(&oneToken, ^{

        __onetimeClass = [[XMPPHelper alloc]init];

    });
    return __onetimeClass;
}
#pragma mark - XMPP方法
- (NSManagedObjectContext *)managedObjectContext_roster
{
    return [xmppRosterStorage mainThreadManagedObjectContext];
}

- (NSManagedObjectContext *)managedObjectContext_capabilities
{
    return [xmppCapabilitiesStorage mainThreadManagedObjectContext];
}

#pragma mark - 初始化XMPP
- (void)setupStream
{
    NSAssert(xmppStream == nil, @"Method setupStream invoked multiple times");
    
    // Setup xmpp stream
    //
    // The XMPPStream is the base class for all activity.
    // Everything else plugs into the xmppStream, such as modules/extensions and delegates.
    
    xmppStream = [[XMPPStream alloc] init];
    
#if !TARGET_IPHONE_SIMULATOR
    {
        // Want xmpp to run in the background?
        //
        // P.S. - The simulator doesn't support backgrounding yet.
        //        When you try to set the associated property on the simulator, it simply fails.
        //        And when you background an app on the simulator,
        //        it just queues network traffic til the app is foregrounded again.
        //        We are patiently waiting for a fix from Apple.
        //        If you do enableBackgroundingOnSocket on the simulator,
        //        you will simply see an error message from the xmpp stack when it fails to set the property.
        
        xmppStream.enableBackgroundingOnSocket = YES;
    }
#endif
    
    // Setup reconnect
    //
    // The XMPPReconnect module monitors for "accidental disconnections" and
    // automatically reconnects the stream for you.
    // There's a bunch more information in the XMPPReconnect header file.
    
    xmppReconnect = [[XMPPReconnect alloc] init];
    xmppReconnect.autoReconnect = YES;
    //设置重连时间间隔
    xmppReconnect.reconnectTimerInterval = 5.0;
    // Setup roster
    //
    // The XMPPRoster handles the xmpp protocol stuff related to the roster.
    // The storage for the roster is abstracted.
    // So you can use any storage mechanism you want.
    // You can store it all in memory, or use core data and store it on disk, or use core data with an in-memory store,
    // or setup your own using raw SQLite, or create your own storage mechanism.
    // You can do it however you like! It's your application.
    // But you do need to provide the roster with some storage facility.
    
    xmppRosterStorage = [[XMPPRosterCoreDataStorage alloc] init];
    //    xmppRosterStorage = [[XMPPRosterCoreDataStorage alloc] initWithInMemoryStore];
    
    xmppRoster = [[XMPPRoster alloc] initWithRosterStorage:xmppRosterStorage];
    
    xmppRoster.autoFetchRoster = YES;
    xmppRoster.autoAcceptKnownPresenceSubscriptionRequests = YES;
    
    // Setup vCard support
    //
    // The vCard Avatar module works in conjuction with the standard vCard Temp module to download user avatars.
    // The XMPPRoster will automatically integrate with XMPPvCardAvatarModule to cache roster photos in the roster.
    
    xmppvCardStorage = [XMPPvCardCoreDataStorage sharedInstance];
    xmppvCardTempModule = [[XMPPvCardTempModule alloc] initWithvCardStorage:xmppvCardStorage];
    
    xmppvCardAvatarModule = [[XMPPvCardAvatarModule alloc] initWithvCardTempModule:xmppvCardTempModule];
    
    // Setup capabilities
    //
    // The XMPPCapabilities module handles all the complex hashing of the caps protocol (XEP-0115).
    // Basically, when other clients broadcast their presence on the network
    // they include information about what capabilities their client supports (audio, video, file transfer, etc).
    // But as you can imagine, this list starts to get pretty big.
    // This is where the hashing stuff comes into play.
    // Most people running the same version of the same client are going to have the same list of capabilities.
    // So the protocol defines a standardized way to hash the list of capabilities.
    // Clients then broadcast the tiny hash instead of the big list.
    // The XMPPCapabilities protocol automatically handles figuring out what these hashes mean,
    // and also persistently storing the hashes so lookups aren't needed in the future.
    //
    // Similarly to the roster, the storage of the module is abstracted.
    // You are strongly encouraged to persist caps information across sessions.
    //
    // The XMPPCapabilitiesCoreDataStorage is an ideal solution.
    // It can also be shared amongst multiple streams to further reduce hash lookups.
    
    xmppCapabilitiesStorage = [XMPPCapabilitiesCoreDataStorage sharedInstance];
    xmppCapabilities = [[XMPPCapabilities alloc] initWithCapabilitiesStorage:xmppCapabilitiesStorage];
    
    xmppCapabilities.autoFetchHashedCapabilities = YES;
    xmppCapabilities.autoFetchNonHashedCapabilities = NO;
    
    // Activate xmpp modules
    
    [xmppReconnect         activate:xmppStream];
    [xmppRoster            activate:xmppStream];
    [xmppvCardTempModule   activate:xmppStream];
    [xmppvCardAvatarModule activate:xmppStream];
    [xmppCapabilities      activate:xmppStream];
    
    // Add ourself as a delegate to anything we may be interested in
    
    [xmppStream addDelegate:self delegateQueue:dispatch_get_main_queue()];
    [xmppRoster addDelegate:self delegateQueue:dispatch_get_main_queue()];
    
    // Optional:
    //
    // Replace me with the proper domain and port.
    // The example below is setup for a typical google talk account.
    //
//     If you don't supply a hostName, then it will be automatically resolved using the JID (below).
//     For example, if you supply a JID like 'user@quack.com/rsrc'
//     then the xmpp framework will follow the xmpp specification, and do a SRV lookup for quack.com.
    //
    // If you don't specify a hostPort, then the default (5222) will be used.
    
    
      allowSelfSignedCertificates = YES;
      allowSSLHostNameMismatch = YES;
   

    
    // You may need to alter these settings depending on the server you're connecting to
     customCertEvaluation = YES;
    
}

#pragma mark - 清除XMPP
- (void)teardownStream
{
    [xmppStream removeDelegate:self];
    [xmppRoster removeDelegate:self];
    
    [xmppReconnect         deactivate];
    [xmppRoster            deactivate];
    [xmppvCardTempModule   deactivate];
    [xmppvCardAvatarModule deactivate];
    [xmppCapabilities      deactivate];
    
    [xmppStream disconnect];
    
    xmppStream = nil;
    xmppReconnect = nil;
    xmppRoster = nil;
    xmppRosterStorage = nil;
    xmppvCardStorage = nil;
    xmppvCardTempModule = nil;
    xmppvCardAvatarModule = nil;
    xmppCapabilities = nil;
    xmppCapabilitiesStorage = nil;
}

#pragma mark - 上线
- (void)goOnline
{
    XMPPPresence *presence = [XMPPPresence presence];
    [[self xmppStream] sendElement:presence];
    
    [self.Messagedelegate isOnline];
}

#pragma - mark - 离线
- (void)goOffline
{
    XMPPPresence *presence = [XMPPPresence presenceWithType:@"unavailable"];
    
    [[self xmppStream] sendElement:presence];
    
    [self.Messagedelegate isOffline];
}

//pragma mark - 登录
- (BOOL)connectByUserName:(NSString *)userName password:(NSString *)passWord
{
    if (![xmppStream isDisconnected]) {
        return YES;
    }

    self.myJID = userName;
    self.myPassword = passWord;

   
    
    if (_myJID == nil || _myPassword == nil) {
        
        return NO;
    }
    
    [xmppStream setHostName:@"121.42.172.47"];
    
   [xmppStream setMyJID:[XMPPJID jidWithUser:_myJID domain:@"im.sino-med.net" resource:nil]];//121.42.172.47

    
    NSError *error = nil;
    
    if (![xmppStream connectWithTimeout:XMPPStreamTimeoutNone error:&error])
    {
        NSLog(@"Error Connecting:%@",error);
        
        return NO;
    }
    
    
    return YES;
}
#pragma mark - 断开连接
- (void)disconnect
{
    [self goOffline];
    [xmppStream disconnect];
}

#pragma mark - 创建群组房间
- (void)creatRoomWithName:(NSString *)roomName withTitle:(NSString *)roomTitle withNickName:(NSString *)roomNickName withDomain:(NSString *)domain
{
    
    XMPPRoomCoreDataStorage *xmppRoomStorage = [[XMPPRoomCoreDataStorage alloc] init];
    if (xmppRoomStorage == nil) {
        xmppRoomStorage = [[XMPPRoomCoreDataStorage alloc] init];
    }
    NSString *roomJid = [NSString stringWithFormat:@"%@@conference.%@",roomName,domain];
    NSLog(@">>>>>>>>>>>> 聊天房间id roomJid : %@", roomJid);
   
    XMPPJID *jid = [XMPPJID jidWithString:roomJid];
    xmppRoom = [[XMPPRoom alloc]initWithRoomStorage:xmppRoomStorage jid:jid dispatchQueue:dispatch_get_main_queue()];
    [xmppRoom activate:xmppStream];
    
    [xmppRoom joinRoomUsingNickname:roomNickName history:nil];
    [xmppRoom addDelegate:self delegateQueue:dispatch_get_main_queue()];
    [xmppRoom fetchConfigurationForm];
    
    [self configRoom];

}

#pragma mark - 配置房间消息
- (void)configRoom
{
    NSXMLElement *x = [NSXMLElement elementWithName:@"x"xmlns:@"jabber:x:data"];
    NSXMLElement *p;
    p = [NSXMLElement elementWithName:@"field" ];
    [p addAttributeWithName:@"var"stringValue:@"muc#roomconfig_persistentroom"];//永久房间
    [p addChild:[NSXMLElement elementWithName:@"value"stringValue:@"1"]];
    [x addChild:p];
        
    p = [NSXMLElement elementWithName:@"field" ];
    [p addAttributeWithName:@"var"stringValue:@"muc#roomconfig_maxusers"];//最大用户
    [p addChild:[NSXMLElement elementWithName:@"value"stringValue:@"10000"]];
    [x addChild:p];
        
    p = [NSXMLElement elementWithName:@"field" ];
    [p addAttributeWithName:@"var"stringValue:@"muc#roomconfig_changesubject"];//允许改变主题
    [p addChild:[NSXMLElement elementWithName:@"value"stringValue:@"1"]];
    [x addChild:p];
        
    p = [NSXMLElement elementWithName:@"field" ];
    [p addAttributeWithName:@"var"stringValue:@"muc#roomconfig_publicroom"];//公共房间
    [p addChild:[NSXMLElement elementWithName:@"value"stringValue:@"1"]];
    [x addChild:p];
        
    p = [NSXMLElement elementWithName:@"field" ];
    [p addAttributeWithName:@"var"stringValue:@"muc#roomconfig_allowinvites"];//允许邀请
    [p addChild:[NSXMLElement elementWithName:@"value"stringValue:@"1"]];
    [x addChild:p];
        
    [xmppRoom configureRoomUsingOptions:x];
}

#pragma mark - 离开房间
-(void)leaveRoom{
    [xmppRoom leaveRoom];
    [xmppRoom deactivate];
    [xmppRoom removeDelegate:self delegateQueue:dispatch_get_main_queue()];
    xmppRoom = nil;
}

#pragma mark - socket已经连接上
- (void)xmppStream:(XMPPStream *)sender socketDidConnect:(GCDAsyncSocket *)socket
{
    NSLog(@"==============> socketDidConnect!");
}


#pragma mark - 设置安全
- (void)xmppStream:(XMPPStream *)sender willSecureWithSettings:(NSMutableDictionary *)settings
{
    NSLog(@"==============> willSecureWithSettings");
    if (allowSelfSignedCertificates)
    {
        [settings setObject:[NSNumber numberWithBool:YES] forKey:(NSString *)kCFStreamSSLAllowsAnyRoot];
    }
    
    if (allowSSLHostNameMismatch)
    {
        [settings setObject:[NSNull null] forKey:(NSString *)kCFStreamSSLPeerName];
    }
    else
    {
        // Google does things incorrectly (does not conform to RFC).
        // Because so many people ask questions about this (assume xmpp framework is broken),
        // I've explicitly added code that shows how other xmpp clients "do the right thing"
        // when connecting to a google server (gmail, or google apps for domains).
        
        NSString *expectedCertName = nil;
        
        NSString *serverDomain = xmppStream.hostName;
        NSString *virtualDomain = [xmppStream.myJID domain];
        
        if ([serverDomain isEqualToString:@"talk.google.com"])
        {
            if ([virtualDomain isEqualToString:@"gmail.com"])
            {
                expectedCertName = virtualDomain;
            }
            else
            {
                expectedCertName = serverDomain;
            }
        }
        else if (serverDomain == nil)
        {
            expectedCertName = virtualDomain;
        }
        else
        {
            expectedCertName = serverDomain;
        }
        
        if (expectedCertName)
        {
            [settings setObject:expectedCertName forKey:(NSString *)kCFStreamSSLPeerName];
        }
    }
}

#pragma mark - 收到信任
- (void)xmppStream:(XMPPStream *)sender didReceiveTrust:(SecTrustRef)trust
 completionHandler:(void (^)(BOOL shouldTrustPeer))completionHandler
{
    // The delegate method should likely have code similar to this,
    // but will presumably perform some extra security code stuff.
    // For example, allowing a specific self-signed certificate that is known to the app.
    NSLog(@"==============> didReceiveTrust");
    dispatch_queue_t bgQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(bgQueue, ^{
        
        SecTrustResultType result = kSecTrustResultDeny;
        OSStatus status = SecTrustEvaluate(trust, &result);
        
        if (status == noErr && (result == kSecTrustResultProceed || result == kSecTrustResultUnspecified)) {
            completionHandler(YES);
        }
        else {
            completionHandler(NO);
        }
    });
}

#pragma mark - XMPP流保证安全
- (void)xmppStreamDidSecure:(XMPPStream *)sender
{
    NSLog(@"==============> xmppStreamDidSecure");
}

#pragma mark - XMPP流已经连接
- (void)xmppStreamDidConnect:(XMPPStream *)sender
{
    NSLog(@"==============> xmppStreamDidConnect");
    
    isXmppConnected = YES;
    
    NSError *error = nil;
    
    WebMainServiceSoapBinding *binding= [WebMainService WebMainServiceSoapBinding];
    
    WebMainService_CreateRandomAuthorizeCode*getsession = [WebMainService_CreateRandomAuthorizeCode new];
    

    getsession.sUserJID = _myJID;
    
    
    WebMainServiceSoapBindingResponse *respone = [binding CreateRandomAuthorizeCodeUsingParameters:getsession];
    
    WebMainService_CreateRandomAuthorizeCodeResponse *resp = [WebMainService_CreateRandomAuthorizeCodeResponse new];
    resp = respone.bodyParts[0];
    
    
    self.key = [NSString stringWithFormat:@"%@",resp.CreateRandomAuthorizeCodeResult];
    
    NSString *str = [DesEncrypt ToDESEncryptString:_myPassword WithKey:_myJID];
    
    NSString *DEStr = [self.key stringByAppendingFormat:@" %@",str];
    
    
    if (![[self xmppStream] authenticateWithPassword:DEStr error:&error])
    {
        NSLog(@"Error authenticating: %@", error);
    }
}

#pragma mark - XMPP流通过认证
- (void)xmppStreamDidAuthenticate:(XMPPStream *)sender
{
    NSLog(@"==============> xmppStreamDidAuthenticate");
    [self.Messagedelegate present];
    
    
    [self goOnline];
}

#pragma mark - XMPP流未通过认证
- (void)xmppStream:(XMPPStream *)sender didNotAuthenticate:(NSXMLElement *)error
{
    NSLog(@"==============> didNotAuthenticate:");
    [self.Messagedelegate accountNotAuthorized];
    [xmppStream disconnect];
}

#pragma mark - 接收到IQ
- (BOOL)xmppStream:(XMPPStream *)sender didReceiveIQ:(XMPPIQ *)iq
{
    return NO;
}

#pragma mark - XMPP接收到消息
- (void)xmppStream:(XMPPStream *)sender didReceiveMessage:(XMPPMessage *)message
{
    NSLog(@"==============> didReceiveMessage");
    // A simple example of inbound message handling.
    
    if ([message isChatMessageWithBody])
    {
        XMPPUserCoreDataStorageObject *user = [xmppRosterStorage userForJID:[message from]
                                                                 xmppStream:xmppStream
                                                       managedObjectContext:[self managedObjectContext_roster]];
        
        NSString *body = [[message elementForName:@"body"] stringValue];
         [self.Messagedelegate receiveMessage:body];
    }
}

#pragma mark - XMPP接收到Presence
- (void)xmppStream:(XMPPStream *)sender didReceivePresence:(XMPPPresence *)presence
{
    
}

#pragma mark - XMPP接收到错误信息
- (void)xmppStream:(XMPPStream *)sender didReceiveError:(id)error
{
    NSLog(@"==============> didReceiveError");
}

#pragma mark - XMPP流断开连接
- (void)xmppStreamDidDisconnect:(XMPPStream *)sender withError:(NSError *)error
{
    NSLog(@"==============> xmppStreamDidDisconnect");
    
    [self.Messagedelegate isOffline];
    
    if (!isXmppConnected)
    {
        NSLog(@"Unable to connect to server. Check xmppStream.hostName");
    }
}

#pragma mark XMPPRosterDelegate
- (void)xmppRoster:(XMPPRoster *)sender didReceiveBuddyRequest:(XMPPPresence *)presence
{
    
    XMPPUserCoreDataStorageObject *user = [xmppRosterStorage userForJID:[presence from]
                                                             xmppStream:xmppStream
                                                   managedObjectContext:[self managedObjectContext_roster]];
    
    NSString *displayName = [user displayName];
    NSString *jidStrBare = [presence fromStr];
    NSString *body = nil;
    
    if (![displayName isEqualToString:jidStrBare])
    {
        body = [NSString stringWithFormat:@"Buddy request from %@ <%@>", displayName, jidStrBare];
    }
    else
    {
        body = [NSString stringWithFormat:@"Buddy request from %@", displayName];
    }
    
    
    if ([[UIApplication sharedApplication] applicationState] == UIApplicationStateActive)
    {

    }
    else
    {
        // We are not active, so use a local notification instead
        UILocalNotification *localNotification = [[UILocalNotification alloc] init];
        localNotification.alertAction = @"Not implemented";
        localNotification.alertBody = body;
        
        [[UIApplication sharedApplication] presentLocalNotificationNow:localNotification];
    }
    
}

- (void)sendMessage:(NSString *) message toUser:(NSString *) user {
    NSXMLElement *body = [NSXMLElement elementWithName:@"body"];
    [body setStringValue:message];
    NSXMLElement *sendmessage = [NSXMLElement elementWithName:@"message"];
    [sendmessage addAttributeWithName:@"type" stringValue:@"chat"];
    NSString *to = user;//@"qq@im.sino-med.net";
    [sendmessage addAttributeWithName:@"to" stringValue:to];
    [sendmessage addChild:body];
    [self.xmppStream sendElement:sendmessage];
}


- (void)sendMessage:(NSString *)message toGroup:(NSString *)groupID from:(NSString*)from
{
        if (message.length > 0){
            NSXMLElement *body = [NSXMLElement elementWithName:@"body"];
            [body setStringValue:message];
            
            //生成XML消息文档
            NSXMLElement *mes = [NSXMLElement elementWithName:@"message"];
            
            //消息类型
            [mes addAttributeWithName:@"type" stringValue:@"groupchat"];
            
            //发送给谁
            [mes addAttributeWithName:@"to" stringValue:groupID];
            
            //由谁发送
            NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
            
//            [mes addAttributeWithName:@"from" stringValue:from];
            
            //组合
            [mes addChild:body];
            
            //发送消息
            [self.xmppStream sendElement:mes];
            
        }
}

#pragma mark - XMPPRoomDelegate
// 加入房间
- (void)xmppRoomDidJoin:(XMPPRoom *)sender
{
    NSLog(@"房间确实已经加入");
    [self.Messagedelegate joinRoomSuccess];
}

- (void)xmppRoomDidLeave:(XMPPRoom *)sender
{
    NSLog(@"房间确实已经离开");
}
// 收到群组消息
- (void)xmppRoom:(XMPPRoom *)sender didReceiveMessage:(XMPPMessage *)message fromOccupant:(XMPPJID *)occupantJID
{
    NSString *messageBody = [[message elementForName:@"body"] stringValue];
    NSLog(@"收到的群组消息体为:%@",messageBody);
    [self.Messagedelegate recvGroupMessage:messageBody];
}

// 有人加入群聊
- (void)xmppRoom:(XMPPRoom *)sender occupantDidJoin:(XMPPJID *)occupantJID
{
    NSLog(@"新人加入群聊");
}

// 有人退出群聊
- (void)xmppRoom:(XMPPRoom *)sender occupantDidLeave:(XMPPJID *)occupantJID
{
    NSLog(@"有人退出群聊");
}
@end
