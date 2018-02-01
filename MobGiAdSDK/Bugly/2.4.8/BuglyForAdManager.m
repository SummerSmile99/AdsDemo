//
//  BuglyForAdManager.m
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/20.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "BuglyForAdManager.h"
#import <Bugly/Bugly.h>
#import <AdsBasicFramework/MobGiAdsCommonUtility.h>

@interface BuglyForAdManager ()<BuglyDelegate>

@property(nonatomic,assign) BOOL isInitBuglyComplete;

@end


@implementation BuglyForAdManager

+ (instancetype)shareInstance
{
    static BuglyForAdManager *info = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        info = [[BuglyForAdManager alloc] init];
    });
    return info;
}

-(void) initBugly
{
    NSString* sdkVersion= [Bugly sdkVersion];
    if (![sdkVersion isEqualToString:@"2.4.8"]) {
        NSLog(@"CP使用了自己的Bugly版本库，广告调用Bugly无效！麻烦CP跟广告确认Bugly使用情况！！！");
        return;
    }
    BuglyConfig * config = [[BuglyConfig alloc] init];
    //config.debugMode = YES; //SDK Debug信息开关
    config.blockMonitorEnable = YES; //卡顿监控开关，默认关闭
    config.blockMonitorTimeout = 4;//卡顿监控判断间隔，单位为秒
    NSDictionary *infoDic=[[NSBundle mainBundle] infoDictionary];
    //NSString* identifer= [infoDic objectForKey:@"CFBundleIdentifier"];
    NSString* appDisplayName= [infoDic objectForKey:@"CFBundleDisplayName"];
    if (appDisplayName==nil||[appDisplayName isEqualToString:@""]||[appDisplayName isEqualToString:@" "]) {
        
        appDisplayName= [infoDic objectForKey:@"CFBundleName"];
    }
    config.channel = appDisplayName; //设置自定义渠道标识,这里是给SDK标示接入的CP游戏名称
    config.version=[MobGiAdsCommonUtility getMobGiAdSDKVersion];
    [Bugly startWithAppId:@"3c0a230090"
        developmentDevice:YES
                   config:config];
//    [Bugly startWithAppId:@"3c0a230090"
//                   config:config];
    NSLog(@"Bugly2.4.8适配器完成Bugly初始化!");
    self.isInitBuglyComplete=YES;
}

-(void) reportException:(NSException*)excp
{
    if (!self.isInitBuglyComplete) {
        return;
    }
    [Bugly reportException:excp];
}

-(void) reportError:(NSError*)err
{
    if (!self.isInitBuglyComplete) {
        return;
    }
    [Bugly reportError:err];
}

-(void) reportCustomErrorInfo:(NSString*)err
                    error:(NSString*)error

{
    NSArray* errorArray=[error componentsSeparatedByString:@"<!!!>"];
    
    if (errorArray!=nil&&errorArray.count>=2) {
        NSArray<NSString*>* callStack= [NSThread callStackSymbols];
        //    + (void)reportExceptionWithCategory:(NSUInteger)category name:(NSString *)aName reason:(NSString *)aReason callStack:(NSArray *)aStackArray extraInfo:(NSDictionary *)info terminateApp:(BOOL)terminate;
        NSDictionary* extraDic=[NSDictionary dictionaryWithObject:err forKey:@"err_key"];
        [Bugly reportExceptionWithCategory:3 name:errorArray[0] reason:errorArray[1] callStack:callStack extraInfo:err terminateApp:NO];
    }
    
}
@end
