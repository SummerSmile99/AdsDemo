//
//  ReportInfoLogic.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/10/19.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

#define REFLESH_EVENTSORT_NOTIFICATION            @"reflesh_eventsort_notification"


@class AdxReportLogicManager;
@class AdxAdsDataReport;
@protocol MobGiNetChangeDelegate;

@interface ReportInfoLogic : NSObject<MobGiNetChangeDelegate>

@property (nonatomic,strong) NSString *sessionIdValue;//游戏单次启动的会话id

@property (nonatomic,strong) NSString *appLoginTimeStamp;//游戏单次启动的时间戳

@property(nonatomic,assign) long long timeStampCoverage; //与服务端校验的时间戳差值，以秒为单位

@property (nonatomic,strong) AdxAdsDataReport *httpOperationManager;

@property(nonatomic,assign) BOOL isCheckTimeStampCoverage;

@property (atomic,assign) BOOL isSwitchBackend; //判断是否已经切换到后台了

+(ReportInfoLogic *)sharedInstance;

+(NSString*) getSessionId;

-(NSString*) startGetAppLoginTimeStamp;
//+(NSString*) getSessionId:(NSString*)timeStamp;

@end
