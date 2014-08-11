//
//  AppDelegate.h
//  MapViewSDK
//
//  Created by zhangke on 14/8/4.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ArcGIS/ArcGIS.h>
#import "OfflineCacheJsonDelegate.h"


@interface AppDelegate : UIResponder <UIApplicationDelegate,AGSMapViewLayerDelegate>{
    OfflineCacheJsonDelegate* dd;
}

@property (strong, nonatomic) UIWindow *window;

@property (nonatomic, strong) AGSMapView *mapView;


@end
