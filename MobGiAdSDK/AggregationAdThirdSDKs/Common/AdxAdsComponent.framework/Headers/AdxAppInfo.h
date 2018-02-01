//
//  app.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>


@interface AdxAppInfo : JSONModel

@property(nonatomic,strong) NSString* appKey;
@property(nonatomic,strong) NSString* name;
@property(nonatomic,strong) NSString* bundle;
@property(nonatomic,strong) NSString* version;

@end
