

#import <UIKit/UIKit.h>
#import "ICTextView.h"
#import <AdsBasicFramework/AdBasicCustomWebView.h>

@protocol SULogboardDelegate <NSObject>

@required

-(void) notify;

@end

@protocol AdLogicDelegate <NSObject>

@optional

-(void) getAdState;

-(void) getAdConfigs;

-(void) getAdsList;

-(void) getSDKVersion;

-(BOOL) sendSDKLog:(NSString*)path
       targetFiles:(NSArray*)fileArray
           zipPath:(NSString*)zipPath;

//是否切换到CP调用接口日志模式，只打印SDK接口层调用日志
-(void) shouldSwitchCPIntegrationLog:(BOOL)isSwitch;

//是否记忆本次debugMode的值，等待下一次启动，重用
-(void)shouldRecordDebugMode:(BOOL)isSwitch;

@end

@interface SULogboard : UIView

@property(nonatomic,weak) id<SULogboardDelegate> delegate;
@property (nonatomic, strong) ICTextView * logTextView;
@property(nonatomic,strong) NSString*logFilePath;
@property(nonatomic,strong) UIViewController* vc;
@property(nonatomic,strong) AdBasicCustomWebView* customWebViewClass;
@property(nonatomic,strong) id<AdLogicDelegate> adLogicDelegate;
/*
 * 更新显示的log
 */
- (void)updateLog:(NSString *)logText;

-(void) updateCacheLogs:(NSAttributedString*) cacheLogTexts;

-(void) hideKeyboard;

@end

