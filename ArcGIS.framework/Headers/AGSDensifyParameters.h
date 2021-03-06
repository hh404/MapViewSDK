/*
 COPYRIGHT 2012 ESRI
 
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

/** @file AGSDensifyParameters.h */ //Required for Globals API doc

/** @brief Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>densifyWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>densifyGeometries:withParams:</code> operation.
 
 @define{AGSDensifyParameters.h, ArcGIS}
 @agssince{1.0, 10.2}
 @see AGSGeometryServiceTask
 */
@interface AGSDensifyParameters : NSObject <AGSCoding>

/** The array of geometries to be densified.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy) NSArray *geometries;

/**All segments longer than @c maxSegmentLength are replaced with sequences of 
 lines no longer than @c maxSegmentLength.
 @agssince{1.0, 10.2}
 */
@property (nonatomic) NSUInteger maxSegmentLength;

/** (Optional) The length unit of @c #maxSegmentLength, can be any @c AGSSRUnit 
 constant.
 @agssince{1.0, 10.2}
 */
@property (nonatomic) AGSSRUnit lengthUnit;

/** A flag that can be set to <code>true</code> if GCS spatial references are 
 used or densify geodesic is to be performed.
 @agssince{1.0, 10.2}
 */
@property (nonatomic) BOOL geodesic;

/** Returns an autoreleased instance of the densify parameters object.
 @agssince{1.0, 10.2}
 */
+ (id)densifyParameters;

@end
