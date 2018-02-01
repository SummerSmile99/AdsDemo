//
//  MGAdDSPResponseDataList.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>
#import "MGAdDSPResponseAdInfoList.h"

@protocol MGAdDSPResponseDataList

@end

@interface MGAdDSPResponseDataList : JSONModel

@property(nonatomic,strong) NSString *dspId;
@property(nonatomic,strong) NSString *bidId;
@property(strong,nonatomic) NSString *outBidId;
@property(nonatomic,assign) int adType;
@property(strong,nonatomic) NSArray<MGAdDSPResponseAdInfoList,Optional> *adInfo;

@end
