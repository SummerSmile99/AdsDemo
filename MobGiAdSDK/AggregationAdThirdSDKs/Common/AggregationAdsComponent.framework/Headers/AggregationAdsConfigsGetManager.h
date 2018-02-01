//
//  AggregationAdsConfigsGetManager.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/1/6.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdsIntergrationPlatInfo.h"
#import "AdsAggregationAreaInfo.h"
#import "AggregationAdvertiserInfo.h"
#import "AggregationAdCommonUtil.h"

#import "AggregationAdKeySettings.h"
#import "AggregationAdsDebugger.h"
#import "AdsPlatformLogicManager.h"
#import "AggregationAVDPrioritPlatInfo.h"
#import "AggregationAVDPrioritListConfig.h"
#import "AggregationAdsDebugger.h"
#import "AggregationAdKeySettings.h"
#import "AggregationAVDPrioritPlatInfo.h"
#import "AggregationAdGlobalConfig.h"
#import "AggregationAdsLogic.h"
#import "AdsAggregationAreaInfo.h"
#import <SDKCommonModule/SDKHttpOperationManager.h>


#define  Queue  dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)



#define   DevMode       @"devMode"

#define   CacheMode     @"cacheMode"

@class AggregationAdGlobalConfig;


typedef void(^ConfigsBlock)(BOOL, AggregationAdGlobalConfig*, NSArray*);

@protocol AggregationAdConfigsGetManagerDelegate <NSObject>

@optional

-(void)getRequestGlobalConfig:(BOOL)supportNetworkType
                    lifeCycle:(double) lifeCycle;



@end


@interface AggregationAdsConfigsGetManager : NSObject

@property (nonatomic, strong) ConfigsBlock configsBlock;
@property (nonatomic, strong) id<AggregationAdConfigsGetManagerDelegate>  configGetManagerDelegate;
@property(nonatomic,assign) int adType;
@property(nonatomic,assign) AggregationAdType aggregationAdType;
@property(nonatomic,strong) AdsPlatformLogicManager* adsPlatformLogicManager;
@property(nonatomic,strong) NSString* sdkVersion;
@property(nonatomic,strong) NSArray                              *dataList; //data
@property(nonatomic,strong) NSArray                              *writeData;
@property(nonatomic,assign) BOOL                                 isHasData;


@property(nonatomic,strong) AggregationAdGlobalConfig* globalConfig;

@property(nonatomic,strong) AggregationAVDPrioritListConfig                 *prioritConfig;

@property (nonatomic,strong) NSMutableArray<NSString*> *serverConfigAdNames;



//用于线上测试的属性
@property(nonatomic,assign) BOOL                                 isUseCache;
@property(nonatomic,assign) BOOL                                 isLineTestMode;

@property(nonatomic,strong) NSString* configInfosPath;
@property(nonatomic,strong) NSString* cacheSwitchPath;
@property(nonatomic,strong) NSString* logSwitchPath;

@property(nonatomic,assign) BOOL                                 isCompleteGetConfig;

@property(nonatomic,strong) NSMutableArray* platArray;

-(NSString*) getNetworkAdShowCount:(NSString*)bid;

-(NSArray*) getConfigBlockids;

-(NSArray*) getConfigs;

-(NSString*) getConfigsString;

-(NSDictionary *)getGlobalAndGeneralConfigs;

-(NSArray*) getPlatRateArray;

-(AggregationAdvertiserInfo*) getAdvertiserInfoForBlockId:(NSString*) blockId
                                      platType:(NSString*) platInfoName;

-(AggregationAdvertiserInfo*) getAdvertiserInfoForBlockId:(NSString*) blockId
                                      platType:(NSString*) platInfoName
                               fromBlockIdData:(NSArray*) data;

/**
 *  获取该广告位对应有配概率的广告商
 *
 *  @param blockId <#blockId description#>
 *
 *  @return <#return value description#>
 */
-(NSArray*) getHasRateAdvertiserInfosForBlockId:(NSString*) blockId;

-(NSArray*) getHasRateAdvertiserInfosForSplash;

-(double) getShowRateForBlockId:(NSString*) blockId;

-(NSArray*) getHasRateInfos:(NSArray *)dataArr  blockId:(NSString*) blockId;

/**
 * 聚合配置信息的读缓存逻辑处理方法
 * ADX模块可以重写该方法，实现自己的读取缓存逻辑
 */
-(void)getCacheConfigAndParsing;

@end
