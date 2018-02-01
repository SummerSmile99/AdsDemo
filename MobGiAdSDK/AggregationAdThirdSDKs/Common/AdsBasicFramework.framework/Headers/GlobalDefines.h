//
//  GlobalDefines.h
//  SDKCommonModule
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//



#pragma mark var

//标示MobGi广告日志执行的全局队列
static void *const MobGiGlobalLoggingQueueIdentityKey = (void *)&MobGiGlobalLoggingQueueIdentityKey;

static dispatch_queue_t _mobgiLoggingQueue;

static dispatch_group_t _mobgiloggingGroup;

static dispatch_semaphore_t _mobgiQueueSemaphore;

static NSUInteger _numProcessors;


#pragma mark enum

typedef NS_OPTIONS(NSInteger, MobGiDDLogMessageOptions){
    /**
     *  Use this to use a copy of the file path
     */
    MobGiDDLogMessageCopyFile        = 1 << 0,
    /**
     *  Use this to use a copy of the function name
     */
    MobGiDDLogMessageCopyFunction    = 1 << 1,
    /**
     *  Use this to use avoid a copy of the message
     */
    MobGiDDLogMessageDontCopyMessage = 1 << 2
};


typedef NS_OPTIONS(NSUInteger, MobGiDDLogFlag){
    /**
     *  0...00001 MobGiDDLogFlagError
     */
    MobGiDDLogFlagError      = (1 << 0),
    
    /**
     *  0...00010 MobGiDDLogFlagWarning
     */
    MobGiDDLogFlagWarning    = (1 << 1),
    
    /**
     *  0...00100 DDLogFlagInfo
     */
    MobGiDDLogFlagInfo       = (1 << 2),
    
    /**
     *  0...01000 DDLogFlagDebug
     */
    MobGiDDLogFlagDebug      = (1 << 3),
    
    /**
     *  0...10000 DDLogFlagVerbose
     */
    MobGiDDLogFlagVerbose    = (1 << 4)
};


typedef NS_ENUM(NSUInteger, MobGiDDLogLevel){
    /**
     *  No logs
     */
    MobGiDDLogLevelOff       = 0,
    
    /**
     *  Error logs only
     */
    MobGiDDLogLevelError     = (MobGiDDLogFlagError),
    
    /**
     *  Error and warning logs
     */
    MobGiDDLogLevelWarning   = (MobGiDDLogLevelError   | MobGiDDLogFlagWarning),
    
    /**
     *  Error, warning and info logs
     */
    MobGiDDLogLevelInfo      = (MobGiDDLogLevelWarning | MobGiDDLogFlagInfo),
    
    /**
     *  Error, warning, info and debug logs
     */
    MobGiDDLogLevelDebug     = (MobGiDDLogLevelInfo    | MobGiDDLogFlagDebug),
    
    /**
     *  Error, warning, info, debug and verbose logs
     */
    MobGiDDLogLevelVerbose   = (MobGiDDLogLevelDebug   | MobGiDDLogFlagVerbose),
    
    /**
     *  All logs (1...11111)
     */
    MobGiDDLogLevelAll       = NSUIntegerMax
};


