//
//  MapViewController.h
//  MapViewSDK
//
//  Created by huangjianwu on 14-8-17.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ArcGIS/ArcGIS.h>

@interface MapViewController : UIViewController<AGSFindTaskDelegate,UISearchBarDelegate,AGSMapViewLayerDelegate, AGSCalloutDelegate, AGSLayerCalloutDelegate>

@property (nonatomic, strong)  AGSMapView *mapView;
@property (nonatomic, strong)  UISearchBar *searchBar;

@end
