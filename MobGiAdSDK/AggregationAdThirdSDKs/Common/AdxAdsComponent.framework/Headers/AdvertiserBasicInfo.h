//
//  AdvertiserBasicInfo.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@protocol AdvertiserBasicInfo
@end

@interface AdvertiserBasicInfo : JSONModel

@property(nonatomic,strong) NSString* thirdPartyName;
@property(nonatomic,strong) NSString* thirdPartyAppkey;
@property(nonatomic,strong) NSString* thirdPartyAppsecret;

-(NSString*) objDescription;

@end
