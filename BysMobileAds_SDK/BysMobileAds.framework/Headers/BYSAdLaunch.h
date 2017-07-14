//
//  BYSAdLaunch.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 17/1/10.
//  Copyright © 2017年 陕西百益软件有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BYSAdLaunch;
@protocol BYSAdLaunchDelegate <NSObject>

@required

- (void)LaunchDidReceivedData:(nullable BYSAdLaunch *)launch;
- (void)LaunchFailToReceiveData:(nullable BYSAdLaunch *)launch withError:(nullable NSError *)error;
- (void)LaunchPlayVideo:(nullable BYSAdLaunch *)launch;
- (void)LaunchPlayVideoFinished:(nullable BYSAdLaunch *)launch;
- (void)LaunchDidClicked:(nullable BYSAdLaunch *)launch;
- (void)LaunchDidClosed:(nullable BYSAdLaunch *)launch;

@end

@interface BYSAdLaunch : NSObject

@property(nonatomic, assign ,nullable) id<BYSAdLaunchDelegate> delegate;

/**
 create or fetch open ad single instance
 */
+ (nullable instancetype)shareInstance;

/**
 init open ad with an unitKey
 */
- (void)initADLaunchWithUnitkey:(nonnull NSString *)unitKey;
/**
 create open ad instance and set it's delegate

 @param unityKey unityKey
 @param delegate delegate
 */
+ (void)ConfigLaunchWithUnitKey:(nonnull NSString *)unityKey delegate:(nonnull id)delegate;

@end
