//
//  MobGiDDLogFileFormatterDefault.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/22.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ProtocolDefines.h"

#import "ConstDefines.h"

@interface MobGiDDLogFileFormatterDefault : NSObject<MobGiDDLogFormatter>

/**
 *  Default initializer
 */
- (instancetype)init;

/**
 *  Designated initializer, requires a date formatter
 */
- (instancetype)initWithDateFormatter:(NSDateFormatter *)dateFormatter NS_DESIGNATED_INITIALIZER;

@end
