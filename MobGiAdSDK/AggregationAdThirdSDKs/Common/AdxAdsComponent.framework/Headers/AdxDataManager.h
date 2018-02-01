//
//  AdxDataManager.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/4/1.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, AdxAdType) {
    ADX_AD=0,    //传默认值为0，通用广告类型
    ADX_VIDEO=1, //视频聚合
    ADX_INTERSTITIAL=2,//插屏聚合
    ADX_CUSTOMAD=3,//自定义
    ADX_SPLASH=4,//开屏
    ADX_NATIVE=5  //原生
};


@interface AdxDataManager : NSObject

@property(nonatomic,strong) NSString* appkey;

@property(nonatomic,strong) NSString* cid;

+(AdxDataManager *)shareInstance;

-(NSString*) generateToken;

@end
