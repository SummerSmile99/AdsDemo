//
//  LingTuiRewardVideo.h
//  LingTuiLibrary
//
//  Created by sweetchao on 17/7/17.
//  Copyright © 2017年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiRewardVideoDelegate.h"
#import "LingTuiBrowserDelegate.h"
@interface LingTuiRewardVideo : NSObject
@property (nonatomic,weak) id<LingTuiRewardVideoDelegate> delegate;
@property (nonatomic,weak) id<LingTuiBrowserDelegate> broswerdelegate;
+ (instancetype)initWithAdid:(NSString *)adid withDelegate:(id<LingTuiRewardVideoDelegate>) delegate withBroswerDelegate:(id<LingTuiBrowserDelegate>) broswerDelegate;
-(void)showRewardVideo;
- (void)stoploadRewardVideoAd;
-(int)getG3;
-(void)clearVideoCache;

-(void)adapterVideoRewardVideo:(NSDictionary *)RewardVideoDic;
-(void)adapterRewardVideoFail;
-(void)adapterRewardVideoReadyed;
-(void)adapterRewardVideoShowSuccess;
-(void)adapterRewardVideoClick;
-(void)adapterRewardVideoClose;
- (void)RewardVideoAdTimeout;
- (void)RewardVideoAdShowFail;
@end
