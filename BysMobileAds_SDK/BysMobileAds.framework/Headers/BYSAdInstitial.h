//
//  BYSAdInstitial.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 16/12/1.
//  Copyright © 2016年 陕西百益软件有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BYSAdInstitial;
@class BYSAdInstitialView;

@protocol BYSAdInstitialDelegate<NSObject>

@required
- (void)InstitialDidReceivedData:(nullable BYSAdInstitial *)Institial;
- (void)InstitialFailToReceiveData:(nullable BYSAdInstitial *)Institial withError:(nullable NSError *)error;
- (void)InstitialWillPresent:(nullable BYSAdInstitial *)Institial;
- (void)InstitialDidPresent:(nullable BYSAdInstitial *)Institial;
- (void)InstitialDidClicked:(nullable BYSAdInstitial *)Institial;
- (void)InstitialDidClosed:(nullable BYSAdInstitial *)Institial;
- (void)InstitialPlayVideo:(nullable BYSAdInstitial *)Institial;
- (void)InstitialPlayVideoFinished:(nullable BYSAdInstitial *)Institial;

@end


@interface BYSAdInstitial : NSObject

@property(nonatomic, assign ,nonnull) id <BYSAdInstitialDelegate> delegate;

/**
 create an Institial ad with an unitkey
 */
+ (nullable instancetype)createADInstitialWithUnityKey:(nonnull NSString *)unitKey;

/**
 load Institial ad
 */
- (void)load;
/**
 check if Institial is ready
 */
- (BOOL)isReady;
/**
 show Institial ad
 */
- (void)show;
/**
 close Institial ad
 */
- (void)close;

@end
