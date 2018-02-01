//
//  LingTuiInterstitialLingTuiAdBaseAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiInterstitialAdNetworkAdapter.h"

@interface LingTuiInterstitialLingTuiAdBaseAdNetworkAdapter : LingTuiInterstitialAdNetworkAdapter
-(instancetype)initWithLingTuiSplashDelegate:(id<LingTuiInterstitialDelegate>)delegate spalsh:(LingTuiInterstitial *)interstitial withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (void)loadAd;
- (void)presentAd;
- (void)stopBeingDelegate;
- (void)stopTimer;
- (void)loadAdTimeOut:(NSTimer*)theTimer;
- (void)stopAd;
- (void)setRotationID:(NSString *)rotationid;
- (void)setSidID:(NSString *)sid;
-(void)rotationLoadSuccess;
-(void)rotationLoadFail;
-(void)rotationPresentAd;
-(void)rotationClick;
- (NSTimeInterval)getOvertime;
@end
