//
//  MGAdmobNativeAdapter.h
//  MGAdmobAdapter
//
//  Created by alan.xia on 2018/1/11.
//  Copyright © 2018年 alan.xia. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MGAdmobNativeAdapterDelegate <NSObject>

- (void)nativeAdLoadSuccess:(NSDictionary*)dict;

- (void)nativeAdLoadFail:(NSString*)errorMsg;

- (void)nativeAdClick;

@end

@interface MGAdmobNativeAdapter : NSObject

@property (nonatomic,weak) id<MGAdmobNativeAdapterDelegate>   delegate;

/* topLeft  topRight  bottomLeft  bottomRight  */
@property (nonatomic,copy) NSString    *logoLocation;

- (instancetype) initNativeAd:(UIViewController *)rootVC
                      blockId:(NSString *)blockId;

- (void)loadNativeAd;

- (void)showNativeAd:(UIView *)view;

@end
