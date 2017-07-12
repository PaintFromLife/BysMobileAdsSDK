//
//  BYSAdBannerView.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 16/12/30.
//
//

#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdBaseAdView.h>

@interface BYSAdBannerView : BYSAdBaseAdView
    
@property(nonatomic, assign) BOOL autoShowWhenADReady;

/// set gap of Recycle time between next ad, if seconds==0,time is decide by web survice.
- (void)setBannerRepeatTimeInSeconds:(CGFloat)seconds;

/// load AD data
- (void)loadADData;

/// check if AD data is loaded
- (BOOL)isADDataReady;

/// show ad view
- (void)showADView;

/// close timer and remove ad view
- (void)removeADView;

@end
