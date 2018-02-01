
#import <UIKit/UIKit.h>
#import <AdxAdsComponent/AdxAdsDebugger.h>

NS_ASSUME_NONNULL_BEGIN

@protocol VideoAdLogDelegate <NSObject>

@required

- (void)videoAdSendLog:(NSString *)log level:(NSString*)level;

@end


@protocol VideoAdDelegate <NSObject>

@required

/**
 *  游戏监控该接口回调，判断是否可以发放奖励
 *
 *  @param isShouldReward 是否可以发放奖励，YES标示可以，NO标示不可发奖励
 *  @param blockId        广告位ID
 */
-(void) triggerReward:(BOOL) isShouldReward
        forBlockid:(NSString*) blockId;

@optional

/**
 *  This method is invoked when an ad has been presented.
 *
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
- (void)videoAdDidPresent:(NSString*)platName
                  blockId:(NSString*)blockId;

/**
 *  This method is invoked when an ad has been dismissed.
 *
 *  @param  platName  Detailed message  the name of the platform.
 *  @param  blockId   Detailed message  ad id.
 */
- (void)videoAdDidDismiss:(NSString*)platName
                  blockId:(NSString*)blockId;

/**
 *  This method is invoked when an ad load fails.
 *
 *  @param  errorMessage  Detailed message loading failure.
 */
- (void)videoAdFailedToLoadWithError:(NSString*)errorMessage;

/**
 *  Called when the ad failed to display for some reason
 *
 *  @param errorMessage  Description to show the cause of the failure.
 */
- (void)videoAdShowFailedWithError:(NSString*)errorMessage;

/**
 *  此接口已经废弃，可以调 -(BOOL) isAdPlayable:(NSString*)blockid 方法在刷新界面的时候判断是否就绪
 *  @deprecated This method is deprecated starting in version 0.4.0
 *  @note Please use instead:
 *  @code isAdPlayable:
 *
 *  游戏监控该接口回调，缓存对应的值，在调用show方法时候把值重置
 *
 *  @param isReady 视频广告状态,YES标示就绪，NO标示还没有准备成功
 *  @param blockId 广告位ID
 */
-(void) adReady:(BOOL) isReady
     forBlockid:(NSString*) blockId __attribute__((deprecated));

@end


@interface VideoPolymerizationSDK : NSObject

/**
 *
 * 是否启用默认日志来定位是否调用接口，默认值为YES
 *
 */
@property (nonatomic,assign) BOOL isEnableDefaultLog;

/**
 *  日志开关，方便开发者接入观察视频广告请求过程
 */
@property (nonatomic, assign) BOOL debug;

/**
 *  是否写聚合SDK调试日志到.txt文件
 */
@property(nonatomic,assign) BOOL writeLogFile;


+(VideoPolymerizationSDK *)sharedInstance;


-(void) setLogDelegate:(nullable id<VideoAdLogDelegate>) delegate;

-(void) setLogLevel:(AdxLogLevel)logLevel;

/**
 *  获取SDK版本号
 */
+(NSString*) getCurrentSDKVersion;

/**
 *  获取SDK当前聚合平台信息
 */
+(void) validateIntergration;

/**
 *  初始化接口，开发者接入只需调用一次
 *
 *  @param appkey     appkey,在广告后台申请，联系han.song
 *  @param vc         vc,游戏开发者可传入[UIApplication sharedApplication].keyWindow.rootViewController
 *  @param blockArray 广告位ID数组，例如@[@"blockid1",@"blockid2"],在广告后台申请，联系han.song
 *  @param delegate   delegate
 */
-(void) initSDK:(NSString*) appkey
             vc:(UIViewController*) vc
       blockIds:(NSArray*) blockArray
       delegate:(id<VideoAdDelegate>) delegate;


/**
 *  判断视频是否准备就绪接口，可以反复调用
 *
 *  在展示广告之前调用此方法，获取到返回值，如果返回YES则对应广告位就绪，可以展示视频，如果返回NO则对应广告位没有加载好，不能展示视频，
 *
 *  @param blockid    传入广告位
 */
-(BOOL) isAdPlayable:(NSString*)blockid;



/**
 *  游戏开发者进行调用展示视频广告，监控adReady:forBlockid:回调方法的值为YES，才建议调用
 *  如果对应的广告商广告没有准备就绪，调用无法展示广告，监控callBack参数回调，游戏进行相应提示处理
 *
 *  @param vc       vc,游戏开发者可传入[UIApplication sharedApplication].keyWindow.rootViewController
 *  @param blockId  要展示视频广告的广告位ID
 *  @param callBack 无法展示视频广告，发生异常，监控callBack参数回调，游戏进行相应提示处理,该block在异步线程上执行
 */
-(void) showViewAd:(UIViewController*)vc
        forBlockId:(NSString*)blockId
          callBack:(void(^)())callBack;

@end

NS_ASSUME_NONNULL_END
