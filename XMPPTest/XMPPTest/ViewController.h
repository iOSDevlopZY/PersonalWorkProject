//
//  ViewController.h
//  XMPPTest
//
//  Created by Developer_Yi on 2020/2/12.
//  Copyright © 2020 medcare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ChatRoomViewController.h"
#import "XMPPHelper.h"

@interface ViewController : UIViewController
@property (strong, nonatomic) UITextField *userNameTF;
@property (strong, nonatomic) UITextField *passWordTF;
@property (strong, nonatomic) UITextField *roomNoTF;
@property (strong, nonatomic) UILabel *onLineStatusLabel;
@property (strong, nonatomic) UIButton *createRoomBtn;
@property (strong, nonatomic) ChatRoomViewController *roomVC;
@property (assign, nonatomic) BOOL isCurrentVC;
@end

