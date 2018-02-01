//
//  Device.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@interface AdxDeviceInfo : JSONModel

@property(nonatomic,strong) NSString* ua;
@property(nonatomic,strong) NSString* ip;
@property(nonatomic,strong) NSString* brand;

@property(nonatomic,strong) NSString* model;
@property(nonatomic,assign) int platform;
@property(nonatomic,assign) NSString* version;

@property(nonatomic,strong) NSString* resolution;
@property(nonatomic,assign) int operator;
@property(nonatomic,assign) int net;

@property(nonatomic,strong) NSString* deviceId;
@property(nonatomic,assign) int screenDirection;
@property(nonatomic,assign) double screenSize;


@end
