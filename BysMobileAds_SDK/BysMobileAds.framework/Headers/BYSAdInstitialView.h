//
//  BYSAdInstitialView.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 16/12/20.
//  Copyright © 2016年 陕西百益软件有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdBaseAdView.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN

@class BYSAdInstitial;
@class BYSAdInstitialView;

@protocol BYSAdInstitialDelegate<NSObject>

@required

///The interstitial ad receives a data callback
- (void)institialDidReceivedData:(BYSAdInstitial *)institial;

///Interstitial ad receives data failure callback
- (void)institialFailToReceiveData:(BYSAdInstitial *)institial withError:(NSError *)error;

///The interstitial ad is about to appear
- (void)institialWillPresent:(BYSAdInstitial *)institial;

///The interstitial ad has been displayed
- (void)institialDidPresent:(BYSAdInstitial *)institial;

///Interstitial ads have been clicked
- (void)institialDidClicked:(BYSAdInstitial *)institial;

///The interstitial ad has been closed
- (void)institialDidClosed:(BYSAdInstitial *)institial;

///Interstitial callback when playing video
- (void)institialPlayVideo:(BYSAdInstitial *)institial;

///The interstitial ad plays the video when the callback is complete
- (void)institialPlayVideoFinished:(BYSAdInstitial *)institial;

@end


///Interstitial ad configuration
@interface BYSAdInstitial : NSObject

@property(nonatomic, weak) id <BYSAdInstitialDelegate> delegate;

/// create an Institial ad with an unitkey
+ (instancetype)createADInstitialWithUnityKey:(NSString *BYSAD_NULLABLE_TYPE)unitKey;

/// load Institial ad
- (void)load;

/// check if Institial is ready
- (BOOL)isReady;

/// show Institial ad
- (void)show;

/// close Institial ad
- (void)close;

@end


///The loading of the interstitial ad is displayed
@interface BYSAdInstitialView :BYSAdBaseAdView

@property(nonatomic, assign ,getter=isADReady ,readonly) BOOL adReady;

@end

BYSAD_ASSUME_NONNULL_END
