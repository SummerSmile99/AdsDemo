//
//  AdBasicCustomWebView.h
//  AdsBasicFramework
//
//  Created by star.liao on 2017/5/27.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol AdBasicCustomWebViewDelegate <NSObject>

@optional

-(void)willCloseCustomWebBrowser;

@end

@interface AdBasicCustomWebView : NSObject

@property (nonatomic,weak)id<AdBasicCustomWebViewDelegate>       customWebViewDelegate;

@property (nonatomic, strong) NSString                           *jumpUrl;

@property (nonatomic, strong) UIWebView                          *customWebBrowser;

@property (nonatomic, strong) UIButton                           *closeWebBrowserButton;

@property (nonatomic, strong) UIView                             *bgWebBrowserView;

@property (nonatomic, strong) UIView                             *bgBtnView;

@property (nonatomic, strong) UIButton                           *backButton;

@property (nonatomic, strong) UIButton                           *forwardButton;

@property (nonatomic, strong) UIButton                           *refreshButton;

@property (nonatomic, strong) UIButton                           *jumpDetailsButton;

@property (nonatomic,strong) NSString *passJsonData;

- (void )createCustomWebBrowserWithView:(UIView *)view withWebSitePath:(NSString *)webSitePath;

-(void)hiddenCustomWebView;

-(void)showCustomWebView;

-(void)adaptingFrameWithView:(UIView *)view;

-(void)removeCustomWebBrowser;

@end
