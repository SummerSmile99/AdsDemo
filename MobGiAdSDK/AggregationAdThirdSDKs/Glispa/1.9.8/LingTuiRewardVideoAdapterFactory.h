//
//  LingTuiRewardVideoAdapterFactory.h
//  LingTuiLibrary
//
//  Created by sweetchao on 17/7/18.
//  Copyright © 2017年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LingTuiRewardVideoAdNetworkAdapter;
@class LingTuiRewardVideo;
@protocol LingTuiRewardVideoDelegate;
@protocol LingTuiBrowserDelegate;
@interface LingTuiRewardVideoAdapterFactory : NSObject
- (LingTuiRewardVideoAdNetworkAdapter *) createSDKRewardVideoAdapterByConfig:(NSDictionary *)dict withdelegate:(id<LingTuiRewardVideoDelegate>)delegate
                                                           withBrowserDelegate:(id<LingTuiBrowserDelegate>)browserDelegate       withRewardVideo:(LingTuiRewardVideo *)RewardVideo;
@end
