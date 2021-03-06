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
@protocol AGSGDBFeatureSourceInfo;
@class AGSGeometry;

/** @brief An abstract geographic feature
 
 This protocol represents abstract geographic features. Conforming classes provide implementations of features which either
 reside in a local geodatabase (@c AGSGDBFeature) or in memory (@c AGSGraphic)
 
 A feature can contain a set of attributes (key-value paris) providing more
 information about the real-world entity it represents. Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A feature can also have a geometry which describes the location and the shape of the 
 entity.
 
 @define{AGSFeature.h, ArcGIS}
 @since 10.2
 */
@protocol AGSFeature <NSObject>

/** The geometry that defines the feature's shape and location.
 Note, the geometry object assigned to this property will be copied over. Any change you make to the geometry
 thereafter will not affect the feature, because the feature will continue to use its private copy.
 To update the feature's geometry, assign the gometry object to the feature again.
 @since 10.2
 */
@property (nonatomic, copy, readwrite) AGSGeometry *geometry;

/** An ID that uniquely identifies this feature.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSUInteger featureId;

#pragma mark attributes

/** Returns a dictionary containing all the attributes of the feature.
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 The dictionary returned is a copy. Any changes you make to it do not affect the feature.
 @since 10.2
 */
-(NSDictionary*)allAttributes;

/** Sets attributes for this feature based on key-value pairs specified in the provided
 dictionary. The dictionary is copied over. Any changes you make to the dictionary thereafter will not affect
 the feature. If you want to update the feature's attributes, you must call this method again.
 
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber. Other attribute types will be ignored.
 @since 10.2
 */
-(void)setAttributes:(NSDictionary*)attributes;

/** Indicates whether the feature contains an attribute for the specified key.
 @param key Name of the attribute
 @since 10.2
 */
-(BOOL)hasAttributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 The type returned will be one of NSNull, NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @since 10.2
 */
-(id)attributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 Since this is the "safe" version, if the value is NSNull it will return nil.
 The type returned will be one of  NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @since 10.2
 */
-(id)safeAttributeForKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 If nil is passed in, it will remove the key.
 @param value of the attribute
 @param key Name of the attribute
 @since 10.2
 */
-(void)setAttribute:(id)value forKey:(NSString*)key;

@end
