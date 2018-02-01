//
//  AdxAppblockList.h
//  AdxAdsComponent
//
//  Created by star.liao on 2017/4/18.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SDKCommonModule/JSONModel.h>

@protocol AdxAppblockList
@end

@interface AdxAppblockList : JSONModel

@property(nonatomic,strong) NSString* rate;
@property(nonatomic,assign) int showLimit;
@property(nonatomic,strong) NSString* blockIdName;
@property(nonatomic,strong) NSString* blockId;

-(NSString*) objDescription;

@end
