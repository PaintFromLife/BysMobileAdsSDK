
# BysMobileAdsSDK
<h3>CocoaPods</h3>

CocoaPods is a dependency manager for Cocoa projects. You can install it with the following command:

```
$ gem install cocoapods
```
To integrate Bys-Mobile-Ads-SDK into your Xcode project using CocoaPods, specify it in your Podfile:
```
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'
#use_frameworks!

target '<Your Target Name>' do
  pod 'BysMobileAds', '~> 0.0.1’
end
```
Then, run the following command:
```
$ pod install
```
<h3>Usage</h3>
After some setup, using BysMobileAdsSDK is really simple. You can access an API like this

```
#import "AppDelegate.h"
#import <BysMobileAds/BYSAdConfiger.h>
#import <BysMobileAds/BYSAdLaunchView.h>

@interface AppDelegate ()<BYADConfigerDelegate ,BYSAdLaunchDelegate>

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [BYSAdConfiger configerWithAppKey:@"" delegate:self];
        //设置开启或关闭开屏广告
    BYSAdConfiger *configer = [BYSAdConfiger sharedConfiger];
    configer.enableLauch = YES;
    //配置开屏广告
    [BYSAdLaunch configLaunchWithUnitKey:@"" delegate:self];
    return YES;
}
```
```
#pragma mark -- BYADConfigerDelegate  广告Api配置代理
- (void)ConfigerDidSucess:(BYSAdConfiger *)configer{
    NSLog(@"ConfigerDidSucess call back");
}
- (void)ConfigerDidFailed:(BYSAdConfiger *)configer withError:(NSError *)error{
    NSLog(@"ConfigerDidFailed call back");
    NSString *str =  [NSString stringWithFormat:@"ConfigerDidFailed:%@",error.localizedDescription];
    NSLog(@"%@",str);
}
```
```
#pragma mark -- BYSAdLaunchDelegate 
- (void)LaunchDidReceivedData:(BYSAdLaunch *)launch{
    NSLog(@"LaunchDidReceivedData call back");
}
- (void)LaunchFailToReceiveData:(BYSAdLaunch *)launch withError:(NSError *)error{
    NSLog(@"LaunchFailToReceiveData call back");
}
- (void)LaunchDidClicked:(BYSAdLaunch *)launch{
    NSLog(@"LaunchDidClicked call back");
}
- (void)LaunchDidClosed:(BYSAdLaunch *)launch{
    NSLog(@"LaunchDidClosed call back");
}
- (void)LaunchPlayVideo:(BYSAdLaunch *)launch{
    NSLog(@"LaunchPlayVideo call back");
}
- (void)LaunchPlayVideoFinished:(BYSAdLaunch *)launch{
    NSLog(@"LaunchPlayVideoFinished call back");
}
```

#Stream ads
```
#import "ViewController.h"
#import <BysMobileAds/BYSAdStreamView.h>

@interface ViewController ()<BYSAdStreamViewDelegate,BYSAdStreamDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
     //1、生成信息流对象，并设置信息流代理
    BYSAdStream *stream = [BYSAdStream createStreamWithUnitkey:@""];
    stream.delegate = self;
    
    // 如果需要，可以设置字体、颜色
   [stream setTitleFont:[UIFont systemFontOfSize:19]
            subTitleFont:[UIFont systemFontOfSize:10]
             contentFont:[UIFont systemFontOfSize:25]
              titleColor:[UIColor redColor]
           subTitleColor:[UIColor greenColor]
            contentColor:[UIColor blueColor]];
  
    //2、用信息流对象产出信息流视图，并设置信息流视图代理
    /// produce four ad views
    [stream makeAdViewWithStreamViewDelegate:self];
}

#pragma mark -
#pragma mark BYSAdStreamDelegate
/// ad data load sucess callback
- (void)streamDidReceiveData:(BYSAdStream *)streamAd {
    
    NSLog(@"BYSAdStream did receive ad data");
}
/// ad data load false callback
- (void)stream:(BYSAdStream *)Ad didFailToReceiveDataWithError:(NSError *)error {
    NSLog(@"BYSAdStream receive ad data with error:%@", error);
}

#pragma mark -
#pragma mark BYSAdStreamViewDelegate
- (void)streamViewDidClicked:(BYSAdStreamView *)streamView {
//    BYADAdDataModel *model = streamView.dataModel;
//    NSLog(@"stream view did clicked model = %@",model);
}

///3、信息流视图布局完成调用此方法，此时根据其广告类容视图已布局完成，信息流视图大小已确定。
/// when streamView layout is finished it's view height is formed.
- (void)streamViewLayoutFinished:(BYSAdStreamView *)streamView {
    /// when streamView layout is finished then append ad view to scrollView
    [self.view addSubview:streamView];
}
@end
```
#Banner ads
```
#import "ViewController.h"
#import <BysMobileAds/BYSAdBannerView.h>

@interface ViewController ()<BYSAdBannerDelegate>{
    BYSAdBanner *_banner;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor brownColor];

    int y = 180;
    UIButton *btn1 = [self addButton:@"Create picture banner" offsetY:y selector:@selector(createBanner:)];
    [btn1 setTitleColor:[UIColor yellowColor] forState:UIControlStateNormal];
    y+= 70;
    UIButton *btn3 = [self addButton:@"Banner recycle showing" offsetY:y selector:@selector(showBannerRecycle:)];
    [btn3 setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    y+= 70;
    [self addButton:@"Load banner" offsetY:y selector:@selector(LoadBanner:)];
    y+= 60;
    [self addButton:@"Show banner" offsetY:y selector:@selector(showBanner:)];
    y+= 60;
}

/// close banner when view is going to close
-(void)viewWillDisappear:(BOOL)animated{
    if (_banner) {
        [_banner close];
        _banner = nil;
    }
    [super viewWillDisappear:animated];
}

//create picture banner
- (void)createBanner:(id)sender{
    if (_banner) {
        [_banner close];
        _banner = nil;
    }
    _banner = [BYSAdBanner createBannerWithUnitKey:@"" size:BYS_Banner adPosition:BYADAdPositionBottomOfScreen];
    _banner.delegate = self;
    [self pringStatus:@"create picture banner" isRight:YES];
}

- (void)showBannerRecycle:(id)sender{
    [_banner setCircleTime:0];
}


- (void)LoadBanner:(id)sender{
    [_banner load];
}

- (void)showBanner:(id)sender{
    [_banner show];
}

#pragma -mark BYSAdBannerDelegate
- (void)bannerDidReceivedData:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner Load ok" isRight:YES];
}
- (void)bannerFailToReceiveData:(BYSAdBanner *)ad withError:(NSError *)error{
    [self pringStatus:@"Banner Load false" isRight:NO];
}
- (void)bannerWillPresent:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner will present on screen" isRight:YES];
}
- (void)bannerDidPresent:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner is show on screen" isRight:YES];
}
- (void)bannerDidClicked:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner is clicked" isRight:YES];
}
- (void)bannerDidClosed:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner is closed" isRight:YES];
}

- (void)bannerPlayVideo:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner Play Video" isRight:YES];
}
- (void)bannerPlayVideoFinshed:(BYSAdBanner *)banner{
    [self pringStatus:@"Banner Play Video Finished " isRight:YES];
}
@end
```
#Institial Ads
```
#import "ViewController.h"
#import <BysMobileAds/BYSAdInstitialView.h>

@interface ViewController ()<BYSAdInstitialDelegate>{
    BYSAdInstitial *_insititial;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor brownColor];
    
    int y = 180;
    UIButton *btn1 = [self addButton:@"Create Insititial AD" offsetY:y selector:@selector(createInsititial:)];
    [btn1 setTitleColor:[UIColor yellowColor] forState:UIControlStateNormal];
    y+= 70;
    [self addButton:@"Load Insititial AD" offsetY:y selector:@selector(LoadInsititial:)];
    y+= 60;
    [self addButton:@"Show Insititial AD" offsetY:y selector:@selector(showInsititial:)];
    y+= 60;
    
}

- (void)viewWillDisappear:(BOOL)animated{
    if (_insititial) {
        [_insititial close];
        _insititial = nil;
    }
    [super viewWillDisappear:animated];
}

- (void)createInsititial:(id)sender{
    if (_insititial) {
        [_insititial close];
        _insititial = nil;
    }
    _insititial = [BYSAdInstitial createADInstitialWithUnityKey:@""];
    _insititial.delegate = self;
    [self pringStatus:@"create Institial" isRight:YES];
}

- (void)LoadInsititial:(id)sender{
    [_insititial load];
}

- (void)showInsititial:(id)sender{
    [_insititial show];
}

#pragma -mark BYSAdInstitialDelegate
- (void)institialDidReceivedData:(BYSAdInstitial *)Institial{
    [self pringStatus:@"Institial Load ok" isRight:YES];
}
- (void)institialFailToReceiveData:(BYSAdInstitial *)Institial withError:(NSError *)error{
    [self pringStatus:@"Institial Load false" isRight:NO];
}
- (void)institialWillPresent:(BYSAdInstitial *)Institial{
    [self pringStatus:@"Institial will present on screen" isRight:YES];
}
- (void)institialDidPresent:(BYSAdInstitial *)Institial{
    [self pringStatus:@"Institial is show on screen" isRight:YES];
}
- (void)institialDidClicked:(BYSAdInstitial *)Institial{
    [self pringStatus:@"Institial is clicked" isRight:YES];
}
- (void)institialDidClosed:(BYSAdInstitial *)Institial{
    [self pringStatus:@"Institial is closed" isRight:YES];
}

- (void)institialPlayVideo:(BYSAdInstitial *)Institial{
    [self pringStatus:@"InstitialPlayVideo" isRight:YES];
}
- (void)institialPlayVideoFinished:(BYSAdInstitial *)Institial{
    [self pringStatus:@"InstitialPlayVideoFinished" isRight:YES];
}
@end
```








