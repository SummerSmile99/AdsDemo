

//聚合广告debugger，统一管理所有广告形式的聚合
#define AGGREGATIONAD_EXCEPTION(frmt, ...) if ([AggregationAdsDebugger sharedInstance].debug) NSLog((XCODE_COLORS_ESCAPE @"fg255,0,0;" @"ERROR [MobGi T:0x%x %@] %s:%d " frmt XCODE_COLORS_RESET), (unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#define AGGREGATIONAD_ERROR(frmt, ...) if ([AggregationAdsDebugger sharedInstance].debug&&[AggregationAdsDebugger sharedInstance].switchLogError)   NSLog((XCODE_COLORS_ESCAPE @"fg255,0,0;" @"ERROR [MobGi T:0x%x %@ obj:%p] %s:%d " frmt XCODE_COLORS_RESET), (unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#define AGGREGATIONAD_DEBUG(frmt, ...) if ([AggregationAdsDebugger sharedInstance].debug&&[AggregationAdsDebugger sharedInstance].switchLogDebug) (NSLog((XCODE_COLORS_ESCAPE @"fg246,173,16;" @"DEBUG [MobGi T:0x%x %@ %p] %s:%d " frmt XCODE_COLORS_RESET), (unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__))

#define AGGREGATIONAD_INFO(frmt, ...) if ([AggregationAdsDebugger sharedInstance].debug&&[AggregationAdsDebugger sharedInstance].switchLogInfo) NSLog((XCODE_COLORS_ESCAPE @"fg255,255,255;" @"INFO [MobGi T:0x%x %@ %p] %s:%d " frmt XCODE_COLORS_RESET), (unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#pragma mark                   -
#pragma mark                   数据上报类型

//聚合SDK广告展示
#define AGGREGATION_SDK_AD_SHOW @"16"

//聚合SDK初始化
#define AGGREGATIONAD_TYPE_SDK_INIT @"15"

#pragma mark 视频

#define VIDEO_TYPE_PLAYSTART                                       @"1"
#define VIDEO_TYPE_PLAYEND                                         @"2"
#define VIDEO_TYPE_COMPLETEDREWARD                                 @"3"
#define VIDEO_TYPE_CLICK                                           @"4"
#define VIDEO_TYPE_CONFIG_SYN_COMPLETE                             @"5"
#define VIDEO_TYPE_VIDEO_START_REQUEST                             @"6"
#define VIDEO_TYPE_VIDEO_REQUEST_SUCCESS                           @"7"
#define VIDEO_TYPE_AGGREGATION_SDK_INITIALIZATION                  @"15"
#define VIDEO_TYPE_VIDEO_SHOW_BEGIN                                @"16"

#pragma mark 插页

//插页点击
#define INTERSTITIAL_TYPE_CLICK @"10"

//插页展示
#define INTERSTITIAL_TYPE_PRESENT @"8"

//插页关闭
#define INTERSTITIAL_TYPE_DISSMISS @"9"

//插页配置请求
#define INTERSTITIAL_TYPE_CONFIG_START_SYN @"11"

//插页配置同步完成
#define INTERSTITIAL_TYPE_CONFIG_SYN_COMPLETE @"12"

//插页缓存成功
#define INTERSTITIAL_TYPE_CACHE_SUCCESS @"13"

//插页开始请求
#define INTERSTITIAL_TYPE_START_CACHE @"14"

#pragma mark 开屏

#define SPLASH_TYPE_SDK_AD_SHOW @"35"

#define SPLASH_TYPE_SDK_AD_CONFIG_REQUEST @"31"

#define SPLASH_TYPE_SDK_AD_CONFIG_REQUEST_SUCCESS @"32"

#define SPLASH_TYPE_SDK_AD_REQUEST @"33"

#define SPLASH_TYPE_SDK_AD_REQUEST_SUCCESS @"34"

#define SPLASH_TYPE_SDK_AD_CLICK @"36"

#define SPLASH_TYPE_SDK_AD_CLOSE @"37"

#pragma mark 原生

//41:原生信息流广告配置请求
//42:原生信息流广告配置请求成功
//43:原生信息流开始请求
//44:原生信息流缓存成功
//45:原生信息流展示
//46:原生信息流点击
#define NATIVE_TYPE_SDK_AD_CONFIG_REQUEST @"41"
#define NATIVE_TYPE_SDK_AD_CONFIG_REQUEST_SUCCESS @"42"
#define NATIVE_TYPE_SDK_AD_REQUEST @"43"
#define NATIVE_TYPE_SDK_AD_REQUEST_SUCCESS @"44"
#define NATIVE_TYPE_SDK_AD_SHOW @"45"
#define NATIVE_TYPE_SDK_AD_CLICK @"46"

#import <Foundation/Foundation.h>

static NSMutableDictionary* debuggerDictionary;

#import <Foundation/Foundation.h>
//#import "AggregationAdsLogicMacro.h"
#import "AdsIntergrationPlatInfo.h"

@interface AggregationAdsDebugger : NSObject

@property(nonatomic,assign) AggregationAdType adType;

/**
 *  <#Description#>
 */
@property(nonatomic,strong) NSString* ADSBaseURL;

/**
 *  <#Description#>
 */
@property(nonatomic,strong) NSString* ADSReportURL;

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

+(AggregationAdsDebugger *)sharedInstance;

/**
 *  根据不同的聚合广告形式，获取对应的调试器
 *
 *  @param adType <#adType description#>
 *
 *  @return <#return value description#>
 */
+(AggregationAdsDebugger *)debuggerWithAd:(AggregationAdType)adType;

/**
 *  切换请求环境
 *
 *  @param requestEnvironment 0:测试环境；1:正式环境; 其它为正式环境
 */
-(void) setRequestEnvironment:(int) requestEnvironment;

/**
 *  根据打入文件判定是否切换到测试http环境,文件命名格式为:%@adaggregation_networks_testhttpmode,其中%@替换为对应的广告形式,比如native,interstitial,video,splash
 *
 *  @param adType 聚合广告类型
 */
-(void) switchTestHttpEnvironmentInDueCourse:(AggregationAdType)adType;

/**
 *  根据打入文件判定是否切换到正式http环境,文件命名格式为:%@adaggregation_networks_onlinehttpmode,其中%@替换为对应的广告形式,比如native,interstitial,video,splash
 *
 *  @param adType 聚合广告类型
 */
-(void) switchOnlineHttpEnvironmentInDueCourse:(AggregationAdType)adType;

/**
 *  根据打入文件判定是否启用SDK日志打印模式,文件命名格式为:%@adaggregation_networks_logmode,其中%@替换为对应的广告形式,比如native,interstitial,video,splash
 *
 *  @param adType 聚合广告类型
 */
-(void) switchLogModeInDueCourse:(AggregationAdType)adType;

/**
 *  根据打入文件判定是否启用SDK日志文件写入模式,文件命名格式为:%@adaggregation_networks_logfilewritemode,其中%@替换为对应的广告形式,比如native,interstitial,video,splash
 *
 *  @param adType 聚合广告类型
 */
-(void) switchLogFileWriteModeInDueCourse:(AggregationAdType)adType;

@end
