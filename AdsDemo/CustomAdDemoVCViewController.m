//
//  CustomAdDemoVCViewController.m
//  AdsDemo
//
//  Created by star.liao on 2017/6/25.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import "CustomAdDemoVCViewController.h"
#import "CrossPromoteAds.h"
#import "AppDelegate.h"
#import "CustomAdDataInfo.h"


@interface CustomAdDemoVCViewController ()<UIGestureRecognizerDelegate>

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *indicator;//自定义banner广告数据加载标示
@property (weak, nonatomic) IBOutlet UIImageView *customAdImageview;//自定义banner广告视图-广告icon图片
@property (weak, nonatomic) IBOutlet UILabel *customAdTitile;//自定义banner广告视图-广告标题
@property (weak, nonatomic) IBOutlet UILabel *customAdDesc;//自定义banner广告视图-广告描述
@property (weak, nonatomic) IBOutlet UIView *customAdView;//自定义banner广告视图界面-展示和点击区域

@property(nonatomic,assign) BOOL isShowing; //自定义banner广告视图是否展示
@property(nonatomic,assign) BOOL isTemplateShowing;//自定义banner(带模版)广告视图是否展示

@end

static BOOL isCrossPromoteAdInit;

@implementation CustomAdDemoVCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    if (!isCrossPromoteAdInit) {
        [[CrossPromoteAds shareInstance] initSDK:APPKEY];
        [[CrossPromoteAds shareInstance] preloadCustomWindowAd:CrossPromoteAd_windowbid listBlockid:CrossPromoteAd_listid];//预加载橱窗广告，单次进程只加载一次
        [[CrossPromoteAds shareInstance] loadCustomBannerAdData:CrossPromoteAd_bid1];//预加载自定义banner广告数据，针对每一个广告位ID，单次进程只加载一次！
        [[CrossPromoteAds shareInstance] loadCustomBannerAdData:CrossPromoteAd_bid2];//预加载自定义banner(带模版）广告数据，针对每一个广告位ID，单次进程只加载一次！
        isCrossPromoteAdInit=YES;
    }
    else
    {
        NSLog(@"交叉推广广告已经初始化和加载过！！！");
    }
    
    
    //[self.indicator startAnimating];
    self.customAdView.alpha=0.0;
    [self.customAdView setUserInteractionEnabled:YES];
    UITapGestureRecognizer* singleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleSingleTap:)];
    [self.customAdView addGestureRecognizer:singleTap];
    singleTap.delegate = self;

    
    
    
    
    self.isShowing=NO;
    self.isTemplateShowing=NO;
    
    
    
    // Do any additional setup after loading the view.
}

#pragma mark -
#pragma mark 自定义banner广告

- (IBAction)showCustomAd:(id)sender {
    if (self.isShowing) {
        NSString* msg=@"正在展示中，请刷新页面，可通过点击返回上一页按钮，退出该页面，再进来,再刷新页面！注意⚠️：退出页面的时候，调用广告关闭接口";
        NSLog(@"%@",msg);
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示!"
                                                        message:msg
                                                       delegate:self
                                              cancelButtonTitle:@""
                                              otherButtonTitles:@"",nil];
        [alert show];
        return;
    }
    if ([[CrossPromoteAds shareInstance] isCustomAdReady:CrossPromoteAd_bid1]) {
        //有广告了，则去刷新广告界面
        CustomAdDataInfo* data=[[CrossPromoteAds shareInstance] getCustomAdData:CrossPromoteAd_bid1];
        
        if (data) {
            
            dispatch_async(dispatch_get_main_queue(), ^{
                //开始渲染自定义banner页面
                self.customAdImageview.image=[UIImage imageWithContentsOfFile:data.iconLocalURL];
                [self.customAdTitile setText:data.title];
                [self.customAdDesc setText:data.descriptionText];
                
                //做个动画
                
                CATransition* anim=[CATransition animation];
                anim.type=@"cube";
                anim.duration=0.5;
                [self.customAdView.layer addAnimation:anim forKey:nil];
                self.customAdView.alpha=1.0;
                //上报展示统计
                [[CrossPromoteAds shareInstance] reportCustomAdShow:CrossPromoteAd_bid1];
                
                [UIView animateWithDuration:2 animations:^{
                    
                }];
                
                self.isShowing=YES;
                
            });
            
            
        }
    }
    else
    {
        NSString* msg=@"自定义banner广告 广告数据还没有准备好，请等待一会儿！";
        NSLog(@"%@",msg);
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示!"
                                                        message:msg
                                                       delegate:self
                                              cancelButtonTitle:@""
                                              otherButtonTitles:@"",nil];
        [alert show];
    }
}

-(void)handleSingleTap:(UITapGestureRecognizer *)sender {
    [[CrossPromoteAds shareInstance] reportCustomAdClick:CrossPromoteAd_bid1 vc:self];
}

#pragma mark -
#pragma mark 自定义banner广告-带模版

- (IBAction)showTemmplateCustomAd:(id)sender {
    if (self.isTemplateShowing) {
        NSString* msg=@"正在展示中，请刷新页面，可通过点击返回上一页按钮，退出该页面，再进来,再刷新页面！注意⚠️：退出页面的时候，调用广告关闭接口";
        NSLog(@"%@",msg);
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示!"
                                                        message:msg
                                                       delegate:self
                                              cancelButtonTitle:@""
                                              otherButtonTitles:@"",nil];
        [alert show];
        return;
    }
    //这里以模版2作演示，模版2是顶部丝带
    BOOL isCustomAdReady= [[CrossPromoteAds shareInstance] isCustomAdReady:CrossPromoteAd_bid2];
    if (!isCustomAdReady) {
        NSString* msg=@"自定义banner广告-带模版 广告数据还没有准备好，请等待一会儿！";
        NSLog(@"%@",msg);
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示!"
                                                        message:msg
                                                       delegate:self
                                              cancelButtonTitle:@""
                                              otherButtonTitles:@"",nil];
        [alert show];
    }
    else
    {
        //获取模版2的自定义banner广告视图尺寸，已经为ios设备屏幕作了适配
        CGSize tempSize=[[CrossPromoteAds shareInstance] getSizeForTemplate:TEMPLATE2];
        //以iOS当前屏幕方向point布局为参考，左边距为200point，上边距0point
        CGPoint pos=CGPointMake(200, 0);
        NSLog(@"开始展示%@......",CrossPromoteAd_bid2);
        //        fade	淡出效果
        //        push	新视图推出旧视图
        NSMutableDictionary* extraInfo=[[NSMutableDictionary alloc] initWithObjects:@[@"push",@"#0079f7"] forKeys:@[@"animateType",@"templateColorValue"]];
        [[CrossPromoteAds shareInstance] showCustomAd:CrossPromoteAd_bid2 template:TEMPLATE2 position:pos size:tempSize vc:self extraInfo:extraInfo];
        self.isTemplateShowing=YES;
    }
}

#pragma mark
#pragma mark - 橱窗广告

- (IBAction)displayWindowAd:(id)sender {
    if ([[CrossPromoteAds shareInstance] isWindowAdReady]) {
        //橱窗广告准备就绪，展示橱窗广告界面
        [[CrossPromoteAds shareInstance] presentWindowAd:self];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示!"
                                                        message:@"橱窗广告没有准备就绪！！！！ 请稍后再试！！！！"
                                                       delegate:self
                                              cancelButtonTitle:@""
                                              otherButtonTitles:@"",nil];
        [alert show];
        NSLog(@"橱窗广告没有准备就绪！！！！ 请稍后再试！！！！");
    }
}

#pragma mark -
#pragma mark

-(IBAction)goToLastPage:(id)sender
{
    if (self.isTemplateShowing) {
        //退出该页面，自定义banner(带模版)广告视图不可见了，要调用下面方法
        [[CrossPromoteAds shareInstance] reportCustomAdClose:CrossPromoteAd_bid2 useTemplate:YES];
    }
    if (self.isShowing) {
        //退出该页面，自定义banner广告视图不可见了，要调用下面方法
        [[CrossPromoteAds shareInstance] reportCustomAdClose:CrossPromoteAd_bid1 useTemplate:NO];
        //[self closeAd];
    }
    
    [self dismissViewControllerAnimated:YES
                             completion:^{
                                 
                             }];
}

-(void) dealloc
{
    NSLog(@"vc dealloc!");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
