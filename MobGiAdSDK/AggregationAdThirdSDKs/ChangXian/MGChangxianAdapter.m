//
//  MGChangxianAdapter.m
//  TestAdxAdsProject
//
//  Created by alan.xia on 2017/12/7.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "MGChangxianAdapter.h"
#import <DianyunIOSSdk/DianyunIOSSdk.h>

@implementation MGChangxianAdapter

+(NSNumber *)getPlayTime
{
    double playTime = [[DianyunSdk instance] getPlayDuration];
    //NSLog(@"%s,playTime : %f",__PRETTY_FUNCTION__,playTime);
    return [NSNumber numberWithDouble:playTime];
}

@end
