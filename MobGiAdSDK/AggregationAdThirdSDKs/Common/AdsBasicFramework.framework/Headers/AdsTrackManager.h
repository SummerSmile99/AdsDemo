//
//  AdsTrackManager.h
//  trackactivetest
//
//  Created by star.liao on 16/5/4.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AdsTrackManager : NSObject

+ (instancetype)shareInstance;

/**
 *  打开游戏
 *
 *  @param consumerkey 调用方必传的参数
 *
 *  @return GET请求连接字符串，CP用自己的网络库进去请求
 */
-(void) getRequestUrlForOpen:(NSString*)consumerkey
                      resultBlock:(void(^)(NSString*))resultBlock;

/**
 *  完成登录
 *  建议调用场景:完成帐号登录后调用
 *
 *  @param consumerkey 调用方必传的参数
 *
 *  @return GET请求连接字符串，CP用自己的网络库进去请求
 */
-(void) getRequestUrlForCompleteLogin:(NSString*)consumerkey
                               resultBlock:(void(^)(NSString*))resultBlock;

@end
