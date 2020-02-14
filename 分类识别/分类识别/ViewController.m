//
//  ViewController.m
//  猫狗识别
//
//  Created by Developer_Yi on 2020/1/21.
//  Copyright © 2020 medcare. All rights reserved.
//

#import "ViewController.h"
#import <Photos/Photos.h>

#define screenW [UIScreen mainScreen].bounds.size.width
#define screenH [UIScreen mainScreen].bounds.size.height

@interface ViewController ()<UIImagePickerControllerDelegate,UINavigationControllerDelegate>

@end

@implementation ViewController
- (void)viewWillAppear:(BOOL)animated{
    self.thermenalState = 0;
    // 初始化CoreML
    [self initCoreMLModel];
    // 监控设备温度变化
    [self observeDeviceTemp];
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.view setBackgroundColor:[UIColor systemBackgroundColor]];
    // 拍照按钮
    UIButton *takePhotoBtn = [[UIButton alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.2, screenW*0.4, screenW*0.4)];
    takePhotoBtn.layer.masksToBounds = YES;
    [takePhotoBtn.layer setCornerRadius:takePhotoBtn.bounds.size.width*0.5];
    [takePhotoBtn addTarget:self action:@selector(takePhotoClick) forControlEvents:UIControlEventTouchUpInside];
    [takePhotoBtn setImage:[UIImage imageNamed:@"TakePhoto"] forState:UIControlStateNormal];
    [self.view addSubview:takePhotoBtn];
    // 拍照按钮说明
    UILabel *cameraDescLabel = [[UILabel alloc]initWithFrame:CGRectMake(screenW*0.3, screenH*0.4, screenW*0.4, screenH*0.05)];
    [cameraDescLabel setTextAlignment:NSTextAlignmentCenter];
    [cameraDescLabel setText:@"Take Photo/Album"];
    [self.view addSubview:cameraDescLabel];
    
    // 选择的相片
    self.selPhotoView = [[UIImageView alloc]initWithFrame:CGRectMake(screenW*0.1, screenH*0.5, screenW*0.8, screenH*0.3)];
    self.selPhotoView.layer.masksToBounds = YES;
    self.selPhotoView.layer.cornerRadius = 10;
    self.selPhotoView.contentMode = UIViewContentModeScaleAspectFit;
    self.selPhotoView.image = [UIImage imageNamed:@"NoPhoto"];
    [self.view addSubview:self.selPhotoView];
    
    // 分类标签
    self.classifyLabel = [[UILabel alloc]initWithFrame:CGRectMake(screenW*0.1, screenH*0.85, screenW*0.8, screenH*0.05)];
    self.classifyLabel.textAlignment=NSTextAlignmentCenter;
    [self.classifyLabel setText:@"当前图片被识别为:"];
    [self.view addSubview:self.classifyLabel];
    
    // 分类可信度标签
     self.classifyConfidenceLabel = [[UILabel alloc]initWithFrame:CGRectMake(screenW*0.1, screenH*0.9, screenW*0.8, screenH*0.05)];
     self.classifyConfidenceLabel.textAlignment=NSTextAlignmentCenter;
     [self.classifyConfidenceLabel setText:@"当前图片被识别为  的概率为"];
     [self.view addSubview:self.classifyConfidenceLabel];
}


- (void)dealloc
{
    //当ViewController销毁前删除通知监听器
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"NSProcessInfoThermalStateDidChangeNotification" object:nil];
}

#pragma mark - 初始化CoreML Model
- (void)initCoreMLModel{
    self.classifier = [[CatDogClassifier alloc]init];
}

#pragma mark - 监听设备温度变化
- (void)observeDeviceTemp{
    [[NSNotificationCenter defaultCenter] addObserverForName:NSProcessInfoThermalStateDidChangeNotification object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
        [self setThermalState];
    }];
}

#pragma mark - 获取当前设备温度档次
- (void)setThermalState{
    NSProcessInfo *processInfo = [NSProcessInfo processInfo];
    switch(processInfo.thermalState){
        case NSProcessInfoThermalStateNominal:
            self.thermenalState = 0;
            break;
        case NSProcessInfoThermalStateFair:
            self.thermenalState = 1;
            break;
        case NSProcessInfoThermalStateSerious:
            self.thermenalState = 2;
            break;
        case NSProcessInfoThermalStateCritical:
            self.thermenalState = 3;
            break;
    }
}

#pragma mark - 拍照/选择相册点击事件
- (void)takePhotoClick{
    UIAlertController *ac = [UIAlertController alertControllerWithTitle:@"Choose a type" message:@"Select a way to get photo" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *takePhotoAction = [UIAlertAction actionWithTitle:@"Take Photo" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self openCamera];
    }];
    UIAlertAction *chooseAlbumAction = [UIAlertAction actionWithTitle:@"Choose Album" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self openAlbum];
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
          
    }];
    [ac addAction:takePhotoAction];
    [ac addAction:chooseAlbumAction];
    [ac addAction:cancelAction];
    [self presentViewController:ac animated:YES completion:^{
        
    }];
}

#pragma mark - 打开摄像头
- (void)openCamera{
    bool isAuth = false;
    // 1.获取相机授权状态
    AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
        // 2.检测授权状态
        switch (status) {
            case AVAuthorizationStatusNotDetermined: { // 用户还没有做出选择
                [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
                    if (granted) {
                        // 成功授权
                        dispatch_sync(dispatch_get_main_queue(), ^{
                                 [self pickupCamera];
                        });
                      
                    }else {
                        // 拒绝授权
                    }
                }];
            }
                break;
            case    AVAuthorizationStatusRestricted:
                // 受限制,家长控制,不允许访问
                [self remindUserAlert:@"Not Authorized" WithMessage:@"Your App's camera permission is limited"];
                break;
            case   AVAuthorizationStatusDenied:
                // 用户拒绝授权使用相机，需提醒用户到设置里面去开启app相机权限
                [self remindUserAlert:@"Not Authorized" WithMessage:@"Your App doesn't have camera permission,please go to Settings to setup"];
                break;
            case   AVAuthorizationStatusAuthorized:
                // 已经授权
                isAuth = true;
                break;
               
            default:
                break;
        }
    if(isAuth)
    {
        [self pickupCamera];
    }
}

#pragma mark - 掉起相机
- (void)pickupCamera{
    [self setThermalState];
    if(self.thermenalState < 2)
    {
                UIImagePickerController *picker = [[UIImagePickerController alloc] init];

                   picker.delegate = self;

                   picker.allowsEditing = YES;

                   //判断是否可以打开照相机
                   if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])
                   {
                       //摄像头
                       picker.sourceType = UIImagePickerControllerSourceTypeCamera;

                       [self presentViewController:picker animated:YES completion:nil];

                   }
                   else
                   {
                       NSLog(@"没有摄像头");
                   }
    }
    else
    {
         [self remindUserAlert:@"Warning" WithMessage:@"Your device's temperature is high,camera is unavailable"];
    }
  
}

#pragma mark - 本地相册
- (void)openAlbum{
    bool isAuth = false;
       // 1.获取相册授权状态
       PHAuthorizationStatus status = [PHPhotoLibrary authorizationStatus];
       // 2.根据状态进行相应的操作
       switch (status) {
           case PHAuthorizationStatusNotDetermined: { // 用户还没有做出选择
               // 2.1请求获取权限
               [PHPhotoLibrary requestAuthorization:^(PHAuthorizationStatus status) {
                   if (status == PHAuthorizationStatusDenied) {
                       // 拒绝授权
                   }else if (status == PHAuthorizationStatusAuthorized) {
                       // 授权成功
                       dispatch_sync(dispatch_get_main_queue(), ^{
                           [self pickupAlbum];
                       });
                   }else if (status == PHAuthorizationStatusRestricted) {
                       // 受限制,家长控制,不允许访问
                   }
               }];
               break;
           }
           case PHAuthorizationStatusRestricted:
             // 受限制,家长控制,不允许访问
                [self remindUserAlert:@"Not Authorized" WithMessage:@"Your App's album permission is limited"];
               break;
           case PHAuthorizationStatusDenied:
               // 用户拒绝授权使用相册，需提醒用户到设置里面去开启app相册权限
               [self remindUserAlert:@"Not Authorized" WithMessage:@"Your App doesn't have album permission,please go to Settings to setup"];
               break;
           case PHAuthorizationStatusAuthorized:
             // 用户已经授权，可以使用
               isAuth = true;
               break;
           default:
               break;
       }
    if(isAuth)
    {
        [self pickupAlbum];
    }
}

#pragma mark - 掉起相册
- (void)pickupAlbum{
    UIImagePickerController *picker = [[UIImagePickerController alloc] init];

    picker.delegate = self;

    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
          
    picker.allowsEditing = YES;
          
    [self presentViewController:picker animated:YES completion:nil];
}

#pragma mark - 提示信息
- (void)remindUserAlert:(NSString*)title WithMessage:(NSString*)msg{
    UIAlertController *ac = [UIAlertController alertControllerWithTitle:title message:msg preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil];
    [ac addAction:okAction];
    [self presentViewController:ac animated:YES completion:^{
        
    }];
}

#pragma mark - 获取回调
-(void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    NSString *type = [info objectForKey:UIImagePickerControllerMediaType];
    
    if([type isEqualToString:@"public.image"])
    {
        UIImage *image = info[UIImagePickerControllerEditedImage];

        self.selPhotoView.image = image;
        
        [self predictImageResultWithImage:image];
    }
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark - 预测结果
-(void)predictImageResultWithImage:(UIImage *)selImg
{
    NSError *error;
    UIImage *predictImg = [self scaleToSize:selImg size:CGSizeMake(299, 299)];
    CVPixelBufferRef buff = [self pixelBufferFromCGImage:predictImg.CGImage];
    CatDogClassifierOutput *output = [self.classifier predictionFromImage:buff error:&error];
    
    NSString *labelStr = [NSString stringWithFormat:@"当前图片被识别为:%@",output.classLabel];
    [self.classifyLabel setText:labelStr];
    NSString *confidenceStr = [NSString stringWithFormat:@"当前图片被识别为 %@ 的概率为 %.2f",output.classLabel,output.classLabelProbs[output.classLabel].floatValue];
    [self.classifyConfidenceLabel setText:confidenceStr];
}

#pragma mark - UIImage指定大小
- (UIImage *)scaleToSize:(UIImage *)img size:(CGSize)size{
    // 创建一个bitmap的context
    // 并把它设置成为当前正在使用的context
    UIGraphicsBeginImageContext(size);
    // 绘制改变大小的图片
    [img drawInRect:CGRectMake(0, 0, size.width, size.height)];
    // 从当前context中创建一个改变大小后的图片
    UIImage* scaledImage = UIGraphicsGetImageFromCurrentImageContext();
    // 使当前的context出堆栈
    UIGraphicsEndImageContext();
    // 返回新的改变大小后的图片
    return scaledImage;
}
#pragma mark - UIImage转CVPixelBufferRef
- (CVPixelBufferRef) pixelBufferFromCGImage: (CGImageRef) image{
    NSDictionary *options = @{
                              (NSString*)kCVPixelBufferCGImageCompatibilityKey : @YES,
                              (NSString*)kCVPixelBufferCGBitmapContextCompatibilityKey : @YES,
                              (NSString*)kCVPixelBufferIOSurfacePropertiesKey: [NSDictionary dictionary]
                              };
    CVPixelBufferRef pxbuffer = NULL;
    
    CGFloat frameWidth = CGImageGetWidth(image);
    CGFloat frameHeight = CGImageGetHeight(image);
    
    CVReturn status = CVPixelBufferCreate(kCFAllocatorDefault,
                                          frameWidth,
                                          frameHeight,
                                          kCVPixelFormatType_32BGRA,
                                          (__bridge CFDictionaryRef) options,
                                          &pxbuffer);
    
    NSParameterAssert(status == kCVReturnSuccess && pxbuffer != NULL);
    
    CVPixelBufferLockBaseAddress(pxbuffer, 0);
    void *pxdata = CVPixelBufferGetBaseAddress(pxbuffer);
    NSParameterAssert(pxdata != NULL);
    
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    
    CGContextRef context = CGBitmapContextCreate(pxdata,
                                                 frameWidth,
                                                 frameHeight,
                                                 8,
                                                 CVPixelBufferGetBytesPerRow(pxbuffer),
                                                 rgbColorSpace,
                                                 (CGBitmapInfo)kCGImageAlphaNoneSkipFirst);
    NSParameterAssert(context);
    CGContextConcatCTM(context, CGAffineTransformIdentity);
    CGContextDrawImage(context, CGRectMake(0,
                                           0,
                                           frameWidth,
                                           frameHeight),
                       image);
    CGColorSpaceRelease(rgbColorSpace);
    CGContextRelease(context);
    
    CVPixelBufferUnlockBaseAddress(pxbuffer, 0);
    
    return pxbuffer;
}

@end
