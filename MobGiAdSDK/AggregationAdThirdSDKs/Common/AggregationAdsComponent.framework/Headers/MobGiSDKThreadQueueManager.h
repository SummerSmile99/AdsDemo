//
//  MobGiSDKThreadQueueManager.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/11/15.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MobGiSDKThreadQueueManager : NSObject

+ (dispatch_queue_t)adLoadingQueue;

+ (dispatch_queue_t)adReporingTaskQueue;

@end
