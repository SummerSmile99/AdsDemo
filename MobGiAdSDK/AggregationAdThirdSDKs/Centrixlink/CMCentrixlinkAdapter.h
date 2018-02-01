//
//  CMCentrixlinkAdapter.h
//  TestVideoAdAggregation
//
//  Created by alan.xia on 2017/4/19.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Centrixlink/Centrixlink.h>
#import <Centrixlink/CentrixlinkConst.h>

@protocol CMCentrixlinkSplashAdapterDelegate <NSObject>

-(void)centrixlinkSplashInitFail:(NSString *)error;

-(void)centrixlinkSplashInitSuccess;

@optional

@end

@protocol CMCentrixlinkAdapterDelegate <NSObject>

@optional

-(void)centrixlinkInitFail:(NSString *)error;

-(void)centrixlinkInitSuccess;

-(void)centrixlinkPreloadStatus:(BOOL)status;

-(void)centrixlinkShowFail:(NSString *)error;

-(void)centrixlinkStartShow;

-(void)centrixlinkDidClick;

-(void)centrixlinkIsReward:(BOOL)isReward;

-(void)centrixlinkDidCloseError:(NSString *)error;

-(void)centrixlinkDidClose;


@end

@interface CMCentrixlinkAdapter : NSObject

@property(nonatomic, strong)id<CMCentrixlinkAdapterDelegate>        centrixlinkAdapterDelegate;

@property(nonatomic, strong)id<CMCentrixlinkSplashAdapterDelegate>     centrixlinkSplashAdapterDelegate;

+(instancetype)shareInstance;

+(NSString *)getVersion;

-(void)initSDK:(NSString *)appkey appSecret:(NSString *)appSecret;

-(void)initSplashSDK:(NSString *)appkey appSecret:(NSString *)appSecret;

-(void)openLogMode;

-(BOOL)isReady;

-(void)showAd:(UIViewController *)vc;

@end
