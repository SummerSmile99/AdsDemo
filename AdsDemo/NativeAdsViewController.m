

#import "NativeAdsViewController.h"
#import "NativePolymerization.h"
#import "NativeAdData.h"
#import "NativeAdExtraOptionInfo.h"
#import <AggregationAdsComponent/AggregationAdsDebugger.h>
#import "NativeViewController.h"
#import "AppDelegate.h"


@interface NativeAdsViewController ()<NativeAdDelegate,UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, retain)   UIStoryboard *storyBoard;

@end

@implementation NativeAdsViewController



- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    demoBids=[[NSArray alloc] initWithObjects:BLOCKID_1,BLOCKID_2, nil];
    NSMutableArray *array = [NSMutableArray arrayWithArray:demoBids];
    
    NativeAdExtraOptionInfo *optionInfo = [[NativeAdExtraOptionInfo alloc] init];
    optionInfo.logoLocation = MGNativeAdLogoLocation_BottomRight;
    [[NativePolymerization sharedInstance] setOptionInfo:optionInfo];
    
    [[NativePolymerization sharedInstance] initSDK:APPKEY blockids:array];
    demoTitles = [[NSArray alloc] initWithObjects:@"原生广告1",@"原生广告2",@"返回上一页!", nil];
    _storyBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
}

-(void) initSuccess
{
    NSLog(@"聚合原生广告SDK初始化完成!");
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [demoTitles count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *SimpleTableIdentifier = @"SimpleTableIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:SimpleTableIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:SimpleTableIdentifier];
    }
    
    cell.textLabel.text = demoTitles[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row==2) {
        
        [self dismissViewControllerAnimated:YES completion:^{
            
        }];
        return;
    }
    
    [self showNativeView:[demoBids objectAtIndex:indexPath.row]];
}

-(void)showNativeView:(NSString*)blockid
{
    UIViewController *viewcontroller = [_storyBoard instantiateViewControllerWithIdentifier:@"nativeadviewcontroller"];
    [viewcontroller setValue:blockid forKey:@"blockid"];
    [self presentViewController:viewcontroller animated:YES
completion:^{
    
}];
}

//#pragma mark - NativeAdDelegate
//
//-(void)nativeAdSuccessToLoad:(NSString *)blockId
//{
//    NSLog(@"blockId:%@",blockId);
//}
//
////这里不会触发!
//-(void)nativeAdFailToLoad:(NSError *)error
//{
//    
//}

@end
