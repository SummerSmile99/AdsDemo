//
//  LingTuiInterstitial.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LingTuiInterstitialDelegate.h"
#import "LingTuiBrowserDelegate.h"
@class LingTuiInterstitialAdNetworkAdapter;

@interface LingTuiInterstitial : NSObject
@property (nonatomic,weak) id<LingTuiInterstitialDelegate> delegate;
@property (nonatomic,weak) id<LingTuiBrowserDelegate> broswerdelegate;
+ (instancetype)initWithAdid:(NSString *)adid withDelegate:(id<LingTuiInterstitialDelegate>) delegate withBroswerDelegate:(id<LingTuiBrowserDelegate>) broswerDelegate withStopRefresh:(BOOL)isStopRefresh;
- (void)reqInterstitialAd;
- (void)cancelInterstitialAd;
- (void)stoploadInterstitialAd;

- (void)interstitialAdLoadFail:(LingTuiInterstitialAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
- (void)interstitialAdLoadSuccess:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdWillPresent:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdDidPresent:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdWillDismiss:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdDidDismiss:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdPresentFail:(LingTuiInterstitialAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
- (void)interstitialAdTimeout:(LingTuiInterstitialAdNetworkAdapter *)adapter;
- (void)interstitialAdClick:(LingTuiInterstitialAdNetworkAdapter *)adapter;

@end
