//
//  NativeToPassJsDataModel.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/11/30.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/SDKUtilManager.h>

/*
 该类用来ios端传递数据js端的数据Moddel,后续可以动态添加属性
 */
@interface NativeToPassJsDataModel : SDKUtilManager

@property (nonatomic,strong) NSString *appkey;

@property (nonatomic,strong) NSMutableDictionary *infoPlistDic;

@property (nonatomic,strong) NSString *extraInfos;

+(NativeToPassJsDataModel *)sharedManager;

@end
