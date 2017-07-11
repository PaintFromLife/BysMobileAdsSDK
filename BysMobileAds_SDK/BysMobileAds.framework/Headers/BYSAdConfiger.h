//
//  ADsApiConfig.h
//  MakeSDK
//
//  Created by hanJianXin on 16/12/10.
//  Copyright © 2016年 hanJianXin. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "BYSAdBaseDataModel.h"

@class BYSAdConfiger;

@protocol BYADConfigerDelegate <NSObject>

- (void)ConfigerDidSucess:(BYSAdConfiger *)configer;
- (void)ConfigerDidFailed:(BYSAdConfiger *)configer withError:(NSError *)error;

@end


typedef NS_ENUM(NSInteger, BYAPIState) {
    kApiStateNone = 0,
    kApiStateOk = 1,
    kApiStateError = 2,
    kApiStateIsExecuting = 3
};

@interface BYSAdConfiger : BYSAdBaseDataModel

@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) BYAPIState configState;
@property (nonatomic, copy) NSNumber *modify_time;                         /// ad unit info update time
@property (nonatomic, assign) BOOL enableLauch;

@property (nonatomic, weak) id<BYADConfigerDelegate> delegate;

/// create or fetch ad configer single instence
+ (BYSAdConfiger *)sharedConfiger;

/// init ad condition with app key
- (void)initWithAppKey:(NSString *)appkey;

/// check if ad condition config is done
- (BOOL)isInitSucess;

/// create or fetch ad configer single instence and set is delegate
+ (void)ConfigerWithAppKey:(NSString *)appkey delegate:(id<BYADConfigerDelegate>)delegagte;


/// init ad unit (when produce ad object you must init ad unit)
+ (BOOL)initADUnitWithUnitkey:(NSString *)unitkey;

- (void)restoreConfigerFromFile;

@end
