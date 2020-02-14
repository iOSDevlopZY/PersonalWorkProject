//
//  XMPPHelper.h
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/14.
//  Copyright © 2020 medcare. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "XMPPFramework.h"

NS_ASSUME_NONNULL_BEGIN

/*XMPP代理*/
@protocol sendMessageDelegate <NSObject>
-(void)accountNotAuthorized;
-(void)receiveMessage:(NSString*)str;
-(void)present;
-(void)isOnline;
-(void)isOffline;
-(void)joinRoomSuccess;
-(void)recvGroupMessage:(NSString*)str;
@end

@interface XMPPHelper : NSObject<XMPPRosterDelegate,XMPPStreamDelegate,XMPPReconnectDelegate,XMPPRoomDelegate>
{
       XMPPStream *xmppStream;
       XMPPReconnect *xmppReconnect;
       XMPPRoster *xmppRoster;
       XMPPRosterCoreDataStorage *xmppRosterStorage;
       XMPPvCardCoreDataStorage *xmppvCardStorage;
       XMPPvCardTempModule *xmppvCardTempModule;
       XMPPvCardAvatarModule *xmppvCardAvatarModule;
       XMPPCapabilities *xmppCapabilities;
       XMPPCapabilitiesCoreDataStorage *xmppCapabilitiesStorage;
       
       NSString *password;
       
       BOOL customCertEvaluation;
       BOOL allowSelfSignedCertificates;
       BOOL allowSSLHostNameMismatch ;
       
       BOOL isXmppConnected;
}
@property(nonatomic,strong) NSString *key;
@property (nonatomic, strong) XMPPRoom *xmppRoom;
@property (nonatomic, strong, readonly) XMPPStream *xmppStream;
@property (nonatomic, strong, readonly) XMPPReconnect *xmppReconnect;
@property (nonatomic, strong, readonly) XMPPRoster *xmppRoster;
@property (nonatomic, strong, readonly) XMPPRosterCoreDataStorage *xmppRosterStorage;
@property (nonatomic, strong, readonly) XMPPvCardTempModule *xmppvCardTempModule;
@property (nonatomic, strong, readonly) XMPPvCardAvatarModule *xmppvCardAvatarModule;
@property (nonatomic, strong, readonly) XMPPCapabilities *xmppCapabilities;
@property (nonatomic, strong, readonly) XMPPCapabilitiesCoreDataStorage *xmppCapabilitiesStorage;
@property(nonatomic,assign)id<sendMessageDelegate>Messagedelegate;
- (NSManagedObjectContext *)managedObjectContext_roster;
- (NSManagedObjectContext *)managedObjectContext_capabilities;

+ (XMPPHelper *)sharedInstance;
- (BOOL)connectByUserName:(NSString*)userName password:(NSString *)passWord;
- (void)disconnect;
- (void)setupStream;
- (void)teardownStream;
- (void)sendMessage:(NSString *) message toUser:(NSString *) user;
- (void)sendMessage:(NSString *)message toGroup:(NSString *)groupID from:(NSString*)from;
- (void)creatRoomWithName:(NSString *)roomName withTitle:(NSString *)roomTitle withNickName:(NSString *)roomNickName withDomain:(NSString *)domain;
- (void)leaveRoom;

@end

NS_ASSUME_NONNULL_END
