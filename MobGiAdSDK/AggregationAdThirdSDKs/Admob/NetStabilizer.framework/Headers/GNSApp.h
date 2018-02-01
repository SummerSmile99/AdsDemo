#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// How Network Stability Utility being enabled.
typedef NS_ENUM(NSUInteger, GNSSwitchSetting) {
  GNSSwitchSettingOff,
  GNSSwitchSettingPreferredOn,
  GNSSwitchSettingForcedOn
};

/// Entry point to Network Stability Utility.
@interface GNSApp : NSObject

/// The switch of features in this utility.
@property GNSSwitchSetting switchSetting;

/// Configures the utility.
+ (void)configure;

/// Shared instance of GNSApp.
+ (GNSApp *)sharedInstance;

/// Sets domainNames to be protected as user requested.
- (void)setProtectedDomainNames:(NSArray<NSString *> *)domainNames;

/// Returns array of NSURLProcotol which required by the features of utility.
/// Callers can configure NSURLSession by returned NSURLProcotol when they need protection.
+ (NSArray<Class> *)requiredURLProcotols;

@end

NS_ASSUME_NONNULL_END
