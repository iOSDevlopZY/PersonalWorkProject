//
//  SecondViewController.m
//  NSNotificationTest
//
//  Created by Developer_Yi on 2020/2/4.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "SecondViewController.h"
#define screenW [UIScreen mainScreen].bounds.size.width
#define screenH [UIScreen mainScreen].bounds.size.height

@interface SecondViewController ()
{
    UITextField *messageTF;
    UITextField *secondMessageTF;
    UIButton *pushBtn;
}
@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view setBackgroundColor:[UIColor systemBackgroundColor]];
    
    UILabel *messageDescLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, screenH*0.3, screenW*0.3, screenH*0.05)];
    [messageDescLabel setTextColor:[UIColor whiteColor]];
    [messageDescLabel setText:@"发送的消息"];
    [messageDescLabel setTextAlignment:NSTextAlignmentCenter];
    [self.view addSubview:messageDescLabel];
    
    
    messageTF = [[UITextField alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.3, screenW*0.65, screenH*0.05)];
    [messageTF setBorderStyle:UITextBorderStyleLine];
    [self.view addSubview:messageTF];
    
    UILabel *messageDescLabel1 = [[UILabel alloc]initWithFrame:CGRectMake(0, screenH*0.4, screenW*0.3, screenH*0.05)];
    [messageDescLabel1 setTextColor:[UIColor whiteColor]];
    [messageDescLabel1 setText:@"发送的消息2"];
    [messageDescLabel1 setTextAlignment:NSTextAlignmentCenter];
    [self.view addSubview:messageDescLabel1];
       
       
    secondMessageTF = [[UITextField alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.4, screenW*0.65, screenH*0.05)];
    [secondMessageTF setBorderStyle:UITextBorderStyleLine];
    [self.view addSubview:secondMessageTF];
    
    pushBtn = [[UIButton alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.5, screenW*0.4, screenH*0.05)];
    [pushBtn.layer setMasksToBounds:YES];
    [pushBtn.layer setCornerRadius:5];
    [pushBtn.layer setBorderWidth:2];
    [pushBtn.layer setBorderColor:[UIColor lightGrayColor].CGColor];
    [pushBtn setTitle:@"推送消息" forState:UIControlStateNormal];
    [pushBtn setTitleColor:[UIColor lightGrayColor] forState:UIControlStateNormal];
    [pushBtn addTarget:self action:@selector(pushMessage) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:pushBtn];
}

#pragma mark - 推送消息
- (void)pushMessage{
    NSNotification *notification = [NSNotification notificationWithName:@"MessageOccur" object:self userInfo:@{@"info":messageTF.text}];
    [[NSNotificationCenter defaultCenter]postNotification:notification];
    
    NSNotification *notification1 = [NSNotification notificationWithName:@"MessageOccur1" object:self userInfo:@{@"info":secondMessageTF.text}];
    [[NSNotificationCenter defaultCenter]postNotification:notification1];
}

@end
