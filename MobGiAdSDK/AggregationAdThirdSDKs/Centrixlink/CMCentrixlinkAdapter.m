//
//  CMCentrixlinkAdapter.m
//  TestVideoAdAggregation
//
//  Created by alan.xia on 2017/4/19.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import "CMCentrixlinkAdapter.h"


@interface CMCentrixlinkAdapter ()<CentrixLinkADDelegate>

@end

@implementation CMCentrixlinkAdapter

+(instancetype)shareInstance
{
    static CMCentrixlinkAdapter *centrixlinkAdapter;
    static dispatch_once_t oneceToken;
    dispatch_once(&oneceToken, ^{
        centrixlinkAdapter = [[CMCentrixlinkAdapter alloc]init];
    });
    return centrixlinkAdapter;
}

+(NSString *)getVersion
{
    return [CentrixlinkAD SDKVersion];
}

-(void)initSDK:(NSString *)appkey appSecret:(NSString *)appSecret
{
    //NSLog(@"%s,video appkey:%@,appSecret:%@",__PRETTY_FUNCTION__,appkey,appSecret);
    NSError *initError;
    [[CentrixlinkAD sharedInstance] startWithAppID:appkey AppSecretKey:appSecret error:&initError];
    if (initError) {
        if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkInitFail:)]) {
            [self.centrixlinkAdapterDelegate centrixlinkInitFail:[initError localizedDescription]];
        }
    }else{
        if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkInitSuccess)]) {
            [self.centrixlinkAdapterDelegate centrixlinkInitSuccess];
        }
    }
    [[CentrixlinkAD sharedInstance] setDelegate:self];
}

-(void)initSplashSDK:(NSString *)appkey appSecret:(NSString *)appSecret
{
    //NSLog(@"%s,splash appkey:%@,appSecret:%@",__PRETTY_FUNCTION__,appkey,appSecret);
    NSError *initError;
    [[CentrixlinkAD sharedInstance] startWithAppID:appkey AppSecretKey:appSecret error:&initError];
    if (initError) {
        if (self.centrixlinkSplashAdapterDelegate != nil && [self.centrixlinkSplashAdapterDelegate respondsToSelector:@selector(centrixlinkSplashInitFail:)]) {
            [self.centrixlinkSplashAdapterDelegate centrixlinkSplashInitFail:[initError localizedDescription]];
        }
    }else{
        if (self.centrixlinkSplashAdapterDelegate != nil && [self.centrixlinkSplashAdapterDelegate respondsToSelector:@selector(centrixlinkSplashInitSuccess)]) {
            [self.centrixlinkSplashAdapterDelegate centrixlinkSplashInitSuccess];
        }
    }
}

-(void)openLogMode
{
    [[CentrixlinkAD sharedInstance] setDebugEnable:YES];
    [[CentrixlinkAD sharedInstance] setDebugCallBack:^(NSString *message, CLSLogLevel level) {
        //NSLog(@"%s,message:%@",__PRETTY_FUNCTION__,message);
    }];
}

-(BOOL)isReady
{
    CentrixlinkAD *manager = [CentrixlinkAD sharedInstance];
    if (manager.hasPreloadAD) {
        return YES;
    }else{
        return NO;
    }
}

-(void)showAd:(UIViewController *)vc
{
    //NSLog(@"%s,vc:%@",__PRETTY_FUNCTION__,vc);
    
    CentrixlinkAD *manager = [CentrixlinkAD sharedInstance];
    NSError *showError;
    
    //插屏显示，如全屏显示则NO
    BOOL isInterstitialShow = NO;
    
    //是否只显示预加载广告,如果允许显示实时广告则为NO
    BOOL isOnlyPreloadADShow = YES;
    
    //是否自动关闭EndCard，防止用户跳出后游戏自动恢复状态
    BOOL isAutoCloseEndCard = NO;
    //,
    NSDictionary *dic = @{ShowADOptionKeyRESIZEVIDEOAD:[NSNumber numberWithBool:isInterstitialShow],ShowADOptionKeyOnlyPreload:[NSNumber numberWithBool:isOnlyPreloadADShow],CentrixlinkPlayAdOptionKeyIECAutoClose:[NSNumber numberWithBool:isAutoCloseEndCard]};
    
    [manager playAD:vc options:dic error:&showError];
    
    if (showError) {
        //NSLog(@"%s,showError:%@",__PRETTY_FUNCTION__,showError);
        if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkShowFail:)]) {
            [self.centrixlinkAdapterDelegate centrixlinkShowFail:[showError localizedDescription]];
        }
    }
}

#pragma mark - CentrixLinkADDelegate

-(void)centrixLinkHasPreloadAD:(BOOL)hasPreload
{
    if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkPreloadStatus:)]) {
        [self.centrixlinkAdapterDelegate centrixlinkPreloadStatus:hasPreload];
    }
}

- (void)centrixLinkVideoADShowFail:(NSError *)error
{
    if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkShowFail:)]) {
        [self.centrixlinkAdapterDelegate centrixlinkShowFail:[error localizedDescription]];
    }
}

- (void)centrixLinkVideoADWillShow:(NSDictionary *)ADInfo
{
    
}

- (void)centrixLinkVideoADDidShow:(NSDictionary *)ADInfo
{
    if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkStartShow)]) {
        [self.centrixlinkAdapterDelegate centrixlinkStartShow];
    }
}

- (void)centrixLinkVideoADAction:(NSDictionary *)ADInfo
{
    
}

- (void)centrixLinkVideoADClose:(NSDictionary *)ADInfo
{
    NSNumber *isPlayFinish= [ADInfo objectForKey:ADInfoKEYADPlayStatus];
    BOOL isReward = [isPlayFinish boolValue];
    if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkIsReward:)]) {
        [self.centrixlinkAdapterDelegate centrixlinkIsReward:isReward];
    }
    if ([[ADInfo objectForKey:ADInfoKEYIsClick] boolValue]) {
        if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkDidClick)]) {
            [self.centrixlinkAdapterDelegate centrixlinkDidClick];
        }
    }
    if (self.centrixlinkAdapterDelegate != nil && [self.centrixlinkAdapterDelegate respondsToSelector:@selector(centrixlinkDidClose)]) {
        [self.centrixlinkAdapterDelegate centrixlinkDidClose];
    }
}


@end
