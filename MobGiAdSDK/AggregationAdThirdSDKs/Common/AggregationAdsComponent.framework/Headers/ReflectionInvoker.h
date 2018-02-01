//
//  DynamicLoadClass.h
//  TestVideoAdAggregation
//
//  Created by star.liao on 16/4/22.
//  Copyright © 2016年 star.liao. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface ReflectionInvoker : NSObject

/**
 * 判断某个类是否已经加载，一般用来判断某家广告商是否已经聚合？
 */
+(BOOL) isHasLoadClass:(NSString*) className;

/**
 * 创建某个类的单例，比如[className sharedInstance]
 */
+(id) createClassSharedInstance:(NSString*) className;

/**
 * 创建某个类的单例，比如[className sharedInstanceFunctionName]
 */
+(id) createClass:(NSString*) className
   sharedInstance:(SEL) sharedInstanceFunctionName;

/**
 * 反射调用: [[className sharedInstance:para] functionName]
 *
 */
+(void) singleClassName:(NSString*) className
         sharedInstance:(SEL) sharedInstance
                   para:(id) para
           functionName:(SEL) functionName;

/**
 * 反射调用: [[className sharedInstance] functionName]
 *
 */
+(void) singleClassName:(NSString*) className
         sharedInstance:(SEL) sharedInstance
           functionName:(SEL) functionName;

/**
 * 反射调用: [AdwoSDK loadAd]=> [ReflectionInvoker invokeStaticFunction:@"AdwoSDK" functionName:@selector(loadAd)];
 *
 *
 *
 */
+(id) invokeStaticFunction:(NSString*) className
              functionName:(SEL) functionName;

/**
 *  反射调用:[self.interstitial load];
 *
 *
 */
+(id) invokeClass:(NSString*) className
              obj:(id) objVal
     functionName:(SEL) functionName;

/**
 * 获取某个类的实例，比如[[className alloc] init]
 */
+(id) getClassInstance:(NSString*)className;


/**
 *  反射调用:  self.interstitial=[[GADInterstitial alloc] initWithAdUnitID::self.thirdBlockid]=>self.interstitial=[ReflectionInvoker invokeStaticFunction:@"GADInterstitial" initFunction:@selector(initWithAdUnitID:) parasType:nil paras:self.thirdBlockid, nil];
 *
 *  @param className
 *  @param initFunction
 *  @param parasType    @"CGRect",@"CGSize",@"NSInteger",@"int",@"LongLong",@"Bool",@"Double",nil,@"",@" "
 *  @param para         NSObject*，NSNumber*,NSValue*
 *
 *  @return NSObject*，NSNumber*,NSValue*
 */
+(id) invokeStaticFunction:(NSString*) className
              initFunction:(SEL) initFunction
                 parasType:(NSArray*)parasType
                     paras:(id)para, ...NS_REQUIRES_NIL_TERMINATION;

/**
 *  反射调用:  id sdk=[ALSdk sharedWithKey:advertiser.thirdPartyAppkey]   =>  id sdk= [ReflectionInvoker invokeStaticFunction:@"ALSdk" functionName:@selector(sharedWithKey:) parasType:nil paras:advertiser.thirdPartyAppkey, nil];
 *
 *  @param className
 *  @param functionName
 *  @param parasType    @"CGRect",@"CGSize",@"NSInteger",@"int",@"LongLong",@"Bool",@"Double",nil,@"",@" "
 *  @param para         NSObject*，NSNumber*,NSValue*
 *
 *  @return NSObject*，NSNumber*,NSValue*
 */
+(id) invokeStaticFunction:(NSString*) className
              functionName:(SEL) functionName
                 parasType:(NSArray*)parasType
                     paras:(id)para, ...NS_REQUIRES_NIL_TERMINATION;

/**
 *  反射调用: [[MobgiAdSDK shareInstance] showCachedPromotionAd]
 *
 *  @param className    类名
 *  @param msg
 *  @param function
 *
 *  @return NSObject*，NSNumber*,NSValue*
 */
+(id) invokeClass:(NSString*) className
              msg:(SEL) msg
         function:(SEL) function;
/**
 *  反射调用: [[MobgiAdSDK shareInstance] showCachedPromotionAd:self.vc blockId:@"**" delegate:self]
 *
 *  @param className    类名
 *  @param msg
 *  @param function
 *  @param parasType    @"CGRect",@"CGSize",@"NSInteger",@"int",@"LongLong",@"Bool",@"Double",nil,@"",@" "
 *  @param para         NSObject*，NSNumber*,NSValue*
 *
 *  @return NSObject*，NSNumber*,NSValue*
 */
+(id) invokeClass:(NSString*) className
              msg:(SEL) msg
         function:(SEL) initFunction
        parasType:(NSArray*)parasType
            paras:(id)para, ...NS_REQUIRES_NIL_TERMINATION;

/**
 *  反射调用：[self.interstitial loadRequest:request]  => [ReflectionInvoker invokeObj:self.interstitial class:NSClassFromString(@"GADInterstitial") function:@selector(loadRequest:) parasType:nil paras:request,nil];
 *
 *  @param target
 *  @param class
 *  @param function
 *  @param parasType @"CGRect",@"CGSize",@"NSInteger",@"int",@"LongLong",@"Bool",@"Double",nil,@"",@" "
 *  @param para      NSObject*，NSNumber*,NSValue*
 *
 *  @return NSObject*，NSNumber*,NSValue*
 */
+(id) invokeObj:(id) target
          class:(Class)className
function:(SEL) function
parasType:(NSArray*)parasType
paras:(id)para, ...NS_REQUIRES_NIL_TERMINATION;
@end
