//
//  CustomAdsAdxDataManagerModule.h
//  CrossPromoteAds
//
//  Created by star.liao on 2017/5/29.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <AdxAdsComponent/AdxAdsComponent.h>
#import <AggregationAdsComponent/AggregationAdsConfigsGetManager.h>
#import <AdxAdsComponent/AdxAdItemConfigData.h>
#import <AdxAdsComponent/AdxAdsModule.h>
#import <AdxAdsComponent/AdxDataManager.h>
#import <AdxAdsComponent/AdGlobalConfig.h>
#import <SDKCommonModule/BasicUtilTools.h>
#import <AdxAdsComponent/AdxAdsConfigsGetManager.h>
#import <AdxAdsComponent/AdxAppblockList.h>
#import <AdsBasicFramework/AdLoggerManager.h>
#import <AggregationAdsComponent/AggregationAdKeySettings.h>


@protocol CustomAdConfigRequestDelegate <AdxConfigRequestDelegate>

@end

@interface CustomAdsAdxDataManagerModule : AdxAdsModule


@end
