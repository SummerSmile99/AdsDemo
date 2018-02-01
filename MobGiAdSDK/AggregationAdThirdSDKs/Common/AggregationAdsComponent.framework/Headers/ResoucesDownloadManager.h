//
//  ResoucesDownloadManager.h
//  AggregationAdsComponent
//
//  Created by star.liao on 2017/3/1.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ResourcesDownloadDelegate <NSObject>

@required

-(void) downloadSuccess;

-(void) downloadError;

@end


@interface ResoucesDownloadManager : NSObject

- (void)downLoadWithUrlString:(NSString *)urlString
            withStoreLocalUrl:(NSString*)localUrl
                     delegate:(id<ResourcesDownloadDelegate>) delegate;

+(NSString *)generateFileLocalStorePath:(NSString*)url
                                blockid:(NSString*)blockid
                               platName:(NSString*)platName;

+(BOOL) cleanupResource:(NSString*)localUrl;

@end
