//
//  DesEncrypt.h
//  DesEncrypt
//
//  Created by pg on 16/1/28.
//  Copyright © 2016年 美迪康. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>

@interface DesEncrypt : NSObject

+(NSString *)ToDESEncryptString:(NSString *)encryptString WithKey:(NSString *)key;
+ (NSString *)stringFromHexString:(NSString *)hexString;

@end
