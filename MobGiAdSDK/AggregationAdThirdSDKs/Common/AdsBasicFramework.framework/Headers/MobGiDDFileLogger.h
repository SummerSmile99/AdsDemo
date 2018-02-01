//
//  MobGiDDFileLogger.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/22.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MobGiDDAbstractLogger.h"

#import "ProtocolDefines.h"

#import "ConstDefines.h"


@class MobGiDDLogFileInfo;

@interface MobGiDDFileLogger : MobGiDDAbstractLogger<MobGiDDLogger>

- (instancetype)init;

- (instancetype)initWithLogFileManager:(id <MobGiDDLogFileManager>)logFileManager NS_DESIGNATED_INITIALIZER;

@property (strong, nonatomic, readonly) id <MobGiDDLogFileManager> logFileManager;

- (MobGiDDLogFileInfo *)currentLogFileInfo;

@end
