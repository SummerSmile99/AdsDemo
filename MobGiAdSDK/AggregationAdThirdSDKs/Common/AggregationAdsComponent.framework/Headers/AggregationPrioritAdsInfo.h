//
//  AggregationPrioritAdsInfo.h
//  AggregationAdsComponent
//
//  Created by alan.xia on 2017/9/5.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AggregationPrioritAdsInfo : NSObject

@property(nonatomic,strong) NSString* thirdPartyBlockId;
@property(nonatomic,strong) NSString* thirdPartyName;
@property(nonatomic,strong) NSString* thirdPartyAppkey;
@property(nonatomic,strong) NSString* thirdPartyAppsecret;
@property(nonatomic,assign) int index;
@property(nonatomic,assign) int showNumber;
@property(nonatomic,strong) id extraInfos;

-(NSString*) objDescription;

@end
