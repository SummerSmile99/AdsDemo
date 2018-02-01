//
//  AdxAggregationBlockidConfig.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>
#import "AdxAggregationBlockidAdConfig.h"
#import "AdxAggregationBlockidAdPriorityConfig.h"

@protocol AdxAggregationBlockidConfig
@end

@interface AdxAggregationBlockidConfig : JSONModel

@property(nonatomic,strong) NSString* blockIdName;
@property(nonatomic,strong) NSString* blockId;
@property(nonatomic,strong) NSArray<AdxAggregationBlockidAdConfig>* generalConfigs;
@property(nonatomic,strong) NSArray<AdxAggregationBlockidAdPriorityConfig>* prioritConfig;

-(NSString*) objDescription;

@end
