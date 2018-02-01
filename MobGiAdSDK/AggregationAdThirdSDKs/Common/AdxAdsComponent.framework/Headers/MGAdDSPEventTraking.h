//
//  MGAdDSPEventTraking.h
//  AdxAdsComponent
//
//  Created by alan.xia on 2017/10/24.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SDKCommonModule/JSONModel.h>

@protocol MGAdDSPEventTraking

@end

@interface MGAdDSPEventTraking : JSONModel

@property(nonatomic,strong) NSArray<Optional>* reportDataClickUrl;
@property(nonatomic,strong) NSArray<Optional>* reportDataShowUrl;
@property(nonatomic,strong) NSArray<Optional>* reportDataHtmlCloseUrl;
@property(nonatomic,strong) NSArray<Optional>* reportDataVideoEndUrl;

@end
