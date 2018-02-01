//
//  LingTuiBannerNetworkRegistry.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/1.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiAdapterNetworkRegistry.h"
@interface LingTuiBannerNetworkRegistry : LingTuiAdapterNetworkRegistry
+ (LingTuiBannerNetworkRegistry *)sharedRegistry;

@end
