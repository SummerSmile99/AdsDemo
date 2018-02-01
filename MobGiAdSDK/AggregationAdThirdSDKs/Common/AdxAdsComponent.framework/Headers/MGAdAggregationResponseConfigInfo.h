//
//  MGAdAggregationResponseConfigInfo.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/19.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "MGAdAggregationResponseDataList.h"
#import <SDKCommonModule/JSONModel.h>

//@protocol MGAdAggregationResponseConfigInfo
//
//@end

@interface MGAdAggregationResponseConfigInfo : JSONModel

@property(nonatomic,strong) NSString* ret;
@property(nonatomic,strong) NSString* msg;
@property(nonatomic,strong) MGAdAggregationResponseDataList<Optional> *data;
@property(nonatomic,strong) NSString<Optional> *devModeConfig;

-(NSString*) objDescription;

@end
