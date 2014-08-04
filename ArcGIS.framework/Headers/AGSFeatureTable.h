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

@class AGSField;
@class AGSEditResult;
@class AGSQuery;

/** @file AGSFeatureTable.h */ //Required for Globals API doc

/** @brief A dataset in a local storage
 
 This class represents an abstraction for a dataset in local storage (file, folder, database, etc).
 The dataset can contain geographic features or ordinary records that have no spatial information.
 You need to use an @c AGSFeatureTableLayer to visualize the features on a map.

 @see @c AGSGDBFeatureTable to access a dataset in a local *.geodatabase file
 @define{AGSFeatureTable.h, ArcGIS}
 @agssince{10.2,10.2}
 */

@interface AGSFeatureTable : NSObject

/**
 Add a new feature to the dataset.
 @param feature to add
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)addFeature:(id<AGSFeature>)feature;

/**
 Update existing feature in the dataset.
 @param feature to udpate
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)updateFeature:(id<AGSFeature>)feature;

/**
 Delete existing feature in the dataset.
 @param feature to delete
 @return result of the operation
 @since 10.2
 */
-(AGSEditResult*)deleteFeature:(id<AGSFeature>)feature;


/**
 Add a set of new features to the dataset.
 @param features to add as an array of @c id<AGSFeature> objects.
 @return results as an array of @c AGSEditResult objects
 @since 10.2
 */
-(NSArray*)addFeatures:(NSArray*)features;

/**
 Update a set of existing features in the dataset.
 @param features to update as an array of @c id<AGSFeature> objects.
 @return results as an array of @c AGSEditResult objects
 @since 10.2
 */
-(NSArray*)updateFeatures:(NSArray*)features;

/**
 Delete a set of existing features in the dataset.
 @param features to delete as an array of @c id<AGSFeature> objects.
 @return results as an array of @c AGSEditResult objects
 @since 10.2
 */
-(NSArray*)deleteFeatures:(NSArray*)features;


/**
 Indicates whether any edits have been made to the dataset.
 @since 10.2
 */
-(BOOL)hasLocalEdits;

/**
 Set of @c id<AGSFeature> objects that have been added to the dataset.
 @since 10.2
 */
-(NSSet*)addedFeatures;

/**
 Set of @c id<AGSFeature> objects that have been updated.
 @since 10.2
 */
-(NSSet*)updatedFeatures;

/**
 Set of @c id<AGSFeature> objects that have been deleted from the dataset.
 @since 10.2
 */
-(NSSet*)deletedFeatures;

/**
 Undo all edits made to the dataset.
 @since 10.2
 */
-(void)clearEdits;


/**
 Array of @c AGSField objects representing the fields (columns) in the dataset.
 @since 10.2
 */
-(NSArray*)fields;

/**
 Get the field with specified name
 @param name of the field
 @return field
 @since 10.2
 */
-(AGSField*)fieldWithName:(NSString*)fieldName;


/**
 Name of the dataset as defined in the storage medium.
 @since 10.2
 */
-(NSString*)tableName;


/**
 Indicates whether the dataset contains a geometry field (column).
 If YES, the dataset contains geographic features.
 If NO, the dataset contains records, similar to a database table.
 @since 10.2
 */
-(BOOL)hasGeometry;


/**
 Indicates whether the dataset can be edited.
 @since 10.2
 */
-(BOOL)isEditable;


/**
 Query the dataset to find specific features or records.
 @param query representing the criteria
 @param completion The block that is called when the query is complete, returning an array of results or an NSError if an error occured. The results are @c id<AGSFeature> objects or, if statistics are requested, they are @c NSDictionary objects.
 @since 10.2
 */
-(void)queryResultsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *results, NSError *error))completion;

@end
