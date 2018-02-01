//
//  LingTuiAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiAdNetworkConfig;

#define TimeOut 8

@interface LingTuiAdNetworkAdapter : NSObject
- (void)loadAd;
- (void)stopBeingDelegate;
- (void)stopAd;
- (BOOL)isSupportLocation;

@end
