//
//  MGAdAggregationResponseNoConfig.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/19.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <SDKCommonModule/SDKCommonModule.h>
#import <SDKCommonModule/JSONModel.h>

//@protocol MGAdAggregationResponseNoConfig
//
//@end

@interface MGAdAggregationResponseNoConfig : JSONModel

@property(nonatomic,strong) NSString* ret;
@property(nonatomic,strong) NSString* msg;
@property(strong,nonatomic) NSObject<Optional> *data;
@property(nonatomic,strong) NSString<Optional>* devModeConfig;

@end
