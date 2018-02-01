//
//  LingTuiNativeAdapterFactory.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiBookNativeAdNetworkAdapter;
@class LingTuiBookNative;
@protocol LingTuiBookNativeDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiBookNativeAdapterFactory : NSObject
- (LingTuiBookNativeAdNetworkAdapter *) createSDKNativeAdapterByConfig:(NSDictionary *)dict withdelegate:(id<LingTuiBookNativeDelegate>)delegate
                                               withBrowserDelegate:(id<LingTuiBrowserDelegate>)browserDelegate       withNative:(LingTuiBookNative *)native withNativeTypeSize:(NSString *)typeSize;
@end
