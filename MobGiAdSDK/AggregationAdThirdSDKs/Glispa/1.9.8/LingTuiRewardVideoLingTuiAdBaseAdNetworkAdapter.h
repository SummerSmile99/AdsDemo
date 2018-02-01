//
//  LingTuiRewardVideoLingTuiAdBaseAdNetworkAdapter.h
//  LingTuiLibrary
//
//  Created by sweetchao on 17/7/18.
//  Copyright © 2017年 LingTui. All rights reserved.
//

#import "LingTuiRewardVideoAdNetworkAdapter.h"

@interface LingTuiRewardVideoLingTuiAdBaseAdNetworkAdapter : LingTuiRewardVideoAdNetworkAdapter
-(instancetype)initWithLingTuiRewardVideoDelegate:(id<LingTuiRewardVideoDelegate>)delegate RewardVideo:(LingTuiRewardVideo *)RewardVideo withBroswerDelegate:(id<LingTuiBrowserDelegate>)browserDelegate networkConfig:(LingTuiAdNetworkConfig *)netConf;
- (void)setRotationID:(NSString *)rotationid;
- (void)setSidID:(NSString *)sid;
- (void)showRewardVideo;
@end
