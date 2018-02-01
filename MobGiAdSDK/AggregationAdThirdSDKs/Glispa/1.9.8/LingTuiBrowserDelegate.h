//
//  LingTuiBrowserDelegate.h
//  LingTuiLibrary
//
//  Created by LingTui on 16/4/25.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LingTuiBrowserDelegate <NSObject>
/*
 浏览器将要展示
 */
- (void)LingTuiWebBrowserWillAppear;

/*
 浏览器已经展示
 */
- (void)LingTuiWebBrowserDidAppear;

/*
 浏览器将要关闭
 */
- (void)LingTuiWebBrowserWillClosed;

/*
 浏览器已经关闭
 */
- (void)LingTuiWebBrowserDidClosed;
@end
