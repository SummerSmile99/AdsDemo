//
//  LingTuiUser.h
//  LingTuiLibrary
//
//  Created by sweetchao on 16/11/4.
//  Copyright © 2016年 LingTui. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LingTuiAudience : NSObject
@property(nonatomic,assign) int age;/*用户年龄*/
@property(nonatomic,assign) int gender; /*性别 ： 0：未知；1：男；2：女；*/
@property(nonatomic,strong) NSString * keywords; /*关键字 ：用','分隔关键字*/
@property(nonatomic,strong) NSString * birthday;/*生日 ：格式为"yyyy-MM-dd"*/
@property(nonatomic,strong) NSString * postalcode;/*邮编*/
@property(nonatomic,strong) NSString * hobbies;/*爱好*/
@property(nonatomic,strong) NSString * work;/*职业*/
@property(nonatomic,assign) int salary;/*收入：整数，以元为单位*/
@property(nonatomic,assign) int education;/*用户最高教育学历 ： 学历输入数字，范围为0-6   0代表小学，1代表初中，2代表中专/高中，3代表专科，4代表本科，5代表硕士，6代表博士*/
-(void)setUser;

@end
