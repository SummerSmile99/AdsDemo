//
//  DianyunSdk.h
//  DianyunIOSSdk
//
//  Created by mac on 16/8/29.
//  Copyright © 2016年 heyi. All rights reserved.
//

#import <Foundation/Foundation.h>

#define DIANYUN_PLAYABLE_NOTIFICATION @"DIANYUN_PLAYABLE_NOTIFICATION"
#define DIANYUN_ADIDS @"adIds"
#define DIANYUN_PLAYABLE_LIST @"playableList"

@protocol DianyunSdkDelegate <NSObject>

@optional

/**
 点击下载回调
 */
- (void)didClickDownload;

/**
 退出回调
 点击退出按钮退出试玩界面时调用
 */
- (void)didCloseController;

/**
 进入试玩失败回调
 如果处理了异常，请返回YES; 返回NO时会有默认弹框提示
 */
- (BOOL)didLaunchFailure:(NSError *)error;

@end

@interface DianyunSdk : NSObject
/**
 初始化SDK
 
 参数:
 uid: 用户唯一标识
 channel: 渠道号
 */
+ (void)initWithUid:(NSString *)uid channel:(NSString *)channel;

/**
 释放SDK
 */
+ (void)fini;

/**
 获取SDK版本号
 */
+ (NSString *)version;

+ (instancetype)instance;

/**
 获取当前试玩时间
 */
- (NSTimeInterval)getPlayDuration;

/**
 是否可试玩, 同步返回
 */
- (BOOL)isPlayable:(int)adId;

/**
 检查是否可试玩
 
 参数:
 adIds: 广告位ID数组
 */
- (void)checkPlayable:(NSArray *)adIds;

/**
 重置所有状态，重新拉取可试玩配置
 */
- (void)reset;

/**
 进入试玩
 
 参数:
 adId: 广告位ID
 */
- (void)launchWithController:(UIViewController *)controller delegate:(id<DianyunSdkDelegate>)delegate adId:(NSInteger)adId;
@end
