//
//  ViewController.h
//  猫狗识别
//
//  Created by Developer_Yi on 2020/1/21.
//  Copyright © 2020 medcare. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreML/CoreML.h>
#import "CatDogClassifier.h"

@interface ViewController : UIViewController
@property (nonatomic,strong) CatDogClassifier *classifier;
@property (nonatomic,strong) UIImageView *selPhotoView;
@property (nonatomic,strong) UILabel *classifyLabel;
@property (nonatomic,strong) UILabel *classifyConfidenceLabel;
@property (nonatomic,assign) int thermenalState;
@end

