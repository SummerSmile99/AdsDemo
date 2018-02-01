

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface SULogger : NSObject

@property(nonatomic,assign) BOOL isUpdateLogOnHiddenState;
@property (atomic,assign) BOOL isEnableCPLogMode;
@property (nonatomic,strong) NSString *aggregationAdConfigResult;
//给子类重写!
/**
 *  描述：初始化Logger
 */
- (void)start;

+ (instancetype)logger;

- (void)start:(NSString*)log_file_path vc:(UIViewController*)vc;

#pragma mark -

/**
 *  描述：改变Log面板状态(隐藏->显示 or 显示->隐藏)
 */
- (void)visibleChange:(UIViewController*) vc;

-(double) getLoggerPannelOriginY;

//给子类调用
-(void) superSendLog:(NSString*)log level:(NSString*)level;

- (void)show:(UIViewController*) vc;

- (void)hide ;

-(void) alertView:(NSString*)message
            title:(NSString*)title;

@end

