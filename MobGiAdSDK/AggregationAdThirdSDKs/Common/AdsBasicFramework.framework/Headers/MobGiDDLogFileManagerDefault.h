//
//  MobGiDDLogFileManagerDefault.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/22.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ProtocolDefines.h"

#import "ConstDefines.h"

@interface MobGiDDLogFileManagerDefault : NSObject<MobGiDDLogFileManager>

/**
 *  Default initializer
 */
- (instancetype)init;

/**
 *  Designated initialized, requires the logs directory
 */
- (instancetype)initWithLogsDirectory:(NSString *)logsDirectory NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithLogsDirectory:(NSString *)logsDirectory defaultFileProtectionLevel:(NSString *)fileProtectionLevel;

- (BOOL)isLogFile:(NSString *)fileName;

- (NSString *)createNewLogFile:(NSString*)tag;

@end
