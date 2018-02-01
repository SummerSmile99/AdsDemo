//
//  SKStoreProductManager.h
//  HouseAdClientComponent
//
//  Created by star.liao on 2016/11/22.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <StoreKit/StoreKit.h>
#import <CoreMedia/CoreMedia.h>

@protocol AdSKStoreProductVCDelegate <NSObject>

@required

- (void)productViewControllerDidFinish:(SKStoreProductViewController *)viewController;

@optional

-(void) productViewControllerLoading;

-(void) productViewControllerDisplayed;

-(void) productViewControllerDisplayTimeout;

@end

@interface AdSKStoreProductManager : NSObject<UIWebViewDelegate>

@property(nonatomic,weak) id<AdSKStoreProductVCDelegate> delegate;

//当调用方在调用navigateToSKStoreProductVC：targetUrl：方法的时候，会存在耗时，按照产品需求，在这期间用户是可以关闭当前广告的，通过设置该值，防止用户关闭广告后，还弹出应用商店内页
@property(nonatomic,assign) BOOL isNotShowAppstorePage;

//表示应用商店内页是否已经弹出
@property(nonatomic,assign) BOOL isDisplayed;

@property(nonatomic,assign) BOOL isNotDelay;

+(AdSKStoreProductManager *)sharedManager;

//耗时操作,弹出会有延时，接入方可以在delegate回调各方法里做额外逻辑
-(void) navigateToSKStoreProductVC:(UIViewController*)vc
                         targetUrl:(NSString*)urlStr;

-(void) navigateToSKStoreProductVC:(UIViewController*)vc
                         targetUrl:(NSString*)urlStr
                useRootVCDirection:(BOOL) useRootVCDirection;

@end
