//
//  TYTinyConfig.h
//  TinyKern
//
//  Created by 兖志飞 on 2019/8/1.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define kConfigurationResourceVersion @"resourceVersion"

#define ktinyName @"tiny"

#define CustomerConfigurationDir @"CustomerConfig.plist"
#define SystemConfigurationDir @"System.plist"

#define kConfigurationBoxModel @"boxModel"
#define kConfigurationCacheImage @"cacheImage"
#define kConfigurationLogLEVEL @"LEVEL"
#define kConfigurationLogFILTERS @"FILTERS"
#define kConfigurationIgnorePath @"ignorePath"
#define kConfigurationOutCage  @"OutCage"
#define kConfigurationAntiDebug @"antiDebug"
#define kConfigurationTouchSecurity @"touchSecurity"
#define kConfigurationTouchIDTypeSign @"sign"
#define kConfigurationTouchIDTypeSecurity @"security"
#define kConfigurationErrorPage @"errorPage"
#define kConfigurationPasswordMd5 @"passwordMd5"
#define kConfigurationScale @"scale"
#define kConfigurationResourceEncrypted   @"resEncrypt"
#define kConfigurationFrostedGlass  @"FrostedGlass"
#define kCOnfigurationDimAmount  @"dimAmount"
#define kConfigurationDebug @"tinyIDE"
#define kConfigurationAutomationTest @"automationTest"
#define kConfigurationKeyboardFeedback  @"keyboardfeedback"
#define kConfigurationNoDelayLock @"noDelayLock"
#define kConfigurationSaveToKeychain  @"saveToKeychain"
#define kConfigurationClickInterval @"clickInterval"
#define kConfigurationUseGoogleMap @"useGoogleMap"
#define kConfigurationRootCheck @"rootCheck"
#define kConfigurationLimitScreenShot @"limitScreenShot"
#define kConfigurationScreenFuzzy @"screenFuzzy"
#define kConfigurationHidesStatusBar @"hidesStatusBar"
#define kConfigurationHideSafeArea  @"hideSafeArea"

#define kConfigurationTimeout @"timeout"
#define kConfigurationList @"list"
#define kConfigurationHost @"Host"

#define kConfigurationEncryptionUrlInfo @"appBaseUrl"
#define kConfigurationEncryptionUrlInfos @"appBaseUrls"
#define kConfigurationEncryptionOpen @"encrypt"
#define kConfigurationSignature @"signRequest"
#define kConfigurationVersionResUpdate @"versionResUpdate"
#define kConfigurationUpdataUrl @"updataUrlConfig"
#define kConfigurationSignRequestType @"signRequestType"
#define kConfigurationEncryptType @"encryptType"
#define kSecAttrAccountClientDataKey @"secAccountData"
#define kSecAttrAccountClientPassKey @"secAccountPass"

#define kResourceHudPathKey @"resourceHud"
#define kimageTbsPathKey @"imageTbs"

#define kwebUserScalableKey @"webUserScalable"

//HTTPS双向验证证书密码
#define  kHTTPSAuthoAuthoritationPass @"sunline"
//HTTPS双向验证证书名称
#define  kHTTPSAuthoAuthoritationName @"test"

#define kConfigurationTrue @"true"
#define kConfigurationFalse @"false"

static NSString* const kApplicationLastVersionKey = @"tiny_application_last_version";
static NSString* const kAppLastResourceUpdateTime = @"tiny_app_resource_last_update_time";
static NSString* const kAppLastUpdateTime = @"tiny_app_last_update_time"; //app更新时间
static NSString* const kAppLaunchTime = @"tiny_app_launch_time"; //app更新时间

@interface TYTinyConfig : NSObject

+ (instancetype)sharedInstance;

@property(nonatomic,strong)NSString *timeStandard;//时间基准  使用服务端时间
@property(nonatomic,strong)NSNumber *timeRegulation;//时间校准值 客户端-服务端的差值  正客户端晚 负值客户端早

- (NSString*)isCacheImage;

- (NSInteger)logLEVEL;

- (NSString*)isIgnorePath;

- (NSString *)isOutCage;

- (NSString *)antiDebug;

- (NSString *)resourceVersion;

- (NSString *)scale;

- (NSString *)isNeedMd5;

- (NSString *)isResourceEncrypted;

- (NSString *)isFrostedGlass;

- (NSString *)noDelayLock;

- (NSString*)clickInterval;

- (NSString*)isUseGoogleMap;

- (BOOL)isDebug;

- (BOOL)isAutomationTest;

- (BOOL)getKeyboardVisualFeedback;

- (BOOL)isNeedSaveDeviceIdTokeyChain;


- (BOOL)isHiddenStatusBar;

- (BOOL)isHideSafeArea;

- (int)timeout;

- (NSArray*)Host;

- (NSArray*)stationList;

- (NSString *)isTouchSecurity;

- (NSString *)logFILTERS;

-(NSString *)encryptionBaseUrl;

-(NSString *)fullPathBaseUrlsWithPath:(NSString *)path apiRule:(BOOL)apiRule;

- (NSString *)isEncryptionOpen;

- (NSString *)isSignature;

- (NSString *)updataUrl;

- (NSString *)signRequestType;

- (NSString *)encryptType;

- (NSString*)errorPage;

- (NSString *)urlBasePath;

- (NSString *)secAccountDataKey;

- (NSString *)dimAmount;

- (NSString *)secAccountPassKey;

- (NSDictionary *)getIMConfig;

- (NSDictionary *)getTraceConfig;

- (NSDictionary *)getLanguageConfig;

- (NSDictionary *)getComponentConfig;

- (NSString *)limitScreenShot;//true（默认）打开屏幕锁检测 false关闭

- (NSString *)screenFuzzy;//true (默认) 后台模糊化  false关闭

- (NSString *)rootCheck;//true (默认) 越狱检测  false关闭

- (NSString *)resourceHudPath;

- (NSString *)imageTbsPath;

/// 应用资源文件夹
- (NSString *)appResourceDirectoryName;
- (NSString *)mainAppResourceDirectoryName;

-(NSString *)touchSecurity;

- (BOOL)isTraceEnable;
/// 服务端时间与本地时间统一
/// @param severTime 服务端时间
-(void)calculateTimeStandard:(NSString *)severTime;

/// 根据与服务器的时间差 利用当前时间  计算出服务器时间
-(NSString *)calculateSeverTime;


/**
 *  获取指定配置信息
 *
 *  key 配置文件对应的key,中间用 "/" 分隔, 如"common/appBaseUrl",如需获取数组中配置信息直接写对应下标,如"common/2"
 *
 *  @return NSString
 */
-(id)getCurrentConfigWithKey:(NSString *)key;

// 当前服务器时间距离上次请求时间差
- (double)distanceLastSeverTime;

// 是否开启用户手指缩放
- (NSString *)isWebUserScalable;

@end

NS_ASSUME_NONNULL_END
