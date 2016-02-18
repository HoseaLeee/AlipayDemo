//
//  AlipayRequestConfig.h
//  Alipay
//
//  Created by Hosea on 16/2/17.
//  Copyright © 2016年 HoseaLee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlipayHeader.h"

@interface AlipayRequestConfig : NSObject

/**
 *  普通支付调用 仅含必要商品参数
 *
 *  @param tradeNO            商品唯一订单号
 *  @param productName        商品名称
 *  @param productDescription 商品描述
 *  @param amount             商品金额
 */
+ (void)alipayWithTradeNO:(NSString *)tradeNO
              productName:(NSString *)productName
       productDescription:(NSString *)productDescription
                   amount:(NSString *)amount
                 complete:(void (^)(NSDictionary * dictionary))complete;


@end

/**
 *  支付宝的一些参数的生成
 */
@interface AlipayToolKit : NSObject

+ (NSString *)genTradeNoWithTime;

@end
