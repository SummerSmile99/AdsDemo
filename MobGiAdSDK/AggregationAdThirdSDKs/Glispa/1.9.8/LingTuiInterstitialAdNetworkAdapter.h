//
//  LingTuiInterstitialAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiInterstitialDelegate.h"
#import "LingTuiInterstitial.h"
#import "LingTuiAdNetworkType.h"
#import "LingTuiBrowserDelegate.h"
@interface LingTuiInterstitialAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,assign) BOOL isAPI;
@property (nonatomic,strong) NSDictionary *network_key; //竞价内部轮换 sdk平台key v1.9.5
@property (nonatomic,strong) LingTuiInterstitialAdNetworkAdapter *LingTuiInterstitialLingTuiAdBaseAdNetworkAdapter; //竞价内部轮换 插屏适配器 v1.9.5

/*
 插屏广告适配器
 */
- (instancetype)initWithLingTuiSplashDelegate:(id<LingTuiInterstitialDelegate>)delegate
                                       spalsh:(LingTuiInterstitial *)interstitial
                          withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;

- (LingTuiInterstitialAdNetworkAdapter *)getLingTuiInterstitialLingTuiAdBaseAdNetworkAdapter;
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
- (NSTimeInterval)getOvertime;
- (void)presentAd;
- (BOOL)isReadyPresentInterstitial;
- (NSDictionary *)key;
- (UIViewController *)viewControllerForPresent;
- (void)adRequestSuccess;
- (void)adRequestFail:(NSError *)error;
- (void)adClick;
- (void)interstitialWillPresent;
- (void)interstitialDidPresent;
- (void)interstitialWillDismiss;
- (void)interstitialDidDismiss;
- (void)interstitialPresentFail:(NSError *)error;;
- (BOOL)testMode;
- (LingTuiAdNetworkConfig *)getAdapterConfig;

- (void)presentInterstitialAndStopTimer;

- (void)browserWillAppear;
- (void)browserDidAppear;
- (void)browserWillDisappear;
- (void)browserDidDisappear;
-(NSTimeInterval)getReqTimeOut;
@end
