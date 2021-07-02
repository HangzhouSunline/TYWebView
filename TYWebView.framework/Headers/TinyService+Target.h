//
//  TinyService+Target.h
//  TinyPart
//
//  Created by peanut on 2019/7/19.
//  Copyright © 2019 peanut. All rights reserved.
//

#import "TinyService.h"

NS_ASSUME_NONNULL_BEGIN

@interface TinyService (Target)

- (void)registerServiceWithParams:(NSDictionary *)params;

- (id)instanceWithParams:(NSDictionary *)params;

- (Class)impClassWithParams:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
