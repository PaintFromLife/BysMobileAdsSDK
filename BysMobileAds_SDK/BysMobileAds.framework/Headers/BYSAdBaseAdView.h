//
//  BYSAdBaseAdView.h
//  Unity-iPhone
//
//  Created by hanJianXin on 16/12/30.
//
//

#import <UIKit/UIKit.h>
#import "BYSAdDataModels.h"
#import "BYSAdBannerUnitInfoModel.h"
#import "BYSAdUtil.h"
#import <AVFoundation/AVFoundation.h>


@protocol BYADAdViewDelegate <NSObject>

@optional

- (void)adViewDidReceiveAD:(id)adView;                                      /// ad data load sucess callback
- (void)adView:(id)adView didFailToReceiveAdWithError:(NSString *)error;    /// ad data load false callback
- (void)adViewOnClicked:(id)adView;                     /// ad view is clicked callback
- (void)adViewWillPresentScreen:(id)adView;           /// ad view will show on screen callback
- (void)adViewDidPresentScreen:(id)adView;            /// ad view is show on screen callback
- (void)adViewOnClosed:(id)adView;                    /// ad view close callback

- (void)adViewPlayVideo:(id)adView;
- (void)adViewPlayVideoFinished:(id)adView;

@end


@interface BYSAdBaseAdView : UIImageView

@property(nonatomic, strong) NSString *unitKey;             /// unit key
@property(nonatomic, assign) id<BYADAdViewDelegate> adDelegate;    /// ad view delegate
@property(nonatomic, strong) BYADAdDataModel *curAdModel;
@property(nonatomic, strong) BYSAdBannerUnitInfoModel *adUnitInfo;               /// ad unit info

@property(nonatomic, strong) NSMutableArray *dataArray;

/// load ad data list
- (void)loadAdList;

/// after load ad data list do something (this function must be overwritened in the subclass)
- (void)afterLoadADList;

/// do some ad init and fetch ad position infomation
- (void)initWithUnit:(NSString *)unityKey;

/// show close button and webUrl button
- (void)showFunctionButtons;

/// remove ad view
- (void)removeADView;

- (void)playeMovie:(NSString *)urlStr;

- (void)shutDownMovieShow;


@end
