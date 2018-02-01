//
//  LingTuiSplashDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/4.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiSplash;
@protocol LingTuiSplashDelegate <NSObject>

- (UIViewController *)LingTuiSplashAdViewControllerForPresentingModalView;
- (UIWindow *)getSplashShowWindow;

- (UIImage *)backgroundImage;

- (void)LingTuiSplashAdAllAdFail:(LingTuiSplash *)splashAd withError:(NSError *)err;

- (void)LingTuiSplashAdWillPresent:(LingTuiSplash *)splashAd;

- (void)LingTuiSplashAdDidPresent:(LingTuiSplash *)splashAd;

- (void)LingTuiSplashAdWillDismiss:(LingTuiSplash *)splashAd;

- (void)LingTuiSplashAdDidDismiss:(LingTuiSplash *)splashAd;

- (void)LingTuiSplashAdClick:(LingTuiSplash *)splashAd;
/*
 设置自售 交换 自动优化的广告位置
 // 如果不实现此回调 默认展示位置为（0.0 ， 0.0）
 */
- (CGPoint)LingTuiSplashAdOrigin;


@end
