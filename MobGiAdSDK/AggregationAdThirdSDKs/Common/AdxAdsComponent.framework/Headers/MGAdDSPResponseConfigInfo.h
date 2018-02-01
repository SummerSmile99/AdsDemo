//
//  MGAdDSPResponseConfigInfo.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>
#import "MGAdDSPResponseDataList.h"

@protocol MGAdDSPResponseConfigInfo

@end

@interface MGAdDSPResponseConfigInfo : JSONModel

@property(nonatomic,strong) NSString* ret;
@property(nonatomic,strong) NSString* msg;
@property(strong,nonatomic) MGAdDSPResponseDataList<Optional> *data;

@end
