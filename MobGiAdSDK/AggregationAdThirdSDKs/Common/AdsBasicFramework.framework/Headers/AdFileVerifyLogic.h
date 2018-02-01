//
//  AdFileVerifyLogic.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/7/3.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface AdFileVerifyLogic : NSObject

//判断指定格式数据是否有效，当前支持jpg,jpeg,png,tiff,gif
+(BOOL) isValidImageData:(NSString*)path;

//判断当前屏幕方向下，根据宽高比例，缓存图片是否可以展示在开屏和插页之上！
+(BOOL) isImageFileValid:(NSString*)fileLocalPath
             aspectRatio:(double)scale;

+(CGSize) getImageFileSize:(NSString*)fileLocalPath;

@end
