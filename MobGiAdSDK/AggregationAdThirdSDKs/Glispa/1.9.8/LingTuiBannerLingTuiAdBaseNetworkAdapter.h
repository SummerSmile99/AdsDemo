//
//  LingTuiBannerLingTuiAdBaseNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiBannerAdNetworkAdapter.h"

@interface LingTuiBannerLingTuiAdBaseNetworkAdapter : LingTuiBannerAdNetworkAdapter

/*
 横幅广告适配器
 */
- (instancetype)initWithLingTuiBannerDelegate:(id<LingTuiBannerViewDelegate>)delegate
                          withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate
                                   bannercore:(LingTuiBannerManager *)bannercore
                                networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
- (void)setRotationID:(NSString *)rotationid;
- (void)setSidID:(NSString *)sid;
-(void)rotationLoadSuccess:(id)object;
-(void)rotationLoadFail;
-(void)rotationClick;
-(LingTuiAdType)rolatationAdType;
 //2017 1-7 改变竞价中的点击
-(void)rotationClickinsdk;
@end
