//
//  LingTuiCustomInterstitialAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by mac on 16/5/22.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiInterstitialAdNetworkAdapter.h"

@interface LingTuiCustomInterstitialAdNetworkAdapter : LingTuiInterstitialAdNetworkAdapter
#pragma mark custom overwrite method

+ (LingTuiAdNetworkType)networkType;
-(void)loadAd;
- (void)presentAd;
- (BOOL)isReadyPresentInterstitial;
#pragma mark custom use method
+(void)registerClass:(id)clazz;
- (NSDictionary *)key;

-(void)LingTuiInterstitialLoadSuccessCustom:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter ;
-(void)LingTuiInterstitialCustom:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter didFailAd:(NSError *)error;
-(void)LingTuiInterstitialCustomClick:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter;
-(void)LingTuiInterstitialCustomwillShow:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter;
-(void)LingTuiInterstitialCustomDidShow:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter;
-(void)LingTuiInterstitialCustomwillDismiss:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter;
-(void)LingTuiInterstitialCustomDidDismiss:(LingTuiCustomInterstitialAdNetworkAdapter *)adapter;

@end
