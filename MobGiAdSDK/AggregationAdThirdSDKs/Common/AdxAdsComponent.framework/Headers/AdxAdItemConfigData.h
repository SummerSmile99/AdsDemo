//
//  AdxAdItemConfigData.h
//  HouseAdClientComponent
//
//  Created by star.liao on 2017/4/9.
//  Copyright © 2017年 star.liao. All rights reserved.
//

@protocol AdxAdItemConfigData
@end

@interface AdxAdItemConfigData :NSObject

@property(strong) NSString* requestId;
@property(strong) NSString* adUnitId;
@property(strong) NSString* adId;
@property(strong) NSString* originalityId;
@property(strong) NSString* targetUrl;
@property(strong) NSString* adType;

@property(strong) NSString* closeButton;
@property(strong) NSString* jumpType;

@property(nonatomic,strong) NSString* packageName;
@property(nonatomic,strong) NSString* adName;
@property(nonatomic,strong) NSString* iconUrl;
@property(nonatomic,strong) NSString* deepLink;

@property(nonatomic,strong) NSArray* reportDataShowUrl;
@property(nonatomic,strong) NSArray* reportDataClickUrl;

@property(nonatomic,assign) BOOL closeBtnIsDelayShow;
@property(nonatomic,assign) int delayShowCloseBtnTimes; //关闭按钮延迟多少秒展示
@property(nonatomic,assign) int jumpAppStoreType;
@property(nonatomic,strong) NSString* networkAdVersion;


@property(nonatomic,assign) int chargeType;
@property(nonatomic,strong) NSString* bidId;
@property(nonatomic,strong) NSString* dspId;
@property(nonatomic,strong) NSString* outBidid;
@property(nonatomic,strong) NSString* nurl;
@property(nonatomic,assign) int width;
@property(nonatomic,assign) int height;
@property(nonatomic,strong) NSString* adDesc;
@property(nonatomic,strong) NSString* price;
@property(nonatomic,assign) int currency;
@property(nonatomic,strong) NSString* versionCode;

@property(nonatomic,strong) NSArray* reportDataVideoEndUrl;
@property(nonatomic,strong) NSArray* reportDataHtmlCloseUrl;

@property(nonatomic,assign) BOOL isDspAd;

//2.7.0增加
@property (nonatomic,strong) NSString *configId;
@property (nonatomic,assign) int userType;

//构造聚合广告商信息-名称和版本号
-(instancetype) initNetworkAdName:(NSString*)adName
                   networkVersion:(NSString*)adVersion;

-(void) adpater;

@end
