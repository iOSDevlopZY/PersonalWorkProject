//
//  ChatRoomViewController.m
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/12.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "ChatRoomViewController.h"
#import "AppDelegate.h"
#define ScreenW [UIScreen mainScreen].bounds.size.width
#define ScreenH [UIScreen mainScreen].bounds.size.height

@interface ChatRoomViewController ()

@end

@implementation ChatRoomViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _isOfflineReconnect = false;
    self.historyMessage = @"";
    
    [self.view setBackgroundColor:[UIColor whiteColor]];
    // Do any additional setup after loading the view.
    
    self.roomTitleLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, ScreenW, ScreenH*0.1)];
      [self.roomTitleLabel setTextColor:[UIColor blackColor]];
      [self.roomTitleLabel setFont:[UIFont systemFontOfSize:25]];
      [self.roomTitleLabel setTextAlignment:NSTextAlignmentCenter];
      [self.roomTitleLabel setText:@"房间名:"];
      [self.view addSubview:self.roomTitleLabel];
    
    self.recvLabel = [[UITextView alloc]initWithFrame:CGRectMake(0, ScreenH*0.1, ScreenW, ScreenH*0.3)];
    [self.recvLabel setBackgroundColor:[UIColor lightGrayColor]];
    [self.recvLabel setFont:[UIFont systemFontOfSize:15]];
    [self.recvLabel setTextAlignment:NSTextAlignmentLeft];
    [self.recvLabel setText:@"收到的最后一条消息为："];
    [self.recvLabel setEditable:false];
    [self.view addSubview:self.recvLabel];
    
    _sendMessageTF = [[UITextField alloc]initWithFrame:CGRectMake(ScreenW*0.1, ScreenH*0.45, ScreenW*0.8, ScreenH*0.08)];
    [_sendMessageTF setTextColor:[UIColor blackColor]];
    [_sendMessageTF setBackgroundColor:[UIColor whiteColor]];
    [_sendMessageTF.layer setBorderColor:[UIColor lightGrayColor].CGColor];
    [_sendMessageTF.layer setBorderWidth:1];
    [_sendMessageTF setBorderStyle:UITextBorderStyleRoundedRect];
    [_sendMessageTF setPlaceholder:@"请输入要发送的消息"];
    [self.view addSubview:_sendMessageTF];
    
     self.sendBtn= [[UIButton alloc]initWithFrame:CGRectMake(ScreenW*0.2, ScreenH*0.55, ScreenW*0.6, ScreenH*0.05)];
      [self.sendBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
      [self.sendBtn.layer setMasksToBounds:YES];
      [self.sendBtn.layer setCornerRadius:5];
      [self.sendBtn.layer setBorderColor:[UIColor blackColor].CGColor];
      [self.sendBtn.layer setBorderWidth:2];
      [self.sendBtn setTitle:@"发送" forState:UIControlStateNormal];
      [self.sendBtn addTarget:self action:@selector(sendMessageToGroup) forControlEvents:UIControlEventTouchUpInside];
      [self.view addSubview:self.sendBtn];
    
    self.statusLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, ScreenH*0.7, ScreenW, ScreenH*0.1)];
    [self.statusLabel setTextColor:[UIColor blackColor]];
    [self.statusLabel setFont:[UIFont systemFontOfSize:25]];
    [self.statusLabel setTextAlignment:NSTextAlignmentCenter];
    [self.statusLabel setText:@"当前状态:在线"];
    [self.view addSubview:self.statusLabel];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [[XMPPHelper sharedInstance] leaveRoom];
    [self dismissViewControllerAnimated:YES completion:nil];
}
#pragma mark - 显示房间名
- (void)setRoomName
{
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSString *name = [defaults objectForKey:@"XMPP_RoomName"];
    _domain = [defaults objectForKey:@"XMPP_Domain"];
    _roomTitle = [defaults objectForKey:@"XMPP_RoomTitle"];
    _nickName = [defaults objectForKey:@"XMPP_JoinRoomNickName"];
    _roomName = name;
    _roomName = [_roomName stringByAppendingString:@"@conference.im.sino-med.net"];
    [self.roomTitleLabel setText:[NSString stringWithFormat:@"房间名:%@",name]];
}

#pragma mark - 收到群组消息
-(void)recvGroupMessage:(NSString*)str
{
    self.historyMessage = [self.historyMessage stringByAppendingString:[NSString stringWithFormat:@"收到的最后一条消息为：%@\n",str]];
    [self.recvLabel setText:self.historyMessage];
    NSRange bottom =  NSMakeRange(self.recvLabel.text.length-1, 1);
    [self.recvLabel scrollRangeToVisible:bottom];
}

#pragma mark - 发送群组消息
- (void)sendMessageToGroup
{
    [[XMPPHelper sharedInstance] sendMessage:_sendMessageTF.text toGroup:_roomName from:@""];
    [_sendMessageTF setText:@""];
}
#pragma mark - 上线
- (void)isOnline
{
    [self.statusLabel setText:@"当前状态:在线"];
    [self.sendBtn setEnabled:true];
    if(_isOfflineReconnect)
    {
        _isOfflineReconnect = false;
        NSString *XMPP_RoomName = [_roomName stringByReplacingOccurrencesOfString:@"@conference.im.sino-med.net" withString:@""];
        [[XMPPHelper sharedInstance] leaveRoom];
        //重新加入房间
        [[XMPPHelper sharedInstance] creatRoomWithName:XMPP_RoomName withTitle:_roomTitle withNickName:_nickName withDomain:_domain];
    }
}

#pragma mark - 下线
- (void)isOffline
{
    [self.statusLabel setText:@"当前状态:离线"];
    self.historyMessage = @"";
    [self.recvLabel setText:@""];
    [self.sendBtn setEnabled:false];
    
    _isOfflineReconnect = true;
}
@end
