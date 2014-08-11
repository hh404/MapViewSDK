//
//  OfflineCacheJsonDelegate.m
//  MapViewSDK
//
//  Created by zhangke on 14/8/8.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import "OfflineCacheJsonDelegate.h"
#import <ArcGIS/ArcGIS.h>



@implementation OfflineCacheJsonDelegate

@synthesize currentElement = _currentElement;
@synthesize tileFormat = _tileFormat;
@synthesize WKT = _WKT;
@synthesize tileOrigin = _tileOrigin;
@synthesize lod = _lod;
@synthesize lods = _lods;
@synthesize spatialReference = _spatialReference;
@synthesize fullEnvelope = _fullEnvelope;
@synthesize tileInfo = _tileCacheInfo;
@synthesize error = _error;




-(void)ddddd:(id)json
{
    self.lods =[NSMutableArray array];
    
    NSDictionary* dic = (NSDictionary*)json;
    
    for(NSString* key in dic.allKeys){
        
        NSDictionary* subdic = nil;
        NSString* substr=nil;
        NSNumber* subnum=nil;
        if([[dic objectForKey:key] isKindOfClass:[NSDictionary class]]){
            subdic=[dic objectForKey:key];
        }else if([[dic objectForKey:key] isKindOfClass:[NSString class]]){
            substr=[dic objectForKey:key];
        }else{
            subnum=[dic objectForKey:key];
        }

        if([key isEqualToString:@"fullExtent"]){
            
            _xmin = [[subdic objectForKey:@"xmin"] doubleValue];
            _xmax = [[subdic objectForKey:@"xmax"] doubleValue];
            _ymin = [[subdic objectForKey:@"ymin"] doubleValue];
            _ymax = [[subdic objectForKey:@"ymax"] doubleValue];
            _WKID = [[[subdic objectForKey:@"spatialReference"] objectForKey:@"wkid"] intValue];
            
        }
        
        if([key isEqualToString:@"tileInfo"]){

            _tileOriginX = [[[subdic objectForKey:@"origin"] objectForKey:@"x"] doubleValue];
            _tileOriginY = [[[subdic objectForKey:@"origin"] objectForKey:@"y"] doubleValue];
            
            _tileHeight = [[subdic objectForKey:@"cols"] doubleValue];
            _tileWidth = [[subdic objectForKey:@"rows"] doubleValue];
            
            _dpi = [[subdic objectForKey:@"dpi"] doubleValue];

            self.tileFormat =  [subdic objectForKey:@"format"];
            
            NSArray* array=[subdic objectForKey:@"lods"];
            
            for(NSDictionary* dic in array){
                
                _level = [[dic objectForKey:@"level"] intValue];
                _resolution = [[dic objectForKey:@"resolution"] doubleValue];
                _scale = [[dic objectForKey:@"scale"] doubleValue];
                
                self.lod = [[AGSLOD alloc]initWithLevel:_level resolution:_resolution scale:_scale];
                [self.lods addObject:_lod];
                
            }
        }
        if([key isEqualToString:@"units"]){
            self.units= AGSUnitsMeters;
        }

    }
    
    
    _tileSize = CGSizeMake(_tileWidth, _tileHeight);
    self.spatialReference =[[AGSSpatialReference alloc] initWithWKID:_WKID];
    self.tileOrigin = [[AGSPoint alloc] initWithX:_tileOriginX y:_tileOriginY spatialReference:_spatialReference];
    self.fullEnvelope = [AGSEnvelope envelopeWithXmin:_xmin
                                                 ymin:_ymin
                                                 xmax:_xmax
                                                 ymax:_ymax
                                     spatialReference:_spatialReference];
    self.tileInfo = [[AGSTileInfo alloc] initWithDpi: _dpi
                                              format:_tileFormat
                                                lods:_lods
                                              origin:_tileOrigin
                                    spatialReference:_spatialReference
                                            tileSize:_tileSize];
    
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"lodview" object:nil];

    
}



@end
