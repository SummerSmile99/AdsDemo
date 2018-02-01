//
//  LingTuiNativeAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiNativeDelegate.h"
#import "LingTuiNative.h"
#import "LingTuiAdNetworkType.h"
#import "LingTuiBrowserDelegate.h"
@class LingTuiNativeAdInfo;
@interface LingTuiNativeAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,assign) BOOL isAPI;

- (instancetype)initWithLingTuiNativeDelegate:(id<LingTuiNativeDelegate>)delegate
                                       native:(LingTuiNative *)native
                          withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
- (void)adRequestSuccess:(NSArray *)objArray;
- (void)adRequestFail:(NSError *)error;
- (BOOL)testMode;
- (NSDictionary *)key;
- (LingTuiAdNetworkConfig *)getAdapterConfig;
- (UIViewController *)viewControllerForPresent;
//展示广告
-(void)attachAdView:(UIView*)view nativeData:(LingTuiNativeAdInfo*)info;
//点击广告
-(void)clickAd:(LingTuiNativeAdInfo*)info;
//是否过期
-(BOOL)isAvailable:(LingTuiNativeAdInfo * )info;
- (void)browserWillAppear;
- (void)browserDidAppear;
- (void)browserWillDisappear;
- (void)browserDidDisappear;
-(NSTimeInterval)getReqTimeOut;
@end
