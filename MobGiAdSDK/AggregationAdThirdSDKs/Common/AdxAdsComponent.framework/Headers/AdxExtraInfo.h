//
//  extra.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@interface AdxExtraInfo : JSONModel

@property(nonatomic,strong) NSString* adsList;
@property(nonatomic,strong) NSString* sdkVersion;
@property(nonatomic,assign) int isNewUser;

@end
