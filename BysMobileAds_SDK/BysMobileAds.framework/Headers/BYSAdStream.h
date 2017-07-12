//
//  BYSAdStream.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 17/2/15.
//  Copyright © 2017年 陕西百益软件有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class BYSAdStream;
@class BYSAdStreamView;
@protocol BYSAdStreamViewDelegate;

@protocol BYSAdStreamDelegate <NSObject>

@optional

/**
 ad data load sucess callback
 */
- (void)BYSAdStreamDidReceiveData:(nullable BYSAdStream *)streamAd;
/**
 /// ad data load false callback
 */
- (void)BYSAdStream:(nullable BYSAdStream *)Ad didFailToReceiveDataWithError:(nullable NSError *)error;

@end

@interface BYSAdStream : NSObject
/**
 unitKey
 */
@property (nonatomic, strong ,nonnull ,readonly) NSString *unitKey;
/**
 BYSAdStreamDelegate
 */
@property (nonatomic, weak   ,nullable) id<BYSAdStreamDelegate> delegate;
/**
 Title font size
 */
@property (nonatomic, strong ,nullable) UIFont *titleFont;
/**
 Subtitle font size font size
 */
@property (nonatomic, strong ,nullable) UIFont *subTitleFont;
/**
 Content font size
 */
@property (nonatomic, strong ,nullable) UIFont *contentFont;
/**
 Title font color
 */
@property (nonatomic, strong ,nullable) UIColor *titleColor;
/**
 Subtitle font color
 */
@property (nonatomic, strong ,nullable) UIColor *subTitleColor;
/**
 Content font color
 */
@property (nonatomic, strong ,nullable) UIColor *contentColor;
/**
 Initialize traffic advertising based on Unitkey
 
 @param unitKey AdUnitkey is requested from the ad developer platform
 @return BYSAdStream
 */
+ (nullable instancetype)createStreamWithUnitkey:(nonnull NSString *)unitKey;
/**
 Generate BYSAdStreamView, font size and color must be configured before the method

 @param delegate delegagte
 @return BYSAdStreamView
 */
- (nullable BYSAdStreamView *)makeAdViewWithStreamViewDelegate:(nonnull id)delegate;
/**
 Unify configuration view parameters
 */
- (void)setTitleFont:(nullable UIFont *)titleFont
        SubTitleFont:(nullable UIFont *)subTitleFont
         ContentFont:(nullable UIFont *)ContentFont
          TitleColor:(nullable UIColor *)titleColor
       SubTitleColor:(nullable UIColor *)subTitleColor
        ContentColor:(nullable UIColor *)ContentColor;

@end
