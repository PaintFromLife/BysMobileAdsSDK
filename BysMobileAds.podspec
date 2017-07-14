
Pod::Spec.new do |s|


  s.name         = "BysMobileAds"
  s.version      = "0.0.0.6"
  s.summary      = "BysMobileAds_SDK"
  s.description  = <<-DESC
        BysMobileAds_SDK (0.0.0.6)
                   DESC
  s.homepage     = "https://github.com/baiyisoftware/BysMobileAdsSDK"
  s.license      = { :type => "MIT", :file => "LICENSE" }


  s.author       = { "TemaSir" => "tianxin@gsoft.cc" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/baiyisoftware/BysMobileAdsSDK.git", :tag => s.version }
  s.frameworks   = "UIKit","Foundation","AVFoundation","Security","MobileCoreServices","StoreKit"
  s.requires_arc = false
  s.ios.vendored_frameworks = 'BysMobileAds_SDK/BysMobileAds.framework'
  #s.xcconfig  = { 'USER_HEADER_SEARCH_PATHS' => '"$(PODS_ROOT)"' }
  #s.dependency 'FBSDKCoreKit'
  s.resource     = 'Resources/BYSAdBundle.bundle'
end