//
//  ReportModelData.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/SDKCommonModule.h>
#import <SDKCommonModule/JSONModel.h>

extern int const ADXAD_REPORT_DATA_INT_DEFAULT_VALUE;
extern NSString* const ADXAD_REPORT_DATA_STRING_DEFAULT_VALUE;

@interface AdxReportModelData : JSONModel

@property(nonatomic,assign) int providerId;
@property(nonatomic,assign) int sspType;
@property(nonatomic,strong) NSString* bidId;
@property(nonatomic,strong) NSString* outBidid;
@property(nonatomic,strong) NSString* dspId;
@property(nonatomic,strong) NSString* adId;
@property(nonatomic,strong) NSString* originalityId;
@property(nonatomic,strong) NSString* blockId;
@property(nonatomic,strong) NSString* appKey;
@property(nonatomic,assign) int adType;
@property(nonatomic,strong) NSString* imei;
@property(nonatomic,strong) NSString* brand;
@property(nonatomic,strong) NSString* model;
@property(nonatomic,strong) NSString* eventType;
@property(nonatomic,strong) NSString* imsi;
@property(nonatomic,assign) int netType;
@property(nonatomic,assign) int operator;
@property(nonatomic,assign) int platform;
@property(nonatomic,strong) NSString* resolution;
@property(nonatomic,strong) NSString* uuid;
@property(nonatomic,strong) NSString* appVersion;
@property(nonatomic,strong) NSString* sdkVersion;
@property(nonatomic,strong) NSString* price;
@property(nonatomic,strong) NSString* currency;
@property(nonatomic,assign) int chargeType;
@property(nonatomic,strong) NSString* cid;
@property(nonatomic,strong) NSString* dspVersion;
@property(nonatomic,strong) NSString* clientTime;
//2.5.0增加
@property (nonatomic,strong) NSString *sessionId;

//2.7.0增加
@property (nonatomic,strong) NSString *configId;
@property (nonatomic,assign) int userType;

@property (nonatomic,strong) NSString *eventTime;//从登录到事件触发的时间差（单位：毫秒）

-(void) initData;

@end
