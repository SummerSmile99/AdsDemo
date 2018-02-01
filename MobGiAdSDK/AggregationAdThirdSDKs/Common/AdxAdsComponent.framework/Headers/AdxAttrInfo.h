//
//  attr.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/3/31.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@interface AdxAttrInfo : JSONModel

@property(nonatomic,assign) int w;
@property(nonatomic,assign) int h;
@property(nonatomic,assign) int pos;

@end
