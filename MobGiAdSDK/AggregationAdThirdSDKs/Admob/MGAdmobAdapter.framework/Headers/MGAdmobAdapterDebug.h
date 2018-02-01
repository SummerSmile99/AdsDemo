//
//  MGAdmobAdapterDebug.h
//  MGAdmobAdapter
//
//  Created by alan.xia on 2018/1/11.
//  Copyright © 2018年 alan.xia. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MGAdmobAdapter_Log(frmt, ...) if ([MGAdmobAdapterDebug sharedInstance].debug) NSLog((@"[T:0x%x %@ %p] %s:%d " frmt),(unsigned int)[NSThread currentThread], ([[NSThread currentThread] isMainThread] ? @"M" : @"S"),self, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface MGAdmobAdapterDebug : NSObject

@property (nonatomic, assign) BOOL debug;

+ (MGAdmobAdapterDebug *)sharedInstance;

@end
