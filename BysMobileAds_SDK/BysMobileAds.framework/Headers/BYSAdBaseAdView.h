//
//  BYSAdBaseAdView.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 16/12/30.
//
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN

@protocol BYADAdViewDelegate <NSObject>

@optional

/// ad data load sucess callback
- (void)adViewDidReceiveAD:(BYSAD_NULLABLE id)adView;

/// ad data load false callback
- (void)adView:(BYSAD_NULLABLE id)adView didFailToReceiveAdWithError:(BYSAD_NULLABLE NSError *)error;

/// ad view is clicked callback
- (void)adViewOnClicked:(BYSAD_NULLABLE id)adView;

/// ad view will show on screen callback
- (void)adViewWillPresentScreen:(BYSAD_NULLABLE id)adView;

/// ad view is show on screen callback
- (void)adViewDidPresentScreen:(BYSAD_NULLABLE id)adView;

/// ad view close callback
- (void)adViewOnClosed:(BYSAD_NULLABLE id)adView;

/// ad view play video callback
- (void)adViewPlayVideo:(BYSAD_NULLABLE id)adView;

/// ad view play video finish callback
- (void)adViewPlayVideoFinished:(BYSAD_NULLABLE id)adView;

@end

@interface BYSAdBaseAdView : UIImageView

@property(nonatomic, strong ,readonly) NSString *unitKey;             /// unit key
@property(nonatomic, weak ) id<BYADAdViewDelegate> adDelegate;    /// ad view delegate

/// load ad data list
- (void)loadAdList;

/// after load ad data list do something (this function must be overwritened in the subclass)
- (void)afterLoadADList;

/// do some ad init and fetch ad position infomation
- (void)initWithUnit:(NSString *BYSAD_NULLABLE_TYPE)unityKey;

/// show close button and webUrl button
- (void)showFunctionButtons;

/// remove ad view
- (void)removeADView;

///Play video with URL link
- (void)playeMovie:(NSString *BYSAD_NULLABLE_TYPE)urlStr;

///Stop playing and hide
- (void)shutDownMovieShow;

@end
BYSAD_ASSUME_NONNULL_END
