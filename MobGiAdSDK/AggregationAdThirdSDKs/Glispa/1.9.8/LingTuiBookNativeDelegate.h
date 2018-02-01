//
//  LingTuiInterstitialDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiBookNative;
@protocol LingTuiBookNativeDelegate <NSObject>
@required
/*
 返回广告rootViewController
 */
- (UIViewController *)LingTuiViewNativeControllerForPresentingModalView;
@optional
- (void)LingTuiNativeLoadSuccess:(LingTuiBookNative *)native withObjectView:(UIView *)objView;
- (void)LingTuiNativeLoadAdFail:(NSError *)error;
-(void)LingTuiNativeClick;

@end
