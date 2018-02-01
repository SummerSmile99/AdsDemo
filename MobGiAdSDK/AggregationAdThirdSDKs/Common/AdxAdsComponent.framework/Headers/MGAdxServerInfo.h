//
//  MGAdxServerInfo.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/12/14.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <SDKCommonModule/SDKCommonModule.h>
#import <SDKCommonModule/JSONModel.h>

@interface MGAdxServerInfo : JSONModel

@property (nonatomic,strong) NSString *bidId;
@property (nonatomic,strong) NSString *configId;
@property (nonatomic,assign) int userType;

@end
