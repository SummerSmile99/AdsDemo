//
//  AdxReportLogicManager.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/4/1.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdxReportModelData.h"


@protocol AdxDataReportDelegate

@required

-(void) reportResult:(BOOL)result
     orignReportData:(NSString*)reportData;

@end


@protocol AdxDataFillDelegate

@required

-(AdxReportModelData*) generateAdxReportDataItem;

@optional

-(void) fillAdxReportDataExtra:(id)extraData;

@end



@class TReportRecordObject;

#define MG_ADXAD_SSPTYPE_ADX   1
#define MG_ADXAD_SSPTYPE_AGGREGATION   2

extern NSString* const ADXAD_REPORT_REQUEST_CONFIG;
extern NSString* const ADXAD_REPORT_REQUEST_CONFIG_SUCCESS;
extern NSString* const ADXAD_REPORT_DOWNLOAD_RESOURCE;
extern NSString* const ADXAD_REPORT_DOWNLOAD_RESOURCE_SUCCESS;
extern NSString* const ADXAD_REPORT_SHOW;
extern NSString* const ADXAD_REPORT_HTML_SHOW;
extern NSString* const ADXAD_REPORT_CLICK;
extern NSString* const ADXAD_REPORT_CLOSE;
extern NSString* const ADXAD_REPORT_TRIGGER_VIDEO_REWARD;
extern NSString* const ADXAD_REPORT_VIDEO_SHOW_AGAIN;
extern NSString* const ADXAD_REPORT_NAVIGATE_SYSTEM_BROWSER;
extern NSString* const ADXAD_REPORT_NAVIGATE_SYSTEM_STORE;
extern NSString* const ADXAD_REPORT_NAVIGATE_SELF_BUILD_BROWSER;
extern NSString* const ADXAD_REPORT_NAVIGATE_SYSTEM_STORE_PAGE;
extern NSString* const ADXAD_REPORT_SDK_SHOW;
extern NSString* const ADXAD_REPORT_SDK_INIT;
extern NSString* const ADXAD_REPORT_SDK_SPLASH_SKIP;
extern NSString* const ADXAD_REPORT_SDK_EXIT;

extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_SUCCESS;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_PARAMERROR;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_NOADSAVAILABLE;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_NOMEETNETWORK;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_ADUNITLIMIT;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_BEYONDPROBABILITYRANGE;
extern NSString* const ADXAD_REPORT_SDK_CACHE_STATUS_FAIL_ADPLATFORMLIMIT;





extern int const ADXAD_CHARGETYPE_CPM;
extern int const ADXAD_CHARGETYPE_CPC;

@interface AdxReportLogicManager : NSObject<AdxDataFillDelegate>

@property(nonatomic,assign) int adType;
@property(nonatomic,strong) NSString* sdkversion;
@property(nonatomic,assign) BOOL isDspAd;
@property (atomic,assign) int reportCount;
@property (nonatomic,assign) BOOL isSetReportCount;
@property(nonatomic,strong) id reportHttpManager;
@property(nonatomic,strong) id thirldAdReportClickHttpManager;
@property(nonatomic,strong) id thirldAdReportShowHttpManager;
@property(nonatomic,strong) NSString* requestUrl;
@property (nonatomic,strong) NSString *bidId;
@property (nonatomic,strong) NSString *configId;
@property (nonatomic,assign) int userType;

@property (nonatomic,weak) id<AdxDataReportDelegate> reportResultDelegate;

-(instancetype) init:(int)adType
          sdkversion:(NSString*)sdkversion;

-(void) reportAdInfo:(AdxReportModelData*)data;

-(void) reportAdInfoStr:(NSString*)targetData;

#pragma mark -

-(AdxReportModelData*) generateCustomAdAdxReportDataItem;

-(AdxReportModelData*) generateAdxReportDataItem;

//上报第三方点击
-(void) reportAdClick:(NSString*)clickUrl;

//上报第三方展示
-(void) reportAdShow:(NSString*)showUrl;

-(void)reportPlatName:(NSString*)dspid
            eventType:(NSString*)eventType
           dspVersion:(NSString*)dspVersion;

-(void)reportPlatName:(NSString*)dspid
            eventType:(NSString*)eventType
              blockid:(NSString*)bid
           dspVersion:(NSString*)dspVersion;

-(void)reportPlatName:(NSString*)dspid
            eventType:(NSString*)eventType
              blockid:(NSString*)bid
           dspVersion:(NSString*)dspVersion
                 data:(AdxReportModelData*)data;

-(void)reportSDKShow:(NSString*)dspid
          dspVersion:(NSString*)dspVersion;

-(void)reportSDKShow:(NSString*)dspid
             blockid:(NSString*)bid
          dspVersion:(NSString*)dspVersion;

-(void)reportbidId:(NSString*)bidId
             dspId:(NSString*)dspId
          originalityId:(NSString*)originalityId
          outBidid:(NSString*)outBidid
              adId:(NSString*)adId
             price:(NSString*)price
          currency:(int)currency
        chargeType:(int)chargeType
         eventType:(NSString*)eventType;

-(void)reportBlockid:(NSString*)blockid
        bidId:(NSString*)bidId
             dspId:(NSString*)dspId
          originalityId:(NSString*)originalityId
          outBidid:(NSString*)outBidid
              adId:(NSString*)adId
             price:(NSString*)price
          currency:(int)currency
        chargeType:(int)chargeType
         eventType:(NSString*)eventType;

-(void)reportBlockid:(NSString*)blockid
               bidId:(NSString*)bidId
               dspId:(NSString*)dspId
       originalityId:(NSString*)originalityId
            outBidid:(NSString*)outBidid
                adId:(NSString*)adId
               price:(NSString*)price
            currency:(int)currency
          chargeType:(int)chargeType
           eventType:(NSString*)eventType
                data:(AdxReportModelData*)data;

#pragma mark 请求配置
-(void)reportRequestConfig;

-(void)reportRequestConfig:(NSString*)bid;

-(void)reportDSPRequestConfig:(NSString*)bid
                         data:(AdxReportModelData*)data;

#pragma mark 请求配置成功

-(void)reportRequestConfigSuccess:(NSString*)bid
                             data:(AdxReportModelData*)data;

-(void)reportRequestConfigSuccessWithData:(AdxReportModelData*)data;

-(void)reportDSPRequestConfigSuccess:(NSString*)bid
                    data:(AdxReportModelData*)data;

//广告形式SDK初始化
-(void)reportSDKInit;

//SDK初始化和退出
-(void)reportMobGiAdInit;

-(void)reportMobGiAdExit;

-(NSString*) getReportStringForExit;

-(TReportRecordObject*)getReportRecordForExit;

-(void)reportSDKCacheStatus:(int)sspType
                  eventType:(NSString*)eventType
                    blockid:(NSString*)bid
                       data:(AdxReportModelData*)data;

@end
