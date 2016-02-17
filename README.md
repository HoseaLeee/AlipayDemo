说明：在原作者作品的基础上对支付宝支付做了一些修改，在支付方法上增加了支付回调结果，更加方便开发者对支付结果进行处理,对iOS9进行了适配
使用：
   1. 将本工程中的Alipay文件夹导入工程中，记得选copy；
   2. 点击项目名称,点击“Build Settings”选项卡,在搜索框中,以关键字“search” 搜索,对“Header Search Paths”增加头文件路径:“$(SRCROOT)/项目名称/IntegratedAlipay/AlipayFiles”（注意：不包括引号，如果不是放到项目根目录下，请在项目名称后面加上相应的目录名）；
   3. 点击项目名称,点击“Build Phases”选项卡,在“Link Binary with Librarles” 选项中,新增“AlipaySDK.framework”和“SystemConfiguration.framework” 两个系统库文件。如果项目中已有这两个库文件,可不必再增加；
   4. BuildSettings  EnableBitcode 设置为 No；
   5. Info.plist  SourceCode打开 增加 安全传输协议
 
        <key>NSAppTransportSecurity</key>
        <dict>
            <key>NSAllowsArbitraryLoads</key>
            <true/>
        </dict>
    ；
    

  6. Info.plist  SourceCode打开 增加支付宝白名单（不然支付宝客户端无法打开）
 
        <key>LSApplicationQueriesSchemes</key>
        <array>
            <string>alipay</string>
        </array>
    ；
      

   7. 在本头文件中设置kPartnerID、kSellerAccount、kNotifyURL、kAppScheme和kPrivateKey的值（所有的值在支付宝回复的邮件里面：注意，建议除appScheme以外的字段都从服务器请求）；
   8. 点击项目名称,点击“Info”选项卡，在URL types里面添加一项，Identifier可以不填，URL schemes必须和appScheme的值相同，用于支付宝处理回到应用的事件（建议使用BundleID）；
   9. 在需要用的地方导入“AlipayHeader.h”，并使用“[AlipayRequestConfig alipayWithPartner:...”方法进行支付（增添回调）；

# AlipayDemo
