//
//  AdxRequestDataConfigInfoSenior.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/6/27.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AdxAdsComponent/AdxAdsComponent.h>
#import <SDKCommonModule/JSONModel.h>
#import <AdxAdsComponent/AdxImpInfo.h>
#import <AdxAdsComponent/AdxAppInfo.h>
#import <AdxAdsComponent/AdxDeviceInfo.h>
#import <AdxAdsComponent/AdxUserInfo.h>
#import <AdxAdsComponent/AdxExtraInfo.h>

@interface AdxRequestDataConfigInfoSenior : JSONModel

@property(nonatomic,assign) int providerId;
@property(nonatomic,assign) int adType;
@property(nonatomic,assign) int isTest;
@property(nonatomic,strong) NSMutableArray<AdxImpInfo>* imp;
@property(nonatomic,strong) AdxAppInfo*app;
@property(nonatomic,strong) AdxDeviceInfo*device;
@property(nonatomic,strong) AdxUserInfo*user;
@property(nonatomic,strong) AdxExtraInfo<Optional>*extra;
@property(nonatomic,assign) NSString* sdkVersion;

@end
