//
//  ViewController.m
//  NSNotificationTest
//
//  Created by Developer_Yi on 2020/2/4.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "ViewController.h"
#import "SecondViewController.h"

#define screenW [UIScreen mainScreen].bounds.size.width
#define screenH [UIScreen mainScreen].bounds.size.height
@interface ViewController ()
{
    UILabel *messageLabel;
    UILabel *messageLabel1;
    UIButton *turnBtn;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view setBackgroundColor:[UIColor systemBackgroundColor]];
    messageLabel = [[UILabel alloc]initWithFrame:CGRectMake(0, screenH*0.2, screenW, screenH*0.2)];
    [messageLabel setTextAlignment:NSTextAlignmentCenter];
    [messageLabel setFont:[UIFont systemFontOfSize:25]];
    [messageLabel setTextColor:[UIColor labelColor]];
    [self.view addSubview:messageLabel];
    
    messageLabel1 = [[UILabel alloc]initWithFrame:CGRectMake(0, screenH*0.4, screenW, screenH*0.2)];
    [messageLabel1 setTextAlignment:NSTextAlignmentCenter];
    [messageLabel1 setFont:[UIFont systemFontOfSize:25]];
    [messageLabel1 setTextColor:[UIColor labelColor]];
    [self.view addSubview:messageLabel1];
    
    turnBtn = [[UIButton alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.6, screenW*0.4, screenH*0.05)];
    [turnBtn.layer setMasksToBounds:YES];
    [turnBtn.layer setCornerRadius:5];
    [turnBtn.layer setBorderWidth:2];
    [turnBtn.layer setBorderColor:[UIColor lightGrayColor].CGColor];
    [turnBtn setTitle:@"进入下一页" forState:UIControlStateNormal];
    [turnBtn setTitleColor:[UIColor lightGrayColor] forState:UIControlStateNormal];
    [turnBtn addTarget:self action:@selector(push) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:turnBtn];
    //添加通知监听者
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(recvMessage:) name:@"MessageOccur" object:nil];
    
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(recvMessage1:) name:@"MessageOccur1" object:nil];
}

- (void)dealloc{
    [[NSNotificationCenter defaultCenter]removeObserver:self];
}

#pragma mark -  收到消息的处理方法
- (void)recvMessage:(NSNotification *)notification{
    NSDictionary *infoDic = notification.userInfo;
    [messageLabel setText:[NSString stringWithFormat:@"收到的消息1：%@",infoDic[@"info"]]];
}

- (void)recvMessage1:(NSNotification *)notification{
    NSDictionary *infoDic = notification.userInfo;
    [messageLabel1 setText:[NSString stringWithFormat:@"收到的消息2：%@",infoDic[@"info"]]];
}

#pragma mark - 跳转到下一页
- (void)push{
    SecondViewController *secondVC = [[SecondViewController alloc] init];
    [self presentViewController:secondVC animated:YES completion:nil];
}
@end
