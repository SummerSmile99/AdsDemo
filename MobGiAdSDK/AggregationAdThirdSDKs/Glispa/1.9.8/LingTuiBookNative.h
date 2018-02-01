//
//  LingTuiNative.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/24.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiBookNativeDelegate.h"
#import "LingTuiBrowserDelegate.h"
@class LingTuiNativeAdInfo;
@class LingTuiBookNativeAdNetworkAdapter;
@interface LingTuiBookNative : NSObject
@property (nonatomic,weak) id<LingTuiBookNativeDelegate> delegate;
@property (nonatomic,weak) id<LingTuiBrowserDelegate> broswerdelegate;
+ (instancetype)initWithAdid:(NSString *)adid withDelegate:(id<LingTuiBookNativeDelegate>) delegate withBroswerDelegate:(id<LingTuiBrowserDelegate>) broswerDelegate;
-(void)loadWithSize:(CGSize)size;
-(void)attachAdView:(UIView*)view;
-(BOOL)isAvailable;

- (void)nativeAdLoadSuccess:(LingTuiBookNativeAdNetworkAdapter *)adapter withObjectView:(UIView *)objView;
- (void)nativeAdLoadFail:(LingTuiBookNativeAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
-(void)sendImpStatistics:(LingTuiBookNativeAdNetworkAdapter *)adapter withShowView:(UIView *)view;
-(void)sendClickStatistics:(LingTuiBookNativeAdNetworkAdapter *)adapter;
@end
