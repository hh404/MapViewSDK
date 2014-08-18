//
//  AppDelegate.m
//  MapViewSDK
//
//  Created by zhangke on 14/8/4.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import "AppDelegate.h"
#import "OfflineTiledLayer.h"


#define kTiledMapServiceURL @"http://server.arcgisonline.com/ArcGIS/rest/services/ESRI_StreetMap_World_2D/MapServer"
#define kDynamicMapServiceURL @"http://sampleserver1.arcgisonline.com/ArcGIS/rest/services/Specialty/ESRI_StateCityHighway_USA/MapServer"
#define kTiledMapServiceURL_test @"http://1.202.234.140:9080/gisserver/rest/services/beijing_tile/MapServer"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    self.window.backgroundColor = [UIColor whiteColor];
    
    self.mapView=[[AGSMapView alloc] initWithFrame:self.window.bounds];
    [self.window addSubview:self.mapView];
    
    // set the delegate for the map view
	self.mapView.layerDelegate = self;
    
    self.mapView.gridLineWidth=0.2;
    self.mapView.gridLineColor=[UIColor colorWithRed:0.2 green:0.2 blue:0.2 alpha:0.8];
    self.mapView.backgroundColor=[UIColor whiteColor];

//    self.mapController = [[MapViewController alloc] init];
//    self.window.rootViewController = self.mapController;

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(lodview) name:@"lodview" object:nil];
    
    
    id JSON=[[NSUserDefaults standardUserDefaults] objectForKey:@"mapServiceJson"];

    if(JSON){
        dd=[[OfflineCacheJsonDelegate alloc] init];
        [dd ddddd:JSON];
    }else{
//        NSURL *url = [NSURL URLWithString:kTiledMapServiceURL_test];
//        NSURLRequest *request = [NSURLRequest requestWithURL:url];
//        AFJSONRequestOperation *operation = [AFJSONRequestOperation JSONRequestOperationWithRequest:request success:^(NSURLRequest *request, NSHTTPURLResponse *response, id JSON) {
//            NSLog(@"App.net Global Stream: %@", JSON);
//            [[NSUserDefaults standardUserDefaults] setObject:JSON forKey:@"mapServiceJson"];
//            [[NSUserDefaults standardUserDefaults] synchronize];
//            
//            dd=[[OfflineCacheJsonDelegate alloc] init];
//            [dd ddddd:JSON];
//            
//        } failure:nil];
//        [operation start];
        
        AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
        manager.responseSerializer = [AFJSONResponseSerializer serializer];
        manager.requestSerializer=[AFJSONRequestSerializer serializer];
        [manager GET:kTiledMapServiceURL_test parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
            NSLog(@"%@", responseObject);
            NSLog(@"App.net Global Stream: %@", JSON);
            [[NSUserDefaults standardUserDefaults] setObject:responseObject forKey:@"mapServiceJson"];
            [[NSUserDefaults standardUserDefaults] synchronize];
            
            dd=[[OfflineCacheJsonDelegate alloc] init];
            [dd ddddd:JSON];
        } failure:^(AFHTTPRequestOperation *operation, NSError *error){
            NSLog(@"Error: %@", error);
        }
         ];
    }
    

    
    [self.window makeKeyAndVisible];
    return YES;
}

-(void)lodview
{
    OfflineTiledLayer* offlineLayer=[[OfflineTiledLayer alloc] initWithDataFramePath:nil with:dd];
    [self.mapView addMapLayer:offlineLayer withName:@"Tiled Layer"];
}


-(void) mapViewDidLoad:(AGSMapView*)mapView {
    
    [_mapView.locationDisplay startDataSource];

}




@end
