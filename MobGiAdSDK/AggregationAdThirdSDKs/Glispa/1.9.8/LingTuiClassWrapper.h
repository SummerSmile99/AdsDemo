//
//  LingTuiClassWrapper.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/18.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LingTuiClassWrapper : NSObject
- (id)initWithClass:(Class)c;
@property (nonatomic, readonly,weak) Class theClass;

@end
