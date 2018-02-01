//
//  AdNavigationLogicModule.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/5/27.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdBasicCustomWebView.h"
#import "AdSKStoreProductManager.h"

/**
 
 管理广告(开屏，视频，插页，交叉推广，原生广告)的跳转逻辑模块
 
 - returns: <#return value description#>
 */
@interface AdNavigationLogicModule : NSObject

@property (nonatomic, strong) NSString                        *jumpUrl;
@property (nonatomic,strong) NSString                        *deepLink;
@property(nonatomic,strong) UIViewController* parentVC;
@property(nonatomic,strong) id<AdSKStoreProductVCDelegate> skDelegate;
@property(nonatomic,strong) AdBasicCustomWebView*      customWebViewClass;

@property(nonatomic,assign) BOOL isInvokedeepLink;

@property(nonatomic,assign) BOOL isHouseAdDSP;

-(instancetype) initWithJumpUrl:(NSString*) jumpUrl;
-(instancetype) initWithJumpUrl:(NSString *)jumpUrl
                       deepLink:(NSString*)deepLink;

-(BOOL)jumpCustomBrower:(UIViewController *)vc
               delegate:(id<AdBasicCustomWebViewDelegate>)delegate;

-(BOOL)jumpAppstorePage:(UIViewController*)vc
                delegate:(id<AdSKStoreProductVCDelegate>)delegate
      useRootVCDirection:(BOOL)useRootVCDirection;

-(BOOL)jumpAppstore;

/**
 *  是否启用deepLink跳转
 *
 *  @return <#return value description#>
 */
-(BOOL) isEnableDeepLinkNavigate:(NSString*)deepLink;

@end
