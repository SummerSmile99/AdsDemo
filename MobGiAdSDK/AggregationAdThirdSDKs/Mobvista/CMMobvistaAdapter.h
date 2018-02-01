//
//  CMMobvistaAdapter.h
//  TestInterstitialPolymerization
//
//  Created by alan.xia on 2017/5/23.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol CMMobvistaAdapterDelegate <NSObject>

- (void)nativeAdLoadSuccess:(NSDictionary *)dict;

- (void)nativeAdLoadFail:(NSString *)error;

- (void)nativeAdClick;

@end

@interface CMMobvistaAdapter : NSObject

@property (nonatomic,strong)id<CMMobvistaAdapterDelegate>  delegate;

@property (nonatomic,assign)BOOL  isNativeAd;

- (instancetype) init:(UIViewController *)vc
              blockId:(NSString *)blockId;

- (void)loadAd;

- (void)showAd:(UIView *)view;

- (void)closeAd;

@end
