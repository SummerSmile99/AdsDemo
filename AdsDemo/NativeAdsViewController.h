

#import <UIKit/UIKit.h>

@interface NativeAdsViewController : UIViewController

{
    NSArray *demoTitles;
    NSArray *demoBids;
   
}

@property(nonatomic,weak) IBOutlet UITableView *tableView;
@property(nonatomic,strong) NSString* blockid;

@end
