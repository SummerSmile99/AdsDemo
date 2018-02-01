//
//  LingTuiSplash.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/4.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiSplashAdNetworkAdapter;
@protocol LingTuiSplashDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiSplash : NSObject

- (instancetype)initWithSplashAdid:(NSString *)adid LingTuiSplashDelegate:(id<LingTuiSplashDelegate>)delegate LingTuiBroswerDelegate:(id<LingTuiBrowserDelegate>)broswerdelegate withshowView:(UIView *)showView;

- (void)requestSplashAd;


- (void)adapterDidSuccess:(LingTuiSplashAdNetworkAdapter *)adapter;


- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter didFailAd:(NSError *)error ;

- (void)adapterClick:(LingTuiSplashAdNetworkAdapter *)sdkAdapter;

- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter WillPresent:(id)splashAd;

- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter DidPresent:(id)splashAd;

- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter WillDismiss:(id)splashAd;

- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter didDismiss:(id)splashAd;

- (void)adapter:(LingTuiSplashAdNetworkAdapter *)adapter click:(id)splashAd;

-(NSTimeInterval)getSplashShowTime;
@end
