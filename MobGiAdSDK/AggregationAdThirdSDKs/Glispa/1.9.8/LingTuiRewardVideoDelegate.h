//
//  LingTuiRewardVideoDelegate.h
//  LingTuiLibrary
//
//  Created by sweetchao on 17/7/17.
//  Copyright © 2017年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiRewardVideo;
@protocol LingTuiRewardVideoDelegate <NSObject>
- (UIViewController *)LingTuiRewardVideoAdViewControllerForPresentingModalView;
-(void)LingTuiVideoRewardVideo:(NSDictionary *)RewardVideoDic;
-(void)LingTuiRewardVideoFail;
-(void)LingTuiRewardVideoReadyed;
-(void)LingTuiRewardVideoShowSuccess;
-(void)LingTuiRewardVideoClick;
-(void)LingTuiRewardVideoClose;
@end
