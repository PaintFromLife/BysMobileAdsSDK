//
//  BYStitialADManger.h
//  MakeSDK
//
//  Created by hanJianXin on 16/12/1.
//  Copyright © 2016年 hanJianXin. All rights reserved.
//


/*
 
 注：
 1、在plist文件中添加支持https协议代码：
 
 <key>NSAppTransportSecurity</key>
 <dict>
 <key>NSAllowsArbitraryLoads</key>
 <true/>
 </dict>
 
 2、拖拽117.cer文件到工程中
 
 */

#import <Foundation/Foundation.h>

@class BYSAdInstitial;
@class BYSAdInstitialView;

@protocol BYSAdInstitialDelegate<NSObject>
@required
- (void)InstitialDidReceivedData:(BYSAdInstitial *)Institial;
- (void)InstitialFailToReceiveData:(BYSAdInstitial *)Institial withError:(NSString *)error;
- (void)InstitialWillPresent:(BYSAdInstitial *)Institial;
- (void)InstitialDidPresent:(BYSAdInstitial *)Institial;
- (void)InstitialDidClicked:(BYSAdInstitial *)Institial;
- (void)InstitialDidClosed:(BYSAdInstitial *)Institial;
- (void)InstitialPlayVideo:(BYSAdInstitial *)Institial;
- (void)InstitialPlayVideoFinished:(BYSAdInstitial *)Institial;

@end


@interface BYSAdInstitial : NSObject

@property(nonatomic, assign) id <BYSAdInstitialDelegate> delegate;

//  create an Institial ad with an unitkey
+ (BYSAdInstitial *)createADInstitialWithUnityKey:(NSString *)unitKey;

/// load Institial ad
- (void)load;

/// check if Institial is ready
- (BOOL)isReady;

/// show Institial ad
- (void)show;

/// close Institial ad
- (void)close;


@end
