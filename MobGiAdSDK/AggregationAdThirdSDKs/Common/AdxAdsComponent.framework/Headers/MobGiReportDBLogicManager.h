//
//  AdxDataStoreManager.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/10/20.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TReportRecordObject;

@interface MobGiReportDBLogicManager : NSObject

+ (void)createReportDataTable:(void (^)(BOOL result))block;

+(void) isLastExitRecordExist:(NSString*)sessionId
                  resultBlock:(void (^)(BOOL result))block;

+(void) updateLastExitRecord:(NSString*)sessionId
                   eventTime:(NSString*)eventTime
                  reportData:(NSString*)reportData
                  reportDate:(NSString*)reportDate
                 resultBlock:(void (^)(BOOL result))block;

+(void)addExitReportData:(NSString*)sessionId
               eventTime:(NSString*)eventTime
              recordInfo:(NSString*)recordInfo
              clientTime:(NSString*)timeStamp
             resultBlock:(void (^)(BOOL result))block;

//记录进程内(包括前后台切换)，sessionid的记录
+(void)addSessionIdRecord:(NSString*)sessionId
               clientTime:(NSString*)timeStamp
              resultBlock:(void (^)(BOOL result))block;

//获取上一次进程最后使用的sessionid,这种情况一般会存在于切换到后台一分钟之后，会出现，否则是启动时候的sessionid
+(void) getLastProcessSessionIdRecord:(void (^)(NSMutableArray<NSString*>* results))block;

//判断上一次进程内保存的sessionid是否存在
+(void) isSessionIdRecordExist:(NSString*)sessionId
                   resultBlock:(void (^)(BOOL result))block;

+(void)deleteCurrentProcessLastSessionId:(NSString*)sessionId
                             resultBlock:(void (^)(BOOL result))block;

+(void)deleteExitRecordData:(NSString*)reportData
                  sessionId:(NSString*)sessionId
                resultBlock:(void (^)(BOOL result))block;

+(void) getLastSessionExitRecords:(void (^)(NSMutableArray<TReportRecordObject*>* results))block;

@end
