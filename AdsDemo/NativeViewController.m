
#import "NativeViewController.h"
#import "NativeAdData.h"
#import "NativePolymerization.h"
#import "NativeAdDetailsInfo.h"


@interface NativeViewController ()
{
    UIView *_adView;            //当前展示的原生广告界面
    NativeAdData* _currentAd;   //当前要使用的原生广告数据
    BOOL _attached;            //表示当前原生广告数据是否已经绑定并展示
    BOOL _isGetData;           //表示当前原生广告数据获取结果
}

@property (weak, nonatomic) IBOutlet UITextView *resultTV;
@property (weak, nonatomic) IBOutlet UITextField *posTextField;


@end

@implementation NativeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSLog(@"self.bid:%@",self.blockid);
    [self.posTextField setText:self.blockid];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)loadAd:(id)sender {
    
    if (_attached) {
        NSLog(@"正在展示原生广告，请移除后再重新获取......");
        return;
    }
    if (_isGetData) {
        NSLog(@"已经获取到不为空的原生广告数据，请先展示......");
        return;
    }
    
    
    if (_attached) {
        NSLog(@"正在展示的原生广告数据，准备进行移除......");
        [UIView animateWithDuration:0.5 animations:^{
            CGRect adviewFrame = _adView.frame;
            adviewFrame.origin.x += [[UIScreen mainScreen] bounds].size.width;
            _adView.frame = adviewFrame;
            CGRect textViewFrame = _resultTV.frame;
            textViewFrame.origin.x += [[UIScreen mainScreen] bounds].size.width;
            _resultTV.frame = textViewFrame;
            
        } completion:^(BOOL finished) {
            [self unattachAd];
            NSLog(@"开始重新获取新的原生广告数据......");
            
            [self refleshData];
        }];
        _attached = NO;
    }
    else
    {
        NSLog(@"当前没有展示的原生广告数据，准备获取....");
        [self refleshData];
    }
    
}

-(void) refleshData
{
    NativeAdData* data= [[NativePolymerization sharedInstance] getNativeAd:self.blockid];
    _currentAd=data;
    if (_currentAd!=nil) {
        _isGetData=YES;
        dispatch_async(dispatch_get_main_queue(), ^{
            NSMutableString *result = [NSMutableString string];
            [result appendString:@"原生广告返回数据:\n"];
            [result appendFormat:@"%@",data.description];
            [result appendString:@"\n------------------------"];
            _resultTV.text = result;
            NSLog(@"获取到了最新的原生广告数据!");
        });
    }
    else
    {
        _isGetData=NO;
        NSLog(@"获取原生广告数据为空,请稍后重试!");
    }
}

-(void) unattachAd
{
    if (_attached) {
        NSLog(@"移除原生广告数据绑定");
        [[NativePolymerization sharedInstance] unAttachAd:_currentAd toView:_adView];
        NSLog(@"原生广告界面不可见了或者移除销毁");
        [_adView removeFromSuperview];
        _adView = nil;
        [self clearResultText];
        _isGetData=NO;
    }
}

-(void) clearResultText
{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSMutableString *result = [NSMutableString string];
        [result appendString:@""];
        _resultTV.text = result;
    });
}

- (IBAction)attach:(id)sender {
    if (_attached){
        _resultTV.text = @"原生广告数据已经绑定并展示，请移除绑定后再试......";
        [self unattachAd];
        _attached=NO;
    }
    NativeAdData* data= [[NativePolymerization sharedInstance] getNativeAd:self.blockid];
    _currentAd=data;
    if (_currentAd) {
        _isGetData=YES;
        NSLog(@"重新获取到了最新的原生广告数据!");
        [UIView animateWithDuration:0.5 animations:^{
            CGRect adviewFrame = _adView.frame;
            adviewFrame.origin.x += [[UIScreen mainScreen] bounds].size.width;
            _adView.frame = adviewFrame;
            CGRect textViewFrame = _resultTV.frame;
            textViewFrame.origin.x += [[UIScreen mainScreen] bounds].size.width;
            _resultTV.frame = textViewFrame;
            
        } completion:^(BOOL finished) {
            [_adView removeFromSuperview];
            [self clearResultText];
            [self showNativead];
        }];
    }
    else {
        _isGetData=NO;
        _resultTV.text = @"原生广告数据拉取为空! 请稍后重试......";
    }

}


-(void)showNativead
{
    /*开始渲染广告界面*/
    _adView = [[UIView alloc] initWithFrame:CGRectMake([[UIScreen mainScreen] bounds].size.width, 150, 320, 250)];
    _adView.layer.borderWidth = 1;
    _adView.backgroundColor = [UIColor whiteColor];
    
    /*广告详情图*/
    UIImageView *imgV = [[UIImageView alloc] initWithFrame:CGRectMake(2, 70, 316, 176)];
    [_adView addSubview:imgV];
    NSString* url=_currentAd.imageURL;
    url=_currentAd.imageLocalURL;
    if ([url isEqualToString:@""]) {
        NSURL *imageURL = [[NSURL alloc] initWithString:url];
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
            NSData *imageData = [NSData dataWithContentsOfURL:imageURL];
            dispatch_async(dispatch_get_main_queue(), ^{
                imgV.image = [UIImage imageWithData:imageData];
            });
        });
    }
    else
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            imgV.image = [UIImage imageWithContentsOfFile:url];
        });
    }
    
    /*广告Icon*/
    UIImageView *iconV = [[UIImageView alloc] initWithFrame:CGRectMake(10, 5, 60, 60)];
    [_adView addSubview:iconV];
    NSString* iconUrl=_currentAd.iconURL;
    iconUrl=_currentAd.iconLocalURL;
    if ([iconUrl isEqualToString:@""]) {
        NSURL *iconURL = [NSURL URLWithString:iconUrl];
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
            NSData *imageData = [NSData dataWithContentsOfURL:iconURL];
            dispatch_async(dispatch_get_main_queue(), ^{
                iconV.image = [UIImage imageWithData:imageData];
            });
        });
    }
    else
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            iconV.image = [UIImage imageWithContentsOfFile:iconUrl];
        });
    }
    
    /*广告标题*/
    UILabel *txt = [[UILabel alloc] initWithFrame:CGRectMake(80, 5, 100, 35)];
    txt.text = _currentAd.title;
    [_adView addSubview:txt];
    
    /*广告描述*/
    UILabel *desc = [[UILabel alloc] initWithFrame:CGRectMake(80, 45, 200, 20)];
    desc.text = _currentAd.descriptionText;
    [_adView addSubview:desc];
    
    [self.view addSubview:_adView];
    
    CGSize size= _adView.bounds.size;
    
    //广告平台标示
    UILabel *platLabel = [[UILabel alloc] initWithFrame:CGRectMake(size.width-60, 0, 60, 30)];
    platLabel.text = _currentAd.adName;
    platLabel.textColor=[UIColor blackColor];
    platLabel.backgroundColor=[UIColor redColor];
    [_adView addSubview:platLabel];
    
    
    //广告标示图片
    UIImageView* adMarkView=[[UIImageView alloc] initWithFrame:CGRectMake(size.width-60, size.height-30, 60, 30)];
    adMarkView.image=[UIImage imageNamed:@"广告"];
    [_adView addSubview:adMarkView];
    
    
    /*注册点击事件*/
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(viewTapped:)];
    [_adView addGestureRecognizer:tap];
    
    //动画开始
    [UIView animateWithDuration:0.5 animations:^{
        
        CGRect adviewFrame = _adView.frame;
        adviewFrame.origin.x -= [[UIScreen mainScreen] bounds].size.width;
        _adView.frame = adviewFrame;
        CGRect textViewFrame = _resultTV.frame;
        textViewFrame.origin.x -= [[UIScreen mainScreen] bounds].size.width;
        _resultTV.frame = textViewFrame;
        
        NSLog(@"展示原生广告");
        
    } completion:nil];
    
    /*
     * 广告数据渲染完毕，即将展示时需调用AttachAd方法。
     */
    NativeAdDetailsInfo *detailsInfo = [[NativeAdDetailsInfo alloc]init];
    detailsInfo.isGame = NO;
    [[NativePolymerization sharedInstance] attachAd:_currentAd toView:_adView vc:self detailsInfo:detailsInfo];
    
    _attached = YES;
}


- (void)viewTapped:(UITapGestureRecognizer *)gr {
    /*点击发生，调用点击接口*/
    [[NativePolymerization sharedInstance] clickAd:_currentAd];
}

#pragma mark 
#pragma mark -

- (IBAction)returnLastPage:(id)sender {
    [self unattachAd];
    [self dismissViewControllerAnimated:YES completion:^{
        
    }];
}

@end
