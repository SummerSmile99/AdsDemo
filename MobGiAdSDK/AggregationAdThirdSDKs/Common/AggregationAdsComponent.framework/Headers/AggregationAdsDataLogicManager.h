//
//  AggregationAdsDataLogicManager.h
//  AggregationAdsComponent
//
//  Created by alan.xia on 2017/9/6.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AggregationPrioritAdsInfo;
@class AggregationAdvertiserInfo;

@interface AggregationAdsDataLogicManager : NSObject

+(AggregationAdsDataLogicManager *)sharedInstance;

-(NSArray*) getPrioritArray:(NSArray*)prioritArray
                     adType:(AggregationAdType)adType;

-(NSArray*) getGeneralArray:(NSArray*)generalArray
                     adType:(AggregationAdType)adType;

-(AggregationPrioritAdsInfo*) getPrioritPlatInfo:(NSArray*) dataArray
                                         blockId:(NSString*) blockId
                                        platType:(NSString*) platInfoName;

-(AggregationAdvertiserInfo*) getGeneralPlatInfo:(NSArray*) dataArray
                                         blockId:(NSString*) blockId
                                        platType:(NSString*) platInfoName;

-(AggregationPrioritAdsInfo*) getPrioritPlatInfo:(NSArray*) dataArray
                                        platType:(NSString*) platInfoName;

-(AggregationAdvertiserInfo*) getGeneralPlatInfo:(NSArray*) dataArray
                                        platType:(NSString*) platInfoName;

-(NSArray*) getPrioritInfo:(NSArray*)dataArray
                   blockId:(NSString*)blockId
                    adType:(AggregationAdType)adType;

-(NSArray*) getAllPrioritInfo:(NSArray*)dataArray
                   blockId:(NSString*)blockId
                    adType:(AggregationAdType)adType;

-(NSArray*) getGeneralInfo:(NSArray*)dataArray
                   blockId:(NSString*)blockId
                    adType:(AggregationAdType)adType;

-(NSArray*) getAllGeneralInfo:(NSArray*)dataArray
                   blockId:(NSString*)blockId
                    adType:(AggregationAdType)adType;

-(BOOL) isHasTheBlockId:(NSArray *)dataArray  blockId:(NSString*) blockId;

-(BOOL) isHasRate:(NSArray*)dataArray  blockId:(NSString*)blockId;

-(BOOL) getProbabilityRange:(NSArray *)dataArray blockId:(NSString*)blockId;

-(void) savePlatformShowLimit:(NSArray*)dataArray adType:(AggregationAdType)adType;

-(BOOL) isLimitAdWithBlockId:(NSString *)blockid;

@end
