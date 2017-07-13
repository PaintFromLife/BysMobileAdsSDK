//
//  BYADScrollView.h
//  Unity-iPhone
//
//  Created by 陕西百益软件有限公司 on 17/1/11.
//
//

#import <UIKit/UIKit.h>

@class BYSAdLaunchView;

@protocol BYSAdLaunchViewDelegate <NSObject>

@required

- (void)BYSAdLaunchView:(nullable BYSAdLaunchView *)launchView didSelectedAtIndex:(NSInteger)index;
- (void)BYSAdLaunchViewNotAutoClose:(nullable BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewShutdown:(nullable BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewPlayVideo:(nullable BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewPlayVideoFinished:(nullable BYSAdLaunchView *)launchView;

@end

@interface BYSAdLaunchView : UIView

@property(nonatomic, assign ,nonnull) id<BYSAdLaunchViewDelegate> adDelegate;

@end
