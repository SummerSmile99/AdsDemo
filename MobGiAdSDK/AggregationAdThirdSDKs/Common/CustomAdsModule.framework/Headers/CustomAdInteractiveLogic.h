//
//  CrossPromoteAdInteractiveLogic.h
//  CrossPromoteAds
//
//  Created by star.liao on 2017/5/27.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CustomAdInteractiveLogic : NSObject

@property(nonatomic,strong) NSDate* lastClickDate;
@property(nonatomic,assign) int clickedInternalTimes;

-(BOOL) checkShouldClick;

-(void) refreshClickTimes;

-(BOOL) checkShouldClick:(NSDate*)lastClickDate
    clickedInternalTimes:(int)clickedInternalTimes;

-(BOOL) isEnableDeepLinkNavigate:(NSString*)jumpUrl
                        deepLink:(NSString*)deepLink;

-(void) navigateOnAdClick:(NSString*)targetUrl
                 jumpType:(int)jumpAppStoreType
                 parentVC:(UIViewController*)presentVC
                 deepLink:(NSString*)deepLink
             isHouseAdDSP:(BOOL)isHouseAdDSP;

@end
