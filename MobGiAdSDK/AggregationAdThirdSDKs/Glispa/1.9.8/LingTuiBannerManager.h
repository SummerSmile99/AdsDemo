//
//  LingTuiBannerManager.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiAdType.h"
#import "LingTuiBrowserDelegate.h"
#import "LingTuiBannerViewDelegate.h"
@class LingTuiBannerAdNetworkAdapter;
typedef enum : NSUInteger {
    LingTuiBannerManagerLoadInit=1,
    LingTuiBannerManagerLoadGetConfig=2,
    LingTuiBannerManagerLoadRequesting=3,
    LingTuiBannerManagerLoadPause=4,
    LingTuiBannerManagerLoadDisplay = 5,
} LingTuiBannerManagerStatus;

@class LingTuiBannerView;
@interface LingTuiBannerManager : NSObject
@property (nonatomic,strong) LingTuiBannerAdNetworkAdapter *adapter;
- (instancetype)initWithBannerView:(LingTuiBannerView *)view withAdid:(NSString *)adid adType:(LingTuiAdType)type LingTuiViewDelegate:(id<LingTuiBannerViewDelegate>)delegate LingTuiBroswerDelegate:(id<LingTuiBrowserDelegate>)broswerDelegate withStopRefresh:(BOOL)isStopRefresh;
- (void)requestAd;
- (void)pauseloadAd;
- (void)continueloadAd;
- (void)destoryAd;
- (void)adapter:(LingTuiBannerAdNetworkAdapter *)adapter didGetAd:(NSString *)adType;

- (void)adapter:(LingTuiBannerAdNetworkAdapter *)adapter didReceiveAdView:(UIView *)view;

- (void)adapter:(LingTuiBannerAdNetworkAdapter *)adapter didReceiveAdView:(UIView *)view waitUntilDone:(BOOL)isWait;

- (void)adapter:(LingTuiBannerAdNetworkAdapter *)adapter didFailAd:(NSError *)error ;
/*
 第三方SDK点击回调
 SDK中提供点击回调可以调用这个方法 向灵推聚合发送点击统计
 */
- (void)adapterClick:(LingTuiBannerAdNetworkAdapter *)sdkAdapter;
- (LingTuiBannerManagerStatus)getLingTuiManagerStatus;
- (LingTuiAdType)getUserRequestBannerType;

- (void)LingTuipreclickhiddeclose:(BOOL)ishidden;
@end
