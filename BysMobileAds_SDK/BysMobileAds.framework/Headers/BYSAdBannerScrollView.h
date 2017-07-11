//
//  BYSAdBannerScrollView.h
//  BYADAdDemo
//
//  Created by hanJianXin on 17/2/23.
//  Copyright © 2017年 hanJianXin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BYSAdAttributedLabel.h"
#import "BYSAdBannerUnitInfoModel.h"

@interface BYSAdBannerScrollView : UIScrollView<UIScrollViewDelegate>

@property(nonatomic,strong) BYSAdAttributedLabel *titleLabel;
@property(nonatomic,strong) BYSAdAttributedLabel *subTitleLabel;
@property(nonatomic,strong) BYSAdAttributedLabel *remarkLabel;
@property(nonatomic,strong) BYSAdBannerUnitInfoModel *bannerUnitInfo;

- (void)layoutWithTitle:(NSString *)title
               subTitle:(NSString *)subTitle
                 remark:(NSString *)remark;

- (void)stopShowTimer;

@end
