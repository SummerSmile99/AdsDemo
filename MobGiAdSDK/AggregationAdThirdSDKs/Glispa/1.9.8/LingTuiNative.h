//
//  LingTuiNative.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/24.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiNativeDelegate.h"
#import "LingTuiBrowserDelegate.h"

@class LingTuiNativeAdInfo;
@class LingTuiNativeAdNetworkAdapter;
@interface LingTuiNative : NSObject
@property (nonatomic,weak) id<LingTuiNativeDelegate> delegate;
@property (nonatomic,weak) id<LingTuiBrowserDelegate> broswerdelegate;
+ (instancetype)initWithAdid:(NSString *)adid withDelegate:(id<LingTuiNativeDelegate>) delegate withBroswerDelegate:(id<LingTuiBrowserDelegate>) broswerDelegate;
-(void)load;
- (void)nativeAdLoadSuccess:(LingTuiNativeAdNetworkAdapter *)adapter withObjectArray:(NSArray *)objArray;
- (void)nativeAdLoadFail:(LingTuiNativeAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
-(void)sendImpStatistics:(LingTuiNativeAdNetworkAdapter *)adapter withShowView:(UIView *)view withInfo:(LingTuiNativeAdInfo * )info;
-(void)sendClickStatistics:(LingTuiNativeAdNetworkAdapter *)adapter withInfo:(LingTuiNativeAdInfo *)info;
@end
