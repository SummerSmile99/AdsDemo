//
//  NetStabilizerAdapter.m
//  TestInterstitialPolymerization
//
//  Created by star.liao on 2017/3/7.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "NetStabilizerAdapter.h"
@import GoogleMobileAds;
@import NetStabilizer;
//#import <NetStabilizer/NetStabilizer.h>
//#import <NetStabilizer/GNSApp.h>

@implementation NetStabilizerAdapter

+(void) initAppId:(NSString*)appid
{
    //NSLog(@"%s,appid:%@",__PRETTY_FUNCTION__,appid);
    [GNSApp configure];
    [GNSApp sharedInstance].switchSetting = GNSSwitchSettingForcedOn;
    [[GNSApp sharedInstance] setProtectedDomainNames:@[
                                                       @"googleads.g.doubleclick.net",
                                                       @"csi.gstatic.com",
                                                       @"pagead2.googlesyndication.com",
                                                       @"googleads4.g.doubleclick.net",
                                                       @"lh3.googleadsserving.cn",
                                                       ]];
    dispatch_async(dispatch_get_main_queue(), ^{
        [GADMobileAds configureWithApplicationID:appid];
    });
    
}

@end
