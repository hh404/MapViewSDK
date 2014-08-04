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
@class AGSGeometry;
@class AGSSpatialReference;
@class AGSFeatureServiceInfo;

/** @file AGSGDBGenerateParameters.h */ //Required for Globals API doc

/** @brief Parameters to download a replica geodatabase
 
 Instances of this class represent parameters to download a replica geodatabase from
 a sync-enabled ArcGIS Feature service. The service may be hosted on ArcGIS Online, Esri's cloud platform,
 or published on your own on-premise ArcGIS Servers.
 
 @define{AGSGDBGenerateParameters.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBGenerateParameters : NSObject <NSCoding>

/** The prefix name for the replica geodatabase. The name generated on the server
 may or may not be identical to this prefix. If there are other geodatabases
 with the same name on the server, this prefix will be used and an identifier
 will be appended.
@agssince{10.2, 10.2}
*/
@property (nonatomic, copy) NSString *prefixName;

/** The geographic extent within which features will be included in the replica. Cannot be nil.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong) AGSGeometry *extent;

/** Array of layer ids as NSNumber objects. Cannot be nil.
 The datasets of these layers on the server will be included in the geodatabase.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) NSArray *layerIDs;

/** Array of AGSGDBLayerQuery objects specifiying how to further filter
 features for inclusion into the replica on a layer-by-layer basis.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) NSArray *queries;

/** Specifies whether the replica to be generated should be setup to sync as a whole or per
 individual layer. Default is AGSGDBSyncModelPerReplica
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) AGSGDBSyncModel syncModel;

/** Indicates whether or not the replica geodatabase should contain attachments for the features 
 that are included.
 The default is NO.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL returnAttachments;

/**
 The spatial reference in which you would like the generated geodatabase.
 If the data on the server is not in this spatial reference, it will be reprojected on the fly.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

/** Initialize the object
 @param extent The extent to create replica. Cannot be nil.
 @param layerIDs An array of layer ids as NSNumber objects. Cannot be nil.
 @agssince{10.2, 10.2}
 */
-(id)initWithExtent:(AGSGeometry*)extent layerIDs:(NSArray*)layerIDs;

/** Initialize the object
 Provides some default parameters for a feature service. These parameters
 can be modified after you create them.
 @agssince{10.2, 10.2}
 */
-(id)initWithFeatureServiceInfo:(AGSFeatureServiceInfo*)featureServiceInfo;

@end
