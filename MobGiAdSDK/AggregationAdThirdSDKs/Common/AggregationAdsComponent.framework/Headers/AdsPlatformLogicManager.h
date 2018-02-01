//
//  AdPlatGetManager.h
//  TestAdCampaignPolymerization
//
//  Created by star.liao on 16/3/23.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AggregationAdsLogic.h"


@protocol AdsPlatformLogicDelegate <NSObject>

@required

-(AggregationAdsLogic*) generateAdStyleLogic;

@end

typedef void(^PlatBlock)(int);

@interface AdsPlatformLogicManager : NSObject

@property(nonatomic,weak) id<AdsPlatformLogicDelegate> delegate;

@property(nonatomic,strong) AggregationAdsLogic* platInfoDes;

- (instancetype)init:(AggregationAdType)adType
          sdkVersion:(NSString*)sdkVersion;

-(void) initAdTypeLogic;

/**
 *  根据广告商集成情况，概率控制，确定要使用的广告商
 *
 *  @param blockid 广告位ID
 *  @param info    广告位信息数组
 *
 *  @return 需要的广告商类型
 */
-(int) getAdNetworkType:(NSString*) blockid
        configs:(NSArray*) info;

/**
 *  根据广告商集成情况，概率控制，确定要使用的广告商
 *
 *  @param platInfoArray 广告商信息数组
 *
 *  @return 需要的广告商类型
 */
-(int)getAdsPlatType:(NSArray*) platInfoArray;
@end
