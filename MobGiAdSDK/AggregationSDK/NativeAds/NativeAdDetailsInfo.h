//
//  NativeAdDetailsInfo.h
//  NativePolymerization
//
//  Created by alan.xia on 2018/1/18.
//  Copyright © 2018年 com.idreamsky. All rights reserved.
//

/*该类用于展示的时候传入一些属性设置*/

#import <Foundation/Foundation.h>

@interface NativeAdDetailsInfo : NSObject

//按实际类型设置,游戏类型传YES,应用类型传NO,如果传错类型,会影响展示和点击跳转
@property(nonatomic,assign) BOOL isGame;

@end
