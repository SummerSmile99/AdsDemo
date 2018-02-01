//
//  LingTuiNativeAdInfo.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/8/30.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LingTuiNativeAdNetworkAdapter.h"
@interface LingTuiNativeAdInfo : NSObject

@property(nonatomic,strong) NSString * adTitle;  //广告标题
@property(nonatomic,strong) NSString * icon_Url; //广告图标url
@property(nonatomic,assign) int icon_Width; //广告图标宽度
@property(nonatomic,assign) int icon_Height; //广告图标高度
@property(nonatomic,strong) NSString * adDescripition;//广告描述
@property(nonatomic,strong) NSString * image_Url; //广告内容图片url
@property(nonatomic,assign) int image_Width; //广告内容图片宽度
@property(nonatomic,assign) int image_Height; //广告内容图片高度
@property(nonatomic,strong) NSString * itid; //广告点击下载app的itunes ID;
@property(nonatomic,strong) NSString * linktype;// 广告点击后行为
@property(nonatomic,strong) NSString *  ration_name; //平台名称
@property(nonatomic,strong) NSString * rating;//应用评分



@property(nonatomic,assign) id  pdata; //平台数据对象
@property(nonatomic,strong) LingTuiNativeAdNetworkAdapter * adapter;
@property(nonatomic,strong) NSString *  adid;
@property(nonatomic,strong) NSString *  rid;
@property(nonatomic,strong) NSString *  scid;
@property(nonatomic,strong) NSString *  sid;
@property (nonatomic,assign) BOOL  isClick;
@property(nonatomic,strong) NSDictionary * tracksDict;
@property(nonatomic,strong) NSDictionary * clickDict;
@property (nonatomic,assign) id  et;
-(void)attachAdView:(UIView*)view; // 广告展示时调用
-(void)clickAd; //广告点击时调用
-(BOOL)isAvailable:(LingTuiNativeAdInfo *)info;
@end
