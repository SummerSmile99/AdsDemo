//
//  LingTuiAdapterNetworkRegistry.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class  LingTuiClassWrapper;
@interface LingTuiAdapterNetworkRegistry : NSObject
- (NSMutableDictionary *)getAdapterDict;
- (void)setAdapterDict:(NSMutableDictionary *)adapterDict;
- (void)registerClass:(Class)adapterClass;
- (LingTuiClassWrapper *)adapterClassFor:(NSInteger)adNetworkType;
@end
