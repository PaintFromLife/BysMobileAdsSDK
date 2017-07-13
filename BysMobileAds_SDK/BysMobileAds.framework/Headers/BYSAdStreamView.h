//
//  BYSAdStreamView.h
//  StreamADTest
//
//  Created by 陕西百益软件有限公司 on 17/2/7.
//  Copyright © 2017年 陕西百益软件有限公司. All rights reserved.
//
#import <UIKit/UIKit.h>

@class BYSAdStreamView;

@protocol BYSAdStreamViewDelegate <NSObject>

- (void)BYSAdStreamViewDidClicked:(nullable BYSAdStreamView *)streamView;
- (void)BYSAdStreamViewLayoutFinished:(nullable BYSAdStreamView *)streamView;

@end

@interface BYSAdStreamView : UIView

@property (nonatomic, weak   ,nullable) id<BYSAdStreamViewDelegate> delegate;

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

// layout no images ad style
- (void)layoutWithTitle:(nullable NSString *)title
               subTitle:(nullable NSString *)subTitle
                content:(nullable NSString *)content;

// layout as three images ad style
- (void)layoutWithTitle:(nullable NSString *)title
               subTitle:(nullable NSString *)subTitle
              leftImage:(nullable UIImage *)leftImage
            middleImage:(nullable UIImage *)middleImage
             rithtImage:(nullable UIImage *)rightImage;

// layout as two images ad style
- (void)layoutWithTitle:(nullable NSString *)title
               subTitle:(nullable NSString *)subTitle
              leftImage:(nullable UIImage *)leftImage
             rithtImage:(nullable UIImage *)rightImage;

// layout as one left image or one right image ad style
- (void)layoutWithTitle:(nullable NSString *)title
               subTitle:(nullable NSString *)subTitle
         oneLittleImage:(nullable UIImage *)image;

// layout as one middle image ad style
- (void)layoutWithTitle:(nullable NSString *)title
               subTitle:(nullable NSString *)subTitle
            middleImage:(nullable UIImage *)middleImage;
@end
