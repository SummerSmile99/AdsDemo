//
//  AdReportResponseData.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDKCommonModule+Namespace.h"

#import <SDKCommonModule/SDKCommonModule.h>
#import <SDKCommonModule/JSONModel.h>

@interface ADXAdReportResponseData : JSONModel

@property(nonatomic,assign) BOOL ret;
@property(nonatomic,strong) NSString* msg;
@property(strong,nonatomic) NSArray<Optional> *data;

@end
