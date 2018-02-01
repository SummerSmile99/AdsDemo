//
//  BuglyForAdManager.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/20.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  针对广告的Bugly监控调用器， 可外放给CP调用，或者内部调用
 */
@interface BuglyAdInvoker : NSObject

+ (instancetype)shareInstance;
/**
 *  开启Bugly监控！
 */
-(void) initBugly;

-(void) reportException:(NSException*)excp;

-(void) reportError:(NSError*)err;

-(void) reportCustomErrorInfo:(NSString*)err
                    errorName:(NSString*)errorName
                  errorReason:(NSString*)errorReason;

@end
