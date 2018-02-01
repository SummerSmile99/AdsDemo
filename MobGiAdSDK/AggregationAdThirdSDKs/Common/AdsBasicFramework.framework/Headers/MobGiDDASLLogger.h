//
//  MobGiDDASLLogger.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MobGiDDAbstractLogger.h"

// Custom key set on messages sent to ASL
extern const char* const MobGikDDASLKeyDDLog;

// Value set for kDDASLKeyDDLog
extern const char* const MobGikDDASLDDLogValue;


@interface MobGiDDASLLogger : MobGiDDAbstractLogger<MobGiDDLogger>

+ (instancetype)sharedInstance;

- (void)logMessage:(MobGiDDLogMessage *)logMessage;

@end
