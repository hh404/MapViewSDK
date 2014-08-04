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

@class AGSGDBFeature;

/** @file AGSGDBAttachment.h */ //Required for Globals API doc

/** @brief An attachment in a local geodatabase
 
 Instances of this class represent an attachment in a local geodatabase.
 
 @define{AGSGDBAttachment.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBAttachment : NSObject

#if TARGET_OS_IPHONE
/** Returns an attachment for the item chosen in a UIImagePickerController
 @param info The dictionary provided by UIImagePickerController
 @since 10.2
 */
+(instancetype)attachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info;
#endif

/** The name of the attachment
 @since 10.2
 */
@property (nonatomic, copy) NSString *name;

/** The MIME type of the attachment
 @since 10.2
 */
@property (nonatomic, copy) NSString *contentType;

/** The size of the attachment in bytes
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** The attachment data in binary format.
 @since 10.2
 */
@property (nonatomic, copy) NSData *data; // copy semantics

/** Returns a thumbnail image the attachment. Only works with some types of attachments - mainly images and videos.
 @since 10.2
 */
-(AGSImage*)thumbnail;

// creates a temporary file if one doesn't exist for this attachment
/** Location on disk where the attachment data is available.
 The data will be saved to this location if it hasn't been already.
 @since 10.2
 */
-(NSString*)filepath;

@end
