//
//  AdLoggerManager.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/4.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

//#define MobGiDefaultDDLogDebug(frmt, ...)  MobGi_LOG_MACRO(YES, MobGiDDLogLevelAll, MobGiDDLogFlagVerbose,    0, @"MobGi", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

//调试
#define  MobGiAssertNil(a,b,...)NSAssert((a)==nil,(b))

#define  MobGiAssertNotNil(a,b,...)NSAssert((a)!=nil,(b))

#define  MobGiAssertTrue(a,b,...)NSAssert((a),(b))

#define MobGiAssertEqualsTrue(a,b,c,...) NSAssert(([NSString stringWithFormat:@"%d",a]==[NSString stringWithFormat:@"%d",b]),(c))

#define MobGiAssertEquals(a,b,c,...)NSAssert((a==b),(c))

#define  MobGiAssertNotEquals(a,b,c,...)NSAssert((a!=b),(c))

//默认日志
#define DEFAULT_LOG(frmt, ...) NSLog(@"[MobGi] " frmt, ##__VA_ARGS__);



#define AD_SDK_VERSION @"2.8.0"

#import <Foundation/Foundation.h>

@interface AdLoggerManager : NSObject

@end
