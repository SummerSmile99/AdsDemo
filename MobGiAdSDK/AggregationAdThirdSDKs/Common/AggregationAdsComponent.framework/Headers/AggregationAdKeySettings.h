//
//  AggregationAdKeySettings.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/1/6.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AggregationAdConfigType) {
    PRIORITY=1,
    GENERAL=2
};


@interface AggregationAdKeySettings : NSObject

+(AggregationAdKeySettings *)shareInstance;

@property (nonatomic, strong) NSString                                            *appKey;

-(void)loadData:(NSString*) appKey;

-(void)saveShowLimit:(int) showLimit
             blockid:(NSString*)blockid;

-(void)refreshShowCount:(NSString*)blockid;

-(NSInteger) getShowCount:(NSString*)blockid;

-(NSInteger) getShowLimit:(NSString*)blockid;

-(void) updateDevMode:(BOOL)dev
           devModeKey:(NSString*) devModeKey;

-(BOOL) getDevMode:(NSString*) devModeKey;

-(BOOL)isNewUser;

-(void)refreshNetworkAdShowCount:(NSString*)blockid
                          adName:(NSString*)platName;

-(NSInteger) getNetworkAdShowCount:(NSString*)blockid
                            adName:(NSString*)platName;

-(void)savePlatformShowLimit:(int)showLimit
                platformName:(NSString*)platformName
                      adType:(AggregationAdType)adType
                  configType:(AggregationAdConfigType)configType;

-(void)refreshPlatformShowCount:(NSString*)platformName
                         adType:(AggregationAdType)adType
                     configType:(AggregationAdConfigType)configType;

-(NSInteger) getPlatformShowCount:(NSString*)platformName
                          adType:(AggregationAdType)adType
                       configType:(AggregationAdConfigType)configType;

-(NSInteger) getPlatformShowLimit:(NSString*)platformName
                           adType:(AggregationAdType)adType
                       configType:(AggregationAdConfigType)configType;


@end
