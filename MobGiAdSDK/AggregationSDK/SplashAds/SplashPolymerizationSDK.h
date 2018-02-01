//
//  SplashPolymerization.h
//  SplashPolymerization
//
//  Created by star.liao on 2017/1/4.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdxAdsComponent/AdxAdsDebugger.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SplashAdLogDelegate <NSObject>

@required

- (void)splashAdSendLog:(NSString *)log level:(NSString*)level;

@end



@interface SplashPolymerizationSDK : NSObject

/**
 *  日志开关，方便开发者接入观察视频广告请求过程
 */
@property (nonatomic, assign) BOOL debug;


/**
 *  拉取广告超时时间，默认为5秒
 *  详解：拉取广告超时时间，在该超时时间内，如果广告拉
 *  取成功，则立马展示开屏广告，否则放弃此次广告展示机会。
 *  注意: 广告后台可以控制超时时间，如果CP没有设置该属性，则以SDK默认或广告后台进行控制
 */
@property (nonatomic, assign) int fetchDelay;

/**
 *
 * 是否启用默认日志来定位是否调用接口，默认值为YES
 *
 */
@property (nonatomic,assign) BOOL isEnableDefaultLog;

/**
 *  是否写聚合SDK调试日志到.txt文件
 */
@property(nonatomic,assign) BOOL writeLogFile;

+(SplashPolymerizationSDK *)sharedInstance;



-(void) setLogDelegate:(nullable id<SplashAdLogDelegate>) delegate;

/**
 *  设置日志打印等级
 *  注意:只有在debug属性设置为YES的时候，才有效果; debug属性默认为NO
 *
 *  @param logLevel 日志级别
 */
-(void) setLogLevel:(AdxLogLevel)logLevel;

-(void) showSplash:(NSString*)appkey
        withWindow:(UIWindow*)window
           blockid:(NSString*)blockid;

@end

NS_ASSUME_NONNULL_END
