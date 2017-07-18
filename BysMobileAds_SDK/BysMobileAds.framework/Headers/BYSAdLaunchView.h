//
//  BYADScrollView.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 17/1/11.
//
//

#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN


@class BYSAdLaunch;
@class BYSAdLaunchView;

@protocol BYSAdLaunchDelegate <NSObject>

@required

///When the screen ads receive data, callback
- (void)LaunchDidReceivedData:(BYSAdLaunch *)launch;

///The open screen ad receives a callback when the data fails
- (void)LaunchFailToReceiveData:(BYSAdLaunch *)launch withError:(NSError *)error;

///Open screen advertising video callback callback
- (void)LaunchPlayVideo:(BYSAdLaunch *)launch;

///Open screen advertising video playback is complete
- (void)LaunchPlayVideoFinished:(BYSAdLaunch *)launch;

///Open screen ad click
- (void)LaunchDidClicked:(BYSAdLaunch *)launch;

///Open screen ads closed
- (void)LaunchDidClosed:(BYSAdLaunch *)launch;

@end

@protocol BYSAdLaunchViewDelegate <NSObject>

@required
///Open a screen to select the current page
- (void)BYSAdLaunchView:(BYSAdLaunchView *)launchView didSelectedAtIndex:(NSInteger)index;

///The open screen ad slides and does not close when the callback is made
- (void)BYSAdLaunchViewNotAutoClose:(BYSAdLaunchView *)launchView;

///Callback when open screen ad is hidden
- (void)BYSAdLaunchViewShutdown:(BYSAdLaunchView *)launchView;

///Open screen advertising video playback callback
- (void)BYSAdLaunchViewPlayVideo:(BYSAdLaunchView *)launchView;

///Open screen advertising video playback is complete
- (void)BYSAdLaunchViewPlayVideoFinished:(BYSAdLaunchView *)launchView;

@end



///AdLaunch is used to initialize the configuration of open screen ads

@interface BYSAdLaunch : NSObject

@property(nonatomic, weak) id<BYSAdLaunchDelegate> delegate;

/// create or fetch open ad single instance
+ (instancetype)shareInstance;

/// init open ad with an unitKey
- (void)initADLaunchWithUnitkey:(NSString * BYSAD_NULLABLE_TYPE)unitKey;

/// create open ad instance and set it's delegate
+ (void)ConfigLaunchWithUnitKey:(NSString * BYSAD_NULLABLE_TYPE)unityKey delegate:(id<BYSAdLaunchDelegate>)delegate;

@end

///AdLaunchView open screen advertising display, configured by adLaunch

@interface BYSAdLaunchView : UIView

@property(nonatomic, weak) id<BYSAdLaunchViewDelegate> adDelegate;

@end

BYSAD_ASSUME_NONNULL_END
