//
//  CustomAdBaseLogicModule.h
//  CrossPromoteAds
//
//  Created by star.liao on 2017/5/27.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdsBasicFramework/SDWebImageDownloader.h>
#import <AdsBasicFramework/SDWebImageManager.h>
#import <AdxAdsComponent/AdxAdsDataReport.h>
#import <AdxAdsComponent/AdxAdItemConfigData.h>

@protocol CustomAdImageDownloadDelegate <NSObject>

@required

-(void) callbackSuccessAdResource;

-(void) callbackSuccessAdResource:(NSArray*)urls;

@end


@protocol AdxAdsDataReportDelegate <NSObject>

@required

-(AdxAdsDataReport*) adxGenerateDataReport:(AdxAdItemConfigData*) temp;

@end


@protocol CustomAdLoadDelegate;

@interface CustomAdBaseLogicModule : NSObject

@property(nonatomic,strong) NSMutableArray* imgLocalUrls;
@property(nonatomic,assign) BOOL isAdReady;
@property(nonatomic,assign) BOOL isPortrait;
@property(nonatomic,weak) id<CustomAdLoadDelegate> callBackDelegate;
@property(nonatomic,weak) id<AdxAdsDataReportDelegate> dataReportDelegate;

-(AdxAdsDataReport*) getReport:(AdxAdItemConfigData*) temp
                          blockid:(NSString*)blockid
                           imgUrl:(NSString*)imgUrl;

-(void)downloadImgUrls:(NSArray*)imgUrls
              delegate:(id<CustomAdImageDownloadDelegate>) delegate;

//让子类重写!!!
-(void) callBackDownloadSuccess;

@end
