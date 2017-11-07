<h1>iOS广告集成文档</h1>

<h2>iOS Guidelines</h2>

You can get started with the following:

[Adding the SDK to your Project](#SDK)

[Preparing your App for iOS 9+](#iOS9)

[Initializing the SDK](#Initializing)

The latest version of AdCools SDK supports iOS 8 and later. Also, this version of iOS SDK requires XCode 8.0 and later.

| Version         | 0.01               | 
| -------------   |:-------------:      | 
| Size (.IPA Inflation)        | 1.51 MB |    
| SDK Link|[Download SDK](https://github.com/baiyisoftware/BysMobileAdsSDK)、 [Change Logs](https://github.com/baiyisoftware/BysMobileAdsSDK) 、[GitHub (Sample Code)](https://github.com/baiyisoftware/BysMobileAdsSDK) 、[Cocoapods](https://cocoapods.org/pods/InMobiSDK)|  


<span id="SDK"></span>
<h2>Adding the SDK to your Project</h2>

**Method 1**: Integration via Cocoapods (https://github.com/baiyisoftware/BysMobileAdsSDK)
Follow these steps :

a. Go to your Xcode project directory and create a pod file using the command below. 

```
pod init
```
b. Add the following to Podfile.  

```
pod 'BysMobileAds', '~> 0.0.7
```
Then, run the following command:
 
c. Run the command below to complete the task for dependency. 	

```
pod install
```
 Workspace with pods is created.

**Method 2**: Integrating the framework directl
Add the following MANDATORY frameworks to your Xcode project:
	•	BysMobileAds.framework from the downloaded AdCools iOS SDK bundle
	
	
![DemoApp1](media/15090677250069/DemoApp1.png)





• Embedded Binaries Add BysMobileAds.framework

![DemoApp2](media/15090677250069/DemoApp2.png)

<span id="iOS9"></span>
<h3>Preparing your App for iOS 9+</h3>
App Transport Security (ATS), a default setting introduced with iOS 9 that mandates apps to make network connections only over TLS version 1.2 and later. Though InMobi is committed towards the adoption of HTTPS, the current setup requires our demand partners to support this change and be 100% compliant with all the requirements of ATS.
While we work with our partners progressing towards a secure environment, to ensure ads work on iOS 9 and later versions, you need to follow these steps as a near-term fix:

**• Disable ATS** (Recommended) - to ensure non-secure content from the partners work correctly in your updated apps. To disable ATS flag, add the following code snippet to your app's Info.plist.

![targettingForiOS93](media/15090677250069/targettingForiOS93.png)

```
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```
<span id="Initializing"></span>
## Initializing the SDK
Import the InMobi SDK header in your AppDelegate.h file:

```
#import "ViewController.h"
#import <BysMobileAds/BYSAdConfiger.h>

@interface AppDelegate ()<BYADConfigerDelegate,BYSAdLaunchDelegate>

@end

@implementation AppDelegate
```

Initialize the SDK in the didFinishLaunchingWithOptions method within the app delegate's .m file:

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [BYSAdConfiger configerWithAppKey:@"" delegate:self];

    return YES;
}

```
Then implement the proxy method in AppDelegate.

```
- (void)configerDidSucess:(BYSAdConfiger *)configer {
    NSLog(@"ConfigerDidSucess call back");
}
- (void)configerDidFailed:(BYSAdConfiger *)configer withError:(NSError *)error{
    NSLog(@"configerDidFailed call back");
    NSString *str =  [NSString stringWithFormat:@"configerDidFailed:%@",error.localizedDescription];
    NSLog(@"%@",str);
}
```

Start monetizing your iOS app with these ad formats:

[Banner Ads](Banner)

[Interstitial Ads](media/15090677250069/iOS%20Guidelines%20%7C%20Institial%20Ads.html)

[open Ads](media/15090677250069/iOS%20Guidelines%20%7C%20Launch%20Ads.html)

[Native Ads](media/15090677250069/iOS%20Guidelines%20%7C%20Native%20Ads.html)


                                                                                                                                                              
### Banner
Banner Ads are graphical ad, typically including a combination of static/animated images and text designed to convey a marketing message and/or cause the user to take an action. All types of apps can leverage banner ads for monetization.

Follow these steps to start monetizing with Banner ads:
[Setting up a Banner Ad](#set)
[Creating a Banner Ad](#create)
	
<span id="set"></span>

**Setting up a Banner Ad**

After adding your app, select BANNER AD to create a placement for ad type Banner.

![Banne](media/15090723263108/Banner1.png)


Once you create the banner placement, you will have the placement id.

![Banne](media/15090723263108/Banner2.png)

<span id="create"></span>
#### Creating a Banner Ad

Banner is a subclass of UIView that shows and the corresponding user touches the native ad. Here's how the BysMobileAds SDK banner ad is initialized.

**a. Programmatic Instantiation**

Import the headers and declare a Banner instance in your ViewController.h file. Your ViewController header file should look like this:

```
#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdBannerView.h>

#define BYS_Banner              CGSizeMake(320, 50)//Custom

@interface BannerDemoViewController ()<BYSAdBannerDelegate>{
    BYSAdBanner *_banner;
}
```

Instantiate the banner object. Your ViewController.m file should look like this:

```
- (void)viewDidLoad {
 [super viewDidLoad];
 /*
 You can use the following transitions while refreshing your banner object:
	◦	BYADAdPositionTopOfScreen
	◦	BYADAdPositionBottomOfScreen
	◦	BYADAdPositionTopLeftOfScreen
	◦	BYADAdPositionTopRightOfScreen
	◦	BYADAdPositionBottomLeftOfScreen
	◦	BYADAdPositionBottomRightOfScreen
 */
  _banner = [BYSAdBanner createBannerWithUnitKey:@"" size:BYS_Banner adPosition:BYADAdPositionBottomOfScreen];
    _banner.delegate = self; }
```

By default, Banner does not refresh, you can set the background in the developer Banner settings refresh and refresh time, in the SDK to provide refresh time settings (default is 0, that is not refreshed).

```
 [_banner setCircleTime:0];
```

Banner needs to be loaded manually with the control display.

```
    [_banner load];
    [_banner show];
```

For ad status callbacks, implement the delegate property of Banner. The following callbacks are supported:

```
- (void)bannerDidReceivedData:(BYSAdBanner *)banner{
    NSLog(@"Banner Load ok");
}
- (void)bannerFailToReceiveData:(BYSAdBanner *)ad withError:(NSError *)error{
    NSLog(@"Banner Load false");
}
- (void)bannerWillPresent:(BYSAdBanner *)banner{
    NSLog(@"Banner will present on screen");
}
- (void)bannerDidPresent:(BYSAdBanner *)banner{
    NSLog(@"Banner is show on screen");
}
- (void)bannerDidClicked:(BYSAdBanner *)banner{
    NSLog(@"Banner is clicked");
}
- (void)bannerDidClosed:(BYSAdBanner *)banner{
    NSLog(@"Banner is closed");
}
- (void)bannerPlayVideo:(BYSAdBanner *)banner{
    NSLog(@"Banner Play Video");
}
- (void)bannerPlayVideoFinshed:(BYSAdBanner *)banner{
    NSLog(@"Banner Play Video Finished");
}
```





### Institial Ads

Interstitial ads are full page ads placed at natural break points in the app flow..

Follow these steps to start monetizing with Institial ads:

[Setting up a Institial Ad](#setting)

[Creating a Institial Ad](#create)
	
<span id="setting"></span>
**Setting up a Institial Ad**
After adding your app, select Institial AD to create a placement for ad type Institial.

![Institia](media/15090721913999/Institial1.png)


Once you create the Institial placement, you will have the placement id.

![Institia](media/15090721913999/Institial2.png)

<span id="create"></span>

#### Creating a Institial Ad

The Institia is simply a UIImage subclass displaying full screen ads that respond to user touch.

Import the headers and declare an interstitial instance in your ViewController.h file. Your ViewController header file should look like this:

**a. Programmatic Instantiation**
Import the headers and declare a Institial instance in your ViewController.h file. Your ViewController header file should look like this:

```
#import <UIKit/UIKit.h>
#import <BysMobileAds/BYSAdInstitialView.h>

@interface ViewController : UIViewController <BYSAdInstitialDelegate>{
    BYSAdInstitial *_insititial;
}
@end
```

Instantiate the Institial object. Your ViewController.m file should look like this:

```
- (void)viewDidLoad {
 [super viewDidLoad];
  _insititial = [BYSAdInstitial createADInstitialWithUnityKey:@""];
    _insititial.delegate = self; }
```

Banner needs to be loaded manually with the control display.

```
  [_insititial load];
  [_insititial show];
```

Important: Create only one object per placement ID and reuse it for subsequent ad loads.

For ad status callbacks, implement the delegate property of Institia. The following callbacks are supported:


```
#pragma -mark BYSAdInstitialDelegate
- (void)institialDidReceivedData:(BYSAdInstitial *)Institial{
    NSLog(@"Institial Load ok");
}
- (void)institialFailToReceiveData:(BYSAdInstitial *)Institial withError:(NSError *)error{
    NSLog(@"Institial Load false");
}
- (void)institialWillPresent:(BYSAdInstitial *)Institial{
    NSLog(@"Institial will present on screen");
}
- (void)institialDidPresent:(BYSAdInstitial *)Institial{
    NSLog(@"Institial is show on screen");
}
- (void)institialDidClicked:(BYSAdInstitial *)Institial{
    NSLog(@"Institial is clicked");
}
- (void)institialDidClosed:(BYSAdInstitial *)Institial{
    NSLog(@"Institial is closed");
}

- (void)institialPlayVideo:(BYSAdInstitial *)Institial{
    NSLog(@"InstitialPlayVideo");
}
- (void)institialPlayVideoFinished:(BYSAdInstitial *)Institial{
    NSLog(@"InstitialPlayVideoFinished");
}
```
	


