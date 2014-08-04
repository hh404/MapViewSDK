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

/** @file AGSGDBRelationship */ //Required for Globals API doc

/** @brief A cursor for query results
 
 This class represent a relationship between two datasets (layer or table) in a local geodatabase.
 
 @define{AGSGDBRelationship.h, ArcGIS}
 @since 10.2
 @note This class is Beta at 10.2.
 */
@interface AGSGDBRelationship : NSObject

/**
 The ID of the relationship.  This is used when querying the geodatbase based on relationships.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger relationshipID;

/**
 The name of the relationship
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 The ID of the related dataset
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger relatedTableID;

@end
