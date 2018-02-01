//
//  MobGiSDKVerifyModule.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/11/6.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 SDK方法调用，检测模块
 处理开发者传参失误，调用场景没有达到预期时候的逻辑处理
 */

extern NSString* const MOBGI_SDK_DEMO_APPKEY;

extern NSString* const MOBGI_SDK_DEMO_BUNDLEID;

@interface MobGiSDKVerifyModule : NSObject

/*
 判断是否可以启动广告初始化逻辑，
 1.appkey传值是否正常？
 2.跟Info.plist文件配置是否一致？
 3.使用DEMO的appkey是否包名正确？
 */
+(BOOL) isCanInitAdStyleSDK:(NSString*)appkey;

//这里处理crash,是因为部分开发者没有认真按照参数传递，直接crash,告知开发者问题的严重性，提起认知!!! 无奈的逻辑做法 = =
/*
 检查appkey传参是否有效，否则就crash
 1.数字，字母，汉字校验
 2.nil,@"",@" ",@"appkey"校验
 */
+(BOOL) isValidForAppkey:(NSString*)appkey;

/*
 检查blockid传参是否有效，否则就crash
 1.字母，汉字校验
 2.nil,@"",@" ",@"blockid"校验
 */
+(BOOL) isValidForBlockid:(NSString*)blockid;

@end
