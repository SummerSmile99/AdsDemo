//
//  ProtocolDefines.h
//  SDKCommonModule
//
//  Created by star.liao on 2017/9/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//
@protocol MobGiDDLogMessage;

@class MobGiDDLogMessage;

@protocol MobGiDDLogFormatter;

@protocol MobGiDDLogger <NSObject>

- (void)logMessage:(MobGiDDLogMessage *)logMessage;

@property (nonatomic, strong) id <MobGiDDLogFormatter> logFormatter;

@optional

- (void)didAddLogger;

- (void)didAddLoggerInQueue:(dispatch_queue_t)queue;

- (void)willRemoveLogger;

- (void)flush;

@property (nonatomic, strong, readonly) dispatch_queue_t loggerQueue;

@property (nonatomic, readonly) NSString *loggerName;

@end

@protocol MobGiDDLogFormatter <NSObject>
@required

- (NSString * __nullable)formatLogMessage:(MobGiDDLogMessage *)logMessage;

@optional

- (void)didAddToLogger:(id <MobGiDDLogger>)logger;

- (void)didAddToLogger:(id <MobGiDDLogger>)logger inQueue:(dispatch_queue_t)queue;

- (void)willRemoveFromLogger:(id <MobGiDDLogger>)logger;

@end



@protocol MobGiDDLogFileManager <NSObject>
@required

// Public properties

/**
 * The maximum number of archived log files to keep on disk.
 * For example, if this property is set to 3,
 * then the LogFileManager will only keep 3 archived log files (plus the current active log file) on disk.
 * Once the active log file is rolled/archived, then the oldest of the existing 3 rolled/archived log files is deleted.
 *
 * You may optionally disable this option by setting it to zero.
 **/
@property (readwrite, assign, atomic) NSUInteger maximumNumberOfLogFiles;

/**
 * The maximum space that logs can take. On rolling logfile all old logfiles that exceed logFilesDiskQuota will
 * be deleted.
 *
 * You may optionally disable this option by setting it to zero.
 **/
@property (readwrite, assign, atomic) unsigned long long logFilesDiskQuota;

// Public methods

/**
 *  Returns the logs directory (path)
 */
- (NSString *)logsDirectory;

/**
 * Returns an array of `NSString` objects,
 * each of which is the filePath to an existing log file on disk.
 **/
- (NSArray *)unsortedLogFilePaths;

/**
 * Returns an array of `NSString` objects,
 * each of which is the fileName of an existing log file on disk.
 **/
- (NSArray *)unsortedLogFileNames;

/**
 * Returns an array of `DDLogFileInfo` objects,
 * each representing an existing log file on disk,
 * and containing important information about the log file such as it's modification date and size.
 **/
- (NSArray *)unsortedLogFileInfos;

/**
 * Just like the `unsortedLogFilePaths` method, but sorts the array.
 * The items in the array are sorted by creation date.
 * The first item in the array will be the most recently created log file.
 **/
- (NSArray *)sortedLogFilePaths;

/**
 * Just like the `unsortedLogFileNames` method, but sorts the array.
 * The items in the array are sorted by creation date.
 * The first item in the array will be the most recently created log file.
 **/
- (NSArray *)sortedLogFileNames;

/**
 * Just like the `unsortedLogFileInfos` method, but sorts the array.
 * The items in the array are sorted by creation date.
 * The first item in the array will be the most recently created log file.
 **/
- (NSArray *)sortedLogFileInfos;

// Private methods (only to be used by DDFileLogger)

/**
 * Generates a new unique log file path, and creates the corresponding log file.
 **/
- (NSString *)createNewLogFile;

-(NSString*)createNewLogFile:(NSString*)tag;

@optional

// Notifications from DDFileLogger

/**
 *  Called when a log file was archieved
 */
- (void)didArchiveLogFile:(NSString *)logFilePath;

/**
 *  Called when the roll action was executed and the log was archieved
 */
- (void)didRollAndArchiveLogFile:(NSString *)logFilePath;

@end


