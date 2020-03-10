//
//  ViewController.m
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/12.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "ViewController.h"

#define ScreenW [UIScreen mainScreen].bounds.size.width
#define ScreenH [UIScreen mainScreen].bounds.size.height

#define XMPP_RoomTitle   @"张艺群聊测试房间"
#define XMPP_JoinRoomNickName @"张艺测试"
#define XMPP_Domain @"im.sino-med.net"
@interface ViewController ()<UITextFieldDelegate,sendMessageDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    _isCurrentVC = true;
    // Do any additional setup after loading the view.
    UILabel *titleLabel = [[UILabel alloc]initWithFrame:CGRectMake(ScreenW*0.1, 0, ScreenW*0.8, ScreenH*0.2)];
    [titleLabel setTextColor:[UIColor whiteColor]];
    [titleLabel setFont:[UIFont systemFontOfSize:30]];
    [titleLabel setTextAlignment:NSTextAlignmentCenter];
    [titleLabel setText:@"XMPP"];
    [self.view addSubview:titleLabel];
    
    UILabel *userLabel = [[UILabel alloc]initWithFrame:CGRectMake(ScreenW*0.1, ScreenH*0.2, ScreenW*0.2, ScreenH*0.1)];
    [userLabel setTextColor:[UIColor whiteColor]];
    [userLabel setFont:[UIFont systemFontOfSize:20]];
    [userLabel setTextAlignment:NSTextAlignmentCenter];
    [userLabel setText:@"用户名："];
    [self.view addSubview:userLabel];
    
    self.userNameTF = [[UITextField alloc]initWithFrame:CGRectMake(ScreenW*0.3, ScreenH*0.2, ScreenW*0.4, ScreenH*0.1)];
    [self.userNameTF setPlaceholder:@"请输入用户名"];
    [self.userNameTF setText:@"yanghao"];
    [self.view addSubview:self.userNameTF];
    
    UILabel *passwdLabel = [[UILabel alloc]initWithFrame:CGRectMake(ScreenW*0.1, ScreenH*0.35, ScreenW*0.2, ScreenH*0.1)];
    [passwdLabel setTextColor:[UIColor whiteColor]];
    [passwdLabel setFont:[UIFont systemFontOfSize:20]];
    [passwdLabel setTextAlignment:NSTextAlignmentCenter];
    [passwdLabel setText:@"密码："];
    [self.view addSubview:passwdLabel];
    
    self.passWordTF = [[UITextField alloc]initWithFrame:CGRectMake(ScreenW*0.3, ScreenH*0.35, ScreenW*0.4, ScreenH*0.1)];
    [self.passWordTF setPlaceholder:@"请输入密码"];
    [self.passWordTF setSecureTextEntry:true];
    [self.passWordTF setText:@"888888"];
    [self.view addSubview:self.passWordTF];
    
    UIButton *loginBtn = [[UIButton alloc]initWithFrame:CGRectMake(ScreenW*0.2, ScreenH*0.5, ScreenW*0.6, ScreenH*0.05)];
    [loginBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
//    [loginBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [loginBtn.layer setMasksToBounds:YES];
    [loginBtn.layer setCornerRadius:5];
    [loginBtn.layer setBorderColor:[UIColor whiteColor].CGColor];
    [loginBtn.layer setBorderWidth:2];
    [loginBtn setTitle:@"登录" forState:UIControlStateNormal];
    [loginBtn addTarget:self action:@selector(login) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginBtn];
    
    self.onLineStatusLabel = [[UILabel alloc]initWithFrame:CGRectMake(ScreenW*0.1, ScreenH*0.6, ScreenW*0.8, ScreenH*0.05)];
    [self.onLineStatusLabel setTextColor:[UIColor whiteColor]];
    [self.onLineStatusLabel setFont:[UIFont systemFontOfSize:25]];
    [self.onLineStatusLabel setTextAlignment:NSTextAlignmentCenter];
    [self.onLineStatusLabel setText:@"当前状态：离线"];
    [self.view addSubview:self.onLineStatusLabel];
    
    self.createRoomBtn = [[UIButton alloc]initWithFrame:CGRectMake(ScreenW*0.2, ScreenH*0.75, ScreenW*0.6, ScreenH*0.05)];
    [self.createRoomBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
//    [self.createRoomBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.createRoomBtn setEnabled:false];
    [self.createRoomBtn.layer setMasksToBounds:YES];
    [self.createRoomBtn.layer setCornerRadius:5];
    [self.createRoomBtn.layer setBorderColor:[UIColor whiteColor].CGColor];
    [self.createRoomBtn.layer setBorderWidth:2];
    [self.createRoomBtn setTitle:@"创建群聊房间" forState:UIControlStateNormal];
    [self.createRoomBtn addTarget:self action:@selector(createRoom) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.createRoomBtn];
    
    UILabel *roomLabel = [[UILabel alloc]initWithFrame:CGRectMake(ScreenW*0.1, ScreenH*0.65, ScreenW*0.2, ScreenH*0.1)];
    [roomLabel setTextColor:[UIColor whiteColor]];
    [roomLabel setFont:[UIFont systemFontOfSize:20]];
    [roomLabel setTextAlignment:NSTextAlignmentCenter];
    [roomLabel setText:@"房间名："];
    [self.view addSubview:roomLabel];
    
    self.roomNoTF = [[UITextField alloc]initWithFrame:CGRectMake(ScreenW*0.3, ScreenH*0.65, ScreenW*0.6, ScreenH*0.1)];
    [self.roomNoTF setPlaceholder:@"请输入房间号"];
    [self.roomNoTF setText:@"ZYGroupChatRoomTest"];
    [self.view addSubview:self.roomNoTF];
    
    self.userNameTF.delegate = self;
    self.passWordTF.delegate = self;
    self.roomNoTF.delegate = self;
    
    [XMPPHelper sharedInstance].Messagedelegate=self;

}

#pragma mark - 登录
- (void)login
{
    if(![self.userNameTF.text  isEqual: @""] && ![self.passWordTF.text  isEqual: @""])
    {
        [[XMPPHelper sharedInstance] connectByUserName:self.userNameTF.text.lowercaseString password:self.passWordTF.text.lowercaseString];
    }
    else
    {
        UIAlertController *ac =[UIAlertController alertControllerWithTitle:@"提示" message:@"用户名和密码都不能为空" preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好" style:UIAlertActionStyleDefault handler:nil];
        [ac addAction:okAction];
        [self presentViewController:ac animated:YES completion:nil];
    }
}

#pragma mark - 用户验证失败
-(void)accountNotAuthorized
{
    UIAlertController *ac =[UIAlertController alertControllerWithTitle:@"提示" message:@"账号未能通过验证，请检查" preferredStyle:UIAlertControllerStyleAlert];
           UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好" style:UIAlertActionStyleDefault handler:nil];
           [ac addAction:okAction];
           [self presentViewController:ac animated:YES completion:nil];
}
#pragma mark - 创建房间
- (void)createRoom
{
    _isCurrentVC = true;
    if(![self.roomNoTF.text isEqual:@""])
    {
        
        [[XMPPHelper sharedInstance] creatRoomWithName:self.roomNoTF.text withTitle:XMPP_RoomTitle withNickName:XMPP_JoinRoomNickName withDomain:XMPP_Domain];
           //保存数据
           NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
           [defaults setObject:self.roomNoTF.text forKey:@"XMPP_RoomName"];
           [defaults setObject:XMPP_RoomTitle forKey:@"XMPP_RoomTitle"];
           [defaults setObject:XMPP_JoinRoomNickName forKey:@"XMPP_JoinRoomNickName"];
           [defaults setObject:XMPP_Domain forKey:@"XMPP_Domain"];

           [defaults synchronize];
    }
    else
    {
        UIAlertController *ac =[UIAlertController alertControllerWithTitle:@"提示" message:@"房间号不能为空" preferredStyle:UIAlertControllerStyleAlert];
               UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好" style:UIAlertActionStyleDefault handler:nil];
               [ac addAction:okAction];
               [self presentViewController:ac animated:YES completion:nil];
    }
   
}

#pragma mark - 回收键盘
- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

#pragma mark - 认证成功
- (void)present
{
    NSLog(@"认证成功");
}

#pragma mark - 上线
- (void)isOnline
{
    [self.onLineStatusLabel setText:@"当前状态：在线"];
    [self.createRoomBtn setEnabled:true];
    if(_roomVC)
    {
        [_roomVC isOnline];
    }
}

- (void)isOffline
{
    [self.onLineStatusLabel setText:@"当前状态：离线"];
    [self.createRoomBtn setEnabled:false];
    if(_roomVC)
    {
        [_roomVC isOffline];
    }
}

#pragma mark - 创建房间加入成功
- (void)joinRoomSuccess
{
            if(_isCurrentVC)
            {
                //当前的界面为根视图
                           _roomVC=[[ChatRoomViewController alloc]init];
                           [self presentViewController:_roomVC animated:YES completion:^{
                               [self->_roomVC setRoomName];
                               self->_isCurrentVC = false;
                           }];
            }
}

#pragma mark - 收到群组通知
-(void)recvGroupMessage:(NSString*)str
{
    if(_roomVC)
    {
        [_roomVC recvGroupMessage:str];
    }
}

@end
