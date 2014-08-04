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

@class AGSGDBFeatureTable;
@class AGSGeometry;
@protocol AGSFeature;
@protocol AGSInfoTemplateDelegate;
@class AGSGDBAttachment;

/** @file AGSFeature.h */ //Required for Globals API doc

/** @brief A feature in a local geodatabase
 
 Instances of this class represent a geographic feature in a local geodatabase.
 
 @define{AGSGDBFeature.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBFeature : NSObject <AGSFeature>

/** The dataset that this feature belongs to.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, weak, readonly) AGSGDBFeatureTable *table;

/** An identifier uniquely identifying this feature in the dataset.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) long long objectID;

/** An array of @c AGSGDBAttachemnt objects representing attachments belonging to this feature.
 This is nil until #c #fetchAttachmentsWithCompletion: is called.
 @agssince{10.2, 10.2}
 */
-(NSArray*)attachments;

/** Initialize an empty feature that belongs to the given dataset
 @param table The dataset the feature belongs to
 @agssince{10.2, 10.2}
 */
-(id)initWithTable:(AGSGDBFeatureTable*)table;

/**
 Asynchronously fetches attachments that belong to this feature.
 @param completionBlock Handler that is called when the operation is complete. The attachments are passed in as an array of @c AGSGDBAttachment objects.
 @agssince{10.2, 10.2}
 */
-(void)fetchAttachmentsWithCompletion:(void(^)(NSArray* attachments))completionBlock;

/** Add a new attachment for this feature.
 @param attachment to be added
 @return boolean indicating success or failure
 @since 10.2
 */
-(BOOL)addAttachment:(AGSGDBAttachment*)attachment;

/** Update an existing attachment for this feature.
 @param attachment to be updated
 @return boolean indicating success or failure
 @since 10.2
 */
-(BOOL)updateAttachment:(AGSGDBAttachment*)attachment;

/** Delete an existing attachment for this feature.
 @param attachment to be deleted
 @return boolean indicating success or failure
 @since 10.2
 */
-(BOOL)deleteAttachment:(AGSGDBAttachment*)attachment;

/** Description for this feature
 @since 10.2
 */
-(NSString*)shortDescription;

@end
