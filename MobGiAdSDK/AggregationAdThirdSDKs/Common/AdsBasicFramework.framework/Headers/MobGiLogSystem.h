//
//  MobGiLogSystem.h
//  SDKCommonModule-CocoaLumberjack
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MobGiDDLogMessage.h"

#import "MobGiDDLoggerNode.h"

#import "GlobalDefines.h"

@interface MobGiLogSystem : NSObject

+ (dispatch_queue_t)loggingQueue;

+(BOOL) doesAppRunInBackground;

+ (void)addLogger:(id <MobGiDDLogger>)logger;

+ (void)removeLogger:(id <MobGiDDLogger>)logger;

- (void)removeLogger:(id <MobGiDDLogger>)logger;

+ (void)log:(BOOL)asynchronous
    message:(NSString *)message
      level:(MobGiDDLogLevel)level
       flag:(MobGiDDLogFlag)flag
    context:(NSInteger)context
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
        tag:(id)tag;

+ (void)log:(BOOL)asynchronous
      level:(MobGiDDLogLevel)level
       flag:(MobGiDDLogFlag)flag
    context:(NSInteger)context
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
        tag:(id)tag
     format:(NSString *)format
       args:(va_list)args;


+ (void)log:(BOOL)asynchronous
      level:(MobGiDDLogLevel)level
       flag:(MobGiDDLogFlag)flag
    context:(NSInteger)context
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
        tag:(id __nullable)tag
     format:(NSString *)format, ...;

+ (void)log:(BOOL)asynchronous
    message:(MobGiDDLogMessage *)logMessage;



@end
