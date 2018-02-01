//
//  ViewController.m
//  VideoVdDemo
//
//  Created by alan.xia on 16/4/26.
//  Copyright © 2016年 alan.xia. All rights reserved.
//

#import "ViewController.h"
#import "VideoPolymerizationSDK.h"
#import "InterstitialPolymerizationSDK.h"
#import "AppDelegate.h"






@interface ViewController ()<VideoAdDelegate,InterstitialInitDelegate,PreloadInterstitialAdDelegate,ShowCachedInterstitialAdDelegate>

@property (weak, nonatomic) IBOutlet UILabel              *videoAdStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel              *rewardStatusLabel;
@property (weak, nonatomic) IBOutlet UILabel *interstitialAdStatusLabel;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *videoVersion =  [VideoPolymerizationSDK getCurrentSDKVersion];
    NSLog(@"%s,videoVersion:%@",__PRETTY_FUNCTION__,videoVersion);
    [VideoPolymerizationSDK validateIntergration];
    
    NSString *interstitialVersion =  [VideoPolymerizationSDK getCurrentSDKVersion];
    NSLog(@"%s,interstitialVersion:%@",__PRETTY_FUNCTION__,interstitialVersion);
    [InterstitialPolymerizationSDK validateIntergration];
}

#pragma mark -
#pragma mark Video aggregation

- (IBAction)initvd:(id)sender {
    
    NSLog(@"%s",__PRETTY_FUNCTION__);
    
    NSArray  *videoBlockids = @[VideoBlockIdOne];
    

    [[VideoPolymerizationSDK sharedInstance]initSDK:APPKEY vc:nil blockIds:videoBlockids delegate:self];

}

- (IBAction)checkVideoAdStatus:(id)sender {
    
    NSLog(@"%s",__PRETTY_FUNCTION__);
    
    self.videoAdStatusLabel.text = [NSString stringWithFormat:@"Video Status"];
    
    NSString *videoBlockId = VideoBlockIdOne;
    BOOL isready = [[VideoPolymerizationSDK sharedInstance] isAdPlayable:videoBlockId];
    
    if (isready) {
        NSLog(@"Video is ready for ad unit %@",videoBlockId);
        self.videoAdStatusLabel.text = [NSString stringWithFormat:@"Video is ready"];
    }
    else
    {
        NSLog(@"Video is not ready for ad unit %@",videoBlockId);
        self.videoAdStatusLabel.text = [NSString stringWithFormat:@"Video isn't ready"];
    }
    
}

- (IBAction)show:(id)sender {
    
    NSLog(@"%s",__PRETTY_FUNCTION__);
    
    self.videoAdStatusLabel.text = [NSString stringWithFormat:@"Video status"];
    self.rewardStatusLabel.text = [NSString stringWithFormat:@"Reward status"];
    
    NSString *videoBlockId = VideoBlockIdOne;
    BOOL isready = [[VideoPolymerizationSDK sharedInstance] isAdPlayable:videoBlockId];
    
    if (isready) {
        
        [[VideoPolymerizationSDK sharedInstance]showViewAd:self forBlockId:videoBlockId callBack:^{
            NSLog(@"Display failed");
        }];
    }
}

#pragma mark -
#pragma mark - VideoAdDelegate

-(void)triggerReward:(BOOL)isShouldReward forBlockid:(NSString *)blockId
{
    
    NSLog(@"%s,isShouldReward:%d,blockId:%@",__PRETTY_FUNCTION__,isShouldReward,blockId);
    
    if (isShouldReward) {
        
        NSLog(@"To get the reward for ad unit %@",blockId);
        
        self.rewardStatusLabel.text = [NSString stringWithFormat:@"Get reward"];
        
    }else{
        
        NSLog(@"There is no reward for ad unit %@",blockId);
        
        self.rewardStatusLabel.text = [NSString stringWithFormat:@"No reward"];
    }
}

-(void)videoAdFailedToLoadWithError:(NSString *)errorMessage
{
    NSLog(@"%s,errorMessage:%@",__PRETTY_FUNCTION__,errorMessage);
}

-(void)videoAdShowFailedWithError:(NSString *)errorMessage
{
    NSLog(@"%s,errorMessage:%@",__PRETTY_FUNCTION__,errorMessage);
}



#pragma mark -
#pragma mark Interstitial aggregation
- (IBAction)startCYClick:(id)sender {
    NSLog(@"%s",__PRETTY_FUNCTION__);
    [[InterstitialPolymerizationSDK sharedInstance] initSDK:APPKEY delegate:nil];
}

- (IBAction)preloadCYClick:(id)sender {
    NSLog(@"%s",__PRETTY_FUNCTION__);
    [[InterstitialPolymerizationSDK sharedInstance] preloadInterstitialAd:InterstitialBlockIdOne delegate:self];
}

- (IBAction)checkCYClick:(id)sender {
    
     NSLog(@"%s",__PRETTY_FUNCTION__);
    
    self.interstitialAdStatusLabel.text = [NSString stringWithFormat:@"Interstitial Status"];
    
    NSString *interstitialBlockId = InterstitialBlockIdOne;
    
    BOOL isready = [[InterstitialPolymerizationSDK sharedInstance] getCacheReady:interstitialBlockId];
    
    if (isready) {
        NSLog(@"Interstitial is ready for ad unit %@",interstitialBlockId);
        self.interstitialAdStatusLabel.text = [NSString stringWithFormat:@"Interstitial is ready."];
    }
    else
    {
        NSLog(@"Interstitial is not ready for ad unit %@",interstitialBlockId);
        self.interstitialAdStatusLabel.text = [NSString stringWithFormat:@"Interstitial isn't ready."];
    }
    
}

- (IBAction)showCYClick:(id)sender {
    
    NSLog(@"%s",__PRETTY_FUNCTION__);
    
    self.interstitialAdStatusLabel.text = [NSString stringWithFormat:@"Interstitial Status"];
    
    [[InterstitialPolymerizationSDK sharedInstance]showCachedInterstitialAd:InterstitialBlockIdOne delegate:self];
    
}

#pragma mark -
#pragma mark - ShowCachedInterstitialAdDelegate

- (void)interstitialPresentScreen:(NSString*)blockid
{
    NSLog(@"%s,blockId:%@",__PRETTY_FUNCTION__,blockid);
}

- (void)interstitialDismissScreen:(NSString*)blockid
{
    NSLog(@"%s,blockId:%@",__PRETTY_FUNCTION__,blockid);
}

@end
