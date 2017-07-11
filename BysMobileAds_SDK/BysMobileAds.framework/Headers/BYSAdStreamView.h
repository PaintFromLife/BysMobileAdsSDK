//
//  BYSAdStreamView.h
//  StreamADTest
//
//  Created by hanJianXin on 17/2/7.
//  Copyright © 2017年 hanJianXin. All rights reserved.
//

#define  BYS_ScreenWidth  [UIScreen mainScreen].bounds.size.width
#define  BYS_ScreenHeight  [UIScreen mainScreen].bounds.size.height


#import <UIKit/UIKit.h>

@class BYSAdStreamView;
@class BYADAdDataModel;
@class BYSAdStreamUnitInfoModel;

@protocol BYSAdStreamViewDelegate <NSObject>
- (void)BYSAdStreamViewDidClicked:(BYSAdStreamView *)streamView;
- (void)BYSAdStreamViewLayoutFinished:(BYSAdStreamView *)streamView;
@end

@interface BYSAdStreamView : UIView
//used for ad boder show
@property (nonatomic, strong) UIView *borderView;
//used to conten user UI interface
@property (nonatomic, strong) UIView *contentView;

@property (nonatomic, strong) BYADAdDataModel *dataModel;
@property (nonatomic, strong) BYSAdStreamUnitInfoModel *adInfoModel;
@property (nonatomic, weak) id<BYSAdStreamViewDelegate> delegate;

@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIFont *subTitleFont;
@property (nonatomic, strong) UIFont *contentFont;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *subTitleColor;
@property (nonatomic, strong) UIColor *contentColor;

// layout no images ad style
- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
                content:(NSString *)content;

// layout as three images ad style
- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
              leftImage:(UIImage *)leftImage
            middleImage:(UIImage *)middleImage
             rithtImage:(UIImage *)rightImage;

// layout as two images ad style
- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
              leftImage:(UIImage *)leftImage
             rithtImage:(UIImage *)rightImage;

// layout as one left image or one right image ad style
- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
         oneLittleImage:(UIImage *)image;

// layout as one middle image ad style
- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
            middleImage:(UIImage *)middleImage;

// make display log to the server
- (void)makeDisplayLog;
@end
