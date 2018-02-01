//
//  AdxAggregationBlockidConfig.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>


@protocol AdxAggregationBlockidAdConfig
@end

@interface AdxAggregationBlockidAdConfig : JSONModel

@property(nonatomic,strong) NSString* thirdPartyBlockId;//下发整型int,这里会自动转成字符串，类型为NSTaggedPointerString
@property(nonatomic,strong) NSString* thirdPartyName;
@property(nonatomic,strong) NSString* rate;
@property(nonatomic,assign) int showNumber;
@property(nonatomic,strong) NSDictionary<Optional> *extraInfos;

-(NSString*) objDescription;

@end
