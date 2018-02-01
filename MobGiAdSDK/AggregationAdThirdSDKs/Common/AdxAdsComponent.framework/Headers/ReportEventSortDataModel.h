//
//  ReportEventSortDataModel.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/11/9.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReportEventSortDataModel : NSObject

@property (atomic,assign) long long presentEventNum;

@property (atomic,assign) long long clickEventNum;

@property (atomic,assign) long long getCacheReadyEventNum;

@end
