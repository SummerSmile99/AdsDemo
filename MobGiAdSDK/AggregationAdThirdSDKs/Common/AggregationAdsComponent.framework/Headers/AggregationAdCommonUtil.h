//
//  AggregationAdCommonUtil.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2016/11/10.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AggregationAdCommonUtil : NSObject

+(NSString*) appVersion;

+(NSString*) CFBundleVersion;

+(NSString*) CFBundleIdentifier;

+(NSString*) getNetType;

+(NSString*) getCarrierName;

+(int) getCarrierIntName;

+(NSString*) udid;

+(NSString*) uuid;

+(NSString*) idfv;

+(NSString*) idfa;

+(NSString*) lang;

+ (NSString*)deviceVersion;

+(NSString*) ledouUUID;

@end
