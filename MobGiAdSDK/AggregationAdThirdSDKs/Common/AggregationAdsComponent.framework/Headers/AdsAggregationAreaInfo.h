//
//  AggregationAdAreaInfo.h
//  TestVideoAdAggregation
//
//  Created by star.liao on 16/3/2.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AggregationAdvertiserInfo.h"

//聚合广告位信息
@interface AdsAggregationAreaInfo : NSObject<NSCoding>

@property(nonatomic,strong) NSString* blockIdName;
@property(nonatomic,strong) NSString* blockId;
@property(nonatomic,strong) NSString* rate;
@property(nonatomic,assign) int showLimit;
@property(nonatomic,strong) NSArray* configs;
@property(nonatomic,strong) NSArray* prioritConfig;

-(NSString*) objDescription;

@end
