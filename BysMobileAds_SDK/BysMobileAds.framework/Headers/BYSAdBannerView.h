//
//  BYSAdBannerView.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 16/12/30.
//
//

#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdBaseAdView.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN

@class BYSAdBanner;
@class BYSAdBannerView;

/// Positions to place a banner.
typedef NS_ENUM(NSUInteger, BYAdPosition) {
    BYADAdPositionTopOfScreen = 0,      ///< Ad positioned at top of screen.
    BYADAdPositionBottomOfScreen ,      ///< Ad positioned at bottom of screen.
    BYADAdPositionTopLeftOfScreen ,     ///< Ad positioned at top left of screen.
    BYADAdPositionTopRightOfScreen ,    ///< Ad positioned at top right of screen.
    BYADAdPositionBottomLeftOfScreen ,  ///< Ad positioned at bottom left of screen.
    BYADAdPositionBottomRightOfScreen   ///< Ad positioned at bottom right of screen.
};


@protocol BYSAdBannerDelegate <NSObject>

@optional

///Banner ad receives a data callback
- (void)bannerDidReceivedData:(BYSAdBanner *)banner;

///Banner ad received data failed callback
- (void)bannerFailToReceiveData:(BYSAdBanner *)ad withError:(NSError *)error;

///Banner ads are coming soon
- (void)bannerWillPresent:(BYSAdBanner *)banner;

///Banner ads have already appeared
- (void)bannerDidPresent:(BYSAdBanner *)banner;

///Banner ad click
- (void)bannerDidClicked:(BYSAdBanner *)banner;

///Banner ad is closed
- (void)bannerDidClosed:(BYSAdBanner *)banner;


///Banner ad plays video
- (void)bannerPlayVideo:(BYSAdBanner *)banner;

///Banner ad video playback is complete
- (void)bannerPlayVideoFinshed:(BYSAdBanner *)banner;

@end


/// A wrapper around BYSAdBannerView. Includes the ability to create BYSAdBannerView objects, load them
/// with ads, and listen for ad events.
@interface BYSAdBanner : NSObject

@property(nonatomic, weak) id <BYSAdBannerDelegate> delegate;


/// create a BYSAdBanner with specified width and height, positioned at either the top or
/// bottom of the screen.
+ (instancetype)createBannerWithUnitKey:(NSString *BYSAD_NULLABLE_TYPE)adUnitKey
                                   size:(CGSize)size
                             adPosition:(BYAdPosition)adPosition;

/// create a full-width BYSAdBanner, positioned at either the top or bottom of the screen.
+ (instancetype)createSmartBannerWithUnitKey:(NSString *BYSAD_NULLABLE_TYPE)adUnitKey
                                  adPosition:(BYAdPosition)adPosition;


/// Makes an ad request. Additional targeting options can be supplied with a request object.
- (void)load;

/// check if ad ready is ready
- (BOOL)isReady;

///Set the cycle time
- (void)setCircleTime:(CGFloat)time;

/// Makes the ad View hidden on not.
- (void)hideBanner:(BOOL)isHiden;

/// show banner on screen
- (void)show;

/// close banner
- (void)close;

@end

///Banner ad loading display
@interface BYSAdBannerView : BYSAdBaseAdView
    
@property(nonatomic, assign ,readonly) BOOL autoShowWhenADReady;

@end

BYSAD_ASSUME_NONNULL_END
