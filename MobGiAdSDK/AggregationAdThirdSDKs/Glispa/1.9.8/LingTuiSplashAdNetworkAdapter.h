//
//  LingTuiSplashAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/4.
//  Copyright © 2016年 LingTui. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "LingTuiAdNetworkAdapter.h"
#import "LingTuiSplashDelegate.h"
#import "LingTuiBrowserDelegate.h"

#import "LingTuiAdNetworkType.h"
@class LingTuiSplash;
@interface LingTuiSplashAdNetworkAdapter : LingTuiAdNetworkAdapter
@property (nonatomic,assign) BOOL isAPI;
/*
 开屏广告适配器
 */
- (instancetype)initWithLingTuiSplashDelegate:(id<LingTuiSplashDelegate>)delegate
                              broswerDelegate:(id<LingTuiBrowserDelegate>)broswerdelegate
                                   spalsh:(LingTuiSplash *)splash
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;

- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
// 横幅适配器是否支持点击回调
- (BOOL)isSupportClickDelegate;
- (NSDictionary *)key;
- (UIViewController *)viewControllerForPresent;
- (UIWindow *)getWindow;
- (void)adFail:(NSError *)error;
- (void)adSuccess;
- (void)adClick;
- (void)splashWillPresent;
- (void)splashDidPresent;
- (void)splashWillDismiss;
- (void)splashDidDismiss;
- (BOOL)testMode;
- (LingTuiAdNetworkConfig *)getAdapterConfig;
- (CGPoint)codeSplashOrigin;
- (void)browserWillAppear;
- (void)browserDidAppear;
- (void)browserWillDisappear;
- (void)browserDidDisappear;
-(NSTimeInterval)getReqTimeOut;
-(NSTimeInterval)getSplashShowTime;
-(void)splashTimeOut;
@end
