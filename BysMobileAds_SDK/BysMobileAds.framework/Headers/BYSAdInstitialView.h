//
//  BYSAdInstitialView.h
//  MakeSDK
//
//  Created by hanJianXin on 16/12/20.
//  Copyright © 2016年 hanJianXin. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "BYSAdBaseAdView.h"

@interface BYSAdInstitialView :BYSAdBaseAdView

@property(nonatomic, assign) BOOL isADReady;    

/// load ad data
- (void)loadADData;

/// check if ad data is loaded ready
- (BOOL)isADDataReady;

/// show ad view
- (void)showADView;

/// close ad view
- (void)removeADView;

@end
