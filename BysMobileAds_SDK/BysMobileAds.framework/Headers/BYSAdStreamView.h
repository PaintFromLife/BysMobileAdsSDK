//
//  BYSAdStreamView.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 17/2/7.
//  Copyright © 2017年 陕西百益软件有限公司. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN

@class BYSAdStream;
@class BYSAdStreamView;
@protocol BYSAdStreamViewDelegate;

@protocol BYSAdStreamDelegate <NSObject>

@optional

/// ad data load sucess callback
- (void)BYSAdStreamDidReceiveData:(BYSAdStream *)streamAd;

/// ad data load false callback
- (void)BYSAdStream:(BYSAdStream *)Ad didFailToReceiveDataWithError:(NSError *)error;

@end

@protocol BYSAdStreamViewDelegate <NSObject>

///When an ad stream ad is clicked
- (void)BYSAdStreamViewDidClicked:(BYSAdStreamView *)streamView;

//When the stream ad load is complete
- (void)BYSAdStreamViewLayoutFinished:(BYSAdStreamView *)streamView;

@end


///AdStream is used to configure the traffic advertisement and generate a stream of advertisements.
///The BYSAdStreamViewDelegate completes the callback that you can load the ad to show

@interface BYSAdStream : NSObject

///unitKey
@property (nonatomic, strong ,readonly) NSString *unitKey;

/// BYSAdStreamDelegate
@property (nonatomic, weak) id<BYSAdStreamDelegate> delegate;

/// Title font size
@property (nonatomic, strong) UIFont *titleFont;

/// Subtitle font size font size
@property (nonatomic, strong) UIFont *subTitleFont;

/// Content font size
@property (nonatomic, strong) UIFont *contentFont;

/// Title font color
@property (nonatomic, strong) UIColor *titleColor;

/// Subtitle font color
@property (nonatomic, strong) UIColor *subTitleColor;

/// Content font color
@property (nonatomic, strong) UIColor *contentColor;

/// Initialize traffic advertising based on Unitkey
/// unitKey AdUnitkey is requested from the ad developer platform
+ (instancetype)createStreamWithUnitkey:(NSString * BYSAD_NULLABLE_TYPE)unitKey;

/// Generate BYSAdStreamView, font size and color must be configured before the method
- (BYSAdStreamView *)makeAdViewWithStreamViewDelegate:(id<BYSAdStreamViewDelegate>)delegate;

/// Unify configuration view parameters
- (void)setTitleFont:(UIFont *)titleFont
        SubTitleFont:(UIFont *)subTitleFont
         ContentFont:(UIFont *)ContentFont
          TitleColor:(UIColor *)titleColor
       SubTitleColor:(UIColor *)subTitleColor
        ContentColor:(UIColor *)ContentColor;

@end

///AdStreamView is configured by AdStream
///and is loaded when the AdStreamView callback is displayed

@interface BYSAdStreamView : UIView

@property (nonatomic, weak) id<BYSAdStreamViewDelegate> delegate;

@end

BYSAD_ASSUME_NONNULL_END
