//
//  LingTuiNativeAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiBookNativeDelegate.h"
#import "LingTuiBookNative.h"
#import "LingTuiAdNetworkType.h"
#import "LingTuiBrowserDelegate.h"
@class LingTuiNativeAdInfo;
@interface LingTuiBookNativeAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,assign) BOOL isAPI;

- (instancetype)initWithLingTuiNativeDelegate:(id<LingTuiBookNativeDelegate>)delegate
                                       native:(LingTuiBookNative *)native
                          withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
- (void)adRequestSuccess:(UIView *)objView;
- (void)adRequestFail:(NSError *)error;
- (BOOL)testMode;
- (NSDictionary *)key;
- (LingTuiAdNetworkConfig *)getAdapterConfig;
- (UIViewController *)viewControllerForPresent;

//展示广告
-(void)attachAdView:(UIView*)view;
//点击广告
-(void)clickAd;
//是否过期
-(BOOL)isAvailable;
-(NSTimeInterval)getReqTimeOut;
@end
