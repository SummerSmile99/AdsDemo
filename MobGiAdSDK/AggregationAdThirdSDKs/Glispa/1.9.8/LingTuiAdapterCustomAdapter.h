//
//  LingTuiAdapterCustomAdapter.h
//  LingTuiLibrary
//
//  Created by mac on 16/5/22.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiBannerAdNetworkAdapter.h"
#import "LingTuiAdType.h"
@interface LingTuiAdapterCustomAdapter : LingTuiBannerAdNetworkAdapter
@property (nonatomic,assign) BOOL isStop;
#pragma mark custom overwrite method
+ (LingTuiAdNetworkType)networkType;
-(void)loadAd;
#pragma mark custom use method
+(void)registerClass:(id)clazz;
-(LingTuiAdType)customAdapterWillgetAdAndGetAdViewType;
- (NSDictionary *)key;

-(void)LingTuiBannerCustom:(LingTuiAdapterCustomAdapter *)adapter didReceiveAdView:(UIView *)adView;
-(void)LingTuiBannerCustom:(LingTuiAdapterCustomAdapter *)adapter didFailAd:(NSError *)error;
-(void)LingTuiBannerCustomClick:(LingTuiAdapterCustomAdapter *)adapter;
@end
