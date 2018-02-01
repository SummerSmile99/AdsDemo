//
//  MGVungleAdapter.m
//  TestAdAggregation
//
//  Created by alan.xia on 2017/7/11.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "MGVungleAdapter.h"
#import <VungleSDK/VungleSDK.h>

@interface MGVungleAdapter ()<VungleSDKDelegate,VungleSDKLogger>

@property(nonatomic,strong)NSString  *appkey;
@property(nonatomic,strong)NSString  *placementId;

@end

@implementation MGVungleAdapter

+(instancetype)shareInstance
{
    static MGVungleAdapter *vungleAdapter;
    static dispatch_once_t oneceToken;
    dispatch_once(&oneceToken, ^{
        vungleAdapter = [[MGVungleAdapter alloc]init];
    });
    return vungleAdapter;
}

-(void)initSDK:(NSString *)appkey placementId:(NSString *)placementId
{
    //NSLog(@"%s,appkey:%@,placementId:%@",__PRETTY_FUNCTION__,appkey,placementId);
    self.appkey = appkey;
    self.placementId = placementId;
    NSError *error;
    NSArray *placementIdArray = [NSArray arrayWithObjects:self.placementId, nil];
    [[VungleSDK sharedSDK] setDelegate:self];
    BOOL startStatus = [[VungleSDK sharedSDK]startWithAppId:self.appkey placements:placementIdArray error:&error];
    if (!startStatus) {
        if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleInitializeFail:)]) {
            [self.vungleAdapterDelegate vungleInitializeFail:[error localizedDescription]];
        }
    }
}

-(BOOL)getCacheStatus
{
    return [[VungleSDK sharedSDK] isAdCachedForPlacementID:self.placementId];
}

-(void)loadAd
{
    //NSLog(@"%s",__PRETTY_FUNCTION__);
    NSError *error;
    BOOL loadStatus = [[VungleSDK sharedSDK]loadPlacementWithID:self.placementId error:&error];
    if (!loadStatus) {
        if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleLoadFail:)]) {
            [self.vungleAdapterDelegate vungleLoadFail:[error localizedDescription]];
        }
    }
}

-(void)showAd:(UIViewController *)vc
{
    //NSLog(@"%s,vc:%@",__PRETTY_FUNCTION__,vc);
    NSError *error;
    BOOL playStatus = [[VungleSDK sharedSDK]playAd:vc options:nil placementID:self.placementId error:&error];
    if (!playStatus) {
        if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleShowFail:)]) {
            [self.vungleAdapterDelegate vungleShowFail:[error localizedDescription]];
        }
    }
}

-(void) setLogging:(NSNumber*)isLogging
{
    BOOL isEnabledLogging=[isLogging boolValue];
    [[VungleSDK sharedSDK] setLoggingEnabled:isEnabledLogging];
//    if (isEnabledLogging) {
//        [[VungleSDK sharedSDK] attachLogger:self];
//    }
//    else
//    {
//        [[VungleSDK sharedSDK] detachLogger:self];
//    }
}

#pragma mark -
#pragma mark VungleSDKLogger

- (void)vungleSDKLog:(NSString*)message
{
    
}

#pragma mark -
#pragma mark VungleSDKDelegate

- (void)vungleSDKDidInitialize
{
    if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleInitializeSuccess)]) {
        [self.vungleAdapterDelegate vungleInitializeSuccess];
    }
}

- (void)vungleSDKFailedToInitializeWithError:(NSError *)error
{
    if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleInitializeFail:)]) {
        [self.vungleAdapterDelegate vungleInitializeFail:[error localizedDescription]];
    }
}

- (void)vungleAdPlayabilityUpdate:(BOOL)isAdPlayable placementID:(nullable NSString *)placementID
{
    if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vunglePlayableChanged:)]) {
        [self.vungleAdapterDelegate vunglePlayableChanged:isAdPlayable];
    }
}

- (void)vungleWillShowAdForPlacementID:(nullable NSString *)placementID
{
    if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleStartDisplay)]) {
        [self.vungleAdapterDelegate vungleStartDisplay];
    }
}

- (void)vungleWillCloseAdWithViewInfo:(nonnull VungleViewInfo *)info placementID:(nonnull NSString *)placementID
{
    //NSLog(@"%s,info:%@,placementID:%@",__PRETTY_FUNCTION__,info,placementID);
    BOOL click = [info.didDownload boolValue];
    if (click) {
        if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleDidClick)]) {
            [self.vungleAdapterDelegate vungleDidClick];
        }
    }
    BOOL complete = [info.completedView boolValue];
    if (complete) {
        if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleDidReward)]) {
            [self.vungleAdapterDelegate vungleDidReward];
        }
    }
    if (self.vungleAdapterDelegate != nil && [self.vungleAdapterDelegate respondsToSelector:@selector(vungleDidClose)]) {
        [self.vungleAdapterDelegate vungleDidClose];
    }
}


@end
