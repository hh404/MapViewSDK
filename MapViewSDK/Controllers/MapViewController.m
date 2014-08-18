//
//  MapViewController.m
//  MapViewSDK
//
//  Created by huangjianwu on 14-8-17.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import "MapViewController.h"
#import "OfflineTiledLayer.h"

@interface MapViewController ()

@end

@implementation MapViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(lodview:) name:@"lodview" object:nil];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor greenColor];
    self.searchBar = [[UISearchBar alloc] initWithFrame:CGRectMake(0, 0, 320, 75)];
    self.searchBar.delegate = self;
    self.mapView=[[AGSMapView alloc] initWithFrame:CGRectMake(0, 75, 320, 493)];
    self.mapView.layerDelegate = self;
	self.mapView.callout.delegate = self;
    self.mapView.gridLineWidth=0.2;
    self.mapView.gridLineColor=[UIColor colorWithRed:0.2 green:0.2 blue:0.2 alpha:0.8];
    self.mapView.backgroundColor=[UIColor whiteColor];
    [self.view addSubview:self.searchBar];
    [self.view addSubview:self.mapView];
    

}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - UISearchBarDelegate

//when the user searches
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar {
	
	//hide the callout
	self.mapView.callout.hidden = YES;
	
	//set find task parameters

	
	[searchBar resignFirstResponder];
}


- (void)searchBarCancelButtonClicked:(UISearchBar *) searchBar {
	[searchBar resignFirstResponder];
}


-(void) mapViewDidLoad:(AGSMapView*)mapView {
    
    [_mapView.locationDisplay startDataSource];
}

-(void)lodview:(NSNotification*)aNo
{
    OfflineTiledLayer* offlineLayer=[[OfflineTiledLayer alloc] initWithDataFramePath:nil with:aNo.object];
    [self.mapView addMapLayer:offlineLayer withName:@"Tiled Layer"];
}


@end
