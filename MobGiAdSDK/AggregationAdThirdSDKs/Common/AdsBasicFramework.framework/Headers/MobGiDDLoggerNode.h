//
//  MobGiDDLoggerNode.h
//  SDKCommonModule-CocoaLumberjack
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GlobalDefines.h"
#import "ProtocolDefines.h"


@interface MobGiDDLoggerNode : NSObject
{
    // Direct accessors to be used only for performance
@public
    id <MobGiDDLogger> _logger;
    MobGiDDLogLevel _level;
    dispatch_queue_t _loggerQueue;
}

@property (nonatomic, readonly) id <MobGiDDLogger> logger;
@property (nonatomic, readonly) MobGiDDLogLevel level;
@property (nonatomic, readonly) dispatch_queue_t loggerQueue;

+ (MobGiDDLoggerNode *)nodeWithLogger:(id <MobGiDDLogger>)logger
                     loggerQueue:(dispatch_queue_t)loggerQueue
                           level:(MobGiDDLogLevel)level;


@end
