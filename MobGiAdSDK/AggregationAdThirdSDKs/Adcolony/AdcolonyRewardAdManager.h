//
//  AdcolonyRewardAdManager.h
//  TestVideoAdAggregation
//
//  Created by alan.xia on 2017/2/17.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdColony/AdColony.h>

@protocol AdcolonyRewardAdManagerDelegate <NSObject>

-(void)adcolonyRewardAdInitSuccess;
-(void)adcolonyRewardAdDidFinishLoad;
-(void)adcolonyRewardAdfailedLoadWithError:(NSError *)error;
-(void)adcolonyRewardAdStartShowSuccess;
-(void)adcolonyRewardAdIsReceiveReward:(BOOL)isReceiveReward;
-(void)adcolonyRewardAdDidClicked;
-(void)adcolonyRewardAdDidClosed;

@end

@interface AdcolonyRewardAdManager : NSObject

@property(nonatomic, strong)id<AdcolonyRewardAdManagerDelegate>    adcolonyDelegate;

@property(nonatomic, strong)NSString    *zoneId;

@property (strong,nonatomic)AdColonyInterstitial   *adVd;

@property(nonatomic,assign)BOOL    isRequestSuccess;

+ (instancetype)shareInstance;

- (void)startWithAppId:(NSString *)appId zoneId:(NSString *)zoneId delegate:(id<AdcolonyRewardAdManagerDelegate>)delegate;

- (void)requestRewardAd;

- (BOOL)isRewardAdReady;

- (void)showRewardAd:(UIViewController *)viewController;

@end
