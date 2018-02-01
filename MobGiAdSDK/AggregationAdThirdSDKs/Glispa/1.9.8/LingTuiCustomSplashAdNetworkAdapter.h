//
//  LingTuiCustomSplashAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by mac on 16/5/22.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiSplashAdNetworkAdapter.h"
#import "LingTuiAdType.h"
@interface LingTuiCustomSplashAdNetworkAdapter : LingTuiSplashAdNetworkAdapter
@property (nonatomic,assign) BOOL isStop;
#pragma mark custom overwrite method
+ (LingTuiAdNetworkType)networkType;
-(void)loadAd;
#pragma mark custom use method
+(void)registerClass:(id)clazz;
- (NSDictionary *)key;

-(void)LingTuiSplashCustom:(LingTuiCustomSplashAdNetworkAdapter *)adapter didReceiveAdView:(UIView *)adView;
-(void)LingTuiSplashCustom:(LingTuiCustomSplashAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
-(void)LingTuiSplashCustomClick:(LingTuiCustomSplashAdNetworkAdapter *)adapter;
-(void)LingTuiSplashDismiss:(LingTuiCustomSplashAdNetworkAdapter *)adapter;
@end
