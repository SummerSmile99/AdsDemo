//
//  LingTuiSSBannerAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import "LingTuiBannerLingTuiAdBaseNetworkAdapter.h"

@interface LingTuiSSBannerAdNetworkAdapter : LingTuiBannerLingTuiAdBaseNetworkAdapter
+ (LingTuiAdNetworkType)networkType;
-(void)rotationLoadSuccess:(id)object;
-(void)rotationLoadFail;
-(void)rotationClick;

@end
