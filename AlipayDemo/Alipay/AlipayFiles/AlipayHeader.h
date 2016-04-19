//
//  AlipayHeader.h
//  Alipay
//
//  Created by Hosea on 16/2/17.
//  Copyright © 2016年 HoseaLee. All rights reserved.
//

/**
 *  说明：在原作者作品的基础上对支付宝支付做了一些修改，在支付方法上增加了支付回调结果，更加方便开发者对支付结果进行处理,ios9适配
 
 *  1. 将本工程中的Alipay文件夹导入工程中，记得选copy；
 *  2. 点击项目名称,点击“Build Settings”选项卡,在搜索框中,以关键字“search” 搜索,对“Header Search Paths”增加头文件路径:“$(SRCROOT)/项目名称/IntegratedAlipay/AlipayFiles”（注意：不包括引号，如果不是放到项目根目录下，请在项目名称后面加上相应的目录名）；
 *  3. 点击项目名称,点击“Build Phases”选项卡,在“Link Binary with Librarles” 选项中,新增“AlipaySDK.framework”和“SystemConfiguration.framework” 两个系统库文件。如果项目中已有这两个库文件,可不必再增加；
 *  4. BuildSettings  EnableBitcode 设置为 No；
 *  5. Info.plist  SourceCode打开 增加 安全传输协议
 
        <key>NSAppTransportSecurity</key>
        <dict>
            <key>NSAllowsArbitraryLoads</key>
            <true/>
        </dict>
    ；
 
 *  6. Info.plist  SourceCode打开 增加支付宝白名单（不然支付宝客户端无法打开）
 
        <key>LSApplicationQueriesSchemes</key>
        <array>
            <string>alipay</string>
        </array>
    ；
 *  7. 在本头文件中设置kPartnerID、kSellerAccount、kNotifyURL、kAppScheme和kPrivateKey的值（所有的值在支付宝回复的邮件里面：注意，建议除appScheme以外的字段都从服务器请求）；
 
 *  8. 点击项目名称,点击“Info”选项卡，在URL types里面添加一项，Identifier可以不填，URL schemes必须和appScheme的值相同，用于支付宝处理回到应用的事件（建议使用BundleID）；
 
 *  9. 在需要用的地方导入“AlipayHeader.h”，并使用“[AlipayRequestConfig alipayWithPartner:...”方法进行支付（增添回调）；
  */

#ifndef IntegratedAlipay_AlipayHeader_h
#define IntegratedAlipay_AlipayHeader_h


#import <AlipaySDK/AlipaySDK.h>     // 导入AlipaySDK
#import "AlipayRequestConfig.h"     // 导入支付类
#import "Order.h"                   // 导入订单类
#import "DataSigner.h"              // 生成signer的类：获取私钥并将商户信息签名,外部商户可以根据情况存放私钥和签名,只需要遵循 RSA 签名规范, 并将签名字符串 base64 编码和 UrlEncode

#import <Foundation/Foundation.h>   // 导入Foundation，防止某些类出现类似：“Cannot find interface declaration for 'NSObject', superclass of 'Base64'”的错误提示

/**
 *  支付宝安全支付回调通知名称
 *
 */
#define kAlipaySafePayResult @"ALIPAYSAFEPAYRESULT"

/**
 *  partner:合作身份者ID,以 2088 开头由 16 位纯数字组成的字符串。
 *
 */
#define kPartnerID @""


/**
 *  seller:支付宝收款账号,手机号码或邮箱格式。
 */
#define kSellerAccount @""

/**
 *  支付宝服务器主动通知商户 网站里指定的页面 http 路径。
 */
#define kNotifyURL @""


/**
 *  appSckeme:应用注册scheme,在Info.plist定义URLtypes，处理支付宝回调
 */
#define kAppScheme @"com.intplus.AlipayDemo"


/**
 *  private_key:商户方的私钥,pkcs8 格式。
 */
#define kPrivateKey @""




#endif
