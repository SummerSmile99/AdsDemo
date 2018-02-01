//
//  AdsIntergrationPlatInfo.h
//  InterstitialPolymerization
//
//  Created by star.liao on 2016/12/12.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

//fix: 跟ADX同样的广告类型定义
typedef NS_ENUM(NSInteger, AggregationAdType) {
    VIDEO=1, //视频聚合
    INTERSTITIAL=2,//插屏聚合
    CUSTOMAD=3,//自定义
    SPLASH=4,//开屏
    NATIVE=5  //原生
};

@interface AdsIntergrationPlatInfo : NSObject

@property(nonatomic,strong) NSString* platInfoName;
@property(nonatomic,strong) id platInfoVersion; //获取广告商SDK版本号
@property(nonatomic,strong) NSString* platInfoDefaultVersion; //每个聚合SDK版本代码里，写死集成的广告商版本号
@property(nonatomic,strong) NSString* infoPlistExceptionDomain;
@property(nonatomic,strong) NSString* sdkResouceFile;//sdk资源文件集成结果
@property(nonatomic,strong) NSString* sdkLoaded;//@"Library files has been added.";
@property(nonatomic,strong) NSString* sdkResult; //sdk集成结果  @"The SDK add success.";
@property(nonatomic,strong) NSString* result;

@property(nonatomic,assign) BOOL integratedResult;//sdk是否集成，可配置广告

//让子类重写!
//-(instancetype) init:(NSString*)platName
//              adType:(AggregationAdType) adType;

-(instancetype) init:(NSString*)platName;

//可以让子类重写，也可以不重写
-(void) getInfoPlistExceptionDomains;

//让子类调用
-(NSString*) getResult;

@end
