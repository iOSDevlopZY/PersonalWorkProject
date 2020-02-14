//
//  ChatRoomViewController.h
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/12.
//  Copyright © 2020 medcare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XMPPHelper.h"

NS_ASSUME_NONNULL_BEGIN

@interface ChatRoomViewController : UIViewController

@property (nonatomic,strong) UILabel* roomTitleLabel;
@property (nonatomic,strong) UITextView* recvLabel;
@property (strong, nonatomic) UITextField *sendMessageTF;
@property (strong, nonatomic) UIButton *sendBtn;
@property (strong,nonatomic) NSString *roomName;
@property (strong,nonatomic) NSString *domain;
@property (strong,nonatomic) NSString *nickName;
@property (strong,nonatomic) NSString *roomTitle;
@property (strong,nonatomic) NSString *historyMessage;
@property (nonatomic,strong) UILabel* statusLabel;
@property (nonatomic,assign) BOOL isOfflineReconnect;
- (void)setRoomName;
-(void)recvGroupMessage:(NSString*)str;
- (void)isOnline;
- (void)isOffline;
@end

NS_ASSUME_NONNULL_END
