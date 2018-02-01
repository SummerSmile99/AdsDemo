//
//  AdxInterstitialDataReport.h
//  HouseAdInterstitials
//
//  Created by star.liao on 2017/4/9.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdxAdItemConfigData.h"
#import "AdxReportLogicManager.h"
#import <AdsBasicFramework/AdThirdUrlReportManager.h>

/**
 *  adx数据上报基类，可能存在子类，添加新参数
 *  通用的新增字段，修改AdxReportLogicManager,AdxReportModelData
 *  区分广告形式的新增字段，继承AdxReportLogicManager
 *  区分事件类型的新增字段
 */
@interface AdxAdsDataReport : NSObject

@property (nonatomic,strong)AdThirdUrlReportManager*              adThirdUrlReportManager;

@property(nonatomic,strong) AdxAdItemConfigData* adxAdItemConfigData;    //上报的数据Model，交予数据上报管理器，进行填充上报

@property(nonatomic,strong) AdxReportLogicManager* adxReportLogicManager; //数据上报管理器

@property (atomic,assign) int reportCount;

@property (nonatomic,assign) BOOL isDspAd; //标示是否是DSP下发广告

-(void) parasInit;

-(void) parasUpdate;

-(void) initReportManager:(AdxReportLogicManager*) adxReportLogicManager;

//参数值，包含dsp或者客户端聚合广告商信息
-(instancetype) init:(AdxAdItemConfigData*)data;

//下面例举通用的上报事件，跟广告形式无关

-(void)reportRequestConfig;

-(void)reportRequestConfigSuccess;

-(void)reportRequestConfig:(NSString*)bid;

-(void)reportRequestConfigSuccess:(NSString*)bid;

-(void)reportDSPRequestConfig:(NSString*)bid;

-(void)reportDSPRequestConfigSuccess:(NSString*)bid;

-(void)reportSDKInit;

-(void)reportMobGiAdInit;

-(void)reportMobGiAdExit;

-(void) reportSDKPresent;

-(void) reportPresentWithEventSort:(int)eventNumStrPara
            configAdsState:(NSString*)adState;

-(void) reportHtmlPresent;

-(void) reportClickWithEventSort:(int)eventNumStrPara;

-(void) reportDownloadResource;

-(void) reportDownloadResourceSuccess;

-(void) reportClose;

-(void) reportHtmlClose;

-(void) reportAdNavigate;

-(void) reportAdTriggerReward;

-(void) reportVideoReplay;

-(void) reportSDKPresent:(NSString*)blockid;

-(void) reportSDKPresent:(NSString*)blockid platName:(NSString*)platName;

-(void) reportPresent:(NSString*)blockid
        eventNum:(int)eventNumStrPara
        configAdsState:(NSString*)adState;

-(void) reportHtmlPresent:(NSString*)blockid;

-(void) reportClick:(NSString*)blockid
           eventNum:(int)eventNumStrPara;

-(void) reportDownloadResource:(NSString*)blockid;

-(void) reportDownloadResourceSuccess:(NSString*)blockid;

-(void) reportClose:(NSString*)blockid;

-(void) reportHtmlClose:(NSString*)blockid;

-(void) reportAdNavigate:(NSString*)blockid;

-(void) reportAdTriggerReward:(NSString*)blockid;

-(void) reportVideoReplay:(NSString*)blockid;

-(void)reportSDKCacheStatus:(int)sspType
                  eventType:(NSString*)eventType
                    blockid:(NSString*)bid
                   eventNum:(int)eventNumStrPara;

-(NSString*) getReportEventType;

@end
