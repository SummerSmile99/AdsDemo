//
//  MGAdDSPBasicInfo.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@protocol MGAdDSPBasicInfo

@end

@interface MGAdDSPBasicInfo : JSONModel

@property(nonatomic,assign) int chargeType;
@property(nonatomic,assign) int currency;
@property(nonatomic,strong) NSString *price;
@property(nonatomic,strong) NSString* adId;
@property(nonatomic,strong) NSString* adUnitId;
@property(nonatomic,strong) NSString* originalityId;
@property(nonatomic,strong) NSString* adName;
@property(nonatomic,strong) NSString* adDesc;
@property(nonatomic,strong) NSString* targetUrl;
@property(nonatomic,assign) int jumpType;
@property(nonatomic,strong) NSString* deepLink;
@property(nonatomic,strong) NSString* packageName;
@property(nonatomic,strong) NSString* iconUrl;

@end
