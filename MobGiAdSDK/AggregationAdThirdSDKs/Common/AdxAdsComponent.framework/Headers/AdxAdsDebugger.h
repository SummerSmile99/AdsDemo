//
//  AdxAdsDebugger.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/4/6.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//



#import "AdxDataManager.h"
#import <AdsBasicFramework/AdLoggerManager.h>
#import <AdsBasicFramework/GlobalDefines.h>
#import <AdsBasicFramework/MobGiLogMacros.h>
#import <AdsBasicFramework/MobGiLogSystem.h>

#define MobGiMDDLogInfo(frmt, ...)    MobGi_LOG_MACRO(YES, MobGiDDLogLevelInfo, MobGiDDLogFlagInfo,    [AdxAdsDebugger debuggerWithAd:ADX_AD].writeLogFile, @"MobGi", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define MobGiMDDLogDebug(frmt, ...)    MobGi_LOG_MACRO(YES, MobGiDDLogLevelDebug, MobGiDDLogFlagDebug,    [AdxAdsDebugger debuggerWithAd:ADX_AD].writeLogFile, @"MobGi", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#define MobGiMDDLogError(frmt, ...)    MobGi_LOG_MACRO(YES, MobGiDDLogLevelError, MobGiDDLogFlagError,    [AdxAdsDebugger debuggerWithAd:ADX_AD].writeLogFile, @"MobGi",__PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

//管理MobGi广告日志，跟广告形式无关，跟MOBGI_DEBUG区别在于，下面可以通过开关进行控制
#define MOBGI_ERROR(frmt, ...) if ([AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogError)   MobGiMDDLogError((XCODE_COLORS_ESCAPE @"fg233,63,68;" @"ERROR [MobGi_V%@ 0x%x %@ %p] %s:%d " frmt XCODE_COLORS_RESET), AD_SDK_VERSION,(unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__); if([[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate respondsToSelector:@selector(sendLog:level:)]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogError) { NSString* target=[NSString stringWithFormat:@"[0x%x %@ %p] %s:%d\n", (unsigned int)[NSThread currentThread],([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__]; [[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate performSelector:@selector(sendLog:level:) withObject: [NSString stringWithFormat:frmt, ##__VA_ARGS__] withObject:[NSString stringWithFormat:@"LOG_ERROR:%@",target]];}

#define MOBGI_DEBUG(frmt, ...) if ([AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogDebug) MobGiMDDLogDebug((XCODE_COLORS_ESCAPE @"fg206,142,94;" @"DEBUG [MobGi_V%@ 0x%x %@ %p] %s:%d " frmt XCODE_COLORS_RESET),AD_SDK_VERSION, (unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__) ; if([[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate respondsToSelector:@selector(sendLog:level:)]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogDebug) { NSString* target=[NSString stringWithFormat:@"[0x%x %@ %p] %s:%d\n", (unsigned int)[NSThread currentThread],([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__]; [[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate performSelector:@selector(sendLog:level:) withObject: [NSString stringWithFormat:frmt, ##__VA_ARGS__] withObject:[NSString stringWithFormat:@"LOG_DEBUG:%@",target]];}

#define MOBGI_INFO(frmt, ...) if ([AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogInfo) MobGiMDDLogInfo((XCODE_COLORS_ESCAPE @"fg242,242,242;" @"INFO [MobGi_V%@ 0x%x %@ %p] %s:%d " frmt XCODE_COLORS_RESET), AD_SDK_VERSION,(unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__); if([[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate respondsToSelector:@selector(sendLog:level:)]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].debug&&[[AdxAdsDebugger debuggerWithAd:ADX_AD] isCanPrintLog:self]&&[AdxAdsDebugger debuggerWithAd:ADX_AD].switchLogInfo){ NSString* target=[NSString stringWithFormat:@"[0x%x %@ %p] %s:%d\n", (unsigned int)[NSThread currentThread],([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__]; [[AdxAdsDebugger debuggerWithAd:ADX_AD].logDelegate performSelector:@selector(sendLog:level:) withObject: [NSString stringWithFormat:frmt, ##__VA_ARGS__] withObject:[NSString stringWithFormat:@"LOG_INFO:%@",target]];}



typedef NS_ENUM(NSInteger, AdxLogLevel) {
    LOG_INFO=0,
    LOG_DEBUG=1,
    LOG_ERROR=2
};

@protocol AdxAdLogDelegate <NSObject>

@optional

- (void)sendLog:(NSString *)log level:(NSString*)level;

@end

#import <Foundation/Foundation.h>

@class MobGiDDASLLogger;
@class MobGiDDTTYLogger;

@interface AdxAdsDebugger : NSObject

@property (nonatomic,strong) NSMutableDictionary *debuggerDic;
@property (nonatomic,strong) NSString *adTypeDefStringKey;
@property (nonatomic,strong) NSString *adTypeDefString;
@property(nonatomic,strong) NSString* logFileName;
@property(nonatomic,strong) NSString* crashlogFileName;
//@property(nonatomic,strong) MobGiDDFileLogger *fileLogger;
@property(nonatomic,strong) MobGiDDASLLogger *aSLLogger;
@property(nonatomic,strong) MobGiDDTTYLogger *tTYLogger;
@property (nonatomic,strong) NSString *debugModeKey;
@property (nonatomic,strong) NSCondition *condition;

//默认环境为https,正式环境
@property(nonatomic,strong) NSString* ADSBaseURL;

@property(nonatomic,strong) NSString* ADSReportURL;

@property(nonatomic,strong) NSString* DspBaseURL;

@property (nonatomic,assign) BOOL isEnableDefaultLog;

//debugMode记忆模式
@property (nonatomic,assign) BOOL isDebugModeRecord;

//是否使用http访问环境
@property(nonatomic,assign) BOOL isHttpDomain;

//默认为NO，表示不打印日志
@property (nonatomic, assign) BOOL debug;

//默认为NO，不打印日志文件
@property(nonatomic,assign) BOOL writeLogFile;

//表示要打印的日志级别为INFO,默认为YES
@property(nonatomic,assign) BOOL switchLogInfo;

//表示要打印的日志级别为DEBUG,默认为YES
@property(nonatomic,assign) BOOL switchLogDebug;

//表示要打印的日志级别为ERROR,默认为YES
@property(nonatomic,assign) BOOL switchLogError;

@property(nonatomic,assign) AdxAdType adType;

//要过滤掉的类日志，如果loggingClassNames数组元素大于0,则忽略classNames
@property(nonatomic,strong) NSMutableArray* classNames;

//要打印的类日志，该数组元素大于0，则忽略classNames
@property(nonatomic,strong) NSMutableArray* loggingClassNames;

@property(nonatomic,weak) id<AdxAdLogDelegate> logDelegate;

/**
 *  设置日志打印等级
 *  注意:只有在debug属性设置为YES的时候，才有效果; debug属性默认为NO
 *
 *  @param logLevel <#logLevel description#>
 */
-(void) setLogLevel:(AdxLogLevel)logLevel;

/**
 *  <#Description#>
 */
@property (nonatomic, assign) BOOL isEnableCharlesCatch;

+(AdxAdsDebugger *)sharedManagerDebugger;

+(AdxAdsDebugger *)debuggerWithAd:(AdxAdType)adType;

-(void) setRequestEnvironment:(int) requestEnvironment;

-(void) switchTestHttpEnvironmentInDueCourse;

-(void) switchOnlineHttpEnvironmentInDueCourse;

-(BOOL) isCanSwitchLogMode;

-(BOOL) isCanSwitchLoFilegMode;

-(BOOL) isCanSwitchCacheMode;

-(BOOL) isCanPrintLog:(id) selfObj;

//通过文件.txt判断是否启用charles抓包功能。
-(void) switchHttpsCharlesCatch;

-(BOOL) isCanSwitchTestCXSpeedMode;

@end
