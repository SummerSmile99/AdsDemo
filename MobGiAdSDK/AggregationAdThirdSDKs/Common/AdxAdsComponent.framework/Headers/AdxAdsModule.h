//
//  AdxAdsModule.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/4/11.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdxDataManager.h"
#import "AdxAdItemConfigData.h"
#import <AggregationAdsComponent/AggregationAdsComponent.h>
#import <SDKCommonModule/BasicUtilTools.h>
#import <AggregationAdsComponent/AggregationAdsConfigsGetManager.h>
#import <AggregationAdsComponent/AdsAggregationAreaInfo.h>
#import <AggregationAdsComponent/AggregationAVDPrioritPlatInfo.h>
#import "AdxAppblockList.h"
#import "AdGlobalConfig.h"
#import "MGAdxServerInfo.h"


@protocol AdsAggregationAreaInfo
@end

@protocol AggregationAVDPrioritPlatInfo
@end

@protocol AdxConfigRequestDelegate <NSObject>

@required

-(void) callBackDevMode:(BOOL)dev;

#pragma mark - 聚合配置

//要使用的聚合配置
-(void) callBackAggregationConfigs:(NSArray<AdsAggregationAreaInfo>*)aggretationConfigData;

-(void) callBackGlobalConfig:(AggregationAdGlobalConfig*)globalConfig;

//没有聚合配置使用
-(void) callBackNoAggregationConfigs;

-(void) callBackNoGlobalConfig;

#pragma mark - ADX广告数据



-(void) callBackAdxConfigDatas:(NSMutableArray<AdxAdItemConfigData>*) adxAdItemConfigData;

//ADX下发数据为空
-(void) callBackAdxDataNull;

-(void) callBackAdxConfigDatas:(NSArray<AdxAdItemConfigData *>*) adxAdItemConfigData
                       blockid:(NSString*)blockid;

-(void) callBackAdxNoConfig:(NSString*)blockid;

@end

@class AdxBidInfo;

@class AdxAdsConfigsGetManager;


@class AdResponseDataConfigListInfoSenior;

@class MGAdAggregationResponseDataList;

@interface AdxAdsModule : AggregationAdsConfigsGetManager

@property(nonatomic,strong) Class responseClass;

@property(nonatomic,strong) id<AdxConfigRequestDelegate> delegate;

@property(nonatomic,strong) AdxAdsConfigsGetManager*             adxConfigManager;

@property(nonatomic,assign) AdxAdType adxAdType;

@property(nonatomic,assign) int adxAdTypeInt;

@property(nonatomic,strong) NSString* adTypeDes;

@property(nonatomic,assign) BOOL isAggregationConfig;

@property(nonatomic,strong)  NSMutableArray<AdxAdItemConfigData>* adxAdItemConfigDatas;

@property(nonatomic,strong) NSArray<AdxAppblockList>* appBlockList;

@property(nonatomic,assign) BOOL isHasAdxInfos;
@property(nonatomic,strong) NSString                             *blockid;

@property (nonatomic,strong) MGAdxServerInfo *adxServerInfo;

@property(nonatomic,strong) NSString                             *reponseInfoPath;


-(AdxAdItemConfigData*) generateAdxItemData:(AdxBidInfo*)bidInfoTemp
                                      dspId:(NSString*)dspId
                                      bidId:(NSString*)bidId
                                   outBidId:(NSString*)outBidId
                               adConfigData:(AdxAdItemConfigData*) adxAdItemConfigData;

-(void) aggregationData:(MGAdAggregationResponseDataList*)listInfo;

-(void) callbackToSDK;

-(BOOL) isOnlyWifiLoadAd;

/**
 *  根据判断广告位开关，次数限制，是否配置概率,来控制是否加载广告
 *
 *  @param blockId <#blockId description#>
 *
 *  @return <#return value description#>
 */
-(BOOL) isCanLoadAd:(NSString*)blockId;

/**
 *  根据判断广告位开关，次数限制，概率触发，来控制是否展示广告
 *
 *  @param blockId <#blockId description#>
 *
 *  @return <#return value description#>
 */
-(BOOL) isBlockidValid:(NSString*)blockId;

-(double) getShowRateForBlockId:(NSString*) blockId;

#pragma mark - 给子类调用
-(void) initAdTypeData:(AdxAdType)adType
                sdkVersion:(NSString*)sdkversion;


-(void) initAdTypeData:(AdxAdType)adType
                sdkVersion:(NSString*)sdkversion
                   blockid:(NSString*)blockid;

-(void) refreshAdxConfigInfos;

-(void) refreshAdxConfigInfos:(NSString*)blockid;

-(void) callBackDevMode:(BOOL)dev;

#pragma mark - 给子类重写

-(NSString*) getAggregationResponseInfo;

-(NSString*) getAggregationAdList;

-(void) callBackBidInfos:(NSArray*)bidInfos
              configList:(MGAdAggregationResponseDataList*)listInfo;


@end
