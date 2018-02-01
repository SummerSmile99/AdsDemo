//
//  BuglyForAdManager.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/20.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BuglyForAdManager : NSObject

+ (instancetype)shareInstance;

-(void) initBugly;

-(void) reportException:(NSException*)excp;

-(void) reportError:(NSError*)err;

@end
