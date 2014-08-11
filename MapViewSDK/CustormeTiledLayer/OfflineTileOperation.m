// Copyright 2012 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the use restrictions at http://help.arcgis.com/en/sdk/10.0/usageRestrictions.htm
//

#import "OfflineTileOperation.h"
#import "AFNetworking.h"
#import "SDWebImageDownloader.h"
#import "SDWebImageManager.h"


@implementation OfflineTileOperation

@synthesize tileKey;
@synthesize target;
@synthesize action;
@synthesize allLayersPath;
@synthesize imageData;

- (id)initWithTileKey:(AGSTileKey *)tk dataFramePath:(NSString *)path target:(id)t action:(SEL)a {
	
	if (self = [super init]) {
		self.target = t;
		self.action = a;
		self.allLayersPath = [path stringByAppendingPathComponent:@"_alllayers"]  ;
		self.tileKey = tk;
	}
	return self;
}

-(void)main {
    
    NSString* string=[NSString stringWithFormat:@"http://1.202.234.140:9080/gisserver/tmsserver/beijing_tile/tile/%d/%d/%d",self.tileKey.level+1,self.tileKey.row,self.tileKey.column];
//    NSString* string=[NSString stringWithFormat:@"http://1.202.234.140:9080/gisserver/tmsserver/beijing_tile/tile/7/388/842"];
    
    NSURL *url = [NSURL URLWithString:string];
    
    NSLog(@"%@",url);
    
    //如果需要 离线缓存地图，改造SDWebImageManager 返回为data，整体处理，现在速度较慢
    
//    [[SDWebImageManager sharedManager] downloadImageWithURL:url options:SDWebImageRetryFailed progress:^(NSInteger receivedSize, NSInteger expectedSize){
//        
//    } completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, BOOL finished, NSURL *imageURL) {
//        self.imageData= UIImagePNGRepresentation(image);
//        [self.target performSelector:self.action withObject:self];
//    }];

    
    
    
    [[SDWebImageDownloader sharedDownloader] downloadImageWithURL:url options:SDWebImageDownloaderUseNSURLCache progress:^(NSInteger receivedSize, NSInteger expectedSize){
        
    } completed:^(UIImage *image, NSData *data, NSError *error, BOOL finished){
        self.imageData= data;
        [self.target performSelector:self.action withObject:self];
    }];
    
    
    
    
//    //If this operation was cancelled, do nothing
//    if(self.isCancelled)
//        return;
//    
//	//Fetch the tile for the requested Level, Row, Column
//	@try {
//        
//
////        
////
////        
////        
////		//Level ('L' followed by 2 decimal digits)
////		NSString *decLevel = [NSString stringWithFormat:@"L%02d",self.tileKey.level];
////		//Row ('R' followed by 8 hex digits)
////		NSString *hexRow = [NSString stringWithFormat:@"R%08x",self.tileKey.row];
////		//Column ('C' followed by 8 hex digits)  
////		NSString *hexCol = [NSString stringWithFormat:@"C%08x",self.tileKey.column];
////		
////		NSString* dir = [self.allLayersPath stringByAppendingFormat:@"/%@/%@",decLevel,hexRow];
////		
////		//Check for PNG file
////		NSString *tileImagePath = [dir stringByAppendingFormat:@"/%@.png",hexCol];
////
////        if([[NSFileManager defaultManager] fileExistsAtPath:tileImagePath]==NO){
////            tileImagePath = [dir stringByAppendingFormat:@"/%@.jpg",hexCol];
////        }
////        self.imageData= [NSData dataWithContentsOfFile:tileImagePath];
////		
//	}
//	@catch (NSException *exception) {
//		NSLog(@"main: Caught Exception %@: %@", [exception name], [exception reason]);
//	}
//	@finally {
//		//Invoke the layer's action method
////        if(!self.isCancelled)
////            [self.target performSelector:self.action withObject:self];
//	}
}


@end


