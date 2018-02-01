//
//  MobGiDDAbstractLogger.h
//  SDKCommonModule-CocoaLumberjack
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ProtocolDefines.h"

@interface MobGiDDAbstractLogger : NSObject
{
    // Direct accessors to be used only for performance
@public
    id <MobGiDDLogFormatter> _logFormatter;
    dispatch_queue_t _loggerQueue;
}

@property (nonatomic, strong, nullable) id <MobGiDDLogFormatter> logFormatter;
@property (nonatomic, strong) dispatch_queue_t loggerQueue;

// For thread-safety assertions

/**
 *  Return YES if the current logger uses a global queue for logging
 */
@property (nonatomic, readonly, getter=isOnGlobalLoggingQueue)  BOOL onGlobalLoggingQueue;

/**
 *  Return YES if the current logger uses the internal designated queue for logging
 */
@property (nonatomic, readonly, getter=isOnInternalLoggerQueue) BOOL onInternalLoggerQueue;


@end
