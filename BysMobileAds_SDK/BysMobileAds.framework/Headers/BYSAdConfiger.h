//
//  ADsApiConfig.h
//  Bys-Mobile-Ads-SDK
//
//  Created by 陕西百益软件有限公司 on 16/12/10.
//  Copyright © 2016年 陕西百益软件有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BysMobileAds/BYSMobileAdsDefines.h>

BYSAD_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const BYSAdConfigerDidConfigurationCompletionNotification;

@class BYSAdConfiger;

@protocol BYADConfigerDelegate <NSObject>

///Ad configuration successfully callback
- (void)configerDidSucess:(BYSAdConfiger *)configer;

/// Ad configuration failed callback with error message
- (void)configerDidFailed:(BYSAdConfiger *)configer withError:(NSError *)error;

@end

///AdConfiger is used to initialize the ad SDK,
///and the initialization is successful for the display of the ad

@interface BYSAdConfiger : NSObject

///Ad request token
@property (nonatomic, strong ,readonly)   NSString *token;

/// ad unit info update time
@property (nonatomic, strong ,readonly)   NSNumber *modify_time;

///Whether the open screen advertising is open
@property (nonatomic, assign) BOOL enableLauch;

@property (nonatomic, weak) id<BYADConfigerDelegate> delegate;

/// create or fetch ad configer single instence
+ (instancetype)sharedConfiger;

/// init ad condition with app key
- (void)initWithAppKey:(NSString * BYSAD_NONNULL_TYPE)appkey;

///check if ad condition config is done
- (BOOL)isInitSucess;

/// create or fetch ad configer single instence and set is delegate
+ (void)configerWithAppKey:(NSString *BYSAD_NONNULL_TYPE)appkey delegate:(id<BYADConfigerDelegate>)delegagte;

/// init ad unit (when produce ad object you must init ad unit)
+ (BOOL)initADUnitWithUnitkey:(NSString * BYSAD_NONNULL_TYPE)unitkey;

@end

BYSAD_ASSUME_NONNULL_END
