/*
 COPYRIGHT 2013 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

#import <Foundation/Foundation.h>

/** @brief Estimates about a tile cache requested by 
 @c AGSTileCacheTask#estimateSizeWithParameters:status:
 
 This class holds estimates about a tile cache requested by the
 @c AGSTileCacheTask#estimateSizeWithParameters:status: operation
 
 @define{AGSTileCacheSizeEstimate, ArcGIS}
 @since 10.2
 */
@interface AGSTileCacheSizeEstimate : NSObject

/**
 The size of the .tpk file in bytes
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) long long fileSize;

/**
 The number of tile in the .tpk file
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger tileCount;

@end
