//
//  ConfigResponseInfo.h
//  TestVideoAdAggregation
//
//  Created by star.liao on 16/3/2.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdsAggregationAreaInfo.h"


@interface AggregationAdsConfigResponseInfo : NSObject

@property(nonatomic,assign) BOOL success;
@property(nonatomic,strong) NSString* msg;
@property(strong,nonatomic) NSArray*data;


@end
