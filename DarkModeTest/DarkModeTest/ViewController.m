//
//  ViewController.m
//  DarkModeTest
//
//  Created by Developer_Yi on 2019/10/26.
//  Copyright © 2019 medcare. All rights reserved.
//

#import "ViewController.h"

#define screenWidth [[UIScreen mainScreen] bounds].size.width
#define screenHeight [[UIScreen mainScreen] bounds].size.height

typedef NS_ENUM(NSUInteger, GradientType) {
    GradientTypeTopToBottom = 0,//从上到下
    GradientTypeLeftToRight = 1,//从左到右
    GradientTypeUpleftToLowright = 2,//左上到右下
    GradientTypeUprightToLowleft = 3,//右上到左下
};

@interface ViewController ()
{
    UILabel *modeLabel;
    
    UIImageView *colorBlockView;
    
    UIButton *clickBtn;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 设置View的背景色跟随系统颜色
    [self.view setBackgroundColor:[UIColor systemBackgroundColor]];
    // 设置圆角头像
    [self setupIconView];
    // 设置昵称
    [self setNickLabel];
    // 设置中间背景块
    [self setColorBlock];
    // 设置当前获取模式
    [self setCurrentModeLabel];
    // 设置点击按钮
    [self setClickBtn];

    [self setCurrentModeText];
}

// 设置点击按钮
- (void)setClickBtn
{
    clickBtn =[[UIButton alloc]initWithFrame:CGRectMake(screenWidth*0.1, screenHeight*0.4, screenWidth*0.8, screenHeight*0.2)];
    [clickBtn setTitle:@"点击更换到当前模式下的APP图标" forState:UIControlStateNormal];
    [clickBtn addTarget:self action:@selector(changeIconClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:clickBtn];
    [self.view bringSubviewToFront:clickBtn];
}

// 更换程序图标
- (void)changeIconClick
{
    [self setAppIcon];
}


// 设置圆角头像
- (void)setupIconView {
    UIImageView *iconView = [[UIImageView alloc]initWithFrame:CGRectMake(screenWidth*0.35, screenHeight*0.1, screenWidth*0.3, screenWidth*0.3)];
    
    iconView.layer.shadowColor = [UIColor grayColor].CGColor;// 阴影的颜色
    
    iconView.layer.shadowOpacity = 0.33;//阴影的不透明度
    
    iconView.layer.shadowOffset = CGSizeMake(0, 1.5);//阴影的偏移
    
    iconView.layer.shadowRadius = 4.0;//阴影半径
    
    iconView.layer.shouldRasterize = YES; //圆角缓存
    
    iconView.layer.rasterizationScale = [UIScreen mainScreen].scale;//栅格化图层 提高流畅度
    //圆角
    iconView.layer.cornerRadius = 10.0f;
    
    iconView.contentMode = UIViewContentModeScaleAspectFill;
    
    iconView.layer.masksToBounds = YES;
    
    iconView.image = [UIImage imageNamed:@"HeadIcon"];
    
    [self.view addSubview:iconView];
}

// 设置昵称
- (void)setNickLabel{
    UIImageView *appleView = [[UIImageView alloc]initWithFrame:CGRectMake(screenWidth*0.26, screenHeight*0.25, screenWidth*0.08, screenHeight*0.08)];
    
    appleView.contentMode = UIViewContentModeScaleAspectFill;
    
    appleView.image = [UIImage imageNamed:@"Icon"];
    
    [self.view addSubview:appleView];
    
    UILabel *descLabel = [[UILabel alloc]initWithFrame:CGRectMake(screenWidth*0.38, screenHeight*0.25, screenWidth*0.4, screenHeight*0.08)];
    
    [descLabel setTextColor:[UIColor labelColor]];
    
    [descLabel setText:@"东方张布斯"];
    
    [descLabel setFont:[UIFont systemFontOfSize:30]];
    
    [self.view addSubview:descLabel];
}

// 设置中间背景块
- (void)setColorBlock{
    colorBlockView = [[UIImageView alloc]initWithFrame:CGRectMake(0, screenHeight*0.35, screenWidth, screenHeight*0.65)];
    
    [self setCurrentLinerColor];
    
    [self.view addSubview:colorBlockView];
}

// 设置当前获取模式
- (void)setCurrentModeLabel{
    modeLabel = [[UILabel alloc]initWithFrame:CGRectMake(screenWidth*0.4, screenHeight*0.85, screenWidth*0.58, screenHeight*0.18)];
    
    [modeLabel setTextColor:[UIColor placeholderTextColor]];
    
    [modeLabel setFont:[UIFont systemFontOfSize:20]];
    
    [modeLabel setTextAlignment:NSTextAlignmentRight];
    
    [self setCurrentModeText];
    
    [self.view addSubview:modeLabel];
    
    [self.view bringSubviewToFront:modeLabel];
}

// 监听模式改变
- (void)traitCollectionDidChange:(UITraitCollection *)previousTraitCollection {
    [super traitCollectionDidChange:previousTraitCollection];
    // trait发生了改变
    if ([self.traitCollection hasDifferentColorAppearanceComparedToTraitCollection:previousTraitCollection]) {
        // 执行操作
        [self setCurrentModeText];
        [self setCurrentLinerColor];
    }
}

// 设置当前模式文本
- (void)setCurrentModeText{
    if(self.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark)
    {
        [modeLabel setText:@"当前模式：黑暗模式"];
    }
    else
    {
        [modeLabel setText:@"当前模式：明亮模式"];
    }
    // 设置动态颜色
    UIColor *labelDyColor = [UIColor colorWithDynamicProvider:^UIColor * _Nonnull(UITraitCollection * _Nonnull trainCollection) {
        if ([trainCollection userInterfaceStyle] == UIUserInterfaceStyleLight) {
            return [UIColor whiteColor];
        }
        else {
            return [UIColor blackColor];
        }
    }];
    UIColor *btnDyColor = [UIColor colorWithDynamicProvider:^UIColor * _Nonnull(UITraitCollection * _Nonnull trainCollection) {
        if ([trainCollection userInterfaceStyle] == UIUserInterfaceStyleLight) {
            return [UIColor blackColor];
        }
        else {
            return [UIColor whiteColor];
        }
    }];
    [modeLabel setTextColor:labelDyColor];
    [clickBtn setTitleColor:btnDyColor forState:UIControlStateNormal];
}

// 设置当前模式渐变色
- (void)setCurrentLinerColor{
    UIColor *blackColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:1.0f];
    
    UIColor *topColor = [UIColor colorWithRed:100/255.0f green:100/255.0f blue:100/255.0f alpha:1.0f];
    UIColor *whiteColor = [UIColor colorWithRed:1 green:1 blue:1 alpha:1.0f];
    if(self.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark)
    {
       
        colorBlockView.image=[self gradientColorImageFromColors:@[blackColor,topColor,whiteColor] gradientType:GradientTypeTopToBottom imgSize:colorBlockView.bounds.size];
    }
    else
    {
        colorBlockView.image=[self gradientColorImageFromColors:@[whiteColor,topColor,blackColor] gradientType:GradientTypeTopToBottom imgSize:colorBlockView.bounds.size];
    }
}

// 设置APP动态图标
- (void)setAppIcon{
    if(self.traitCollection.userInterfaceStyle == UIUserInterfaceStyleDark)
    {
        [self changeAppIconWithName:@"BlackLogo"];
    }
    else
    {
        [self changeAppIconWithName:@"WhiteLogo"];
    }
}

// 设置渐变色
-  (UIImage *)gradientColorImageFromColors:(NSArray*)colors gradientType:(GradientType)gradientType imgSize:(CGSize)imgSize {
    NSMutableArray *ar = [NSMutableArray array];
    for(UIColor *c in colors) {
        [ar addObject:(id)c.CGColor];
    }
    UIGraphicsBeginImageContextWithOptions(imgSize, YES, 1);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    CGColorSpaceRef colorSpace = CGColorGetColorSpace([[colors lastObject] CGColor]);
    CGGradientRef gradient = CGGradientCreateWithColors(colorSpace, (CFArrayRef)ar, NULL);
    CGPoint start;
    CGPoint end;
    switch (gradientType) {
        case GradientTypeTopToBottom:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(0.0, imgSize.height);
            break;
        case GradientTypeLeftToRight:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(imgSize.width, 0.0);
            break;
        case GradientTypeUpleftToLowright:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(imgSize.width, imgSize.height);
            break;
        case GradientTypeUprightToLowleft:
            start = CGPointMake(imgSize.width, 0.0);
            end = CGPointMake(0.0, imgSize.height);
            break;
        default:
            break;
    }
    CGContextDrawLinearGradient(context, gradient, start, end, kCGGradientDrawsBeforeStartLocation | kCGGradientDrawsAfterEndLocation);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    CGGradientRelease(gradient);
    CGContextRestoreGState(context);
    CGColorSpaceRelease(colorSpace);
    UIGraphicsEndImageContext();
    return image;
}

//更换APP图标
- (void)changeAppIconWithName:(NSString *)iconName {
    if (![[UIApplication sharedApplication] supportsAlternateIcons]) {
        return;
    }
    
    if ([iconName isEqualToString:@""]) {
        iconName = nil;
    }
    [[UIApplication sharedApplication] setAlternateIconName:iconName completionHandler:^(NSError * _Nullable error) {
        if (error) {
            NSLog(@"更换app图标发生错误了 ： %@",error);
        }
    }];
}
@end
