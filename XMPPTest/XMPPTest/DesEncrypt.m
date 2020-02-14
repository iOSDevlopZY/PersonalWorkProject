//
//  DesEncrypt.m
//  DesEncrypt
//
//  Created by pg on 16/1/28.
//  Copyright © 2016年 美迪康. All rights reserved.
//

#import "DesEncrypt.h"
#import "base64.h"
const Byte iv[] = {1,2,3,4,5,6,7,8,};
@implementation DesEncrypt



#pragma mark - 加密
+(NSString *)ToDESEncryptString:(NSString *)encryptString WithKey:(NSString *)key
{
    Byte *keyByte;
    Byte arrB[8] = {0,0,0,0,0,0,0,0};
    
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    keyByte = (Byte*)[keyData bytes];

    
    NSString *ciphertext = nil;
    NSData *textData = [encryptString dataUsingEncoding:NSUTF8StringEncoding];
    NSUInteger dataLength = [textData length];
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    size_t numBytesEncrypted = 0;
    
    for (int i = 0; i < [keyData length] && i<8; i++)
    {
        arrB[i] = keyByte[i];
    }


    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding,
                                          arrB, kCCKeySizeDES,NULL,
                                          [textData bytes], dataLength,buffer, 1024,
                                          &numBytesEncrypted);
    if (cryptStatus == kCCSuccess) {
        NSLog(@"DES加密成功");
        
        NSData *data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesEncrypted];
        ciphertext = [base64 encode:data];
        
//        NSString* encodeResult = [data base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];

        return ciphertext;
        
       
    }else{
        NSLog(@"DES加密失败");
    }
    
    free(buffer);
    return nil;
}









// 十六进制转换为普通字符串的。
+ (NSString *)stringFromHexString:(NSString *)hexString { 
    
    char *myBuffer = (char *)malloc((int)[hexString length] / 2 + 1);
    bzero(myBuffer, [hexString length] / 2 + 1);
    for (int i = 0; i < [hexString length] - 1; i += 2) {
        unsigned int anInt;
        NSString * hexCharStr = [hexString substringWithRange:NSMakeRange(i, 2)];
        NSScanner * scanner = [[NSScanner alloc] initWithString:hexCharStr];
        [scanner scanHexInt:&anInt];
        myBuffer[i / 2] = (char)anInt;
    }
    NSString *unicodeString = [NSString stringWithCString:myBuffer encoding:4];
    NSLog(@"------字符串=======%@",unicodeString);
    return unicodeString; 
    
    
}



@end
