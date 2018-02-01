//
//  CMMobvistaAdapter.m
//  TestInterstitialPolymerization
//
//  Created by alan.xia on 2017/5/23.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "CMMobvistaAdapter.h"
#import <MVSDK/MVSDK.h>

@interface CMMobvistaAdapter ()<MVNativeAdManagerDelegate>

@property(nonatomic,strong)NSString *blockId;

@property(nonatomic,strong)UIViewController  *displayVC;

@property(nonatomic,strong) UIView *displayView;

@property(nonatomic, strong) MVNativeAdManager *nativeAdManager;

@property(nonatomic,strong) MVCampaign  *campaign;

@property(nonatomic,strong) NSDictionary  *dataDict;

@property(nonatomic,strong) NSString *iconURL;

@property(nonatomic,strong) NSString *imageURL;

@property(nonatomic,strong) UIImage  *iconLocalImage;

@property(nonatomic,strong) UIImage  *bigLocalImage;

@property(nonatomic,strong) NSString *title;

@property(nonatomic,strong) NSString *descriptionTitle;

@property (nonatomic,assign)int invokeCount;

@end

@implementation CMMobvistaAdapter

-(instancetype)init:(UIViewController *)vc blockId:(NSString *)blockId
{
    self = [super init];
    if (self) {
        self.displayVC = vc;
        self.blockId = blockId;
        self.invokeCount = 0;
    }
    return self;
}

-(void)loadAd
{
    MVTemplate *template = [MVTemplate templateWithType:MVAD_TEMPLATE_BIG_IMAGE adsNum:1];
    NSArray *templateArr = [NSArray arrayWithObject:template];
    
    [[MVSDK sharedInstance]preloadNativeAdsWithUnitId:self.blockId fbPlacementId:@"" supportedTemplates:templateArr autoCacheImage:YES adCategory:MVAD_CATEGORY_ALL];
    
    self.nativeAdManager = [[MVNativeAdManager alloc]initWithUnitID:self.blockId fbPlacementId:@"" supportedTemplates:templateArr autoCacheImage:YES adCategory:MVAD_CATEGORY_ALL presentingViewController:self.displayVC];
    
    [self.nativeAdManager setDelegate:self];
    
    [self.nativeAdManager loadAds];
    
}

-(void)showAd:(UIView *)view
{
    self.displayView = view;
    [self.nativeAdManager registerViewForInteraction:self.displayView withCampaign:self.campaign];
}

-(void)closeAd
{
    self.campaign = nil;
    [self.nativeAdManager unregisterView:self.displayView];
}

-(void)downloadImageSuccess
{
    self.invokeCount++;
    if (self.invokeCount==2) {
        [self downloadNativeAdCompleted];
    }
}


-(void) downloadNativeAdCompleted
{
    if (self.bigLocalImage!=nil&&self.iconLocalImage!=nil) {
        self.dataDict = @{@"title":self.title,
                          @"descriptionTitle":self.descriptionTitle,
                          @"iconURL":self.iconURL,
                          @"imageURL":self.imageURL,
                          @"iconLocalImage":self.iconLocalImage,
                          @"bigLocalImage":self.bigLocalImage};
//        [self.dataDict setValue:self.iconLocalImage forKey:@"iconLocalImage"];
//        [self.dataDict setValue:self.bigLocalImage forKey:@"bigLocalImage"];
        if ([self.delegate respondsToSelector:@selector(nativeAdLoadSuccess:)]) {
            [self.delegate nativeAdLoadSuccess:self.dataDict];
        }
    }
    else
    {
        if ([self.delegate respondsToSelector:@selector(nativeAdLoadFail:)]) {
            [self.delegate nativeAdLoadFail:@"bigLocalImage or iconLocalImage is nil"];
        }
    }
}

#pragma mark - MVNativeAdManagerDelegate

- (void)nativeAdsLoaded:(NSArray *)nativeAds nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    if (nativeAds != nil && nativeAds.count >0) {
        self.campaign = nativeAds[0];
        self.iconURL = self.campaign.iconUrl;
        self.imageURL = self.campaign.imageUrl;
        self.title = self.campaign.appName;
        self.descriptionTitle = self.campaign.appDesc;
        
        if (!self.isNativeAd) {
            [self.campaign loadImageUrlAsyncWithBlock:^(UIImage *image) {
                self.bigLocalImage = image;
                [self downloadImageSuccess];
            }];
            [self.campaign loadIconUrlAsyncWithBlock:^(UIImage *image) {
                self.iconLocalImage = image;
                [self downloadImageSuccess];
            }];
            
        }else{
            self.dataDict = @{@"title":self.title,
                              @"descriptionTitle":self.descriptionTitle,
                              @"iconURL":self.iconURL,
                              @"imageURL":self.imageURL};
            if ([self.delegate respondsToSelector:@selector(nativeAdLoadSuccess:)]) {
                [self.delegate nativeAdLoadSuccess:self.dataDict];
            }
        }
    }
}

- (void)nativeAdsFailedToLoadWithError:(NSError *)error nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    if ([self.delegate respondsToSelector:@selector(nativeAdLoadFail:)]) {
        [self.delegate nativeAdLoadFail:[error localizedDescription]];
    }
}

- (void)nativeAdDidClick:(MVCampaign *)nativeAd nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    if ([self.delegate respondsToSelector:@selector(nativeAdClick)]) {
        [self.delegate nativeAdClick];
    }
}

- (void)nativeAdClickUrlWillStartToJump:(NSURL *)clickUrl nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    
}

- (void)nativeAdClickUrlDidJumpToUrl:(NSURL *)jumpUrl nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    
}

- (void)nativeAdClickUrlDidEndJump:(NSURL *)finalUrl error:(NSError *)error nativeManager:(nonnull MVNativeAdManager *)nativeManager
{
    
}


@end
