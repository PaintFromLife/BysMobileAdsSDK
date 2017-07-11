//
//  BYSAdStream.h
//  BYADAdDemo
//
//  Created by hanJianXin on 17/2/15.
//  Copyright © 2017年 hanJianXin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class BYSAdStream;
@class BYSAdStreamUnitInfoModel;
@class BYSAdStreamView;
@protocol BYSAdStreamViewDelegate;

@protocol BYSAdStreamDelegate <NSObject>
@optional
- (void)BYSAdStreamDidReceiveData:(BYSAdStream *)streamAd;                          /// ad data load sucess callback
- (void)BYSAdStream:(BYSAdStream *)Ad didFailToReceiveDataWithError:(NSString *)error;    /// ad data load false callback
@end

@interface BYSAdStream : NSObject

@property (nonatomic, strong) NSString *unitKey;
@property (nonatomic, strong) BYSAdStreamUnitInfoModel *adUnitInfo;
@property (nonatomic, strong) BYSAdStreamView *adView;
@property (nonatomic, weak) id<BYSAdStreamDelegate> delegate;
@property (nonatomic, strong) NSMutableArray *dataArray;

@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIFont *subTitleFont;
@property (nonatomic, strong) UIFont *contentFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *subTitleColor;
@property (nonatomic, strong) UIColor *contentColor;

+ (BYSAdStream *)createStreamWithUnitkey:(NSString *)adUnitkey;
- (BYSAdStreamView *)makeAdViewWithStreamViewDelegate:(id<BYSAdStreamViewDelegate>)delegate;

- (void)setTitleFont:(UIFont *)titleFont
        SubTitleFont:(UIFont *)subTitleFont
         ContentFont:(UIFont *)ContentFont
          TitleColor:(UIColor *)titleColor
       SubTitleColor:(UIColor *)subTitleColor
        ContentColor:(UIColor *)ContentColor;

@end
