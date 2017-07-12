//
//  ADsApiConfig.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 16/12/10.
//  Copyright © 2016年 陕西百益软件有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BYSAdConfiger;

@protocol BYADConfigerDelegate <NSObject>
/**
 Ad configuration successfully callback

 @param configer BYSAdConfiger
 */
- (void)ConfigerDidSucess:(nullable BYSAdConfiger *)configer;

/**
 Ad configuration failed callback with error message

 @param configer BYSAdConfiger
 @param error error
 */
- (void)ConfigerDidFailed:(nullable BYSAdConfiger *)configer withError:(nullable NSError *)error;

@end

@interface BYSAdConfiger : NSObject

@property (nonatomic, copy ,nonnull ,readonly)   NSString *token;
@property (nonatomic, copy ,nonnull ,readonly)   NSNumber *modify_time;                         /// ad unit info update time

/**
 Whether the open screen advertising is open
 */
@property (nonatomic, assign) BOOL enableLauch;

@property (nonatomic, weak ,nullable) id<BYADConfigerDelegate> delegate;

/**
 create or fetch ad configer single instence
 */
+ (nonnull instancetype)sharedConfiger;

/**
 init ad condition with app key
 */
- (void)initWithAppKey:(nonnull NSString *)appkey;

/**
check if ad condition config is done 
 */
- (BOOL)isInitSucess;

/**
 create or fetch ad configer single instence and set is delegate

 @param appkey appkey
 @param delegagte delegagte
 */
+ (void)ConfigerWithAppKey:(nonnull NSString *)appkey delegate:(nullable id)delegagte;

/**
 init ad unit (when produce ad object you must init ad unit)
 @param unitkey unitkey
 @return return true or fales
 */
+ (BOOL)initADUnitWithUnitkey:(nonnull NSString *)unitkey;
@end
