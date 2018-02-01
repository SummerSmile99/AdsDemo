
Pod::Spec.new do |s|
  s.name         = "MobGiAdSDK"
  s.version      = "2.7.0"
  s.summary      = "Mobgi Ad SDK"
  s.homepage     = "http://github.com/xlf999/AdsDemo"
  s.license      = "MIT"
  s.author       = { 'xlf999' => '1324005894@qq.com' }
  s.source       = { :git => 'https://github.com/xlf999/AdsDemo.git', :tag => s.version, :submodules => true }
  
  s.ios.deployment_target = '8.0'

  s.compiler_flags = '-ObjC', '-lstdc++'

  s.libraries = 'libz', 'ibc++', 'libsqlite3', 'libsqlite3.0','libxml2','libxml2.2','libstdc++','libstdc++.6','libstdc++.6.0.9'
  s.frameworks = 'GLKit','AVFoundation','CoreMedia','Security','CoreVideo','CFNetwork','MobileCoreServices','CoreData','CoreMotion','EventKit','EventKitUI','Mapkit','MessageUI','Twitter','CoreGraphics','CoreLocation','MediaPlayer','QuartzCore','SystemConfiguration','ImageIO','CoreFoundation','AudioToolbox','CoreBluetooth','JavaScriptCore','WatchConnectivity'
  s.weak_frameworks = 'Foundation','UIKit','AVKit','WebKit','AdSupport','StoreKit','CoreTelephony','Passkit','Social'

  s.subspec 'AggregationAdThirdSDKs' do |ss|

    ss.subspec 'Common' do |sss|
      sss.vendored_frameworks = 'AdsBasicFramework.framework','AdxAdsComponent.framework','AggregationAdsComponent.framework','CustomAdsModule.framework','SDKCommonModule.framework'
      sss.resources = ['*']
    end

    ss.subspec 'Adcolony' do |sss|
      sss.source_files = '*'
      sss.subspec '3.2.1' do |ssss|
        ssss.vendored_frameworks = 'AdColony.framework'
      end
    end

    ss.subspec 'Admob' do |sss|
      sss.source_files = '*'
      sss.vendored_frameworks = 'NetStabilizer.framework'
      sss.subspec '7.25.0' do |ssss|
        ssss.vendored_frameworks = 'GoogleMobileAds.framework'
      end
    end

    ss.subspec 'Adview' do |sss|
      sss.subspec '3.2.4' do |ssss|
        ssss.vendored_libraries = 'libAdCompViewSDK.a'
        ssss.subspec 'res' do |sssss|
          sssss.resources = ['*']
          sssss.requires_arc = false
        end
        ssss.subspec 'TouchJSON' do |sssss|
          sssss.source_files = '*'
        end
      end
    end

    ss.subspec 'Applovin' do |sss|
      sss.subspec '4.4.1' do |ssss|
        ssss.subspec '4.4.1' do |sssss|
          sssss.source_files = '*'
        end
        sssss.vendored_libraries = 'libAppLovinSdk.a'
      end
    end

    ss.subspec 'Appnext' do |sss|
      sss.subspec '1.8.3' do |ssss|
        ssss.subspec 'include' do |sssss|
          sssss.subspec 'AppnextLib' do |ssssss|
            sss.source_files = '*'
          end
          sssss.subspec 'AppnextSDKCore' do |ssssss|
            ssssss.source_files = '*'
          end
        end
        ssss.vendored_libraries = 'libAppnextLib.a','libAppnextSDKCore.a'
      end
    end

    ss.subspec 'Centrixlink' do |sss|
      sss.source_files = '*'
      sss.subspec '2.4.2' do |ssss|
        ssss.resource = 'CLBundle.bundle'
        ssss.vendored_frameworks = 'Centrixlink.framework'
      end
    end

    ss.subspec 'Chartboost' do |sss|
      sss.subspec '6.6.3' do |ssss|
        ssss.vendored_frameworks = 'Chartboost.framework'
      end
    end

    ss.subspec 'Domob' do |sss|
      sss.subspec '3.5.0' do |ssss|
        ssss.subspec 'Headers' do |sssss|
          sssss.source_files = '*'
        end
        sssss.resource = 'IndependentVideoBundle.bundle'
        ssss.vendored_libraries = 'libIndependentVideoSDK.a'
      end
    end

    ss.subspec 'GDT' do |sss|
      sss.subspec '4.4.5' do |ssss|
        ssss.source_files = '*'
        ssss.vendored_libraries = 'libGDTMobSDK.a'
      end
    end

    ss.subspec 'Glispa' do |sss|
      sss.subspec '1.9.8' do |ssss|
        ssss.source_files = '*'
        sssss.resource = 'LingTuiBundle.bundle'
        ssss.vendored_libraries = 'libLingTuiLibrary.a'
      end
    end

    ss.subspec 'Inmobi' do |sss|
      sss.subspec '6.1.1' do |ssss|
        ssss.vendored_frameworks = 'InMobiSDK.framework'
      end
    end

    ss.subspec 'Mobvista' do |sss|
      sss.source_files = '*'
      sss.subspec '2.8.1' do |ssss|
        ssss.vendored_frameworks = 'MVSDK.framework','MVSDKInterstitial.framework','MVSDKReward.framework'
      end
    end

    ss.subspec 'Oneway' do |sss|
      sss.subspec '1.2.0' do |ssss|
        ssss.source_files = '*'
        ssss.vendored_libraries = 'OneWaySDK.a'
      end
    end

    ss.subspec 'Supersonic' do |sss|
      sss.subspec '6.6.5' do |ssss|
        ssss.vendored_frameworks = 'IronSource.framework'
      end
    end

    ss.subspec 'Centrixlink' do |sss|
      sss.subspec '11.11.0' do |ssss|
        ssss.subspec 'Resources' do |sssss|
          sssss.resource = 'TapjoyResources.bundle'
        end
        ssss.vendored_frameworks = 'Tapjoy.framework'
      end
    end

    ss.subspec 'Unity' do |sss|
      sss.subspec '2.1.1' do |ssss|
        ssss.vendored_frameworks = 'UnityAds.framework'
      end
    end

    s.subspec 'Upltv' do |sss|
      sss.subspec '1.0.7' do |ssss|
        ssss.resource = 'PlayableAdsSDK.bundle'
        ssss.vendored_frameworks = 'PlayableAdsSDK.framework'
      end
    end

    ss.subspec 'Vungle' do |sss|
      sss.source_files = '*'
      sss.subspec '5.3.0' do |ssss|
        ssss.vendored_frameworks = 'VungleSDK.framework'
      end
    end

    ss.subspec 'Youmi' do |sss|
      sss.subspec '4.1.4' do |ssss|
        ssss.subspec 'include' do |sssss|
          sssss.source_files = '*'
        end
        sssss.resource = 'UMVideo.bundle'
        ssss.vendored_libraries = 'libUMVideoSDK.a'
      end
    end
    
  end
  
  s.subspec 'AggregationSDK' do |ss|

    ss.subspec 'VideoAds' do |sss|
      sss.source_files = '*'
      sss.vendored_libraries = 'libVideoPolymerizationSDK.a'
    end

    ss.subspec 'InterstitialAds' do |sss|
      sss.source_files = '*'
      sss.vendored_libraries = 'libInterstitialPolymerization.a' 
    end

    ss.subspec 'NativeAds' do |sss|
      sss.source_files = '*'
      sss.vendored_libraries = 'libNativePolymerization.a'
    end

    ss.subspec 'SplashAds' do |sss|
      sss.source_files = '*'
      sss.vendored_libraries = 'libSplashPolymerization.a'
    end

  end

  s.subspec 'CrossPromoteAd' do |ss|
    ss.source_files = '*'
    ss.vendored_libraries = 'libCrossPromoteAds.a'
  end

end
