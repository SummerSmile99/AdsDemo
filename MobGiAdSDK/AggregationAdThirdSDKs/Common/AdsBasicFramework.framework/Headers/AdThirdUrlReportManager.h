//
//  AdThirdUrlReportManager.h
//  HouseAdClientComponent
//
//  Created by star.liao on 2017/7/17.
//  Copyright © 2017年 star.liao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AdThirdUrlReportManager : NSObject

-(void) requestThirdUrl:(NSArray*)url;

-(void) reportUrl:(NSString*)url;

@end
