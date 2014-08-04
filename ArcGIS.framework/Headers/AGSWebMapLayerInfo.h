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

@class AGSWebMapFeatureCollection;
@class AGSPopupInfo;
@class AGSLayer;
@class AGSFeatureLayer;
@class AGSTileInfo;
@class AGSEnvelope;

/** @file AGSWebMapLayerInfo.h */ //Required for Globals API doc

/** @brief Information about top-level layers in a webmap
 
 Instances of this class represent information about top-level layers (such as map service layer, bing maps layer, openstreetmap layer, feature layer, feature collection, wms layer, etc) in the web map. 
 
 @agssince{2.2, 10.2}
 */
@interface AGSWebMapLayerInfo : NSObject <AGSCoding>

/**
 @agssince{10.2, 10.2}
 */
- (id)initWithTitle: (NSString *) title
                url: (NSURL *) URL
            opacity: (float) opacity
          layerType: (NSString *) lyrtype
         visibility:(BOOL)visibility;

/**
 @agssince{10.2, 10.2}
 */
-(id)initWithMapLayer:(AGSLayer*)mapLayer;

/** The id of the layer in the webmap.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *layerId;

/** The id of an item containing default information for the layer. The item resides on the same portal as the webmap.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *itemId;

/** The title of the layer in the webmap.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSString *title;

/** URL of the layer's backing service.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readwrite) NSURL *URL; 

/** If the value is 1, the layer is fully opaque. If 0, the layer is fully transparent.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, readwrite) float opacity;

/** The type of the layer. For example, OpenStreetMap, BingMapsAerial, BingMapsRoad, BingMapsHybrid, WMS, CSV, etc
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSString *layerType;

/** Whether the layer is visible or not.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, readwrite) BOOL visibility;

/** If YES, then the layer should be drawn on top of all other layers in the web map. Else, it should be drawn
 based on the order it was stored in the web map. This property only applies to basemap layers, not to operational layers.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL isReference;

/** Only applicable if the layer is a feature collection. A feature collection is a representation of one or more feature layers, where each layer contains the definition of that layer and the features that belong to that layer.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSWebMapFeatureCollection *featureCollection;

/** Only applies if the layer is a feature layer. A value of 0 implies @c AGSFeatureLayerModeSnapshot, 1 implies @c AGSFeatureLayerModeOnDemand, and 2 implies @c AGSFeatureLayerModeSelection. 
 @agssince{2.2, 10.2}
 */
@property (nonatomic, assign, readwrite) NSInteger mode;

/** A popup definition for the layer.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSPopupInfo *popupInfo;

/** An array of @c AGSWebMapSubLayerInfo objects representing the sublayers of the layer. 
 For example, if the layer is based on an ArcGIS map service. Each sublayer will have an id and optionally a popup definition.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSArray *layers;

/** An array of sub-layer ids that should be visible
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSArray *visibleLayers;

/** Only applicable if the layer is a feature layer. This is the JSON returned by a Map or Feature Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson. 
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSDictionary *layerDefinition;

/** A property indicating whether the web map should show the features from this service in the legend.
 @agssince{2.3, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL showLegend;

/** Array of bandIds to override the image service layer's defaults.
 @agssince{2.3, 10.2}
 */
@property (nonatomic, copy, readwrite) NSArray *bandIds;

/** The minimum scale at which this layer is visible. If the map is zoomed out
 beyond this scale, the layer will not be visible.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in
 beyond this scale, the layer will not be visible.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** A property indicating whether the web map has disabled editing for the features in this layer
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL isEditingDisabled;

/** The layer on the map that this is associated with.
 This property will be nil if this AGSWebMapLayerInfo has an AGSWebMapFeatureCollection.
 (In which cases, look at the mapLayer property of the AGSWebMapSubLayerInfos on the AGSWebMapFeatureCollection.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSLayer *mapLayer;

/** The AGSFeatureLayer that is associated with this AGSWebMapLayerInfo.
 If this is populated then it's the same as the mapLayer as the mapLayer represents an AGSFeatureLayer in those cases.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSFeatureLayer *backingFeatureLayer;

/** The url of the portal that potentially contains information to access this layer such as the bing maps key.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readwrite) NSURL *portalURL;

/** The AGSTileInfo associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/** The AGSEnvelope of the full extent of the service associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The web tiled layer template URL associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *templateURL;

/** Determines whether popups are disabled for this layer.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL disablePopup;

@end




