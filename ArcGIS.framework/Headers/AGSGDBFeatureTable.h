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

@class AGSSpatialReference;
@class AGSGDBGeodatabase;
@class AGSQuery;
@class AGSRelationshipQuery;
@class AGSGDBQueryResultCursor;
@class AGSRenderer;
@class AGSEditFieldsInfo;
@class AGSGDBFeature;
@class AGSEditResult;
@class AGSFeatureTable;
@class AGSCredential;
@class AGSFeatureType;
@class AGSFeatureTemplate;
@protocol AGSFeature;
@protocol AGSGDBFeatureSourceInfo;

/** @file AGSGDBFeatureTable.h */ //Required for Globals API doc

/** @brief A dataset in a local geodatabase
 
 Instances of this class represent datasets in a local geodatabase. The dataset may contain
 geographic features, or non-geographic records.
 
 
 @see @c AGSFeatureTableLayer to visualize features from this dataset on a map.
 @define{AGSGDBFeatureTable.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBFeatureTable : AGSFeatureTable <AGSGDBFeatureSourceInfo>

/** The spatial reference of features in this dataset
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The local geodatabase this dataset belongs to
 @since 10.2
 */
@property (nonatomic, weak, readonly) AGSGDBGeodatabase *geodatabase;

#pragma mark feature source info properties

@property (nonatomic, copy, readonly) AGSCredential *credential;
@property (nonatomic, readonly) AGSGeometryType geometryType;
@property (nonatomic, copy, readonly) NSString *displayField;
@property (nonatomic, copy, readonly) NSArray *fields;
@property (nonatomic, copy, readonly) NSString *objectIdField;
@property (nonatomic, copy, readonly) NSString *typeIdField;
@property (nonatomic, copy, readonly) NSArray *types;
@property (nonatomic, copy, readonly) NSArray *templates;
// renderer is really 'copy' semantics
@property (nonatomic, strong, readonly) AGSRenderer *renderer;
@property (nonatomic, strong, readonly) AGSEditFieldsInfo *editFieldsInfo;
@property (nonatomic, assign, readonly) BOOL hasAttachments;
@property (nonatomic, assign, readonly) BOOL isTableOnly;

@property (nonatomic, assign, readonly) BOOL canCreate;
@property (nonatomic, assign, readonly) BOOL canUpdate;
@property (nonatomic, assign, readonly) BOOL canDelete;
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

- (BOOL)canUpdateFeature:(id<AGSFeature>)feature;
- (BOOL)canDeleteFeature:(id<AGSFeature>)feature;

#pragma mark query methods

/** Query the dataset for results coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning an array of results or an NSError if an error occured. The results are @c id<AGSFeature> objects or, if statistics are requested, they are @c NSDictionary objects.
@return void
 @agssince{10.2, 10.2}
 */
-(void)queryResultsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *results, NSError *error))completion;

/** Query the dataset for a cursor of results coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning cursor of results or an NSError if an error occured.
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryResultCursorWithParameters:(AGSQuery*)params completion:(void (^)(AGSGDBQueryResultCursor *cursor, NSError *error))completion;

/** Query the dataset for an array of object IDs coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning an array of object IDs
 and an NSError if an error occured.
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryObjectIDsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *objectIDs, NSError *error))completion;

/** Retrieves all the relationships this dataset participates in
 @return an array of AGSGDBRelationship objects
 @agssince{10.2, 10.2}
 */
-(NSArray*)relationships;

/** Query the geodatabase for the features/records related to a list of features in this dataset.
 @param relatedQueryParams @c AGSRelationshipQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning a dictionary of reults or an NSError if an error occured. The results contain @c AGSGDBQueryResultCursor objects with associated object ID
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryRelatedFeaturesWithParameters:(AGSRelationshipQuery*)relatedQueryParams completion:(void (^)(NSDictionary *results, NSError *error))completion;

#pragma mark other

/** Adds the specified feature to the dataset.
 Only applicable if @c #canCreate is @c YES.
 @param feature to add.
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)addFeature:(AGSGDBFeature*)feature;

/** Updates the specified feature in the dataset.
 Only applicable if @c #canUpdate is @c YES.
 @param feature to update.
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)updateFeature:(AGSGDBFeature*)feature;

/** Deletes the specified feature in the dataset.
 Only applicable if @c #caDelete is @c YES.
 @param feature to delete.
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)deleteFeature:(AGSGDBFeature*)feature;

/** Indicates whether any edits (adds/updates/deletes) have been
 made to the dataset since the specified date.
 @param date
 @return @c YES or @NO
 */
-(BOOL)hasLocalEditsSince:(NSDate*)date;


/** Creates a new autoreleased feature based on the specified feature sub-type and feature
 template. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @return The new feature.
 @since 10.2
 @see @c #addFeature: for
 adding the feature to the dataset.
 */
-(AGSGDBFeature*)featureWithTemplate:(AGSFeatureTemplate*)featureTemplate;

/** Creates a new autoreleased feature based on the specified feature sub-type. Note, the new
 feature is only available in memory at this point, it is not commited to
 the dataset. This method uses the first template in the feature type.
 @param featureType The type of feature to create.
 @return The new feature.
 @since 10.2
 @see @c #addFeature: for
 adding the feature to the dataset.
 */
-(AGSGDBFeature*)featureWithType:(AGSFeatureType*)featureType;

@end
