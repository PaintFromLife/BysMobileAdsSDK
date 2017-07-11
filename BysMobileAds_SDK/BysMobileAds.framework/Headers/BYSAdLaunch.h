//
//  BYSAdLaunch.h
//  BYSAdLaunch
//
//  Created by hanJianXin on 17/1/10.
//  Copyright © 2017年 hanJianXin. All rights reserved.
//

//开屏广告

#import <Foundation/Foundation.h>

@class BYSAdLaunch;
@protocol BYSAdLaunchDelegate <NSObject>

@required
- (void)LaunchDidReceivedData:(BYSAdLaunch *)launch;
- (void)LaunchFailToReceiveData:(BYSAdLaunch *)launch withError:(NSError *)error;
- (void)LaunchPlayVideo:(BYSAdLaunch *)launch;
- (void)LaunchPlayVideoFinished:(BYSAdLaunch *)launch;
- (void)LaunchDidClicked:(BYSAdLaunch *)launch;
- (void)LaunchDidClosed:(BYSAdLaunch *)launch;

@end

@interface BYSAdLaunch : NSObject


@property(nonatomic, assign) id<BYSAdLaunchDelegate> delegate;

/// create or fetch open ad single instance
+ (instancetype)shareInstance;

/// init open ad with an unitKey
- (void)initADLaunchWithUnitkey:(NSString *)unitKey;

/// create open ad instance and set it's delegate
+ (void)ConfigLaunchWithUnitKey:(NSString *)unityKey delegate:(id<BYSAdLaunchDelegate>)delegate;


@end
