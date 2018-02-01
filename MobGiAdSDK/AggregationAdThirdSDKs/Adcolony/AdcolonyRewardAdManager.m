//
//  AdcolonyRewardAdManager.m
//  TestVideoAdAggregation
//
//  Created by alan.xia on 2017/2/17.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import "AdcolonyRewardAdManager.h"

@implementation AdcolonyRewardAdManager

+ (instancetype)shareInstance
{
    static AdcolonyRewardAdManager *adcolonyRewardAdManager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        adcolonyRewardAdManager = [[AdcolonyRewardAdManager alloc] init];
    });
    return adcolonyRewardAdManager;
}

- (void)startWithAppId:(NSString *)appId zoneId:(NSString *)zoneId delegate:(id<AdcolonyRewardAdManagerDelegate>)delegate
{
    //NSLog(@"%s,appId:%@,zoneId:%@,delegate:%@",__PRETTY_FUNCTION__,appId,zoneId,delegate);
    self.zoneId = zoneId;
    self.adcolonyDelegate = delegate;
    dispatch_async(dispatch_get_main_queue(), ^{
        [AdColony configureWithAppID:appId zoneIDs:@[self.zoneId] options:nil completion:^(NSArray<AdColonyZone *> * _Nonnull zones) {
            //NSLog(@"%s,zones:%@",__PRETTY_FUNCTION__,zones);
            if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdInitSuccess)]) {
                [self.adcolonyDelegate adcolonyRewardAdInitSuccess];
            }
            AdColonyZone *zone = [zones firstObject];
            zone.reward = ^(BOOL success, NSString *name, int amount) {
                //NSLog(@"%s,success:%d,name:%@,amount:%d",__PRETTY_FUNCTION__,success,name,amount);
                if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdIsReceiveReward:)]) {
                    [self.adcolonyDelegate adcolonyRewardAdIsReceiveReward:success];
                }
            };
        }];
    });
}

-(void)requestRewardAd
{
    //NSLog(@"%s",__PRETTY_FUNCTION__);
    [AdColony requestInterstitialInZone:self.zoneId options:nil success:^(AdColonyInterstitial * _Nonnull ad) {
        //NSLog(@"%s,ad:%@",__PRETTY_FUNCTION__,ad);
        self.isRequestSuccess = YES;
        if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdDidFinishLoad)]) {
            [self.adcolonyDelegate adcolonyRewardAdDidFinishLoad];
        }
        ad.open = ^{
            //NSLog(@"%s,Adcolony  video ad is open",__PRETTY_FUNCTION__);
            if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdStartShowSuccess)]) {
                [self.adcolonyDelegate adcolonyRewardAdStartShowSuccess];
            }
        };
        ad.click = ^{
            //NSLog(@"%s,Adcolony  video ad is clicked",__PRETTY_FUNCTION__);
            if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdDidClicked)]) {
                [self.adcolonyDelegate adcolonyRewardAdDidClicked];
            }
        };
        ad.close = ^{
            //NSLog(@"%s,Adcolony  video ad is closed",__PRETTY_FUNCTION__);
            if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdDidClosed)]) {
                [self.adcolonyDelegate adcolonyRewardAdDidClosed];
            }
        };
        self.adVd = ad;
    } failure:^(AdColonyAdRequestError * _Nonnull error) {
        //NSLog(@"%s,error:%@",__PRETTY_FUNCTION__,error);
        self.isRequestSuccess = NO;
        if ([self.adcolonyDelegate respondsToSelector:@selector(adcolonyRewardAdfailedLoadWithError:)]) {
            [self.adcolonyDelegate adcolonyRewardAdfailedLoadWithError:error];
        }
    }];
}

-(BOOL)isRewardAdReady
{
    BOOL isReady;
    if (self.isRequestSuccess == YES) {
        BOOL iserpired = self.adVd.expired;
        isReady = !iserpired;
    }else{
        isReady = NO;
    }
    //NSLog(@"%s,isReady:%d",__PRETTY_FUNCTION__,isReady);
    return isReady;
}

- (void)showRewardAd:(UIViewController *)viewController
{
    [self.adVd showWithPresentingViewController:viewController];
}

@end
