//
//  TinyParse.h
//  JSBridgeTest
//
//  Created by Yang on 2021/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TinyParse : NSObject

+ (NSDictionary *)parseDependencies:(NSString *)fileName type:(NSString * _Nullable)type;

@end

NS_ASSUME_NONNULL_END
