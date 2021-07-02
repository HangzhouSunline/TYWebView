//
//  NSObject+WVJBExtension.h
//  TinyKern
//
//  Created by peanut on 2021/4/9.
//  Copyright © 2021 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSMutableDictionary<NSString*, void(^)(id _Nullable)> WVJBHandlersDictionary;

@class WKWebViewJavascriptBridge;
@interface NSObject (WVJBExtension)

/*
 异步回调缓存集合体
 */
- (WVJBHandlersDictionary *)wvjbAsyncHandlers;

- (WKWebViewJavascriptBridge *)bridge;

@end

NS_ASSUME_NONNULL_END
