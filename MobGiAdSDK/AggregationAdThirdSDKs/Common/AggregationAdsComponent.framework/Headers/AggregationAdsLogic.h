//
//  AdsPlatformDefine.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/1/5.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdsIntergrationPlatInfo.h"
#import "AdsPlatformLogicManager.h"
#import "AggregationAdvertiserInfo.h"
#import "AggregationAdsDebugger.h"
#import "AggregationPrioritAdsInfo.h"

//#pragma mark -原生，插页，视频
//
////Inmobi
//#define ADS_PLATNAME_INMOBI @"Inmobi"
//
////Applovin
//#define ADS_PLATNAME_APPLOVIN @"Applovin"
//
//#pragma mark -原生，插页，开屏
////GDT
//#define ADS_PLATNAME_GDT @"GDT"
//
//
//#pragma mark -视频，插页
//
////Loopme
//
//#define ADS_PLATNAME_LOOPME @"Loopme"
//
////Supersonic
//#define ADS_PLATNAME_SUPERSONIC @"Supersonic"
//
////Chartboost
//#define ADS_PLATNAME_CHARTBOOST @"Chartboost"
//
////Applovin
//#define ADS_PLATNAME_APPLOVIN @"Applovin"
//
//#pragma mark -插页,开屏
//
////Adview
//#define ADS_PLATNAME_ADVIEW @"Adview"
//
////Glispa
//#define ADS_PLATNAME_GLISPA @"Glispa"
//
//#pragma mark -视频，插页,开屏
//
////Chance
//#define ADS_PLATNAME_CHANCE @"Chance"
//
//#define ADS_PLATNAME_APPNEXT    @"Appnext"
//
//
//
//#pragma mark -视频
//
//#define ADS_PLATNAME_CENTRIXLINK                    @"CentrixLink"
//
//#define ADS_PLATNAME_YUMI                           @"Yumi"
//
//#define ADS_PLATNAME_ONEWAY                         @"Oneway"
//
//#define ADS_PLATNAME_SHUNFEI                        @"Shunfei"
//
//#define ADS_PLATNAME_MOBVISTA                       @"Mobvista"
//
//#define ADS_PLATNAME_CHANGXIAN                      @"Changxian"
//
//#define ADS_PLATNAME_DIANVIEW                      @"Dianview"
//
//#define ADS_PLATNAME_YOUMI                         @"Youmi"
//
//#define ADS_PLATNAME_DOMOB                         @"Domob"
//
//#define ADS_PLATNAME_UNITY                          @"Unity"
//
//#define ADS_PLATNAME_VUNGLE                         @"Vungle"
//
//#define ADS_PLATNAME_ADCOLONY                       @"Adcolony"
//
//#pragma mark -插页
//
////HouseAd
//#define ADS_PLATNAME_HOUSEAD_INTERSTITIAL @"Mobgi"
//
//#define ADS_PLATNAME_MOBGI @"Mobgi"
//
////Facebook
//#define ADS_PLATNAME_FACEBOOK @"Facebook"
//
////Yeahmobi
//#define ADS_PLATNAME_YEAHMOBI @"Yeahmobi"
//
////Admob
//#define ADS_PLATNAME_ADMOB @"Admob"
//
////Adwo
//#define ADS_PLATNAME_ADWO @"Adwo"
//
//null
#define ADS_PLATNAME_NULL @"AD_NULL"



/**
 *  管理聚合SDK集成的广告商基本信息类
 */
@interface AggregationAdsLogic : NSObject

@property(nonatomic,strong) NSArray* platNameArray;//广告商名字定义,例如:ADS_PLATNAME_VUNGLE或@"Vungle"
@property(nonatomic,strong) NSArray* platTypeArray; //广告商枚举类型，例如:AdsPlatInfoAdmob
@property(nonatomic,strong) NSArray* platLoadDefineArray;//标示广告商加载类定义
@property(nonatomic,strong) NSArray* platHanderArray;//广告商加载hander
@property(nonatomic,strong) NSArray* platSDKVersionArray;//广告商对应版本号
@property(nonatomic,strong) NSMutableArray* aggregatedAdNameArray;//聚合的广告商名称列表

@property(nonatomic,strong) NSArray* appkeyBidAdNameArray; //只处理appkey和blockid校验的广告商名称数组
@property(nonatomic,strong) NSArray* appkeyAdNameArray;//只处理appkey校验的广告商名称数组
@property(nonatomic,strong) NSArray* appkeyAppsecretAdNameArray;//只处理appkey和appsecret校验的广告商名称数组
@property(nonatomic,strong) NSArray* appkeyAppsecretBidAdNameArray;//只处理appkey,appsecret和blockid校验的广告商名称数组
@property(nonatomic,strong) NSArray* bidAdNameArray;//只处理blockid校验的广告商名称数组

@property(nonatomic,strong) NSMutableArray* intergrationPlatInfoArray;//存储所有预期的广告商集成详情对象列表，比如2.1.5版本对应20家广告商情况
@property(nonatomic,strong) NSString* sdkversion;//聚合SDK版本号
@property(nonatomic,assign) NSString* adTypeName;//广告类型名称定义； 例如:"video","interstitial"

-(instancetype) init:(NSString*) sdkVersion
              adType:(NSString*)adTypeName;

/**
 *  获取广告商对应的广告加载hander
 *
 *  @param platName <#platName description#>
 *
 *  @return <#return value description#>
 */
-(Class) getAdLoadingHander:(NSString*)platName;

/**
 *  获取广告商对应的版本号
 *
 *  @param int <#int description#>
 *
 *  @return <#return value description#>
 */
-(NSString*) getVersion:(int)adNetworkType;

/**
 *  获取广告商对应的版本号
 *
 *  @param platName <#platName description#>
 *
 *  @return <#return value description#>
 */
-(NSString*) getNetworkVersion:(NSString*)platName;

-(int) getAdsPlatInfoTypeFromName:(NSString*) platName;

-(NSString*) getAdsPlatInfoName:(int) type;

//sdk集成情况，详细字符串
-(NSString*) getIntergrationResult;

//获取按逗号隔开集成的广告商列表
//举例：Vungle,Unity,......
-(NSString*) getHasAggregationPlats;

#pragma mark - 给子类调用

-(BOOL) canLoadPrioritAd:(AggregationPrioritAdsInfo*) adInfo;

/**
 *  自动根据广告商信息，根据概率大小，集成情况，下发值逻辑，自动判断该平台是否可以加载广告!
 *
 *  @param adInfo <#adInfo description#>
 *
 *  @return <#return value description#>
 */
-(BOOL) canLoadAdForNetwork:(AggregationAdvertiserInfo*) adInfo;

/**
 *  根据平台集成情况，该平台是否可以加载广告
 *
 *  @param platInfoName <#platInfoName description#>
 *
 *  @return <#return value description#>
 */
-(BOOL) isShouldLoadPlat:(NSString*) platInfoName;

#pragma mark - 给子类重写

+(NSString*) getValidateIntergrationResult;

+(NSString*) getAdxHasAggregationPlats;

@end


