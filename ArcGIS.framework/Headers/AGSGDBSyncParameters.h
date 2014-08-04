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

@class AGSGDBGeodatabase;

/** @file AGSGDBSyncParameters.h */ // Required for Globals API doc

/** @brief Represents the parameters to be sent to a sync call on the @c AGSGDBTask.
 
 Instances of this class represent the parameters that will be sent to the @c AGSGDBTask sync methods.
 
 @define{AGSGDBSyncParameters.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBSyncParameters : NSObject<NSCoding>

/** Array of AGSGDBLayerSyncInfo objects.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) NSArray *layerSyncInfos;

/** Enumeration that specifies the directionality of the sync.
 The default value is <code>AGSGDBSyncDirectionBidirectional</code>.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) AGSGDBSyncDirection syncDirection;

/** Boolean indicating whether or not to close the replica.
 The default value is <code>NO</code>.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL closeReplica;

/**
 @return
 @agssince{10.2, 10.2}
 */
+(instancetype)syncParameters;

/**
 @agssince{10.2, 10.2}
 */
-(id)initWithGeodatabase:(AGSGDBGeodatabase*)geodatabase;

@end
