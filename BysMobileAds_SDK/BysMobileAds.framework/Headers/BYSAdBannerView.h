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

@protocol BYSAdBannerDelegate <NSObject>

@required
- (void)BannerDidReceivedData:(BYSAdBanner *)banner;
- (void)BannerFailToReceiveData:(BYSAdBanner *)ad withError:(NSError *)error;
- (void)BannerWillPresent:(BYSAdBanner *)banner;
- (void)BannerDidPresent:(BYSAdBanner *)banner;
- (void)BannerDidClicked:(BYSAdBanner *)banner;
- (void)BannerDidClosed:(BYSAdBanner *)banner;

- (void)BannerPlayVideo:(BYSAdBanner *)banner;
- (void)BannerPlayVideoFinshed:(BYSAdBanner *)banner;

@end

/// Positions to place a banner.
typedef NS_ENUM(NSUInteger, BYAdPosition) {
    BYADAdPositionTopOfScreen = 0,      ///< Ad positioned at top of screen.
    BYADAdPositionBottomOfScreen ,      ///< Ad positioned at bottom of screen.
    BYADAdPositionTopLeftOfScreen ,     ///< Ad positioned at top left of screen.
    BYADAdPositionTopRightOfScreen ,    ///< Ad positioned at top right of screen.
    BYADAdPositionBottomLeftOfScreen ,  ///< Ad positioned at bottom left of screen.
    BYADAdPositionBottomRightOfScreen   ///< Ad positioned at bottom right of screen.
};

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
