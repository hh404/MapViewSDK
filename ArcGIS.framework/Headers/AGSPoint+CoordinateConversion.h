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

#import "AGSPoint.h"

/** @file AGSPoint+CoordinateConversion.h */ //Required for Globals API doc

/** @brief Category methods for conversion between string and object representations
 
 This category contains methods to convert @c AGSPoint objects into a variety of string representations and vice-versa. 
 
 @define{AGSPoint+CoordinateConversion.h, ArcGIS}
 @agssince{10.2, 10.2}
 */
@interface AGSPoint (CoordinateConversion)

#pragma mark -
#pragma mark Coordinate Conversion To Point

/** Returns a point for a given MGRS coordinate string
 @param mgrs The MGRS coordinate string. Can contain spaces.
 @param outputSR The spatial reference of the point to be returned.
 @return A point from the MGRS coordinate
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromMGRSString:(NSString*)mgrs withSpatialReference:(AGSSpatialReference*)outputSR;

/** Converts a coordinate notation string in the Degrees Minutes Seconds (DMS) format to an AGSPoint geometry with the specified SpatialReference.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromDegreesMinutesSecondsString:(NSString*)degreesMinutesSeconds withSpatialReference:(AGSSpatialReference*)outputSR;

/** Converts a coordinate notation string in the Decimal Degrees (DD) format to an AGSPoint geometry with the specified SpatialReference.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromDecimalDegreesString:(NSString*)decimalDegrees withSpatialReference:(AGSSpatialReference*)outputSR;

/** Converts a coordinate notation string in the Degrees Decimal Minutes (DDM) format to an AGSPoint geometry with the specified SpatialReference.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromDegreesDecimalMinutesString:(NSString*)ddm withSpatialReference:(AGSSpatialReference*)outputSR;

/** Converts a coordinate notation string in the Global Area Reference System (GARS) format to an AGSPoint geometry with the specified SpatialReference.
 @param conversionMode A value determining whether the returned map point will represent the lower left or center of the cell, quadrant or area.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromGARSString:(NSString*)gars withSpatialReference:(AGSSpatialReference*)outputSR conversionMode:(AGSGARSConversionMode)conversionMode;

/** Converts a coordinate notation string in the Universal Transverse Mercator (UTM) format to an AGSPoint geometry with the specified SpatialReference.
 @param conversionMode A value indicating whether the coordinate string contains North or South Hemisphere indicators.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromUTMString:(NSString*)utm withSpatialReference:(AGSSpatialReference*)outputSR conversionMode:(AGSUTMConversionMode)conversionMode;

/** Converts a coordinate notation string in the Geographic Reference system (GEOREF) format to an AGSPoint geometry with the specified SpatialReference.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromGEOREFString:(NSString*)georef withSpatialReference:(AGSSpatialReference*)outputSR;

/** Converts a coordinate notation string in the United States National Grid (USNG) format to an AGSPoint geometry with the specified SpatialReference.
 @agssince{10.2, 10.2}
 */
+(AGSPoint*)pointFromUSNGString:(NSString*)usng withSpatialReference:(AGSSpatialReference*)outputSR;


#pragma mark -
#pragma mark Coordinate Conversion To String

/** Returns a Military Grid Reference System (MGRS) coordinate for the given point. For example : 4Q 612341 2356781
 @param pt The point for which MGRS coordinate is needed
 @param numDigits The number of digits to be included in the MGRS coordinate
 @param rounding Whether the numeric value should be rounded
 @param addSpaces Whether the MGRS coordinate string should include spaces
 @return The MGRS coordinate string
 @agssince{10.2, 10.2}
 */
-(NSString*)MGRSStringWithNumDigits:(NSInteger)numDigits rounding:(BOOL)rounding addSpaces:(BOOL)addSpaces;

/** Returns a string with degrees minutes seconds (DMS) for a given point.
 @param pt The point to be converted
 @param numDigits The number of digits to be included in the output string
 @agssince{10.2, 10.2}
 */
-(NSString*)degreesMinutesSecondsStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with Decimal Degrees (DD) format for a given point.
 @param pt The point to be converted
 @param numDigits The number of digits to be included in the output string
 @agssince{10.2, 10.2}
 */
-(NSString*)decimalDegreesStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with degrees decimal minute (DDM) format for a given point.
 @param pt The point to be converted
 @param numDigits The number of digits to be included in the output string
 @agssince{10.2, 10.2}
 */
-(NSString*)degreesDecimalMinutesStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with Global Area Reference System (GARS) format for a given point.
 @param pt The point to be converted
 @agssince{10.2, 10.2}
 */
-(NSString*)GARSString;

/** Returns a string with United States National Grid (USNG) format for a given point.
 @param pt The point to be converted
 @param numDigits The number of digits to be included in the output string
 @param rounding Whether the numeric value should be rounded
 @param addSpaces Whether the coordinate string should include spaces
 @agssince{10.2, 10.2}
 */
-(NSString*)USNGStringWithNumDigits:(NSInteger)numDigits
                           rounding:(BOOL)rounding
                          addSpaces:(BOOL)addSpaces;

/** Returns a string with World Geographic Reference system (GEOREF) format for a given point.
 @param pt The point to be converted
 @param numDigits The number of digits to be included in the output string
 @param rounding Whether the numeric value should be rounded
 @agssince{10.2, 10.2}
 */
-(NSString*)GEOREFStringWithNumDigits:(NSInteger)numDigits
                             rounding:(BOOL)rounding;

/** Returns a string with Universal Transverse Mercator (UTM) format for a given point.
 @param pt The point to be converted
 @param conversionMode The mode to use during conversion
 @param addSpaces Whether the coordinate string should include spaces
 @agssince{10.2, 10.2}
 */
-(NSString*)UTMStringWithConversionMode:(AGSUTMConversionMode)conversionMode addSpaces:(BOOL)addSpaces;

@end
