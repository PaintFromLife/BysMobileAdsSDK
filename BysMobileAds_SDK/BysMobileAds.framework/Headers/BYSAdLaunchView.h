//
//  BYADScrollView.h
//  Unity-iPhone
//
//  Created by hanJianXin on 17/1/11.
//
//

#import <UIKit/UIKit.h>

@class BYSAdLaunchView;

@protocol BYSAdLaunchViewDelegate <NSObject>

@required
- (void)BYSAdLaunchView:(BYSAdLaunchView *)launchView didSelectedAtIndex:(NSInteger)index;
- (void)BYSAdLaunchViewNotAutoClose:(BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewShutdown:(BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewPlayVideo:(BYSAdLaunchView *)launchView;
- (void)BYSAdLaunchViewPlayVideoFinished:(BYSAdLaunchView *)launchView;

@end


@interface BYSAdLaunchView : UIView

@property(nonatomic, copy) NSArray *dataArray;
@property(nonatomic, assign) id<BYSAdLaunchViewDelegate> adDelegate;

@end
