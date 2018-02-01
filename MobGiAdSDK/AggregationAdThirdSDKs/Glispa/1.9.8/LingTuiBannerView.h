//
//  LingTuiBannerView.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LingTuiAdType.h"
#import "LingTuiBrowserDelegate.h"
#import "LingTuiBannerViewDelegate.h"
typedef enum : NSUInteger {
    LingTuiBannerTopMiddle=1,
    LingTuiBannerMiddleMiddle=2,
    LingTuiBannerMiddleBottom=3,
    LingTuiBannerLeftTop=4,
    LingTuiBannerLeftMiddle=5,
    LingTuiBannerLeftBottom=6,
    LingTuiBannerRightTop=7,
    LingTuiBannerRightMiddle=8,
    LingTuiBannerRightBottom=9,
    LingTuiBannerCustomer = 100
} LingTuiBannerMiddlePosition;


@interface LingTuiBannerView : UIView
@property (nonatomic,weak) id<LingTuiBannerViewDelegate> delegate;

/*
 ak:开发appkey
 type:请求广告类型
 delegate:代理对象
 AdPointType:广告位置
 自动轮换
 */
-(instancetype)initWithFrame:(CGRect)frame Withadid:(NSString *)adid adType:(LingTuiAdType)type LingTuiViewDelegate:(id<LingTuiBannerViewDelegate>)delegate LingTuiBroswerDelegate:(id<LingTuiBrowserDelegate>)broswerDelegate withStopRefresh:(BOOL)isStopRefresh;
// 广告居中
- (void)setLingTuiBannerPosition:(LingTuiBannerMiddlePosition)bannerposition;
- (void)destoryBanner;
@end
