//
//  LingTuiNativeAdapterFactory.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiNativeAdNetworkAdapter;
@class LingTuiNative;
@protocol LingTuiNativeDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiNativeAdapterFactory : NSObject
- (LingTuiNativeAdNetworkAdapter *) createSDKNativeAdapterByConfig:(NSDictionary *)dict withdelegate:(id<LingTuiNativeDelegate>)delegate
                                                           withBrowserDelegate:(id<LingTuiBrowserDelegate>)browserDelegate       withNative:(LingTuiNative *)native;
@end
