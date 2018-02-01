//
//  LingTuiBannerAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/1.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiBannerViewDelegate.h"
#import "LingTuiBannerManager.h"
#import "LingTuiBrowserDelegate.h"
#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiAdNetworkConfig.h"

@interface LingTuiBannerAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,strong) NSDictionary *network_key; //竞价内部轮换 sdk平台key v1.9.5
@property (nonatomic,strong) LingTuiBannerAdNetworkAdapter *LingTuiBannerLingTuiAdBaseNetworkAdapter;//竞价适配器对象，内部轮换SDK使用v1.9.5

@property (nonatomic,assign) BOOL isAPI;
/*
 横幅广告适配器
 */
- (instancetype)initWithLingTuiBannerDelegate:(id<LingTuiBannerViewDelegate>)delegate
                withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                         bannercore:(LingTuiBannerManager *)bannercore
                      networkConfig:(LingTuiAdNetworkConfig *)netConf;

- (LingTuiBannerAdNetworkAdapter *)getLingTuiBannerLingTuiAdBaseNetworkAdapter;
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
// 横幅适配器是否支持点击回调
- (BOOL)isSupportClickDelegate;
- (NSDictionary *)key;
- (UIViewController *)viewControllerForPresent;
- (void)adFail:(NSError *)error;
- (void)adSuccesswithView:(UIView *)adView;
- (void)adClick;
- (void)browserWillAppear;
- (void)browserDidAppear;
- (void)browserWillDisappear;
- (void)browserDidDisappear;
- (BOOL)testMode;
- (LingTuiAdNetworkConfig *)getAdapterConfig;
- (LingTuiAdType)getBannerUserRequestType;
-(NSTimeInterval)getReqTimeOut;
@end

