//
//  InterstitialPolymerizationSDK.h
//  InterstitialPolymerization
//
//  Created by star.liao on 16/4/6.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AdxAdsComponent/AdxAdsDebugger.h>

NS_ASSUME_NONNULL_BEGIN

@protocol InterstitialInitDelegate <NSObject>

@required
-(void) initSuccess;

@end

@protocol InterstitialLogDelegate <NSObject>

@required

- (void)sendLog:(NSString *)log level:(NSString*)level;

@end


@protocol ShowCachedInterstitialAdDelegate <NSObject>

@required

- (void)interstitialPresentScreen:(NSString*)blockid;

- (void)interstitialDismissScreen:(NSString*)blockid;

/**
 *  Called when the ad failed to display for some reason
 *
 *  @param errorMsg  Description to show the cause of the failure.
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
- (void)interstitialAdShowFailed:(NSString*)errorMsg
                        platName:(NSString*)platName
                         blockId:(NSString*)blockId;

/**
 *  This method is called when an ad has been presented.
 *
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
- (void)interstitialAdDidPresent:(NSString*)platName
                         blockId:(NSString*)blockId;

/**
 *  This method is called when an ad has been dismissed.
 *
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
- (void)interstitialAdDidDismiss:(NSString*)platName
                         blockId:(NSString*)blockId;

@end

@protocol PreloadInterstitialAdDelegate <NSObject>

@optional

/**
 *  此接口已经废弃
 *  @deprecated This method is deprecated starting in version 1.3.0
 *  @param blockId 广告位ID
 */
-(void) interstitialLoadSuccess:(NSString*)blockid __attribute__((deprecated));

/**
 *  此接口已经废弃
 *  @deprecated This method is deprecated starting in version 1.3.0
 *  @param error 错误信息
 *  @param blockId 广告位ID
 */
-(void) interstitialLoadError:(NSError*)error
                      blockid:(NSString*)blockid __attribute__((deprecated));

/**
 *  This method is called when an ad load fails.
 *
 *  @param  errorMsg  Detailed message loading failure.
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
-(void) interstitialAdFailedToLoad:(NSString*)errorMsg
                          platName:(NSString*)platName
                           blockId:(NSString*)blockId;

@end


@interface InterstitialPolymerizationSDK : NSObject

/**
 *  是否可打印SDK日志
 */
@property (nonatomic, assign) BOOL debug;

/**
 *  是否可写入SDK日志文件
 */
@property(nonatomic,assign) BOOL writeLogFile;

/**
 *
 * 是否启用默认日志来定位是否调用接口，默认值为YES
 *
 */
@property (nonatomic,assign) BOOL isEnableDefaultLog;

/**
 *  游戏在appstore上线的版本号，建议传入格式为:1.0.0
 */
@property (nonatomic,strong) NSString* gameVersion;

+(InterstitialPolymerizationSDK *)sharedInstance;

+(NSString*) getCurrentSDKVersion;

+(void) validateIntergration;
/**
 *  初始化插页SDK
 *
 *  @param appkey
 */
-(void) initSDK:(NSString*)appkey;

/**
 *  初始化插页SDK
 *
 *  @param appkey   <#appkey description#>
 *  @param delegate delegate, 建议CP在该代理回调执行完后，再去调用preloadInterstitialAd和showCachedInterstitialAd接口
 */
-(void) initSDK:(NSString*)appkey
       delegate:(nullable id<InterstitialInitDelegate>)delegate;

/**
 *  设置日志打印等级
 *  注意:只有在debug属性设置为YES的时候，才有效果; debug属性默认为NO
 *
 *  @param logLevel <#logLevel description#>
 */
-(void) setLogLevel:(AdxLogLevel)logLevel;

/**
 *  设置日志回调
 *
 *  @param delegate <#delegate description#>
 */
-(void) setLogDelegate:(nullable id<InterstitialLogDelegate>) delegate;


/**
 *  判断广告位对应的插页广告是否准备就绪
 *
 *  @param blockid 广告位
 *
 *  @return BOOL
 */
-(BOOL) getCacheReady:(NSString*)blockid;

/**
 *  如果有缓存，则展示插页广告； 没有缓存则去预加载广告； 关闭插页广告后，会自动去加载下一条广告。
 *  该方法内部已经封装调用getCacheReady方法判断广告状态，接入方可以直接调用该方法显示插页广告，广告关闭后会自动加载下一条插页广告，接入方不需要再调用preloadInterstitialAd:delegate:方法
 *
 *  @param blockid  广告位
 *  @param delegate delegate
 */
- (void) showCachedInterstitialAd:(NSString*)blockid
                          delegate:(nullable id<ShowCachedInterstitialAdDelegate>)delegate;

/**
 *  如果有缓存，则展示插页广告； 没有缓存则去预加载广告； 关闭插页广告后，会自动去加载下一条广告。
 *  该方法内部已经封装调用getCacheReady方法判断广告状态，接入方可以直接调用该方法显示插页广告，广告关闭后会自动加载下一条插页广告，接入方不需要再调用preloadInterstitialAd:delegate:方法
 *
 *  @param blockid 广告位
 */
- (void) showCachedInterstitialAd:(NSString*)blockid;

/**
 *  预加载插页广告
 *
 *  @param blockid 广告位
 */
-(void)preloadInterstitialAd:(NSString*) blockid;

/**
 *  预加载插页广告
 *
 *  @param blockid  广告位
 *  @param delegate 1.0.0版本后，该代理回调已经废弃掉，不再执行
 */
-(void)preloadInterstitialAd:(NSString*) blockid
                     delegate:(nullable id<PreloadInterstitialAdDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
