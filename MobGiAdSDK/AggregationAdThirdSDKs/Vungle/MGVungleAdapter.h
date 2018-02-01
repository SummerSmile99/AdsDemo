//
//  MGVungleAdapter.h
//  TestAdAggregation
//
//  Created by alan.xia on 2017/7/11.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol MGVungleAdapterDelegate <NSObject>

-(void)vungleInitializeFail:(NSString*)errorMsg;

-(void)vungleInitializeSuccess;

-(void)vungleLoadFail:(NSString*)errorMsg;

-(void)vunglePlayableChanged:(BOOL)isAdPlayable;

-(void)vungleShowFail:(NSString*)errorMsg;

-(void)vungleStartDisplay;

-(void)vungleDidReward;

-(void)vungleDidClick;

-(void)vungleDidClose;


@end

@interface MGVungleAdapter : NSObject

@property(nonatomic, strong)id<MGVungleAdapterDelegate>     vungleAdapterDelegate;

+(instancetype)shareInstance;

-(void)initSDK:(NSString *)appkey placementId:(NSString *)placementId;

-(void) setLogging:(NSNumber*)isLogging;

-(void)loadAd;

-(BOOL)getCacheStatus;

-(void)showAd:(UIViewController *)vc;

@end
