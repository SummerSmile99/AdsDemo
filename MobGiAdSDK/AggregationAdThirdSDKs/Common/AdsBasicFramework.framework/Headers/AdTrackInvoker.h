//
//  AdTrackInvoker.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/21.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  外放给CP调用，或者内部调用
 */
@interface AdTrackInvoker : NSObject

+ (instancetype)shareInstance;

/**
 *  开启打开游戏监控
 *
 *  @param appkey <#appkey description#>
 */
-(void) reportOpenTrack:(NSString*)appkey;

/**
 *  开启完成登录监控
 *  ⚠️ CP必接接口
 *
 *  @param appkey <#appkey description#>
 */
-(void) reportLoginTrack:(NSString*)appkey;

@end
