//
//  MGAdDSPResponseAdInfoList.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>
#import "MGAdDSPBasicInfo.h"
#import "MGAdDSPEventTraking.h"

@protocol MGAdDSPResponseAdInfoList

@end

@interface MGAdDSPResponseAdInfoList : JSONModel

@property(nonatomic,strong) MGAdDSPBasicInfo<Optional> *basicInfo;
@property(nonatomic,strong) MGAdDSPEventTraking<Optional> *eventTraking;

@end
