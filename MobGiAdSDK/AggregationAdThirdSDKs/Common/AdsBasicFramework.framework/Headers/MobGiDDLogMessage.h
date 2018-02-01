//
//  MobGiDDLogMessage.h
//  SDKCommonModule-CocoaLumberjack
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GlobalDefines.h"

@interface MobGiDDLogMessage : NSObject
{
    // Direct accessors to be used only for performance
@public
    NSString *_message;
    MobGiDDLogLevel _level;
    MobGiDDLogFlag _flag;
    NSInteger _context;
    NSString *_file;
    NSString *_fileName;
    NSString *_function;
    NSUInteger _line;
    id _tag;
    MobGiDDLogMessageOptions _options;
    NSDate *_timestamp;
    NSString *_threadID;
    NSString *_threadName;
    NSString *_queueLabel;
}
- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithMessage:(NSString *)message
                          level:(MobGiDDLogLevel)level
                           flag:(MobGiDDLogFlag)flag
                        context:(NSInteger)context
                           file:(NSString *)file
                       function:(NSString * __nullable)function
                           line:(NSUInteger)line
                            tag:(id __nullable)tag
                        options:(MobGiDDLogMessageOptions)options
                      timestamp:(NSDate * __nullable)timestamp NS_DESIGNATED_INITIALIZER;

@property (readonly, nonatomic) NSString *message;
@property (readonly, nonatomic) MobGiDDLogLevel level;
@property (readonly, nonatomic) MobGiDDLogFlag flag;
@property (readonly, nonatomic) NSInteger context;
@property (readonly, nonatomic) NSString *file;
@property (readonly, nonatomic) NSString *fileName;
@property (readonly, nonatomic) NSString * __nullable function;
@property (readonly, nonatomic) NSUInteger line;
@property (readonly, nonatomic) id __nullable tag;
@property (readonly, nonatomic) MobGiDDLogMessageOptions options;
@property (readonly, nonatomic) NSDate *timestamp;
@property (readonly, nonatomic) NSString *threadID; // ID as it appears in NSLog calculated from the machThreadID
@property (readonly, nonatomic) NSString *threadName;
@property (readonly, nonatomic) NSString *queueLabel;

@end
