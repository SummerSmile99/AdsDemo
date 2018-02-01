
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  原生广告数据类，接入方根据里面的属性，自行绘制界面
 */
@interface NativeAdData : NSObject

#pragma mark -

//广告位ID
@property(nonatomic,strong) NSString* blockid;

//平台名
@property (copy, nonatomic) NSString *adName;

//标题
@property (copy, nonatomic) NSString *  title;

//图标icon本地缓存地址
@property (strong, nonatomic ) NSString* iconLocalURL;

//大图image本地缓存地址,mainfigureImgUrls里的第一个元素
@property (strong, nonatomic) NSString * imageLocalURL;

//主图本地缓存数组
@property(nonatomic,strong) NSArray* mainfigureLocalImgUrls;

//描述信息
@property (copy, nonatomic) NSString * descriptionText;

//评分
//值为1到10
@property(nonatomic,assign) double rating;

//行动语
@property(nonatomic,strong) NSString* actionLanguageText;


#pragma mark -
//额外信息
@property (nonatomic, strong) NSDictionary* extras;

//大图image
@property(nonatomic,strong) UIImage* bigImage;

//图标icon
@property(nonatomic,strong) UIImage* iconImage;

//废弃的字段

//@property (assign, nonatomic) int  adIdNumber;


//@property (copy, nonatomic) NSString * captionText;
//
//@property (copy, nonatomic) NSString *  ctaText;

//图标icon网络地址
@property (strong, nonatomic ) NSString* iconURL;

//大图image网络地址
@property (strong, nonatomic) NSString * imageURL;


@end
