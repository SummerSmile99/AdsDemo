//
//  LingTuiSplashAdapterFactory.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/4.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiSplashAdNetworkAdapter;
@class LingTuiSplash;
@protocol LingTuiSplashDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiSplashAdapterFactory : NSObject
/*
 创建SDK Splash 适配器
 
 dict:ration信息
 
 delegate:代理实现对象
 
 bannercore:轮换控制对象
 */
- (LingTuiSplashAdNetworkAdapter *) createSDKSplashAdapterByConfig:(NSDictionary *)dict withdelegate:(id<LingTuiSplashDelegate>)delegate  withBrowserDelegate:(id<LingTuiBrowserDelegate>)browserDelegate withSplash:(LingTuiSplash *)splash;
@end
