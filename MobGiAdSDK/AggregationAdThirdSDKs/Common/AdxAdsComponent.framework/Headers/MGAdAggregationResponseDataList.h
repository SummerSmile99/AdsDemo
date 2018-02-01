//
//  MGAdAggregationResponseDataList.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/19.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>
#import "AdGlobalConfig.h"
#import "AdvertiserBasicInfo.h"
#import "AdxAggregationBlockidConfig.h"
#import "AdxAppblockList.h"
#import "MGAdxServerInfo.h"

@interface MGAdAggregationResponseDataList : JSONModel

@property(nonatomic,strong) AdGlobalConfig* globalConfig;
@property(nonatomic,strong) NSArray<AdvertiserBasicInfo>* thirdPartyAppInfo;
@property(nonatomic,strong) NSArray<AdxAggregationBlockidConfig>* thirdBlockList;
@property(nonatomic,strong) NSArray<AdxAppblockList>* appBlockIdList;


-(NSString*) objDescription;


//2.7.0增加
@property (nonatomic,strong) MGAdxServerInfo<Optional> *serverInfo;


@end
