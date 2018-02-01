//
//  MGAdDSPConfigsGetManager.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdxAdReportResponseData.h"
#import <Foundation/Foundation.h>
#import "AdxReportModelData.h"
#import "AdxReportLogicManager.h"
#import <SDKCommonModule/SDKUtilManager.h>
#import <SDKCommonModule/BasicUtilTools.h>
#import <SDKCommonModule/SDKHttpOperationManager.h>
#import "AdxImpInfo.h"
#import "AdxAttrInfo.h"
#import "AdxAppInfo.h"
#import "AdxDeviceInfo.h"
#import "AdxReportModelData.h"
#import "AdxAdsDebugger.h"
#import "AdxDataManager.h"

#import <AggregationAdsComponent/AggregationAdKeySettings.h>
#import <AggregationAdsComponent/AggregationAdsLogic.h>
#import <AggregationAdsComponent/AggregationAdCommonUtil.h>

#import "AdxRequestDataConfigInfoSenior.h"

#import "AdxDataManager.h"
#import "AdxAdItemConfigData.h"
#import <AggregationAdsComponent/AggregationAdsComponent.h>
#import <SDKCommonModule/BasicUtilTools.h>

#import "AdxAppblockList.h"
#import "AdGlobalConfig.h"

#import <AdxAdsComponent/AdxAdsConfigsGetManager.h>
#import <AdxAdsComponent/AdxDataManager.h>

#import "AdxAppblockList.h"

#import "MGAdAggregationResponseConfigInfo.h"
#import "MGAdAggregationResponseDataList.h"

#import "MGAdDSPResponseConfigInfo.h"
#import "MGAdDSPResponseDataList.h"
#import "MGAdDSPResponseAdInfoList.h"
#import "AdxAdsConfigsGetManager.h"

@protocol MGAdDSPConfigsGetManagerDelegate <NSObject,AdsTestCallbackDelegate>

- (void)callBackDspConfigsFailure:(NSString*)errorMsg;

- (void)callBackDspConfigsSuccess:(NSArray<AdxAdItemConfigData *>*) adxAdItemConfigData;

@end

@interface MGAdDSPConfigsGetManager : NSObject

@property(nonatomic,strong) id<MGAdDSPConfigsGetManagerDelegate> delegate;
@property(nonatomic,strong) Class responseClass;
@property(nonatomic,strong) NSString* requestUrl;
@property(nonatomic,strong) AdxReportLogicManager* adxReportLogicManager;
@property(nonatomic,strong) AdxAdsDataReport* adxAdsDataReport;
@property(nonatomic,strong) SDKHttpOperationManager* httpManager;
@property(nonatomic,assign) int adType;
@property(nonatomic,strong) NSString* sdkVersion;
@property(nonatomic,strong) NSString* blockid;
@property(nonatomic,strong) NSString* appKey;
@property(nonatomic,assign) AdxAdType adxAdType;
@property(nonatomic,assign) int adxAdTypeInt;
@property(nonatomic,strong) NSString* adTypeDes;
@property (nonatomic,strong) NSString *bidId;

@property(nonatomic,strong)  NSMutableArray<AdxAdItemConfigData>* adxAdItemConfigDatas;
@property(nonatomic,strong) NSArray<AdxAppblockList>* appBlockList;


-(instancetype) initAdType:(int)adType
                sdkVersion:(NSString*)sdkversion;

-(instancetype) initAdType:(int)adType
                sdkVersion:(NSString *)sdkversion
                   blockid:(NSString*)bid;

-(void) initAdTypeData:(AdxAdType)adType sdkVersion:(NSString*)sdkversion;

-(Class)registResponseClass;

-(void) buildReportManager;

-(AdxRequestDataConfigInfoSenior*) generateAdxRequestDataConfigInfoSenior;

-(AdxImpInfo*) generateImpInfo:(AdxAttrInfo*) attrObj;

-(AdxAttrInfo*)generateAttrInfo;

-(AdxAdItemConfigData*) generateAdxItemData:(MGAdDSPResponseAdInfoList*)adInfo
                                      dspId:(NSString*)dspId
                                      bidId:(NSString*)bidId
                                   outBidId:(NSString*)outBidId
                                     adType:(int)adType
                               adConfigData:(AdxAdItemConfigData*) adxAdItemConfigData;

-(void) refreshDspConfigInfos;

-(void) refreshAdxConfigInfos:(NSString*)blockid;

-(void) callBackDataList:(MGAdDSPResponseDataList*)dataList;

-(void) reportStartRequest;

-(void) reportCompletedRequest;

@end
