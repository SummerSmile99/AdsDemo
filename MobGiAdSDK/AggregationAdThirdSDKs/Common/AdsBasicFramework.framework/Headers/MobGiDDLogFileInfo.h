//
//  MobGiDDLogFileInfo.h
//  CustomLogSystem-xcode7.x
//
//  Created by star.liao on 2017/9/22.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ConstDefines.h"

@interface MobGiDDLogFileInfo : NSObject

@property (strong, nonatomic, readonly) NSString *filePath;
@property (strong, nonatomic, readonly) NSString *fileName;

@property (strong, nonatomic, readonly) NSDictionary *fileAttributes;

@property (strong, nonatomic, readonly) NSDate *creationDate;
@property (strong, nonatomic, readonly) NSDate *modificationDate;

@property (nonatomic, readonly) unsigned long long fileSize;

@property (nonatomic, readonly) NSTimeInterval age;

@property (nonatomic, readwrite) BOOL isArchived;

+ (instancetype)logFileWithPath:(NSString *)filePath;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFilePath:(NSString *)filePath NS_DESIGNATED_INITIALIZER;

- (void)reset;
- (void)renameFile:(NSString *)newFileName;

#if TARGET_IPHONE_SIMULATOR

// So here's the situation.
// Extended attributes are perfect for what we're trying to do here (marking files as archived).
// This is exactly what extended attributes were designed for.
//
// But Apple screws us over on the simulator.
// Everytime you build-and-go, they copy the application into a new folder on the hard drive,
// and as part of the process they strip extended attributes from our log files.
// Normally, a copy of a file preserves extended attributes.
// So obviously Apple has gone to great lengths to piss us off.
//
// Thus we use a slightly different tactic for marking log files as archived in the simulator.
// That way it "just works" and there's no confusion when testing.
//
// The difference in method names is indicative of the difference in functionality.
// On the simulator we add an attribute by appending a filename extension.
//
// For example:
// "mylog.txt" -> "mylog.archived.txt"
// "mylog"     -> "mylog.archived"

- (BOOL)hasExtensionAttributeWithName:(NSString *)attrName;

- (void)addExtensionAttributeWithName:(NSString *)attrName;
- (void)removeExtensionAttributeWithName:(NSString *)attrName;

#else /* if TARGET_IPHONE_SIMULATOR */

// Normal use of extended attributes used everywhere else,
// such as on Macs and on iPhone devices.

- (BOOL)hasExtendedAttributeWithName:(NSString *)attrName;

- (void)addExtendedAttributeWithName:(NSString *)attrName;
- (void)removeExtendedAttributeWithName:(NSString *)attrName;

#endif /* if TARGET_IPHONE_SIMULATOR */

- (NSComparisonResult)reverseCompareByCreationDate:(MobGiDDLogFileInfo *)another;
- (NSComparisonResult)reverseCompareByModificationDate:(MobGiDDLogFileInfo *)another;

@end
