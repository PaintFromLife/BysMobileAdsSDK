//
//  BYSAdInstitialView.h
//  BysMobileAds
//
//  Created by 陕西百益软件有限公司 on 16/12/20.
//  Copyright © 2016年 陕西百益软件有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdBaseAdView.h>

@interface BYSAdInstitialView :BYSAdBaseAdView

@property(nonatomic, assign ,getter=isADReady ,readonly) BOOL adReady;

/**
 check if ad data is loaded ready
 */
- (BOOL)isADDataReady;

/**
 show ad view
 */
- (void)showADView;

/**
 close ad view
 */
- (void)removeADView;

@end
