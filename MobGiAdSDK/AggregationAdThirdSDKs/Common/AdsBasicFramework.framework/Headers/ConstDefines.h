
#define MobGikDDDefaultLogMaxFileSize       1024 * 1024      // 1 MB
#define MobGikDDDefaultLogRollingFrequency  60 * 60 * 24     // 24 Hours
#define MobGikDDDefaultLogMaxNumLogFiles    5               // 5 Files
#define MobGikDDDefaultLogFilesDiskQuota   20 * 1024 * 1024 // 20 MB


//这个宏在项目配置里进行设置
#ifndef MOBGI_ORIGIN_NSLOG_DEBUG
#define MOBGI_ORIGIN_NSLOG_DEBUG NO
#endif

//默认禁用原始日志执行，跟踪实现逻辑
#define MobGiOriginNSLogDebug(frmt, ...) do{ if(MOBGI_ORIGIN_NSLOG_DEBUG) NSLog((frmt), ##__VA_ARGS__); } while(0)


#ifndef MobGi_DD_NSLOG_LEVEL
#define MobGi_DD_NSLOG_LEVEL 0  //默认禁用NSLog日志调试
#endif

#define MobGiNSLogError(frmt, ...)    do{ if(MobGi_DD_NSLOG_LEVEL >= 1) NSLog((frmt), ##__VA_ARGS__); } while(0)
#define MobGiNSLogWarn(frmt, ...)     do{ if(MobGi_DD_NSLOG_LEVEL >= 2) NSLog((frmt), ##__VA_ARGS__); } while(0)
#define MobGiNSLogInfo(frmt, ...)     do{ if(MobGi_DD_NSLOG_LEVEL >= 3) NSLog((frmt), ##__VA_ARGS__); } while(0)
#define MobGiNSLogDebug(frmt, ...)    do{ if(MobGi_DD_NSLOG_LEVEL >= 4) NSLog((frmt), ##__VA_ARGS__); } while(0)
#define MobGiNSLogVerbose(frmt, ...)  do{ if(MobGi_DD_NSLOG_LEVEL >= 5) NSLog((frmt), ##__VA_ARGS__); } while(0)
