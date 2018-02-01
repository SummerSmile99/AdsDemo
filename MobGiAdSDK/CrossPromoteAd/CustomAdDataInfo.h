//
//  CustomAdDataInfo.h
//  CrossPromoteAds
//
//  Created by star.liao on 2017/5/29.
//  Copyright © 2017年 com.idreamsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CustomAdDataInfo : NSObject

//标题
@property (copy, nonatomic) NSString *  title;

//图标icon网络地址
@property (strong, nonatomic ) NSString* iconURL;

//图标icon本地缓存地址
@property (strong, nonatomic ) NSString* iconLocalURL;

//描述信息
@property (copy, nonatomic) NSString * descriptionText;

//广告位ID
@property(nonatomic,strong) NSString* blockid;

-(NSString*) toString;

@end
