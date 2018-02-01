//
//  LingTuiBannerViewDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiBannerView;
@protocol LingTuiBannerViewDelegate <NSObject>
@required
/*
    返回广告rootViewController
 */
- (UIViewController *)LingTuiViewControllerForPresentingModalView;

@optional

- (void)LingTuiWillReviceAd:(LingTuiBannerView *)LingTuiView;
/**
 * You can get notified when the user receive the ad
 广告接收成功回调
 */
- (void)LingTuiDidReceiveAd:(LingTuiBannerView *)LingTuiView;
/**
 * You can get notified when the user failed receive the ad
 广告接收失败回调
 */
- (void)LingTuiDidFailToReceiveAd:(LingTuiBannerView *)LingTuiView didFailWithError:(NSError *)error;
/**
 * 点击广告回调
 */
- (void)LingTuiClickAd:(LingTuiBannerView *)LingTuiView;

- (void)LingTuiClose;
@end
