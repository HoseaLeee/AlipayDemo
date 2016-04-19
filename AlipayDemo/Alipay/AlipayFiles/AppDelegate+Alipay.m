//
//  AppDelegate+Alipay.m
//  AlipayDemo
//
//  Created by Nan on 16/4/18.
//  Copyright © 2016年 HoseaLee. All rights reserved.
//

#import "AppDelegate+Alipay.h"
#import "AlipayHeader.h"


@implementation AppDelegate (Alipay)

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    if ([url.host isEqualToString:@"safepay"]) {
        //跳转支付宝钱包进行支付，处理支付结果
        [[AlipaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(NSDictionary *resultDic) {
            NSLog(@"result = %@",resultDic);
                        
            [[NSNotificationCenter defaultCenter]  postNotificationName:kAlipaySafePayResult object:resultDic];
            
        }];
    }
    
    return YES;
}


@end
