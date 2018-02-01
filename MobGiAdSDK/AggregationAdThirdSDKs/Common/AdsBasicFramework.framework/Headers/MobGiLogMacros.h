//
//  MobGiLogMacros.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#define MOBGI_LOG_LEVEL_OFF     MobGiDDLogLevelOff
#define MOBGI_LOG_LEVEL_ERROR   MobGiDDLogLevelError
#define MOBGI_LOG_LEVEL_WARN    MobGiDDLogLevelWarning
#define MOBGI_LOG_LEVEL_INFO    MobGiDDLogLevelInfo
#define MOBGI_LOG_LEVEL_DEBUG   MobGiDDLogLevelDebug
#define MOBGI_LOG_LEVEL_VERBOSE MobGiDDLogLevelVerbose
#define MOBGI_LOG_LEVEL_ALL     MobGiDDLogLevelAll




#ifndef MOBGI_LOG_ASYNC_ENABLED
#define MOBGI_LOG_ASYNC_ENABLED YES
#endif


#ifndef MOBGI_LOG_LEVEL_DEF
#define MOBGI_LOG_LEVEL_DEF mobgiddLogLevel
#endif

//使用类.m使用方式
//static const int mobgiddLogLevel = MOBGI_LOG_LEVEL_VERBOSE;


#define MobGi_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
[MobGiLogSystem log : isAsynchronous                                     \
level : lvl                                                \
flag : flg                                                \
context : ctx                                                \
file : __FILE__                                           \
function : fnct                                               \
line : __LINE__                                           \
tag : atag                                               \
format : (frmt), ## __VA_ARGS__]



//#define MobGiDDLogInfo(frmt, ...)    MobGi_LOG_MACRO(MOBGI_LOG_ASYNC_ENABLED, MOBGI_LOG_LEVEL_DEF, MobGiDDLogFlagInfo,    0, @"Video", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//
//
//#define MobGiDDLogDebug(frmt, ...)    MobGi_LOG_MACRO(MOBGI_LOG_ASYNC_ENABLED, MOBGI_LOG_LEVEL_DEF, MobGiDDLogFlagDebug,    0, @"Splash", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//
//#define MobGiDDLogError(frmt, ...)    MobGi_LOG_MACRO(MOBGI_LOG_ASYNC_ENABLED, MOBGI_LOG_LEVEL_DEF, MobGiDDLogFlagError,    0, @"Interstitial",__PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//
//
//#define MobGiDDLogWarning(frmt, ...)    MobGi_LOG_MACRO(MOBGI_LOG_ASYNC_ENABLED, MOBGI_LOG_LEVEL_DEF, MobGiDDLogFlagWarning,    0, @"Native", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
//
//#define MobGiDDLogVerbose(frmt, ...)    MobGi_LOG_MACRO(MOBGI_LOG_ASYNC_ENABLED, MOBGI_LOG_LEVEL_DEF, MobGiDDLogFlagVerbose,    0, @"Custom",__PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

//#define MobGiDDLogError(frmt, ...)    MobGi_LOG_MACRO(NO, MOBGI_LOG_LEVEL_VERBOSE, MobGiDDLogFlagVerbose,    0, @"Error",__PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)













