//
//  LingTuiInterstitialDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/5/8.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class LingTuiNative;
@protocol LingTuiNativeDelegate <NSObject>
- (UIViewController *)LingTuiViewNativeControllerForPresentingModalView;
- (void)LingTuiNativeLoadSuccess:(LingTuiNative *)native withObjectArray:(NSArray *)objArray;
- (void)LingTuiNativeLoadAdFail:(NSError *)error;

@end
