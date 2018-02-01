//
//  CustomBannerViewModel.h
//  CrossPromoteAds
//
//  Created by star.liao on 2017/5/30.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "CustomAdBaseLogicModule.h"
#import "CustomAdsAdxDataManagerModule.h"
#import <CustomAdsModule/CustomAdsAdxDataManagerModule.h>
#import "CustomAdInteractiveLogic.h"




@protocol CustomAdLoadDelegate;

@interface CustomAdLogicModule : CustomAdBaseLogicModule<CustomAdConfigRequestDelegate>

@property(nonatomic,strong) NSString* blockid;

@property(nonatomic,assign) int count;

@property(nonatomic,strong) NSArray<AdxAdItemConfigData*>* bannerDatas;

@property(nonatomic,strong) NSMutableArray<AdxAdsDataReport*>* adsDataReports;

@property(nonatomic,strong) NSMutableArray* adIdArray;
@property(nonatomic,strong) NSMutableArray* interactiveLogicArray;

@property(nonatomic,strong) AdxAdsModule*bannerAdDataModule;

@property(nonatomic,strong) id<CustomAdImageDownloadDelegate> downloadDelegate;

@property(nonatomic,assign) BOOL isPresent;

-(instancetype) init:(NSString*)blockid;

-(BOOL) isAdReady;

-(BOOL) isAdReady:(AdxAdItemConfigData*)targetresult;

-(void) closeAd:(AdxAdItemConfigData*)targetresult;

-(void) reportPresentWithEventNum:(int)eventNumStr
                   configAdsState:(NSString*)adState;

-(void) reportClickWithEventNum:(int)eventNumStr;

-(void) reportClose;

//-(void) reportAdNavigate;

-(void) reportPresent:(AdxAdItemConfigData*)targetresult
             eventNum:(int)eventNumStr
       configAdsState:(NSString*)adState;

-(void) reportClick:(AdxAdItemConfigData*)targetresult
           eventNum:(int)eventNumStr;

-(void) reportClose:(AdxAdItemConfigData*)targetresult;

//-(void) reportAdNavigate:(AdxAdItemConfigData*)targetresult;

-(void) callBackAdxConfigDatas:(NSArray<AdxAdItemConfigData *>*) crossPromoteAdItemConfigData
                       blockid:(NSString*)blockid
                      delegate:(id<CustomAdImageDownloadDelegate>)delegate;

#pragma mark -
#pragma mark - 点击逻辑

-(void) clickBehavior:(UIViewController*)vc
             eventNum:(int)eventNumStr;

-(void) clickBehavior:(UIViewController*)vc
             itemData:(AdxAdItemConfigData*)targetresult
             eventNum:(int)eventNumStr;

@end
