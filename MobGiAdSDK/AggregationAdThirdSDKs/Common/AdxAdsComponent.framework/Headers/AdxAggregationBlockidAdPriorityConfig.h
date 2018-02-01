//
//  AdxAggregationBlockidAdPriorityConfig.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/9/5.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <SDKCommonModule/SDKCommonModule.h>
#import <SDKCommonModule/JSONModel.h>

@protocol AdxAggregationBlockidAdPriorityConfig
@end


@interface AdxAggregationBlockidAdPriorityConfig : JSONModel

@property(nonatomic,strong) NSString* thirdPartyBlockId;
@property(nonatomic,strong) NSString* thirdPartyName;
@property(nonatomic,assign) int index;
@property(nonatomic,assign) int showNumber;
@property(nonatomic,strong) NSDictionary<Optional> *extraInfos;

-(NSString*) objDescription;

@end
