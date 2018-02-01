//
//  AdxAdsConfigsGetManager.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
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
#import "AdxAdsDataReport.h"
#import "AdxRequestDataConfigInfoSenior.h"


@protocol AdsTestCallbackDelegate<NSObject>

@optional

-(NSString*)registTestResponseDataString;

-(NSString*)registTestResponseDataFileJsonName;

@end

@protocol AdsCallbackDelegate <NSObject,AdsTestCallbackDelegate>

@required

-(NSString*) getAggregationAdList;

-(void) callBackAggregationRequestSuccess:(id)responseInfo;

-(void) callBackAggregationRequestFail:(id)errorMsg;

-(void) callBackSuccess:(id)data;

-(void) callBackError:(NSError*)error;

-(void) callBackNoConfig;

-(void) reportCompletedRequest;

@optional

//注册ADX响应的类
-(Class)registResponseClass;


#pragma mark - 额外配置

-(void) callBackExtraConfig:(NSMutableDictionary*)dic;

@end

@class AdxRequestDataConfigInfoSenior;

@interface AdxAdsConfigsGetManager : NSObject

@property (nonatomic, strong) id<AdsCallbackDelegate>  configGetManagerDelegate;


@property(nonatomic,strong) NSString* requestUrl;
@property(nonatomic,strong) AdxAdsDataReport* adxAdsDataReport;
@property(nonatomic,strong) SDKHttpOperationManager* httpManager;
@property(nonatomic,assign) int adType;
@property(nonatomic,strong) NSString* sdkVersion;
@property(nonatomic,strong) NSString* blockid;

-(instancetype) initAdType:(int)adType
                sdkVersion:(NSString*)sdkversion;

-(instancetype) initAdType:(int)adType
                sdkVersion:(NSString *)sdkversion
                   blockid:(NSString*)bid;

-(void) refreshConfigInfos;

-(void) buildReportManager;

-(void) reportStartRequest;

-(void) reportCompletedRequest;

#pragma mark -
#pragma mark 给子类重写，不同的请求配置对象，方便后序拓展
/**
 *  <#Description#>
 *
 *  @return <#return value description#>
 */
-(AdxRequestDataConfigInfoSenior*) generateAdxRequestDataConfigInfoSenior;

-(AdxImpInfo*) generateImpInfo:(AdxAttrInfo*) attrObj;

-(AdxAttrInfo*)generateAttrInfo;

@end
