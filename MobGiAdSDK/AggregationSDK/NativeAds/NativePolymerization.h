

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdxAdsComponent/AdxAdsDebugger.h>

@class NativeAdData;
@class NativeAdDetailsInfo;
@class NativeAdExtraOptionInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol NativeAdLogDelegate <NSObject>

@required

- (void)nativeAdSendLog:(NSString *)log level:(NSString*)level;

@end


@protocol NativeAdDelegate <NSObject>

@optional

/**
 *  CP可通过该回调，实时收到广告数据准备就绪的通知; CP可通过调用getNativeAd接口拿到广告数据!
 *
 *  @param blockId 广告位ID
 */
-(void)nativeAdSuccessToLoad:(NSString *)blockId;

#pragma mark 暂时没有对该回调进行处理，已废弃，CP注意不要在该回调里加逻辑处理

-(void)nativeAdFailToLoad:(NSError *)error __attribute__((deprecated));

#pragma mark 注意以下回调，部分广告商会触发，CP可根据需要做额外处理

/**
 *  广告发生点击后，关闭了
 *
 *  GDT广告会触发,Applovin不会触发
 *  CP需要针对广告商进行处理
 *
 *  @param blockId  广告位ID
 *  @param platName 广告商标示名称
 */
-(void)nativeClickedAdDismiss:(NSString*)blockId
                     platName:(NSString*)platName;

@end


@interface NativePolymerization : NSObject

+(NativePolymerization *)sharedInstance;


/**
 *
 * 是否启用默认日志来定位是否调用接口，默认值为YES
 *
 */
@property (nonatomic,assign) BOOL isEnableDefaultLog;

/**
 *  日志开关，方便开发者接入观察原生广告请求过程
 */
@property (nonatomic, assign) BOOL debug;

/**
 *  是否写原生广告SDK调试日志到.txt文件
 */
@property(nonatomic,assign) BOOL writeLogFile;

-(void) setLogDelegate:(nullable id<NativeAdLogDelegate>) delegate;

-(void) setLogLevel:(AdxLogLevel)logLevel;

/*设置一些可选的属性，如logo标志位置*/
-(void) setOptionInfo:(NativeAdExtraOptionInfo*)optionInfo;

#pragma mark

/**
 *  获取SDK版本号
 */
+(NSString*) getCurrentSDKVersion;

/**
 *  获取SDK当前聚合平台信息
 */
+(void) validateIntergration;

#warning 该接口不再支持，之前接的CP需要换掉下面接口调用
/**
 *  此接口已经废弃
 *  初始化原生广告聚合SDK，完成相应广告位的原生广告获取; 建议接入方在游戏启动后，尽早调用该方法
 *
 *  @param appkey appkey
 */
-(void) initSDK:(NSString*)appkey __attribute__((deprecated));

#warning 该接口不再支持，之前接的CP需要换掉下面接口调用
/**
 *  此接口已经废弃
 *  初始化原生广告聚合SDK，完成相应广告位的原生广告获取; 建议接入方在游戏启动后，尽早调用该方法
 *
 *  @param appkey      appkey
 *  @param delegate    设置代理
 */
-(void) initSDK:(NSString*)appkey delegate:(id<NativeAdDelegate>)delegate __attribute__((deprecated));

/**
 *  初始化原生广告聚合SDK，完成相应广告位的原生广告获取; 建议接入方在游戏启动后，尽早调用该方法
 *
 *  @param appkey appkey
 */
-(void) initSDK:(NSString*)appkey blockids:(NSMutableArray*)bids;

/**
 *  初始化原生广告聚合SDK，完成相应广告位的原生广告获取; 建议接入方在游戏启动后，尽早调用该方法
 *
 *  @param appkey      appkey
 *  @param delegate    设置代理
 */
-(void) initSDK:(NSString*)appkey blockids:(NSMutableArray*)bids delegate:(id<NativeAdDelegate> __nullable)delegate;

/**
 *  获取广告位对应的原生广告数据
 *
 *  @param blockid 广告位ID
 *
 *  @return 原生广告数据
 */
-(NativeAdData* __nullable) getNativeAd:(NSString*)blockid;

#warning 该接口不再支持，之前接的CP需要换掉下面接口调用
/**
 *  此接口已经废弃
 *  接入方在拿到原生广告数据后，绘制界面成功后，必须调用该方法，否则广告收益不予结算
 *
 *  @param currentAd 当前显示界面对应的原生广告数据
 *  @param adView    显示界面
  *  @param vc   显示界面所属的视图控制器
 */
-(BOOL) attachAd:(NativeAdData*)currentAd
          toView:(UIView*)adView
              vc:(UIViewController*)vc __attribute__((deprecated));

/**
 *  接入方在拿到原生广告数据后，绘制界面成功后，必须调用该方法，否则广告收益不予结算
 *
 *  @param currentAd 当前显示界面对应的原生广告数据
 *  @param adView    显示界面
 *  @param vc   显示界面所属的视图控制器
 *  @param detailsInfo   应用的信息
 */
-(BOOL) attachAd:(NativeAdData*)currentAd
          toView:(UIView*)adView
              vc:(UIViewController*)vc
     detailsInfo:(NativeAdDetailsInfo*)detailsInfo;

/**
 *  原生广告显示界面不再展示的时候，必须调用该方法
 *  @param currentAd 当前显示界面对应的原生广告数据
 *  @param adView    显示界面
 */
-(BOOL) unAttachAd:(NativeAdData*)currentAd toView:(UIView*)adView;

/**
 *  原生广告显示界面发生点击的时候，必须调用该方法，否则广告收益不予结算
 *
 *  @param currentAd 当前显示界面对应的原生广告数据
 */
-(void) clickAd:(NativeAdData*)currentAd;

@end

NS_ASSUME_NONNULL_END
