/*
 COPYRIGHT 2011 ESRI
 
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

/** @file AGSEnumerations.h */ 

/**
 Specifies the wrap around status of an AGSMapView.
 If Uninitialized, you need to call @c AGSMapView#enableWrapAround
 if Unsupported,  the basemap layer is either not in WGS84 or WebMercator spatial reference, or because it does not cover the entire world.
 @agssince{10.1.1, 10.2}
 */
typedef enum {
    AGSMapViewWrapAroundStatusDisabled,             /*!< Disabled */
    AGSMapViewWrapAroundStatusUninitialized,        /*!< Uninitalized  */
    AGSMapViewWrapAroundStatusUnsupported,          /*!< Unsupported */
    AGSMapViewWrapAroundStatusEnabled               /*!< Enabled */
} AGSMapViewWrapAroundStatus;

/** Specifies how a text symbol should be vertically aligned.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSTextSymbolVAlignmentBottom = 0,		/*!< Bottom */
	AGSTextSymbolVAlignmentMiddle,			/*!< Middle */
	AGSTextSymbolVAlignmentTop,				/*!< Top */
} AGSTextSymbolVAlignment;

/** Specifies how a text symbol should be horizontally aligned.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSTextSymbolHAlignmentLeft = 0,		/*!< Left  */
	AGSTextSymbolHAlignmentCenter,			/*!< Center */
	AGSTextSymbolHAlignmentRight			/*!< Right */
} AGSTextSymbolHAlignment;


/** Supported marker styles.
 @agssince{1.0, 10.2}
 */
typedef enum {
    AGSSimpleMarkerSymbolStyleCircle = 0,	/*!< Circle */
    AGSSimpleMarkerSymbolStyleCross,		/*!< Cross */
    AGSSimpleMarkerSymbolStyleDiamond,		/*!< Diamond */
    AGSSimpleMarkerSymbolStyleSquare,		/*!< Square */
    AGSSimpleMarkerSymbolStyleX,			/*!< X*/
    AGSSimpleMarkerSymbolStyleTriangle		/*!< Triange */
} AGSSimpleMarkerSymbolStyle;


/** Supported interpolations.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSInterpolationBilinear = 0,                       /*!< Bilinear */
	AGSInterpolationCubicConvolution,                   /*!< Convolution */
	AGSInterpolationMajority,                           /*!< Majority */
	AGSInterpolationNearestNeighbor = NSUIntegerMax		/*!< Nearest Neighbor */
} AGSInterpolation;


/** Possible relationships between geometries.
 @agssince{1.0, 10.2}
 */
typedef enum : NSUInteger {
    AGSGeometryRelationCross = 0,				/*!< Cross */
    AGSGeometryRelationDisjoint,				/*!< Disjoint */
    AGSGeometryRelationIn,						/*!< In */
    AGSGeometryRelationInteriorIntersection,	/*!< Interior Intersection */
    AGSGeometryRelationIntersection,			/*!< Intersection */
    AGSGeometryRelationLineCoincidence,			/*!< Line Coincidence */
    AGSGeometryRelationLineTouch,				/*!< Line Touch */
    AGSGeometryRelationOverlap,					/*!< Overlap */
    AGSGeometryRelationPointTouch,				/*!< Point Touch */
    AGSGeometryRelationTouch,					/*!< Touch */
    AGSGeometryRelationWithin,					/*!< Within */
    AGSGeometryRelationRelation					/*!< Relation */
} AGSGeometryRelation;

/** Supported geometry types.
 @agssince{1.0, 10.2}
 */
typedef enum  {
    AGSGeometryTypeUndefined = -1,  /*!< Undefined */
    AGSGeometryTypePoint,           /*!< Point */
    AGSGeometryTypePolyline,        /*!< Polyline */
    AGSGeometryTypePolygon,         /*!< Polygon */
    AGSGeometryTypeMultipoint,      /*!< Multipoint */
    AGSGeometryTypeEnvelope         /*!< Envelope */
} AGSGeometryType;

/** Supported raster function types. These types correspond to the names of
 raster functions.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSRasterFunctionTypeAspect = 0,		/*!< Aspect */
	AGSRasterFunctionTypeColormap,			/*!< Colormap */
	AGSRasterFunctionTypeHillshade,			/*!< Hillshade */
	AGSRasterFunctionTypeNDVI,				/*!< NDVI */
	AGSRasterFunctionTypeShadedRelief,		/*!< Shaded Relief */
	AGSRasterFunctionTypeSlope,				/*!< Slope */
	AGSRasterFunctionTypeStatistics,		/*!< Statistics */
	AGSRasterFunctionTypeStretch,			/*!< Stretch */
} AGSRasterFunctionType;
	

/** List of supported <code>%AGSFieldType</code>'s
 @agssince{1.0, 10.2}
 */
typedef enum {
    AGSFieldTypeInteger = 0,        /*!< Integer */
    AGSFieldTypeSmallInteger,       /*!< Small Integer */
	AGSFieldTypeDouble,             /*!< Double */
	AGSFieldTypeSingle,             /*!< Single */
	AGSFieldTypeString,             /*!< String */
	AGSFieldTypeDate,               /*!< Date */
	AGSFieldTypeGeometry,           /*!< Geometry */
	AGSFieldTypeOID,                /*!< OID */
	AGSFieldTypeBlob,               /*!< Blob */
	AGSFieldTypeGlobalID,           /*!< Global ID */
	AGSFieldTypeRaster,             /*!< Raster */
	AGSFieldTypeGUID,               /*!< GUID */
	AGSFieldTypeXML                 /*!< XML */
} AGSFieldType;


/** Supported time interval units.
 @agssince{1.0, 10.2}
 */
typedef enum {
    AGSTimeIntervalUnitsMilliseconds = 0,	/*!< Milliseconds */
    AGSTimeIntervalUnitsSeconds,            /*!< Seconds */
    AGSTimeIntervalUnitsMinutes,            /*!< Minutes */
    AGSTimeIntervalUnitsHours,              /*!< Hours */
    AGSTimeIntervalUnitsDays,               /*!< Days */
    AGSTimeIntervalUnitsWeeks,              /*!< Weeks */
    AGSTimeIntervalUnitsMonths,             /*!< Months */
    AGSTimeIntervalUnitsYears,              /*!< Years */
    AGSTimeIntervalUnitsDecades,            /*!< Decades*/
    AGSTimeIntervalUnitsCenturies,          /*!< Centuries */
    AGSTimeIntervalUnitsUnknown             /*!< Unknown */	
} AGSTimeIntervalUnits;

/** Possible spatial relationships.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
    AGSSpatialRelationshipIntersects = 0,		/*!< Intersects */
    AGSSpatialRelationshipContains,				/*!< Contains */
    AGSSpatialRelationshipCrosses,				/*!< Crosses */
    AGSSpatialRelationshipEnvelopeIntersects,	/*!< Envelope Intersects */
    AGSSpatialRelationshipIndexIntersects,		/*!< Index Intersects */
    AGSSpatialRelationshipOverlaps,				/*!< Overlaps */
    AGSSpatialRelationshipTouches,				/*!< Touches */
    AGSSpatialRelationshipWithin,				/*!< Within */
	AGSSpatialRelationshipRelation				/*!< Relation */
} AGSSpatialRelationship;

/** Supported linear units.
 @agssince{1.0, 10.2}
 */
typedef enum : NSUInteger {
    AGSUnitsCentimeters = 0,	/*!< Centimenters */
    AGSUnitsDecimalDegrees,		/*!< Decimal Degrees */
    AGSUnitsDecimeters,			/*!< Decimeters */
    AGSUnitsFeet,				/*!< Feet */
    AGSUnitsInches,				/*!< Inches */
    AGSUnitsKilometers,			/*!< Kilometers */
    AGSUnitsMeters,				/*!< Meters */
    AGSUnitsMiles,				/*!< Miles */
    AGSUnitsMillimeters,		/*!< Millimeters */
    AGSUnitsNauticalMiles,		/*!< Nautical miles */
    AGSUnitsPoints,				/*!< Points */
    AGSUnitsUnknown,			/*!< Unknown */
    AGSUnitsYards				/*!< Yards */
} AGSUnits;

/** Supported area units.
 @agssince{1.0, 10.2}
 */
typedef enum : NSUInteger {
    AGSAreaUnitsSquareInches = 0,		/*!< Sq Inches */
    AGSAreaUnitsSquareFeet,				/*!< Sq Feet */
    AGSAreaUnitsSquareYards,			/*!< Sq Yards */
    AGSAreaUnitsAcres,					/*!< Acres */
    AGSAreaUnitsSquareMiles,			/*!< Sq Miles */
    AGSAreaUnitsSquareMillimeters,		/*!< Sq Millimeters */
    AGSAreaUnitsSquareCentimeters,		/*!< Sq Centimeters */
    AGSAreaUnitsSquareDecimeters,		/*!< Sq Decimeters */
    AGSAreaUnitsSquareMeters,			/*!< Sq Meters */
    AGSAreaUnitsAres,					/*!< Sq Ares */
    AGSAreaUnitsHectares,				/*!< Sq Hectares */
    AGSAreaUnitsSquareKilometers		/*!< Sq Kilometers */
} AGSAreaUnits;

/** Supported esriSRUnits.
 @agssince{1.0, 10.2}
 */
typedef enum : NSUInteger {
    AGSSRUnitMeter					= 9001,     /*!< International meter. */
    AGSSRUnitGermanMeter			= 9031,     /*!< German legal meter. */
    AGSSRUnitFoot					= 9002,     /*!< International foot. */
    AGSSRUnitSurveyFoot				= 9003,     /*!< US survey foot. */
    AGSSRUnitClarkeFoot				= 9005,     /*!< Clarke's foot. */
    AGSSRUnitFathom					= 9014,     /*!< Fathom. */
    AGSSRUnitNauticalMile			= 9030,     /*!< International nautical mile. */
    AGSSRUnitSurveyChain			= 9033,     /*!< US survey chain. */
    AGSSRUnitSurveyLink				= 9034,     /*!< US survey link. */
    AGSSRUnitSurveyMile				= 9035,     /*!< US survey mile. */
    AGSSRUnitKilometer				= 9036,     /*!< Kilometer. */
    AGSSRUnitClarkeYard				= 9037,     /*!< Yard (Clarke's ratio). */
    AGSSRUnitClarkeChain			= 9038,     /*!< Chain (Clarke's ratio). */
    AGSSRUnitClarkeLink				= 9039,     /*!< Link (Clarke's ratio). */
    AGSSRUnitSearsYard				= 9040,     /*!< Yard (Sears). */
    AGSSRUnitSearsFoot				= 9041,     /*!< Sears' foot. */
    AGSSRUnitSearsChain				= 9042,     /*!< Chain (Sears). */
    AGSSRUnitSearsLink				= 9043,     /*!< Link (Sears). */
    AGSSRUnitBenoit1895AYard		= 9050,     /*!< Yard (Benoit 1895 A). */
    AGSSRUnitBenoit1895AFoot		= 9051,     /*!< Foot (Benoit 1895 A). */
    AGSSRUnitBenoit1895AChain		= 9052,     /*!< Chain (Benoit 1895 A). */
    AGSSRUnitBenoit1895ALink		= 9053,     /*!< Link (Benoit 1895 A). */
    AGSSRUnitBenoit1895BYard		= 9060,     /*!< Yard (Benoit 1895 B). */
    AGSSRUnitBenoit1895BFoot		= 9061,     /*!< Foot (Benoit 1895 B). */
    AGSSRUnitBenoit1895BChain		= 9062,     /*!< Chain (Benoit 1895 B). */
    AGSSRUnitBenoit1895BLink		= 9063,     /*!< Link (Benoit 1895 B). */
    AGSSRUnitIndianFoot				= 9080,     /*!< Indian geodetic foot. */
    AGSSRUnitIndian1937Foot			= 9081,     /*!< Indian foot (1937). */
    AGSSRUnitIndian1962Foot			= 9082,     /*!< Indian foot (1962). */
    AGSSRUnitIndian1975Foot			= 9083,     /*!< Indian foot (1975). */
    AGSSRUnitIndianYard				= 9084,     /*!< Indian yard. */
    AGSSRUnitIndian1937Yard			= 9085,     /*!< Indian yard (1937). */
    AGSSRUnitIndian1962Yard			= 9086,     /*!< Indian yard (1962). */
    AGSSRUnitIndian1975Yard			= 9087,     /*!< Indian yard (1975). */
    AGSSRUnitFoot1865				= 9070,     /*!< Foot (1865). */
    AGSSRUnitRadian					= 9101,     /*!< Radian. */
    AGSSRUnitDegree					= 9102,     /*!< Degree. */
    AGSSRUnitArcMinute				= 9103,     /*!< Arc-minute. */
    AGSSRUnitArcSecond				= 9104,     /*!< Arc-second. */
    AGSSRUnitGrad					= 9105,     /*!< Grad. */
    AGSSRUnitGon					= 9106,     /*!< Gon. */
    AGSSRUnitMicroradian			= 9109,     /*!< Microradian. */
    AGSSRUnitArcMinuteCentesimal	= 9112,     /*!< Centesimal arc-minute. */
    AGSSRUnitArcSecondCentesimal	= 9113,     /*!< Centesimal arc-second. */
    AGSSRUnitMil6400				= 9114,     /*!< Mil. */
    AGSSRUnitBritish1936Foot		= 9095,		/*!< British Foot (1936). */
    AGSSRUnitGoldCoastFoot			= 9094,		/*!< Gold Coast Foot. */
    AGSSRUnitInternationalChain		= 109003,	/*!< International Chain. */
    AGSSRUnitInternationalLink		= 109004,	/*!< International Link. */
    AGSSRUnitInternationalYard		= 109001,	/*!< International Yard. */
    AGSSRUnitStatuteMile			= 9093,		/*!< Statute Mile. */
    AGSSRUnitSurveyYard				= 109002,	/*!< US survey Yard. */
    AGSSRUnit50KilometerLength		= 109030,	/*!< 50 Kilometer Length. */
    AGSSRUnit150KilometerLength		= 109031,	/*!< 150 Kilometer Length. */
    AGSSRUnitDecimeter				= 109005,	/*!< Decimeter. */
    AGSSRUnitCentimeter				= 109006,	/*!< Centimeter. */
    AGSSRUnitMillimeter				= 109007,	/*!< Millimeter. */
    AGSSRUnitInternationalInch		= 109008,	/*!< International inch. */
    AGSSRUnitUSsurveyInch			= 109009,	/*!< US survey inch. */
    AGSSRUnitInternationalRod		= 109010,	/*!< International rod. */
    AGSSRUnitUSsurveyRod			= 109011,	/*!< US survey rod. */
    AGSSRUnitUSNauticalMile			= 109012,	/*!< US nautical mile (pre-1954). */
    AGSSRUnitUKNauticalMile			= 109013	/*!< UK nautical mile (pre-1970). */
} AGSSRUnit;

/** Supported @p offsetHow types.
 Square only applicable with the AGSGeometryEngine
 @agssince{1.0, 10.2}
 */
typedef enum {
	AGSGeometryOffsetTypeMitered = 0,   /*!< Mietered */
	AGSGeometryOffsetTypeBevelled,      /*!< Bevelled  */
	AGSGeometryOffsetTypeRounded,       /*!< Rounded */
	AGSGeometryOffsetTypeSquare         /**  Square  */
} AGSGeometryOffsetType;


/** Specifies the way of timeOfDay property is used.
 @agssince{2.3, 10.2}
 @avail{10.1}
 */
typedef enum {
    AGSNATimeOfDayUseAsStartTime = 0, /*!<  Use as the start time.*/
    AGSNATimeOfDayUseAsEndTime        /*!<  Use as the end time.*/
} AGSNATimeOfDayUse;

/** Defines content, verbosity of returned directions.
 @agssince{2.3, 10.2}
 @avail{10.1}
 */
typedef enum {
    AGSNADirectionsOutputTypeStandard = 0,		/*!< Standard directions output ﾖ direction text instructions, geometry, time, length, ETA. Does not include events, new types*/
	AGSNADirectionsOutputTypeComplete,      	/*!< Directions output that includes all directions properties.*/
    AGSNADirectionsOutputTypeCompleteNoEvents,  /*!< Directions output that includes all directions properties except events.*/
    AGSNADirectionsOutputTypeInstructionsOnly,  /*!< Directions output that includes text instructions, time, length and ETA. Does not include geometry.*/
    AGSNADirectionsOutputTypeSummaryOnly        /*!< Directions output that contains only summary (time and length). Detailed text instructions and geometry are not provided.*/
} AGSNADirectionsOutputType;

/** Specifies the type of lines generated by the network analyst solvers.
 
 Note: <code>AGSNAOutputLineTrueShapeWithMeasure</code> is only available at 10.1 and beyond.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSNAOutputLineNone = 0,				/*!< No polylines are generated. */
	AGSNAOutputLineStraight,				/*!< Straight polylines between the two endpoints are generated. */
	AGSNAOutputLineTrueShape,				/*!< Polylines based on the true network feature geometry are generated. */
    AGSNAOutputLineTrueShapeWithMeasure     /*!< Polylines based on the true network feature geometry are generated, and measures are added whenever possible. */
} AGSNAOutputLine;

/** Constants representing how U-Turns are handled
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSNAUTurnAllowBacktrack = 0,			/*!<  Allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsOnly,				/*!<  Allow U-turns only at dead ends only.*/
	AGSNAUTurnNoBacktrack,					/*!<  Don't allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsAndIntersections,	/*!<  Allow U-turns at dead ends and intersections only. */
    AGSNAUTurnAtIntersectionsOnly,          /*!<  Allow U-turns at intersections only. */
} AGSNAUTurn;

/** Constants representing directions length units for the @c AGSRouteTask.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSNAUnitCentimeters = 0,	/*!< Centimeters */
	AGSNAUnitDays,				/*!< Days */
	AGSNAUnitDecimalDegrees,	/*!< Decimal Degrees */
	AGSNAUnitDecimeters,		/*!< Decimeters */
	AGSNAUnitFeet,				/*!< Feet */
	AGSNAUnitHours,				/*!< Hours */
	AGSNAUnitInches,			/*!< Inches */
	AGSNAUnitKilometers,		/*!< Kilometers */
	AGSNAUnitMeters,			/*!< Meters */
	AGSNAUnitMiles,				/*!< Miles */
	AGSNAUnitMillimeters,		/*!< Millimeters */
	AGSNAUnitMinutes,			/*!< Minutes */
	AGSNAUnitNauticalMiles,		/*!< Nautical Miles */
	AGSNAUnitPoints,			/*!< Points */
	AGSNAUnitSeconds,			/*!< Seconds */
	AGSNAUnitUnknown,			/*!< Unknown */
	AGSNAUnitYards,				/*!< Yards */
} AGSNAUnit;

/** Constant representing the type of network layer.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSNALayerTypeRoute = 0,			/*!<  Route Layer. */
	AGSNALayerTypeServiceArea,			/*!<  Service Area Layer. */
	AGSNALayerTypeClosestFacility,		/*!<  Closest Facility Layer. */
} AGSNALayerType;

/** Constants representing how the geometry is returned.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSNATravelDirectionFromFacility = 0,	/*!< Tavel to the facility. */
	AGSNATravelDirectionToFacility,			/*!< Travel from the facility. */
} AGSNATravelDirection;

/** Constants representing maneuver types for a direction.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSNADirectionsManeuverUnknown = 0,		/*!< Unknown */
	AGSNADirectionsManeuverStop,			/*!< Arrive At Stop. */
	AGSNADirectionsManeuverStraight,		/*!< Go straight. */
	AGSNADirectionsManeuverBearLeft,		/*!< Bear left.*/
	AGSNADirectionsManeuverBearRight,		/*!< Bear righty. */
	AGSNADirectionsManeuverTurnLeft,		/*!< Turn left.*/
	AGSNADirectionsManeuverTurnRight,		/*!< Turn right. */
	AGSNADirectionsManeuverSharpLeft,		/*!< Make sharp left. */
	AGSNADirectionsManeuverSharpRight,		/*!< Make sharp right. */
	AGSNADirectionsManeuverUTurn,			/*!< Make a U-turn. */
	AGSNADirectionsManeuverFerry,			/*!< Take ferry. */
	AGSNADirectionsManeuverRoundabout,		/*!< Take roundabout. */
	AGSNADirectionsManeuverHighwayMerge,	/*!< Merge to highway. */
	AGSNADirectionsManeuverHighwayExit,		/*!< Exit highway. */
	AGSNADirectionsManeuverHighwayChange,	/*!< Go on another highway. */
    AGSNADirectionsManeuverForkCenter,		/*!< At fork keep center. */
	AGSNADirectionsManeuverForkLeft,		/*!< At fork keep left. */
	AGSNADirectionsManeuverForkRight,		/*!< At fork keep right. */
	AGSNADirectionsManeuverDepart,			/*!< Depart stop. */
	AGSNADirectionsManeuverTripItem,		/*!< Trip planning item. */
	AGSNADirectionsManeuverEndOfFerry,		/*!< End of ferry. */
    AGSNADirectionsManeuverRampRight,       /*!< Ramp right. */
    AGSNADirectionsManeuverRampLeft,        /*!< Ramp left. */
    AGSNADirectionsManeuverTurnLeftRight,	/*!< Turn left and immediately turn right. */
    AGSNADirectionsManeuverTurnRightLeft,	/*!< Turn right and immediately turn left. */
	AGSNADirectionsManeuverTurnRightRight,	/*!< Turn right and immediately turn right. */
    AGSNADirectionsManeuverTurnLeftLeft,	/*!< Turn left and immediately turn left. */
    AGSNADirectionsManeuverPedestrianRamp,  /*!< Pedestrian ramp. */
    AGSNADirectionsManeuverElevator,        /*!< Elevator. */
    AGSNADirectionsManeuverEscalator,       /*!< Escalator. */
    AGSNADirectionsManeuverStairs,          /*!< Stairs. */
    AGSNADirectionsManeuverDoorPassage,     /*!< Door passage. */
} AGSNADirectionsManeuver;

/** Types of direction strings. These are associated with the more detailed
 direction info passed back from a route solving operation.
 @agssince{2.3, 10.2}
 @avail{10.1}
 */
typedef enum {
    AGSNADirectionsStringGeneral = 0,           /*!< General directions string type.*/
    AGSNADirectionsStringDepart,                /*!< Depart directions string type.*/
    AGSNADirectionsStringArrive,                /*!< Arrive directions string type.*/
    AGSNADirectionsStringLength,                /*!< Length directions string type.*/
    AGSNADirectionsStringTime,                  /*!< Time directions string type.*/
    AGSNADirectionsStringSummary,               /*!< Time directions string type.*/
    AGSNADirectionsStringTimeWindow,            /*!< Time Window directions string type.*/
    AGSNADirectionsStringViolationTime,         /*!< Violation Time directions string type.*/
    AGSNADirectionsStringWaitTime,              /*!< Wait Time directions string type.*/
    AGSNADirectionsStringServiceTime,           /*!< Service Time directions string type.*/
    AGSNADirectionsStringEstimatedArrivalTime,  /*!< Estimated Arrival Time directions string type.*/
    AGSNADirectionsStringCumulativeLength,      /*!< Cumulative Length directions string type.*/
    AGSNADirectionsStringStreetName,            /*!< Street name directions string type.*/
    AGSNADirectionsStringAltName,               /*!< Alternate street name directions string type.*/
    AGSNADirectionsStringBranch,                /*!< Sign branch information directions string type.*/
    AGSNADirectionsStringToward,                /*!< Sign toward information directions string type.*/
    AGSNADirectionsStringCrossStreet,           /*!< Cross street name directions string type.*/
    AGSNADirectionsStringExit,                  /*!< Sign exit number directions string type.*/
} AGSNADirectionsStringType;

/** Constants representing the network analyst message type.
 @agssince{1.8, 10.2}
 */
typedef enum {
	AGSNAMessageTypeAbort = 0,					/*!< Abort */
	AGSNAMessageTypeEmpty = 1,					/*!< Empty */
	AGSNAMessageTypeError = 2,					/*!< Error */
	AGSNAMessageTypeInformative = 3,			/*!< Informative */
	AGSNAMessageTypeProcessDefinition = 50,		/*!< Process Definition */
	AGSNAMessageTypeProcessStart = 100,			/*!< Process Start */
	AGSNAMessageTypeProcessStop = 101,			/*!< Process Stop */
	AGSNAMessageTypeWarning = 200,				/*!< Warning */
} AGSNAMessageType;

/** Contstants representing how the geometry is returned.
 @agssince{1.8, 10.2}
 */
typedef enum : NSUInteger {
	AGSNAOutputPolygonDetailed = 0,			/*!< No polygons are generated. */	
	AGSNAOutputPolygonNone,					/*!< Simplified polygons are generated. */
	AGSNAOutputPolygonSimplified			/*!< Detailed polygons are generated. */
} AGSNAOutputPolygon;

/** Conversion mode for MGRS coordinates
 @agssince{2.3, 10.2}
 */
typedef enum {
    AGSMGRSConversionModeNewStyle = 0,      /*!< New Style */
} AGSMGRSConversionMode;

/** Constants representing error codes.
 @agssince{2.1, 10.2}
 */
typedef enum {
	AGSErrorCodeOperationNotSupported = 10000,          /*!< Op Not Supported */
    AGSErrorCodeNoDataTile = 10001,                     /*!< No Data Tile */
    AGSErrorCodeSpatialReferenceNotSupported = 10002,   /*!< Spatial Reference Not Supported */
    AGSErrorCodeInvalidArgument = 10003,                 /*!< Invalid Argument */
    AGSErrorCodeOperationFailed = 10004                 /*!< This error indicates that, for an unknown reason, the operation failed on the server. This error is only possible when adding items on an AGSPortal or updating properties of an AGSPortalItem.*/
} AGSErrorCode;



///** Defines the drawing behavior for a dynamic layer when
// the map's location display is in an autopan mode other than off.
// @agssince{2.1, 10.2}
// */
//typedef enum {
//	AGSDynamicLayerAutoPanDrawingModeNormal = 0,	/*!< Dynamic layer draws normally. */
//    AGSDynamicLayerAutoPanDrawingModeConservative, /*!< Dynamic layer draws only when it doesn't currently have a drawing operation in progress. 
//                                                       This lessens the load on the server.*/
//    AGSDynamicLayerAutoPanDrawingModeNone /*!< Dynamic layer does not draw when the map is in navigation mode. */
//} AGSDynamicLayerAutoPanDrawingMode;


/**
 @agssince{2.2, 10.2}
 */
typedef enum : NSUInteger {
    AGSPortalItemTypeOther = 0,                          /*!< Other */
    AGSPortalItemTypeMapDocument,               /*!< ArcMap Document (mxd) */
    AGSPortalItemTypeExplorerMap,                   /*!< ArcGIS Explorer Document (nmf) */
    AGSPortalItemTypeGlobeDocument,                 /*!< ArcGlobe Document (3dd) */
    AGSPortalItemTypeSceneDocument,                 /*!< ArcScene Document (sxd) */
    //AGSPortalItemTypeExplorerMap,                  /*!< ArcGIS Explorer Application Configuration (ncfg) */
    AGSPortalItemTypePublishedMap,                  /*!< ArcReader Document (pmf) */
    AGSPortalItemTypeMapPackage,                    /*!< ArcGIS Map Package (mpk)  */
    AGSPortalItemTypeGeoprocessingPackage,          /*!< ArcGIS Geoprocessing Package (gpk) */
    AGSPortalItemTypeLocatorPackage,                /*!< ArcGIS Locator Package (apk) */
    AGSPortalItemTypeTilePackage,                   /*!< ArcGIS Server Tile Package (tpk)*/
    AGSPortalItemTypeWindowsMobilePackage,          /*!< ArcGIS Windows Mobile Package */
    AGSPortalItemTypeDesktopApplicationTemplate,    /*!< The Desktop Application Template (.zip) includes either a desktop add in or a toolbar.exe */
    AGSPortalItemTypeMapTemplate,                   /*!< The Map Template (.zip) contains documentation, a map and GDB folder */
    AGSPortalItemTypeCodeSample,                    /*!< Developer Sample */
    AGSPortalItemTypeGeoprocessingSample,           /*!< Tool, Geoprocessing Sample */
    AGSPortalItemTypeLayer,                         /*!< Layer File (lyr) */
    AGSPortalItemTypeLayerPackage,                  /*!< Layer Package (lpk) */
    AGSPortalItemTypeExplorerLayer,                 /*!< ArcGIS Explorer Layer (nmc) */
    AGSPortalItemTypeDesktopAddIn,                  /*!< ArcGIS Add In (esriaddin) */
    AGSPortalItemTypeExplorerAddIn,                 /*!< ArcGIS Explorer Layer (eaz) */
    AGSPortalItemTypeMapService,                    /*!< ArcGIS Server Map Service */
    AGSPortalItemTypeGeocodingService,              /*!< ArcGIS Server Geocoding Service */
    AGSPortalItemTypeNetworkAnalysisService,        /*!< ArcGIS Server Network Analyst Service */
    AGSPortalItemTypeGlobeService,                  /*!< ArcGIS Server Globe Service */
    AGSPortalItemTypeGeoprocessingService,          /*!< ArcGIS Server Geoprocessing Service */
    AGSPortalItemTypeGeodataService,                /*!< ArcGIS Server Geodata Service */
    AGSPortalItemTypeImageService,                  /*!< ArcGIS Server Image Service */
    AGSPortalItemTypeGeometryService,               /*!< ArcGIS Server Geometry Service */
    AGSPortalItemTypeFeatureService,                /*!< ArcGIS Feature Service */
    AGSPortalItemTypeKML,                           /*!< Data, Map, kml */
    AGSPortalItemTypeWMS,                           /*!< Data, Service, Web Map Service, OGC */
    AGSPortalItemTypeWMTS,                          /*!< Data, Service, Web Map Tile Service, OGC */
    AGSPortalItemTypeWebMap,                        /*!< Web Map authored using the arcgis.com Javascript Web Map viewer or using ArcGIS Explorer online. Usable by web, mobile, and desktop clients */
    AGSPortalItemTypeWebMappingApplication,         /*!< A web mapping application built using ArcGIS API for Javascript, ArcGIS API for Flex, ArcGIS API for Silverlight, Java Web Application Developer Framework, .NET Web Application Developer Framework */
    AGSPortalItemTypeMobileApplication,             /*!< A mobile application build using the ArcGIS for iPhone SDK, ArcGIS for Android SDK, ArcGIS Mobile SDK for the Windows Mobile Platform, or the JavaScript or Flex API */
    AGSPortalItemTypeCodeAttachment,                /*!< Code Attachment */
    AGSPortalItemTypeFeaturedItems,                 /*!< Empty Item type with relationships to items that user wants featured */
    AGSPortalItemTypeFeatureCollection,             /*!< A feature collection is a saved web map feature layer with layer definition and a feature set */
    AGSPortalItemTypeFeatureCollectionTemplate,     /*!< Feature Collection, Feature Service Template, Map Notes Template */
    AGSPortalItemTypeSymbolSet,                     /*!< Symbol Set*/
    AGSPortalItemTypeColorSet,                      /*!< Color Set */
    AGSPortalItemTypeCollectionDefinition,          /*!< The definition for a feature collection/web map feature layer */
    AGSPortalItemTypeOperationView,                 /*!< An Operation View */
    AGSPortalItemTypeOperationsDashboardAddin,      /*!< An Operations Dashboard Addin */
    AGSPortalItemTypeCityEngineWebScene,            /*!< A CityEngine Web Scene */
    AGSPortalItemTypeWorkflowManagerPackage,        /*!< A Workflow Manager Package (wpk) */
    AGSPortalItemTypeArcPadPackage,                 /*!< An ArcPad Package (appk) */
    AGSPortalItemTypeShapefile,                     /*!< A shapefile */
    AGSPortalItemTypeCSV,                           /*!< A text file of data values separated by commas or other delimiters */
    AGSPortalItemTypeImage,                         /*!< An image document (.jpg, .jpeg, .png, .tif, .tiff) */
    AGSPortalItemTypeMSWordDocument,                /*!< A Microsoft Word Document (.doc, .docx) */
    AGSPortalItemTypeMSExcelDocument,               /*!< A Microsoft Excel Document (.xls, .xlsx) */
    AGSPortalItemTypeMSPowerPointDocument,          /*!< A Microsoft Power Point Document (.ppt, .pptx) */
    AGSPortalItemTypeVisioDocument,                 /*!< A Visio Document (.vsd) */
    AGSPortalItemTypePDFDocument,                   /*!< A PDF Document (.pdf) */
    AGSPortalItemTypeDocumentLink,                   /*!< A link to a document on the web (URL) */
    AGSPortalItemTypeServiceDefinition              /*!< A Service Definition that can be published to create a geospatial web service */
} AGSPortalItemType;

/** Access types on Portal, Item, Group or User. 
 
 <b> For Portal or Organization </b>
 
 Determines who can view your organization as an anonymous user. <code>AGSPortalAccessPublic</code> 
 means it allows anonymous users to access your organization's custom URL. <code>AGSPortalAccessPrivate </code> restricts access to only members of your organization.  
 
 <b> For Portal Item </b>
 
 Indicates the access level of the item. If <code>AGSPortalAccessPrivate</code>, only the item owner can
 access. <code>AGSPortalAccessShared</code> allows the item to be shared with a specific group. <code>
 AGSPortalAccessOrganization</code> restricts item access to members of your organization. If <code>
 AGSPortalAccessPublic</code>, all users can access the item.
 
 <b> For Portal Group </b>
 
 Determines who can access the group. <code>AGSPortalAccessPrivate</code> gives access to only the group
 members. If <code>AGSPortalAccessOrganization</code>, all members of this organization can access the
 group. <code>AGSPortalAccessPublic</code> makes the group accessible to all.
 
 <b> For Portal User </b>
 
 Determines if other users can search for this user's name to find content and groups owned by this user
 and to invite this user to join their groups. <code>AGSPortalAccessPrivate</code> hides the user from
 user searches and invites. If <code>AGSPortalAccessOrganization</code>, only members of this user's 
 organization can search for this user, the content and groups. <code>AGSPortalAccessPublic</code> makes 
 the user findable.
 
 @agssince{2.2, 10.2}
 */
typedef enum { 
    AGSPortalAccessPrivate = 0,                     /*!< Applicable for All  */
    AGSPortalAccessShared,                          /*!< Applicable for only Items  */
    AGSPortalAccessOrganization,                    /*!< Applicable for Items, Groups and Users  */
    AGSPortalAccessPublic                           /*!< Applicable for All  */
} AGSPortalAccess;

/** Indicates the order of results of the portal query.  
 @agssince{2.2, 10.2}
 */
typedef enum{
	AGSPortalQuerySortOrderAscending = 0,   	/*!< Ascending */
	AGSPortalQuerySortOrderDescending,			/*!< Descending */
} AGSPortalQuerySortOrder;


/** Indicating whether the portal contains multiple organizations or not. 
 @agssince{2.2, 10.2}
 */
typedef enum {
	AGSPortalModeSingleTenant = 0,   	/*!< Only one organization*/
	AGSPortalModeMultiTenant,			/*!< Multiple organizations*/
} AGSPortalMode;

/** Indicates the role of the portal user within an organization.
 @agssince{10.1.1, 10.2}
 */
typedef enum {
    AGSPortalUserRoleNone = 0,              /*!< The user does not belong to an organization */
    AGSPortalUserRoleUser,                  /*!< Information worker */
    AGSPortalUserRolePublisher,             /*!< Publisher */
    AGSPortalUserRoleAdmin,                 /*!< Administrator */
} AGSPortalUserRole;

/** Indicates the desired sorting criterion for group items.
 @agssince{10.2, 10.2}
 */
typedef enum {
	AGSPortalGroupSortFieldTitle = 0,       /*!< Title */
	AGSPortalGroupSortFieldOwner,           /*!< Ownder */
	AGSPortalGroupSortFieldAvgRating,       /*!< Average Rating */
	AGSPortalGroupSortFieldNumViews,        /*!< Number of Views */
	AGSPortalGroupSortFieldCreated,         /*!< Created Date */
	AGSPortalGroupSortFieldModified,        /*!< Modified Date */
} AGSPortalGroupSortField;

/** Return sort field string for @c AGSPortalGroupSortField.
 @param sortField The sort field.
 @return String representation of @p sortField.
 @agssince{10.2, 10.2}
 @see AGSPortalGroupSortField
 */
AGS_EXTERN NSString *AGSPortalGroupSortFieldToString(AGSPortalGroupSortField sortField);

/**
 @agssince{2.3, 10.2}
 */
typedef enum {
    AGSWMTSServiceModeRESTful = 0,              /*!< RESTful */
    AGSWMTSServiceModeKVP                       /*!< Key-value */
} AGSWMTSServiceMode;


/** Supported image formats.
 @agssince{1.0, 10.2}
 */
typedef enum {
    AGSImageFormatUnknown = -1, /*!< Unknown */
    AGSImageFormatPNG32 = 0,	/*!< PNG 32 */
    AGSImageFormatPNG24,		/*!< PNG 24 */
    AGSImageFormatPNG8,			/*!< PNG 8 */
    AGSImageFormatPNG,			/*!< PNG */
    AGSImageFormatJPG,			/*!< JPG */
    AGSImageFormatGIF,			/*!< GIF */
	AGSImageFormatBMP,			/*!< BMP */
	AGSImageFormatTIFF,			/*!< TIFF */
	AGSImageFormatJPGPNG,		/*!< JPG if image fully opaque, PNG if transparent */
    //For most layers JPEG should be treated the same as JPG using jpg for the files extension, however for some (only WMTS so far)
    //the file extension used for JPEG needs to be jpeg.
	AGSImageFormatJPEG          /*!< JPEG */
} AGSImageFormat;

/** An enumeration that is used for defining the style of an AGSPopupsContainer.
 @agssince{2.0, 10.2}
 */
typedef enum {
	AGSPopupsContainerStyleDefault = 0, /*!< Default */
	AGSPopupsContainerStyleBlack,       /*!< Black */
	AGSPopupsContainerStyleCustomColor  /*!< CustomColor */
} AGSPopupsContainerStyle;

/** An enumeration that is used for defining the editing style of an AGSPopupsContainer.
 @agssince{2.0, 10.2}
 */
typedef enum {
	AGSPopupsContainerEditingStyleGeometryTool,     /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
	AGSPopupsContainerEditingStyleGeometryInline    /*!< Has a view to switch between attributes and attachments.
                                                     There is no button for the collecting the geometry, as this is assumed
                                                     the user has access to the map while the popup is up (think ipad), or
                                                     the user will not be collecting a geometry at all. */
} AGSPopupsContainerEditingStyle;

/** An enumeration that is used for defining the Paging style of an AGSPopupsContainer.
 @agssince{2.0, 10.2}
 */
typedef enum {
	AGSPopupsContainerPagingStylePageControl,   /*!< Page Control */
	AGSPopupsContainerPagingStyleToolbar        /*!< Toolbar */
} AGSPopupsContainerPagingStyle;

/** An enumeration that is used for defining statistic calculations in AGSOutStatistics.
 @agssince{10.1.1, 10.2}
 */
typedef enum {
    AGSQueryStatisticsTypeCount,            /*!< Count */
    AGSQueryStatisticsTypeSum,              /*!< Sum */
    AGSQueryStatisticsTypeMin,              /*!< Minimum value */
    AGSQueryStatisticsTypeMax,              /*!< Maximum value */
    AGSQueryStatisticsTypeAvg,              /*!< Average */
    AGSQueryStatisticsTypeStdDev,           /*!< Standard Deviation */
    AGSQueryStatisticsTypeVar,              /*!< Variance */
} AGSQueryStatisticsType;

/** Military symbology dictionary type
 @agssince{10.1.1, 10.2}
 */
typedef enum {
    AGSMPSymbolDictionaryTypeMil2525C,              /*!< Mil-2525C */
    AGSMPSymbolDictionaryTypeApp6B,                 /*!< App-6B */
    AGSMPSymbolDictionaryTypeSimple                 /*!< Simple */
} AGSMPSymbolDictionaryType;
    
/** Returns the image format as a string.
 @agssince{1.0, 10.2}
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormat(AGSImageFormat imageFormat);
    
/** Returns the image format as a string.
 @agssince{10.1.1, 10.2}
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormatWithJPEGEqualToJPG(AGSImageFormat imageFormat, BOOL IsJPEGEqualToJPG);


/** An enumeration that is used for converting GARS coordinates
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSGARSConversionModeLowerLeft = 0, /*!< Lower Left */
    AGSGARSConversionModeCenter = 1     /*!< Center */
} AGSGARSConversionMode;


/** An enumeration that is used for converting UTM coordinates
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSUTMConversionModeNoIndicators = 0,               /*!< No Indicators */
    AGSUTMConversionModeNorthSouthIndicators = 1        /*!< North South Indicators */
} AGSUTMConversionMode;


/** Status of the current job being executed on the AGSGDBTask.
 @agssince{10.2, 10.2}
 */
typedef enum : NSUInteger {
    AGSGDBTaskJobStatusPending = 0,             /*!< Pending */
    AGSGDBTaskJobStatusInProgress,              /*!< In Progress */
    AGSGDBTaskJobStatusCompleted,               /*!< Completed */
    AGSGDBTaskJobStatusFailed,                  /*!< Failed */
    AGSGDBTaskJobStatusImportChanges,           /*!< Importing Changes */
    AGSGDBTaskJobStatusExportChanges,           /*!< Exporting Changes */
    AGSGDBTaskJobStatusExportingData,           /*!< Exporting Data */
    AGSGDBTaskJobStatusExportAttachments,       /*!< Exporting Attachments */
    AGSGDBTaskJobStatusImportAttachments,       /*!< Importing Attachments */
    AGSGDBTaskJobStatusProvisioningReplica,     /*!< Provisioning Replica */
    AGSGDBTaskJobStatusUnRegisteringReplica,    /*!< Unregistering Replica*/
    AGSGDBTaskJobStatusCompletedWithErrors      /*!< Completed with errors */
} AGSGDBTaskJobStatus;

/** Defines whether and how filters will be applied to a layer.
 @agssince{10.2,10.2}
 */
typedef enum{
    AGSGDBQueryOptionNone = 0,      /*!< No features are included, unless they are related to feature in other layers in the replica and @c AGSGDBLayerQuery::includeRelated is @c YES  */
    AGSGDBQueryOptionUseFilter,		/*!< Features that satisfy filtering based on @c AGSGDBLayerQuery::where clause and optionally, @c AGSGDBGenerateParameters#extent (only if @c AGSGDBLayerQuery#useGeometry is @c YES) are included */
    AGSGDBQueryOptionAll			/*!< All the features from the layer are included */
} AGSGDBQueryOption;

/**
 @agssince{10.2,10.2}
 */
typedef enum{
    AGDGDBTaskResponseTypeData,				/*!< Data */
    AGDGDBTaskResponseTypeRegisterData,		/*!< Register Data */
    AGDGDBTaskResponseTypeEdits,			/*!< Edits */	
    AGDGDBTaskResponseTypeReplacementData,	/*!< Replacement Data */
    AGDGDBTaskResponseTypeEditsAndData,		/*!< Edits & Data */
    AGSGDBTaskResponseTypeNoEdits			/*!< No Edits*/
} AGSGDBTaskResponseType;

/** The sync model defines how layers in a replica can be synced.
 @see @c AGSGDBSyncDirection
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSGDBSyncModelPerReplica,	/*!< Layers within a replica cannot be synchronized independently. The sync operation and sync direction applies to all the layers in the replica. */
    AGSGDBSyncModelPerLayer		/*!< Layers within a replica can be synchronized independently. A chosen subset of the layers within a replica can be synchronized when running the sync operation. Also, each layer can independently choose its sync direction */
} AGSGDBSyncModel;

/** Status of an operation initiated by @c AGSTileCacheTask
 @agssince{10.2, 10.2}
 */
typedef enum{
    AGSTileCacheJobNew = 0,		/*!< New */
    AGSTileCacheJobSubmitted,	/*!< Submitted */
    AGSTileCacheJobWaiting,		/*!< Waiting */
    AGSTileCacheJobExecuting,	/*!< Executing */
    AGSTileCacheJobSucceeded,	/*!< Succeeded */
    AGSTileCacheJobFailed,		/*!< Failed */
    AGSTileCacheJobTimedOut,	/*!< Timed Out */
    AGSTileCacheJobCancelling,	/*!< Cancelling */
    AGSTileCacheJobCancelled,	/*!< Cancelled */
    AGSTileCacheJobDeleting,	/*!< Deleting */
    AGSTileCacheJobDeleted		/*!< Deleted */
}AGSTileCacheJobStatus;

/**
 A block that will be invoked when @c AGSTileCacheTask#estimateSizeWithParameters:status: has a new status to report.
 The result parameter is an @c AGSTileCacheSizeEstimate object.
 @agssince{10.2, 10.2}
 */
typedef void (^AGSTileCacheTaskStatusBlock)(NSString *jobId, AGSTileCacheJobStatus status, NSArray *messages, id result, NSError *error);

/**
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSRequestHTTPMethodGet = 0,						/*!< GET */
    AGSRequestHTTPMethodPostFormEncodeParameters = 1,	/*!< POST Form Encoded Params */
    AGSRequestHTTPMethodPostJSON = 2					/*!< POST Json */
}AGSRequestHTTPMethod;


/** Return field type string for @c AGSFieldType.
 @param fieldType The type for field.
 @return String representation of @p fieldType.
 @agssince{10.2, 10.2}
 @see AGSFieldType
 */
AGS_EXTERN NSString *AGSFieldTypeToString(AGSFieldType fieldType);

/** Return @c AGSFieldType from field.
 @param fieldType The string representation of the field type.
 @return @c AGSFieldType for @p fieldType.
 @agssince{10.2, 10.2}
 @see AGSFieldType
 */
AGS_EXTERN AGSFieldType AGSFieldTypeFromString(NSString *fieldType);

/** Return relation type string for @c AGSGeometryRelation.
 @param relation The type for relation.
 @return String representation of @p relation.
 @agssince{10.2, 10.2}
 @see AGSGeometryRelation
 */
AGS_EXTERN NSString *AGSGeometryRelationAsString(AGSGeometryRelation relation);

/** Return @c AGSGeometryRelation from relation.
 @param relation The relation to determine relation type.
 @return @c AGSGeometryRelation for @p relation.
 @agssince{10.2, 10.2}
 @see AGSGeometryRelation
 */
AGS_EXTERN AGSGeometryRelation AGSGeometryRelationFromString(NSString *relation);

/** Return relation type string for @c AGSGeometryOffsetType.
 @param offsetType The type for relation.
 @return String representation of @p offsetType.
 @agssince{10.2, 10.2}
 @see AGSGeometryOffsetType
 */
AGS_EXTERN NSString *AGSGeometryOffsetTypeAsString(AGSGeometryOffsetType offsetType);

/** Return @c AGSGeometryOffsetType from offsetType.
 @param offsetType The offset to determine offset type.
 @return @c AGSGeometryOffsetType for @p offsetType.
 @agssince{10.2, 10.2}
 @see AGSGeometryOffsetType
 */
AGS_EXTERN AGSGeometryOffsetType AGSGeometryOffsetTypeFromString(NSString* offsetType);

/** An enumeration that is used for defining the sync direction.
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSGDBSyncDirectionNone = 0,		/*!< None */
    AGSGDBSyncDirectionDownload,		/*!< Download changes only */
    AGSGDBSyncDirectionUpload,			/*!< Upload changes only */
    AGSGDBSyncDirectionBidirectional,	/*!< Download and Upload changes */
} AGSGDBSyncDirection;

/** Return sync direction string for @c AGSGDBSyncDirection.
 @param syncDirection The direction for sync.
 @return String representation of @p syncDirection.
 @agssince{10.2, 10.2}
 @see AGSGDBSyncDirection
 */
AGS_EXTERN NSString *AGSGDBSyncDirectionAsString(AGSGDBSyncDirection syncDirection);

/** Return @c AGSGDBSyncDirection from syncDirection.
 @param syncDirection The direction to determine the sync.
 @return @c AGSGDBSyncDirection for @p syncDirection.
 @agssince{10.2, 10.2}
 @see AGSGDBSyncDirection
 */
AGS_EXTERN AGSGDBSyncDirection AGSGDBSyncDirectionFromString(NSString *syncDirection);

/** Return job status string for @c AGSGDBTaskJobStatus.
 @param jobStatus The job status.
 @return String representation of @p jobStatus.
 @agssince{10.2, 10.2}
 @see AGSGDBTaskJobStatus
 */
AGS_EXTERN NSString *AGSGDBTaskJobStatusAsString(AGSGDBTaskJobStatus jobStatus);

/** Return @c AGSGDBTaskJobStatus from jobStatus.
 @param jobStatus The job status.
 @return @c AGSGDBTaskJobStatus for @p jobStatus.
 @agssince{10.2, 10.2}
 @see AGSGDBTaskJobStatus
 */
AGS_EXTERN AGSGDBTaskJobStatus AGSGDBTaskJobStatusFromString(NSString *jobStatus);

/** Return query option string for @c AGSGDBQueryOption.
 @param queryOption The query option.
 @return String representation of @p queryOption.
 @agssince{10.2, 10.2}
 @see AGSGDBQueryOption
 */
AGS_EXTERN NSString *AGSGDBQueryOptionAsString(AGSGDBQueryOption queryOption);

/** Return @c AGSGDBQueryOption from queryOption.
 @param queryOption The query option.
 @return @c AGSGDBQueryOption for @p queryOption.
 @agssince{10.2, 10.2}
 @see AGSGDBQueryOption
 */
AGS_EXTERN AGSGDBQueryOption AGSGDBQueryOptionFromString(NSString* queryOption);

/** Return the response type string for an @c AGSGDBTask.
 @param responseType The response type to retrieve a string for.
 @return An NSString representing the @p responseType.
 @agssince{10.2, 10.2}
 @see AGSGDBTaskResponseType
 */
AGS_EXTERN NSString *AGSGDBTaskResponseTypeAsString(AGSGDBTaskResponseType responseType);

/** Return the response type enumeration from a JSON response string
 @param responseType The response type string.
 @return An enumeration representing the @p responseType string.
 @agssince{10.2, 10.2}
 @see AGSGDBTaskResponseType
 */
AGS_EXTERN AGSGDBTaskResponseType AGSGDBTaskResponseTypeFromString(NSString *responseType);

/** Return the sync model enumeration from a JSON syncModel string.
 @param syncModel The sync model string.
 @return An enumeration representing the @p syncModel string.
 @agssince{10.2, 10.2}
 @see AGSGDBSyncModel
 */
AGS_EXTERN AGSGDBSyncModel AGSGDBSyncModelFromString(NSString *syncModel);

/** Return the sync model enumeration from a JSON sync model string.
 @param syncModel The sync model string.
 @return An enumeration representing the @p syncModel string.
 @agssince{10.2, 10.2}
 @see AGSGDBSyncModel
 */
AGS_EXTERN NSString *AGSGDBSyncModelAsString(AGSGDBSyncModel syncModel);


/** Status for jobs that you kick off on the server and wait for them to finish and then download the result.
 Examples of this are generating geodatabases, generating tile caches, and syncing geodatabases.
 @agssince{10.2, 10.2}
 */
typedef enum {
    AGSAsyncServerJobStatusNotStarted = 1,					/*!< Not Started */
    AGSAsyncServerJobStatusWaitingForDefaultParameters,		/*!< Waiting for defaults */
    AGSAsyncServerJobStatusPreProcessingJob,				/*!< Pre Processing */
    AGSAsyncServerJobStatusStartingJob,						/*!< Starting */
    AGSAsyncServerJobStatusPolling,							/*!< Polling */
    AGSAsyncServerJobStatusFetchingResult,					/*!< Fetching Result */
    AGSAsyncServerJobStatusInBGWaitingToFinish,				/*!< Backgrounded; waiting to finish */
    AGSAsyncServerJobStatusDone,							/*!< Done */
    AGSAsyncServerJobStatusCancelled						/*!< Cancelled */
}AGSAsyncServerJobStatus;

/** Marker alignment when map is rotated
 @agssince{10.2, 10.2}
*/
typedef enum{
    AGSMarkerSymbolAngleAlignmentScreen,    /*!< Marker top edge always aligned with screen top edge*/
    AGSMarkerSymbolAngleAlignmentMap      /*!< Marker top edge always aligned with map north */
} AGSMarkerSymbolAngleAlignment;            /*!< */
