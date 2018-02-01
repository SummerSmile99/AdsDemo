//
//  LingTuiNativeLingTuiAdBaseAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiBookNativeAdNetworkAdapter.h"

@interface LingTuiBookNativeLingTuiAdBaseAdNetworkAdapter : LingTuiBookNativeAdNetworkAdapter
- (void)loadAd:(NSArray * )nativeArray;
- (void)setRotationID:(NSString *)rotationid;
- (void)setSidID:(NSString *)sid;
-(void)attachAdView:(UIView*)view;
-(void)LingTuiLoadSuccess:(UIView* )view;
-(void)LingTuiLoadError:(NSError* )error;

@end
