//
//  NativeAdExtraOptionInfo.h
//  NativePolymerization
//
//  Created by alan.xia on 2018/1/19.
//  Copyright © 2018年 com.idreamsky. All rights reserved.
//

/*该类用于初始化的时候传入一些属性设置*/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, MGNativeAdLogoLocation) {
    MGNativeAdLogoLocation_TopLeft = 1,
    MGNativeAdLogoLocation_TopRight = 2,
    MGNativeAdLogoLocation_BottomLeft = 3,
    MGNativeAdLogoLocation_BottomRight = 4
};//广告商Logo位置

@interface NativeAdExtraOptionInfo : NSObject

@property(nonatomic,assign) MGNativeAdLogoLocation logoLocation;

@end
