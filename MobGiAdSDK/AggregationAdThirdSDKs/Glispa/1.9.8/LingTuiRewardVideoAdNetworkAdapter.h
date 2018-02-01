//
//  LingTuiRewardVideoAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by sweetchao on 17/7/18.
//  Copyright © 2017年 LingTui. All rights reserved.
//

#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiRewardVideoDelegate.h"
#import "LingTuiRewardVideo.h"
#import "LingTuiAdNetworkType.h"
#import "LingTuiBrowserDelegate.h"
@interface LingTuiRewardVideoAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,assign) BOOL isAPI;
@property (nonatomic,strong) NSDictionary *network_key;
@property (nonatomic,strong) LingTuiRewardVideoAdNetworkAdapter *LingTuiRewardVideoLingTuiAdBaseAdNetworkAdapter; //竞价内部轮换 插屏适配器 v1.9.5
- (instancetype)initWithLingTuiRewardVideoDelegate:(id<LingTuiRewardVideoDelegate>)delegate_
                                       RewardVideo:(LingTuiRewardVideo *)RewardVideo
                          withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (LingTuiAdNetworkConfig *)getAdapterConfig;
- (LingTuiRewardVideoAdNetworkAdapter *)getLingTuiRewardVideoLingTuiAdBaseAdNetworkAdapter;
- (void)loadAd;
- (void)showRewardVideo;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (NSDictionary *)key;
- (UIViewController *)viewControllerForPresent;
- (BOOL)testMode;
- (void)browserWillAppear;
- (void)browserDidAppear;
- (void)browserWillDisappear;
- (void)browserDidDisappear;
-(NSTimeInterval)getReqTimeOut;
- (void)adRequestSuccess;
- (void)adRequestFail:(NSError *)error;
- (void)adClick;
- (void)RewardVideoDidPresent;
- (void)RewardVideoAdRewardVideo;
- (void)RewardVideoDidDismiss;
- (void)stopExpireTimer;
- (void)interExpire;
- (void)showRewardVideoFail;
@end
