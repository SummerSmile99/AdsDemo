//
//  AdGlobalConfig.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@interface AdGlobalConfig : JSONModel

@property(nonatomic,strong) NSString* lifeCycle;
@property(nonatomic,assign) int supportNetworkType;

-(NSString*) objDescription;

@end
