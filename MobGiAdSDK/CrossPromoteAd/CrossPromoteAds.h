

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdxAdsComponent/AdxAdsDebugger.h>

@class CustomAdDataInfo;

//自定义广告默认提供的展示模版，不需要游戏开发者自行绘制界面
typedef NS_ENUM(NSInteger, CustomAdShowTemplate) {
    TEMPLATE1=0, //
    TEMPLATE2=1,//
    TEMPLATE3=2,//
    TEMPLATE4=3
};

//自定义banner条预置位置
typedef NS_ENUM(NSInteger, TemplateAdPosition) {
    TOP_LEFT = 1, //左上角
    TOP_CENTER = 2,//顶部居中
    TOP_RIGHT = 3,//右上角
    MIDDLE_LEFT = 4,//居中左对齐
    MIDDLE_CENTER = 5,//居中
    MIDDLE_RIGHT = 6,//居中右对齐
    BOTTOM_LEFT = 7,//左下角
    BOTTOM_CENTER = 8,//底部居中
    BOTTOM_RIGHT = 9//右下角
};


NS_ASSUME_NONNULL_BEGIN


@protocol WindowAdShowDelegate <NSObject>

@required

-(void) windowAdViewClose;

@end

@protocol CustomAdLogDelegate <NSObject>

@required

- (void)customAdSendLog:(NSString *)log level:(NSString*)level;

@end


@interface CrossPromoteAds : NSObject

/**
 *  日志开关，方便开发者接入观察视交叉广告请求过程
 */
@property (nonatomic, assign) BOOL debug;

/**
 *  是否写SDK调试日志到.txt文件
 */
@property(nonatomic,assign) BOOL writeLogFile;

+(CrossPromoteAds *)shareInstance;

/**
 *
 * 是否启用默认日志来定位是否调用接口，默认值为YES
 *
 */
@property (nonatomic,assign) BOOL isEnableDefaultLog;

-(void) setLogDelegate:(nullable id<CustomAdLogDelegate>) delegate;

-(void) setLogLevel:(AdxLogLevel)logLevel;

/**
 *  初始化交叉推广广告SDK
 *
 *  @param appkey appkey
 */
-(void) initSDK:(NSString*) appkey;

#pragma mark -
#pragma mark 橱窗广告

/**
 *  预加载橱窗广告数据
 *
 *  @param 精品橱窗－焦点图 广告位ID
 *  @param 精品橱窗－应用墙 广告位ID
 */
-(void) preloadCustomWindowAd:(NSString*)windowBlockid
                  listBlockid:(NSString*)listBlockid;

/**
 *  判断橱窗广告数据是否准备就绪
 *
 *  @return 橱窗广告状态
 */
-(BOOL) isWindowAdReady;
/**
 *  展示橱窗广告
 *
 *  @param presentRootVC
 */
-(void) presentWindowAd:(UIViewController*)presentRootVC;

-(void) presentWindowAd:(UIViewController*)presentRootVC
               delegate:(id<WindowAdShowDelegate>)delegate;


#pragma mark -
#pragma mark 自定义banner广告

/**
 *  加载自定义广告
 *
 *  @param blockid 广告位ID
 */
-(void) loadCustomBannerAdData:(NSString*)blockid;

/**
 *  判断原生banner广告数据是否准备就绪
 *
 *  @param blockid 广告位ID
 *
 *  @return 原生banner广告数据状态？
 */

-(BOOL) isCustomAdReady:(NSString*)blockid;

/**
 *  获取原生banner广告数据
 *
 *  @param blockid 广告位ID
 *
 *  @return 原生banner广告数据，包含广告标题，广告描述信息，文案本地缓存图片地址，文案网络地址，广告位ID
 */
-(nullable CustomAdDataInfo*) getCustomAdData:(NSString*)blockid;

/**
 *  进行广告界面绘制后，广告展示的时候，调用该方法，没调用会产生数据统计风险！
 *  调用场景：调用方拿到广告数据后，自行绘制的广告界面 发生展示的时候
 *
 *  @param blockid <#blockid description#>
 */
-(void) reportCustomAdShow:(NSString*)blockid;

/**
 *  上报自定义广告点击，内部封装支持点击跳转行为；没调用会产生数据统计风险！
 *  调用场景：调用方拿到广告数据后，自行绘制的广告界面 发生点击的时候
 *
 *  @param blockid 广告位ID
 *  @param vc      该自定义广告展示的视图控制器
 */
-(void) reportCustomAdClick:(NSString*)blockid
                   vc:(UIViewController*)vc;

/**
 *  上报自定义广告关闭；没调用会产生数据统计风险！
 *  调用场景：调用方拿到广告数据后，自行绘制的广告界面或者使用系统模版展示的广告界面 发生关闭的时候，
 *
 *  @param blockid     广告位ID
 *  @param useTemplate 该自定义广告是否使用系统模版展示
 */
-(void) reportCustomAdClose:(NSString*)blockid
          useTemplate:(BOOL)useTemplate;

#pragma mark -
#pragma mark 自定义banner广告模版展示

/**
 animateType参数取值如下：
 fade	淡出效果
 push	新视图推出旧视图，只作用于第二种和第三种模版
 none   没有动画效果
 **/

/**
 *  获取指定模版的尺寸
 *
 *  @param showTemplate 展示模版
 *
 *  @return 模版尺寸信息
 */
-(CGSize) getSizeForTemplate:(CustomAdShowTemplate)showTemplate;

-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
               position:(CGPoint)pos
                size:(CGSize)size
                vc:(UIViewController*)vc;

-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
            position:(CGPoint)pos
                size:(CGSize)size
         animateType:(NSString*) type
                vc:(UIViewController*)vc;

-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
       templateColor:(UIColor*)templateColor
            position:(CGPoint)pos
                size:(CGSize)size
         animateType:(NSString*) type
                  vc:(UIViewController*)vc;

-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
       templateColorValue:(NSString*)templateColorValue
            position:(CGPoint)pos
                size:(CGSize)size
         animateType:(NSString*) type
                  vc:(UIViewController*)vc;

/**
 *  使用SDK内置模版展示原生banner广告数据
 *
 *  @param blockid      广告位ID
 *  @param showTemplate 展示模版
 *  @param pos          位置信息
 *  @param size         模版尺寸信息
 *  @param vc           展示模版界面关联的视图控制器
 *  @param extraInfo    展示模版额外信息； 比如展示模版颜色，展示模版动画(目前只提供淡出push，平移fade动画)
 *  实例如下：
 *  NSMutableDictionary* extraInfo=[[NSMutableDictionary alloc] initWithObjects:@[@"push",@"#0079f7"] forKeys:@[@"animateType",@"templateColorValue"]];
 *
 * 
 */
-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
            position:(CGPoint)pos
                size:(CGSize)size
                  vc:(UIViewController*)vc
           extraInfo:(NSMutableDictionary*)extraInfo;


/**
 *  使用SDK内置模版展示原生banner广告数据
 *
 *  @param blockid      广告位ID
 *  @param showTemplate 展示模版
 *  @param pos          预设置位置信息，屏幕预置九个位置
 *  @param vc           展示模版界面关联的视图控制器
 *  @param extraInfo    展示模版额外信息； 比如展示模版颜色，展示模版动画(目前只提供淡出push，平移fade动画)
 *  实例如下：
 *  NSMutableDictionary* extraInfo=[[NSMutableDictionary alloc] initWithObjects:@[@"push",@"#0079f7"] forKeys:@[@"animateType",@"templateColorValue"]];
 *
 *
 */
-(void) showCustomAd:(NSString*)blockid
            template:(CustomAdShowTemplate)showTemplate
                 pos:(TemplateAdPosition)pos
                  vc:(UIViewController*)vc
           extraInfo:(NSMutableDictionary*)extraInfo;

@end

NS_ASSUME_NONNULL_END
