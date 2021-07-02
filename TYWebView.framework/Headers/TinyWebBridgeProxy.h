//
//  TinyWebBridgeProxy.h
//  TinyKern
//
//  Created by peanut on 2021/3/31.
//  Copyright © 2021 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class WKWebViewJavascriptBridge;
@protocol TinyNatvieWVJBridgeProtocol <NSObject>

@property (nonatomic, weak) WKWebViewJavascriptBridge *bridge;

/*
 当前实例所在的作用域
 */
@property (nonatomic, copy) NSString *instanceScope;

@required
/*
 获取webview每个消息对应的源生方法
 要求源生实现一组映射表
 */
- (nullable SEL)nativeBindMethodForKey:(NSString *)channelName;

/*
 * Native:配置需要建立通道的名称,channelName集合体
 * Webview: bridge.callHandler(channelName,...)
 * 注意：channelName 要保证唯一，以免发生冲突
 */
+ (NSArray<NSString *> *)registerChannels;

/*
 需要注入到webview内部的js语句
 */
+ (NSString *)injectJavaScriptCommand;

@optional

/*
 是否为异步回调
 */
- (BOOL)asyncCallResponseAtChannel:(NSString *)channelName;

/*
 消息 绑定 回调方法
 解决异步API异步回调问题
 */
- (void)registerAsyncCallResponse:(void(^)(id))handler toName:(NSString *)channelName;

@end


@interface TinyWebBridgeProxy : NSObject

+ (instancetype)sharedInstance;

/*
 注入到webview的js语句
 */
- (NSError *_Nullable)injectJavaScriptCommand:(NSString *_Nullable)command;

/*
 获取所有注入的语句集合
 */
- (NSArray<NSString *> *_Nullable)allJavaScriptCommand;

/*
 注册消息通道的名字， 如何规避相同的通道名称
 */
- (NSError *_Nullable)registerChannel:(NSString *_Nonnull)channelNames;
- (NSError *_Nullable)registerChannels:(NSArray<NSString *> *)channelNames;

/*
 需要注入到webview的消息通道集合
 */
- (NSArray<NSString *> *)allRegisterChannels;

/*
 将消息通道与源生对象绑定
 */
- (NSError *_Nullable)bindClass:(Class<TinyNatvieWVJBridgeProtocol>)nativeClass toChannel:(NSString *)channelName;

/*
 获取对应实例
 */
- (id<TinyNatvieWVJBridgeProtocol>)instanceObjFromChannel:(NSString *)channelName uuid:(NSString *_Nonnull)uuid;

/*
 调用结束后摧毁源生对应的对象
 需要明确JavaScript调用完成后何时移除
 */
- (void)destroyNativeInstanceWithUuid:(NSString *)uuid;
- (void)destoryNativeInstance:(id)instance;

@end

NS_ASSUME_NONNULL_END
