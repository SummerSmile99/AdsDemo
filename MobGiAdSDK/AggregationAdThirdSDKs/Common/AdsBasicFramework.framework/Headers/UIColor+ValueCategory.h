//
//  UIColor+ValueCategory.h
//  HouseAdClientComponent
//
//  Created by star.liao on 2016/11/22.
//  Copyright © 2016年 star.liao. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (ValueCategory)

+ (UIColor*)colorWithHexString:(NSString*)stringToConvert;

+ (UIColor*)colorWithRGBHex:(UInt32)hex;

@end
