//
//  LingTuiAdNetworkConfig.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiAdNetworkType.h"
@class LingTuiAdapterNetworkRegistry;
@interface LingTuiAdNetworkConfig : NSObject
- (id)initWithDictionary:(NSDictionary *)adNetConfigDict
 adAPISDKNetworkRegistry:(LingTuiAdapterNetworkRegistry *)registry;
//2016 9 - 29 信息流调用初始化方法
- (id)initWithDictionary:(NSDictionary *)adNetConfigDict
 adAPISDKNetworkRegistry:(LingTuiAdapterNetworkRegistry *)registry withTypeSize:(NSString *)typeSize;
//@property (nonatomic,weak,readonly) NSString *nid; // 内部id
@property (nonatomic,weak,readonly) NSString *networkName; // 平台名称
@property (nonatomic,assign,readonly) double trafficPercentage; // 百分比
@property (nonatomic,assign,readonly) NSInteger priority; // 优先级
@property (nonatomic,weak,readonly) NSDictionary *credentials; // 平台key
//@property (nonatomic,weak,readonly) NSString *pubId;
@property (nonatomic,strong,readonly) Class adapterClass;
@property (nonatomic,assign,readonly) BOOL testMode; // 是否是测试模式
@property (nonatomic,strong,readonly) NSString *nws;// 统计信息
@property (nonatomic,strong,readonly) NSString * nativeNws;// 电子书原生广告统计信息
@property (nonatomic,assign,readonly) NSTimeInterval expireTime;// 插屏的过期时间
@property (nonatomic,assign,readonly) NSTimeInterval reqTimeOut;// 请求广告过期时间
@property (nonatomic,assign,readonly) LingTuiAdNetworkType networktype;// 平台适配器编号
@property (nonatomic,assign,readonly) NSInteger prinwid;// 平台编号
@property (nonatomic,weak,readonly) NSString *rurl;
@end
