//
//  TinyUINetworkProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/10/18.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#ifndef TinyUINetworkProtocol_h
#define TinyUINetworkProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TinyBaseProtocol.h"

@protocol TinyRequestExtensionProtocol <NSObject>

@property (nonatomic, copy) NSError* _Nullable(^_Nullable resposneHeaderConform)(NSDictionary *_Nullable object);

@end

@protocol TinyUINetworkProtocol <TinyServiceProtocol>

/*
 获取图片 return data
 */
- (id<TinyRequestExtensionProtocol>)imageRequestWithUri:(NSString *)uri completion:(void (^_Nullable)(NSData * _Nullable, NSError *_Nullable error))compeltion;

/*
 获取图片多参数Api return data
 */
- (id<TinyRequestExtensionProtocol>)imageRequestWithUri:(NSString *)uri relativeUrl:(NSURL * _Nullable)relativeUrl option:(NSMutableDictionary * _Nullable)option completion:(void (^)(NSData * _Nullable, NSError * _Nullable))completion ;

/*
 获取图片 return image
 */
- (id<TinyRequestExtensionProtocol> _Nonnull)loadImageWithUri:(NSString *)uri completion:(void (^)(UIImage * _Nullable, NSError *_Nullable error))compeltion;

/*
 获取图片多参数Api return image
 */
- (id<TinyRequestExtensionProtocol> _Nonnull)loadImageWithUri:(NSString *)uri relativeUrl:(NSURL *_Nullable)relativeUrl option:(NSMutableDictionary *_Nullable)option completion:(void (^)(UIImage * _Nullable, NSError *_Nullable error))compeltion;


/*
 post 表单提交
 */
- (id<TinyRequestExtensionProtocol>)postRequestWithUri:(NSString *)uri header:(NSDictionary *)header body:(id)body completion:(void (^)(NSData * _Nullable, NSError *_Nullable error))compeltion;
                                                      
/*
 下载文件
 */
- (id<TinyRequestExtensionProtocol> _Nullable)downloadRequestWithUri:(NSString *_Nonnull)uri header:(NSDictionary *)header paramters:(NSDictionary *)paramters destination:(NSString *_Nonnull)path progress:(void(^)(long long current, long long total))progress completion:(void(^)(NSURL *_Nullable, NSError * _Nullable))completion;

// 上传文件
/* files 需要上传的文件集合
 * NSDictionary 用来表征上传的对象，包含以下字段
 * data: 上传的数据体，可为空
 * fileURL: 上传文件的路径file:// ,与data互斥
 * name: 名字
 * fileName: 文件名
 * mimeType: 文件类型
 */
- (id<TinyRequestExtensionProtocol> _Nullable)uploadRequestWithUri:(NSString *)uri header:(NSDictionary *)header paramters:(NSDictionary *)paramters file:(NSArray<NSDictionary *> *)files progress:(void(^)(long long current, long long total))progress completion:(void (^)(NSData * _Nullable, NSError *_Nullable error))compeltion;

/*
 取消请求
 */
- (void)cancelRequest:(id)request;

/*
 获取当前的网络状态
 */
- (NSString *_Nonnull)currentNetworkStatus;

@end


#endif /* TinyUINetworkProtocol_h */
