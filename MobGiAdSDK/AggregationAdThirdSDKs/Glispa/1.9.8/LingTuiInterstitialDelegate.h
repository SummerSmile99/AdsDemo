//
//  LingTuiInterstitialDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiInterstitial;
@protocol LingTuiInterstitialDelegate <NSObject>

- (UIViewController *)LingTuiInterstitialAdViewControllerForPresentingModalView;
- (void)LingTuiInterstitialLoadSuccess:(LingTuiInterstitial *)interstitial;
- (void)LingTuiInterstitialLoadAdFail:(NSError *)error;
- (void)LingTuiInterstitialClick:(LingTuiInterstitial *)interstitial;
- (void)LingTuiInterstitialWillAppear:(LingTuiInterstitial *)interstitial;
- (void)LingTuiInterstitialDidAppear:(LingTuiInterstitial *)interstitial;
- (void)LingTuiInterstitialWillDisappear:(LingTuiInterstitial *)interstitial;
- (void)LingTuiInterstitialDidDisappear:(LingTuiInterstitial *)interstitial;
@end
