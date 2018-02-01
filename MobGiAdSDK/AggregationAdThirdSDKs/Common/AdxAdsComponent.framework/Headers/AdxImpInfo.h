//
//  imp.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdxAttrInfo.h"
#import <SDKCommonModule/JSONModel.h>


@protocol AdxImpInfo
@end

@interface AdxImpInfo : JSONModel

@property(nonatomic,strong) NSString* blockId;
@property(nonatomic,strong) AdxAttrInfo* attr;
@property(nonatomic,assign) double bidfloor;

@end
