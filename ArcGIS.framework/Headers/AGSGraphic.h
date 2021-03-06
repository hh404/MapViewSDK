/*
 COPYRIGHT 2009 ESRI
 
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

@class AGSGeometry;
@class AGSGraphicsLayer;
@class AGSSymbol;
@protocol AGSInfoTemplateDelegate;
@protocol AGSFeature;

/** @brief A graphic on the map.
 
 Instances of this class represent graphics. Graphics can be displayed on the 
 map through an @c AGSGraphicsLayer. Graphics can be used as input to a task, or 
 they can be used to display output from a task, or in response to user interaction.
 
 Each graphic must contain an @c AGSGeometry describing the location and the shape 
 of the graphic. The geometry must have the same spatial reference as the map. 
 
 A graphic can be associated with an @c AGSSymbol which determines how the graphic 
 looks. Alternatively, the graphics layer can be assgined an @c AGSRenderer which 
 determines the appearance of all graphics in the layer. Note, symbols associated 
 with individual graphics take precedence over the symbols chosen by the renderer. 
 The #symbol used depends upon the geometry type associated with the graphic. 
 An @c AGSMarkerSymbol is used for point and multipoint geometries, 
 @c AGSSimpleLineSymbol for polyline geometries, and @c AGSSimpleFillSymbol
 for polygon geometries.
 
 A graphic can contain a set of attributes (key-value paris) providing more 
 information about the graphic. This information is displayed in an @c AGSCallout 
 when a user taps on the graphic. Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored.
 
 Graphic objects respond to key value coding (KVC) methods for setting and getting attribute values.
 
 A graphic can also contain an #infoTemplateDelegate that describes how attribute 
 information should be displayed in the callout.
 
 @define{AGSGraphic.h, ArcGIS}
 @agssince{1.0, 10.2}
 @see AGSMapViewCalloutDelegate for events related to tapping on graphics and showing the 
 callout window.
 */
@interface AGSGraphic : NSObject <AGSCoding, AGSFeature>

/** Returns a dictionary containing all the attributes of the graphic.
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 The dictionary returned is a copy. Any changes you make to it do not affect the graphic.
 @agssince{10.1.1, 10.2}
 */
- (NSDictionary*)allAttributes;

/** Sets attributes for this graphic based on key-value pairs specified in the provided
 dictionary. The dictionary is copied over. Any changes you make to the dictionary thereafter will not affect
 the graphic. If you want to update the graphic's attributes, you must call this method again.
 
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber. Other attribute types will be ignored.
 @deprecated Deprecated at 10.2. Please use @c AGSGraphic#setAttributes: instead.
 @agssince{10.1.1, 10.2}
 */
- (void)setAllAttributes:(NSDictionary*)attributes __attribute__((deprecated));

/** Sets attributes for this graphic based on key-value pairs specified in the provided
 dictionary. The dictionary is copied over. Any changes you make to the dictionary thereafter will not affect
 the graphic. If you want to update the graphic's attributes, you must call this method again.
 
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber. Other attribute types will be ignored.
 @agssince{10.2, 10.2}
 */
- (void)setAttributes:(NSDictionary*)attributes;

/** Indicates whether the graphic contains an attribute for the specified key.
 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
 */
-(BOOL)hasAttributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 The type returned will be one of NSNull, NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
  */
-(id)attributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 Since this is the "safe" version, if the value is NSNull it will return nil.
 The type returned will be one of  NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
 */
-(id)safeAttributeForKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 If nil is passed in, it will remove the key.
 @param value of the attribute
 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
 */
-(void)setAttribute:(id)value forKey:(NSString*)key;

/** Removes the attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 */
-(void)removeAttributeForKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary

 */
-(void)setAttributeWithString:(NSString*)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithDouble:(double)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithInt:(int)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithUnsignedInt:(uint)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithFloat:(float)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 */
-(void)setAttributeWithBool:(BOOL)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithDate:(NSDate*)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 */
-(void)setAttributeWithLong:(long)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeWithInteger:(NSInteger)value forKey:(NSString*)key;

/** Sets an attribute value to NSNull for the specified key.
 @agssince{10.1.1, 10.2}
 @see @c #setAllAttributes: for setting all graphic attributes based on an NSDictionary
 */
-(void)setAttributeToNullForKey:(NSString*)key;

/** Returns the attribute value for the specified key as an @c NSString value.  Returns nil if key doesn't exist.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:

 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSString*)attributeAsStringForKey:(NSString*)key;

/** Returns the attribute value for the specified key as an @c NSDate value. Returns nil if key doesn't exist.

 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSDate*)attributeAsDateForKey:(NSString*)key;

/** Returns the attribute value for the specified key as a @c double value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
@param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(double)attributeAsDoubleForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a @c int value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
*/
-(int)attributeAsIntForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a @c uint value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
@param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(uint)attributeAsUnsignedIntForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a @c float value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(float)attributeAsFloatForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key  as a @c BOOL value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
*/
-(BOOL)attributeAsBoolForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a @c long value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not @c NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 */
-(long)attributeAsLongForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as an @c NSInteger value.
 If you don't know the expected type of the value, use @c #attributeForKey: or @c #safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed. Note however, YES doesn't denote
 a successful conversion between data types with no loss.
 @agssince{10.1.1, 10.2}
 @see @c #allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSInteger)attributeAsIntegerForKey:(NSString*)key exists:(BOOL*)exists;

/** The geometry that defines the graphic's shape and location.
 Note, the geometry object assigned to this property will be copied over. Any change you make to the geometry
 thereafter will not affect the graphic, because the graphic will continue to use its private copy.
 To update the graphic's geometry, assign the gometry object to the graphic again.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy) AGSGeometry *geometry;

/** The symbol for the graphic.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong) AGSSymbol *symbol;

/** Template describing how the callout should display this graphic's attributes.
 @see AGSCalloutTemplate
 @agssince{1.0, 10.2}
 @deprecated Deprecated at 10.2. Use @c AGSCallout#delegate or @c AGSHitTestable#calloutDelegate instead.
 */
@property (nonatomic, weak) id<AGSInfoTemplateDelegate> infoTemplateDelegate __attribute__((deprecated));

/** The graphics layer that this graphic belongs to, if any.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, weak, readonly) AGSGraphicsLayer *layer;

/** Whether or not the graphic is visible in the layer.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/** The drawing index that controls the order the graphic is drawn in the layer.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) NSUInteger drawIndex;

/** Initialize the graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Key-value pairs of fields and field values associated with
 the graphic.
 @return A new graphic object.
 @agssince{10.2, 10.2}
 */
- (id)initWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSDictionary *)attributes;

/** Returns autoreleased graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Key-value pairs of fields and field values associated with
 the graphic.
 @return A new, autoreleased, graphic object.
 @agssince{10.2, 10.2}
 */
+ (id)graphicWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSDictionary *)attributes;

//
// Deprecated

/** Initialize the graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Key-value pairs of fields and field values associated with 
 the graphic.
 @param infoTemplateDelegate The template describing how to display @p attributes 
 in the callout. Can be nil.
 @return A new graphic object.
 @deprecated Deprecated at 10.2. Please use @c AGSGraphic#initWithGeometry:symbol:attributes: instead.
 @agssince{1.0, 10.2}
 */
- (id)initWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSDictionary *)attributes infoTemplateDelegate:(id<AGSInfoTemplateDelegate>)infoTemplateDelegate __attribute__((deprecated));

/** Returns autoreleased graphic object. Only the @p geometry argument is mandatory.
 @param geometry The geometry defining the graphic.
 @param symbol The symbol used to draw the graphic. Can be nil.
 @param attributes Key-value pairs of fields and field values associated with 
 the graphic.
 @param infoTemplateDelegate The template describing how to display @p attributes 
 in the callout. Can be nil.
 @return A new, autoreleased, graphic object.
 @deprecated Deprecated at 10.2. Please use @c AGSGraphic#graphicWithGeometry:symbol:attributes: instead.
 @agssince{1.0, 10.2}
 */
+ (id)graphicWithGeometry:(AGSGeometry *)geometry symbol:(AGSSymbol *)symbol attributes:(NSDictionary *)attributes infoTemplateDelegate:(id<AGSInfoTemplateDelegate>)infoTemplateDelegate __attribute__((deprecated));

@end

