//
//  LingTuiInterstitialAdapterFactory.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiInterstitialAdNetworkAdapter;
@class LingTuiInterstitial;
@protocol LingTuiInterstitialDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiInterstitialAdapterFactory : NSObject
/*
 创建SDK Interstitial 适配器
 
 dict:ration信息
 
 delegate:代理实现对象
 
 bannercore:轮换控制对象
 */
- (LingTuiInterstitialAdNetworkAdapter *) createSDKInterstitialAdapterByConfig:(NSDictionary *)dict withdelegate:(id<LingTuiInterstitialDelegate>)delegate
                                                 withBrowserDelegate:(id<LingTuiBrowserDelegate>)browserDelegate       withInterstitial:(LingTuiInterstitial *)interstitial;
@end
