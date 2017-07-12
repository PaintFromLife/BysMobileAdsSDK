//
//  BYSAdBaseAdView.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 16/12/30.
//
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>


@protocol BYADAdViewDelegate <NSObject>

@optional

- (void)adViewDidReceiveAD:(nullable id)adView;                                      /// ad data load sucess callback
- (void)adView:(nullable id)adView didFailToReceiveAdWithError:(nullable NSError *)error;    /// ad data load false callback
- (void)adViewOnClicked:(nullable id)adView;                     /// ad view is clicked callback
- (void)adViewWillPresentScreen:(nullable id)adView;           /// ad view will show on screen callback
- (void)adViewDidPresentScreen:(nullable id)adView;            /// ad view is show on screen callback
- (void)adViewOnClosed:(nullable id)adView;                    /// ad view close callback

- (void)adViewPlayVideo:(nullable id)adView;
- (void)adViewPlayVideoFinished:(nullable id)adView;

@end


@interface BYSAdBaseAdView : UIImageView

@property(nonatomic, strong ,nonnull ,readonly) NSString *unitKey;             /// unit key
@property(nonatomic, assign ,nonnull) id<BYADAdViewDelegate> adDelegate;    /// ad view delegate

/// load ad data list
- (void)loadAdList;

/// after load ad data list do something (this function must be overwritened in the subclass)
- (void)afterLoadADList;

/// do some ad init and fetch ad position infomation
- (void)initWithUnit:(nullable NSString *)unityKey;

/// show close button and webUrl button
- (void)showFunctionButtons;

/// remove ad view
- (void)removeADView;

- (void)playeMovie:(nullable NSString *)urlStr;

- (void)shutDownMovieShow;


@end
