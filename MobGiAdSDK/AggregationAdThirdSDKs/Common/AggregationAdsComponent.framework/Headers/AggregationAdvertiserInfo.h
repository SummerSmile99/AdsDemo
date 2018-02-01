//
//  AdvertiserInfo.h
//  TestVideoAdAggregation
//
//  Created by star.liao on 16/3/2.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AggregationAdsComponent/NSObject+Description.h>

@interface AggregationAdvertiserInfo : NSObject<NSCoding>

@property(nonatomic,strong) NSString* thirdPartyBlockId;
@property(nonatomic,strong) NSString* thirdPartyName;
@property(nonatomic,strong) NSString* thirdPartyAppkey;
@property(nonatomic,strong) NSString* thirdPartyAppsecret;
@property(nonatomic,strong) NSString* rate;
@property(nonatomic,assign) int showNumber;
@property(nonatomic,strong) id extraInfos;

-(NSString*) objDescription;

@end
