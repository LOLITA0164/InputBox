//
//  MyMacro.h
//  GCD学习演示
//
//  Created by LOLITA on 16/11/2.
//  Copyright © 2016年 LOLITA. All rights reserved.
//

#ifndef MyMacro_h
#define MyMacro_h


#endif /* MyMacro_h */


//-------------------获取设备大小-------------------------
//NavBar高度
#define NavigationBar_HEIGHT self.navigationController.navigationBar.frame.size.height

//获取屏幕 宽度、高度，支持横屏
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
#define kScreenWidth ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define kScreenHeight ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define kScreenSize ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define kScreenBounds [UIScreen mainScreen].bounds
#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define kScreenSize [UIScreen mainScreen].bounds.size
#endif
//-------------------获取设备大小-------------------------




//-------------------打印日志-------------------------
//DEBUG  模式下打印日志,当前行
#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif
//重写NSLog,Debug模式下打印日志和当前行数
//#if DEBUG
//#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, ［NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
//#else
//#define NSLog(FORMAT, ...) nil
//#endif
//-------------------打印日志-------------------------







//-------------------返回一个随机数-------------------------
#define getRandomNumberFromAtoB(A,B) (int)(A+(arc4random()%(B-A+1)))

//-------------------返回一个随机数-------------------------








//----------------------系统----------------------------
// 是否iPad
#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//获取系统版本
#define IOS_VERSION ［[UIDevice currentDevice] systemVersion] floatValue]
#define CurrentSystemVersion ［UIDevice currentDevice] systemVersion]

//判断设备的操做系统是不是ios7
#define IOS7 ［[UIDevice currentDevice].systemVersion doubleValue] >= 7.0]

//判断当前设备是不是iphone5
#define kScreenIphone5 ((［UIScreen mainScreen] bounds].size.height)>=568)
//----------------------系统----------------------------





//----------------------颜色类---------------------------
// rgb颜色转换（16进制->10进制）
#define ColorWithHex(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

// 获取RGB颜色
#define ColorWithRGB(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define ColorWithRGBA(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

//背景色
#define BACKGROUND_COLOR [UIColor colorWithRed:79.0/255.0 green:166.0/255.0 blue:240.0/255.0 alpha:1.0]

//清除背景色
#define CLEARCOLOR [UIColor clearColor]

//随机颜色
#define RandColor ColorWithRGB(arc4random_uniform(255), arc4random_uniform(255), arc4random_uniform(255))
//----------------------颜色类---------------------------





//----------------------其他----------------------------
//本地存储
#define USER_DEFAULT  [NSUserDefaults standardUserDefaults]
//通知
#define NotificationCenter [NSNotificationCenter defaultCenter]
//G－C－D
#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)
//以iPhone6为基准，获取缩放比例来设置控件的自适应
#define kScreenWidthRatio (kScreenWidth/375.0)
#define kScreenHeightRatio (kScreenHeight/667.0)
#define AdaptedWidthValue(x) (x*kScreenWidthRatio)
#define AdaptedHeightValue(x) (x*kScreenHeightRatio)
#define AdaptedFontSizeValue(x) (x*(kScreenWidthRatio+kScreenHeightRatio)/2.0)



//toolBar高度
#define TabBarHeight 49

//字体大小
#define BigSize 18
#define normalSize 16
#define smallSize 13
#define tinySize 10


#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;


//暂存时，本地数据路径
#define signInfosFilePath [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

//保存应用配置
#define appInfoFilePath [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/appInfo.data"]


//延迟时间
#define kDelayTime 1.5

#define defaultMainColor ColorWithHex(0xCB0814)
#define defaultNavBarColor ColorWithHex(0xfafafa)  ///0xfafafa
#define defaultlineColor ColorWithHex(0xe6e6e6)



/**
 *  the saving objects      存储对象
 *
 *  @param __VALUE__ V
 *  @param __KEY__   K
 *
 *  @return
 */
#define SaveInfoForKey(__VALUE__,__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] setObject:__VALUE__ forKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

/**
 *  get the saved objects       获得存储的对象
 */
#define GetInfoForKey(__KEY__)  [[NSUserDefaults standardUserDefaults] objectForKey:__KEY__]

/**
 *  delete objects      删除对象
 */
#define UserDefaultRemoveObjectForKey(__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] removeObjectForKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

/*告警框*/
#define Alert(title,msg) [[[UIAlertView alloc] initWithTitle:title message:msg delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil] show]































