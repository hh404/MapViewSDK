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

/** @file AGSMapViewBase.h */

@class AGSSpatialReference;
@class AGSPolygon;
@class AGSPoint;
@class AGSEnvelope;
@class AGSTimeExtent;
@class AGSGeometry;
@class AGSGraphic;
@class AGSLayer;
@class AGSGraphicsLayer;
@class AGSLocationDisplay;
@class AGSCallout;
@protocol AGSMapViewLayerDelegate;
@protocol AGSMapViewCalloutDelegate;
@protocol AGSMapViewTouchDelegate;

/** Notification that indicates that an @c AGSMapView finished zooming.
 @agssince{10.1.1, 10.2}
 */
AGS_EXTERN NSString *const AGSMapViewDidEndZoomingNotification;


/** Notification that indicates that an @c AGSMapView finished panning.
 @agssince{10.1.1, 10.2}
 */
AGS_EXTERN NSString *const AGSMapViewDidEndPanningNotification;

/** Notification that indicates that an @c AGSMapView added a layer.
 @agssince{10.2, 10.2}
 */
AGS_EXTERN NSString *const AGSMapViewDidAddLayerNotification;

/** Notification that indicates that an @c AGSMapView removed a layer.
 @agssince{10.2, 10.2}
 */
AGS_EXTERN NSString *const AGSMapViewDidRemoveLayerNotification;

/** Notification that indicates that an @c AGSMapView has loaded.
 @agssince{10.2, 10.2}
 */
AGS_EXTERN NSString *const AGSMapViewDidLoadNotification;

/** @class AGSMapViewBase
 @brief A base class for AGSMapView 
 
 A base class for @c AGSMapView to facilitate code reuse between iOS and Mac platforms
 */

@interface AGSMapViewBase : UIView
{
@protected
    CGFloat _screenScale;
    CGFloat _screenScaleInverse;
}

/** @property id<AGSMapViewLayerDelegate> layerDelegate
 Delegate to be notified when map layer actions occur. The delegate class must 
 adopt the @c AGSMapViewLayerDelegate protocol.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, weak) id<AGSMapViewLayerDelegate> layerDelegate;

/** Delegate to be notified when touch events occur on the map.The delegate class must 
 adopt the @c AGSMapViewTouchDelegate protocol.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, weak) id<AGSMapViewTouchDelegate> touchDelegate;

/** Delegate to be notified when map callout actions occur.The delegate class must 
 adopt the @c AGSMapViewCalloutDelegate protocol.
 @deprecated Deprecated at 10.2. Use @c AGSCallout#delegate instead.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, weak) id<AGSMapViewCalloutDelegate> calloutDelegate __attribute__((deprecated));

/** Array of @c AGSLayer objects representing the layers in the map. Depending upon the type of layer, each object
 will be specific sub-class of @c AGSLayer.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *mapLayers;

/** After the first layer added to the map is loaded, this value is set to <code>true</code>.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, readonly) BOOL loaded;

/** The map's current resolution (map units per Point).
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double resolution;

/** The current scale of the map. Will return 0 if it cannot be calculated.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double mapScale;


/** The spatial reference of the map. Defined by the <i>basemap</i> layer.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The time extent for the map. Will be used only for time-aware layers. 
 @avail{10.0}
 @see @concept{Viewing_Temporal_data/00pw00000051000000/, Viewing Temporal Data}
 @see @sample{5603382f9f77482098398e01c8d276cc, Temporal}
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readwrite) AGSTimeExtent *timeExtent;

/** Flag to indicate if the map should show the magnifier when the user performs a tap
 and hold gesture on the map. Default is @c NO
 */
@property (nonatomic, assign, readwrite) BOOL showMagnifierOnTapAndHold;

/** Flag to indicate if the map should pan when the magnifer gets near the edge of the map's 
 bounds. The default is <code>YES</code>.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL allowMagnifierToPanMap;


/**The rotation angle (in degrees). The map is rotated in a counter-clockwise direction by the amount specified. To specify a new angle, see 
 @see #setRotationAngle:animated: 
 @see #setRotationAngle:aroundMapPoint:animated: 
 @see #setRotationAngle:aroundScreenPoint:animated:
 @agssince{2.1, 10.2}
 */
@property (nonatomic, assign) double rotationAngle;

/** Flag to indicate if a user should be allowed to rotate the map using a two finger twist gesture.
 Default is @c NO.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, assign) BOOL allowRotationByPinching;

/** A polygon representing the map's visible area. 
 The polygon always contains 1 ring with 4 vertices, each representing a corner of the map.
 
 An envelope is no longer be used to represent the visible area because the map may be rotated and each corner of the map may contain unique x-y coordinates, where as an envelope only permits 2 unique x coordinates (xmin, xmax) and 2 unique y coordinates (ymin, ymax).
 @agssince{2.1, 10.2}
 */
- (AGSPolygon*)visibleArea;

/** An bounding envelope for the map's #visibleArea. The envelope and the visible area will
 be the same if the map has not been rotated. Otherwise, the envelope will be slightly larger to fully contain the visible area. 
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy, readonly) AGSEnvelope *visibleAreaEnvelope;

/** The map coordinates of where the map display is anchored.
 Usually this is the center of the map. However it could be different. For example, if the map is anchored on the location display, this will be the coordinate
 of the location display.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy, readonly) AGSPoint *mapAnchor;

/** Limits the amount by which the map can be panned such that its anchor point (typically the center) never goes outside
 this envelope. By default, this is the full envelope of the basemap layer. If you set a custom extent,
 the envelope must have the same spatial reference as the map.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSEnvelope *maxEnvelope;

/** Display's a location on the map from a datasource such as a gps feed.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong, readonly) AGSLocationDisplay *locationDisplay;

/** A callout view for displaying information on the map.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSCallout *callout;

/**
 The first layer added to the map.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong, readonly) AGSLayer *baseLayer;

/** The background color of the map.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSColor *backgroundColor;

/** The size of the grid squares.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) CGFloat gridSize;

/**
 The width of the grid lines.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) CGFloat gridLineWidth;

/** The color of the grid lines.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong) AGSColor *gridLineColor;

/** Whether the map is currently being dragged, pinched, rotated or scrolled by the user.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL interacting;

/** Whether the map is in a state of animating.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL animating;

/** Whether the last change to the map's scale, resolution, extent or angle was due to user interaction
 (panning, pinching, etc).
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL lastChangeFromInteraction;

/** Whether or not the map will allow the callout to be shown as a result of tapping/clicking on the map.
 The default is YES. The callout can still be shown programmatically by calling the methods on the callout
 when this property is set to NO.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL allowCallout;

/** Convert the specified point in screen units to a point in map units.
 @param point Point in screen units. 
 @return Point in map units. Point will have the same spatial reference as the map.
 @agssince{1.0, 10.2}
 */
- (AGSPoint *)toMapPoint:(CGPoint)point;

/** Convert the specified point in map units to a point in screen units.
 @param point Point in map units. Point must have the same spatial reference as the map.
 @return Point in screen units.
 @agssince{1.0, 10.2}
 */
- (CGPoint)toScreenPoint:(AGSPoint *)point;

/** Convert the specified envelope in map units to a @c CGRect in screen units.
 @param envelope Envelope in map units. Envelope must have the same spatial reference as the map.
 @return @c CGRect in screen coordinates
 @agssince{1.0, 10.2}
 */
- (CGRect)toScreenRect:(AGSEnvelope *)envelope;

/** Converts a rectangle in screen coordinates to an envelope in map units.
 @param rect Rectangle in screen coordinates to convert from.
 @return Envelope in map units. Envelope will have the same spatial reference as the map.
 @agssince{1.0, 10.2}
 */
- (AGSEnvelope *)toMapEnvelope:(CGRect)rect;

/** Zoom/Pan the map to specified envelope.
 @param envelope Map envelope to zoom/pan to. Envelope must have the same spatial reference as the map. 
 Envelope must be in map units.
 @param animated Determines if the scrolling should be animated or immediate.
 @agssince{1.0, 10.2}
 */
- (void)zoomToEnvelope:(AGSEnvelope *)envelope animated:(BOOL)animated;

/** Zooms map by a factor. Anchor Point is in screen coordinates of the map view.
 @param factor Used to determine the amount to zoom. For example, use 0.5 to 
 zoom in twice as far and 2.0 to zoom out twice as far.
 @param anchorPoint Point in screen coordinates around which to zoom. This is ignored if the location display @link AGSLocationDisplay::autoPanMode autoPanMode @endlink is @c AGSLocationDisplayAutoPanModeNavigation or @c AGSLocationDisplayAutoPanModeCompassNavigation in which case map zooms around the location symbol.
 @param animated Determines if the zooming should be animated or immediate.
 @agssince{1.0, 10.2}
 */
-(void)zoomWithFactor:(double)factor atAnchorPoint:(CGPoint)anchorPoint animated:(BOOL)animated;

/** Zooms in to the current center of the map by a factor of .5.
 @param animated Determines if the zooming in should be animated or immediate.
 @agssince{1.0, 10.2}
 */
-(void)zoomIn:(BOOL)animated;

/** Zooms out to the current center of the map by a factor of 2.
 @param animated Determines if the zooming out should be animated or immediate.
 @agssince{1.0, 10.2}
 */
-(void)zoomOut:(BOOL)animated;

/** Center map at specified location.
 @param point Map point to center map. Point must have the same spatial reference as the map.
 Point must be in map units.
 @param animated Determines if the centering should be animated or immediate.
 @agssince{1.0, 10.2}
 */
- (void)centerAtPoint:(AGSPoint *)point animated:(BOOL)animated;

/** Zooms the map such that the given geometry fits the bounds of the map.
 @param geometry to zoom to
 @param padding in points so that the geometry may not touch any edges of the map
 @param animated flag indicating whether to animate the zoom action
 @agssince{2.1, 10.2}
 */
-(void)zoomToGeometry:(AGSGeometry*)geometry withPadding:(CGFloat)padding animated:(BOOL)animated;

/** Zooms the map to the given resolution
 @param res The resolution (map units per pixel) to zoom to
 @param centerPoint to zoom around. If nil and the location display @link AGSLocationDisplay::autoPanMode autoPanMode @endlink is @c AGSLocationDisplayAutoPanModeNavigation or @c AGSLocationDisplayAutoPanModeCompassNavigation, the map zooms around the location symbol.
 If the locationDisplay is not in those modes, but the centerPoint is nil, map zooms around its center. 
 @param animated flag indicating whether to animate the zoom action
 @agssince{2.1, 10.2}
 @see @c AGSTiledLayer#convertedResolutionForLodResolution: to convert @c AGSLOD#resolution to map resolution.

 */
-(void)zoomToResolution:(double)res withCenterPoint:(AGSPoint*)centerPoint animated:(BOOL)animated;

/** Zooms the map to the given scale
 @param scale to zoom to
 @param centerPoint to zoom around. If nil and the locationDisplay @link AGSLocationDisplay::autoPanMode autoPanMode @endlink is @c AGSLocationDisplayAutoPanModeNavigation or @c AGSLocationDisplayAutoPanModeCompassNavigation, the map zooms around the location symbol.
 If the locationDisplay is not in those modes, but the centerPoint is nil, map zooms around its center. 
 @param animated flag indicating whether to animate the zoom action
 @agssince{2.1, 10.2}
 @see @c AGSTiledLayer#convertedScaleForLodScale: to convert @c AGSLOD#scale to map scale.

 */
-(void)zoomToScale:(double)scale withCenterPoint:(AGSPoint*)centerPoint animated:(BOOL)animated;

/** Zooms the map to the given resolution
 @param res The resolution (map units per pixel) to zoom to. See
 @param animated flag indicating whether to animate the zoom action
 @agssince{10.1.1, 10.2}
 @see @c AGSTiledLayer#convertedResolutionForLodResolution: to convert @c AGSLOD#resolution to map resolution.
 */
-(void)zoomToResolution:(double)res animated:(BOOL)animated;

/** Zooms the map to the given scale
 @param scale to zoom to
 @param animated flag indicating whether to animate the zoom action
 @agssince{10.1.1, 10.2}
 @see @c AGSTiledLayer#convertedScaleForLodScale: to convert @c AGSLOD#scale to map scale.
 */
-(void)zoomToScale:(double)scale animated:(BOOL)animated;

/** Resets the map to an original and unloaded state. Will remove any and all layers from the map. The spatial reference,
 extents, and othe properties related to the layer will be cleared. The first
 layer subsequently added to the map after invoking this method will be treated as a basemap layer.
 @agssince{1.8, 10.2}
 */
-(void)reset;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param animated flag indicating if the map should animate to new rotation angle
 @agssince{2.1, 10.2}
 */
-(void)setRotationAngle:(double)angle animated:(BOOL)animated;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param screenPoint the location on screen around which the map should be rotated
 @param animated flag indicating if the map should animate to new rotation angle
 @agssince{2.1, 10.2}
 */
-(void)setRotationAngle:(double)angle aroundScreenPoint:(CGPoint)screenPoint animated:(BOOL)animated;

/** Rotate the map in counter-clockwise direction based on the angle (degrees) specified.
 @param angle to rotate the map by
 @param mapPoint the location on the map around which the map should be rotated. The point
 should have the same spatial reference as the map.
 @param animated flag indicating if the map should animate to new rotation angle
 @agssince{2.1, 10.2}
 */
-(void)setRotationAngle:(double)angle aroundMapPoint:(AGSPoint*)mapPoint animated:(BOOL)animated;

/** Add a layer to the map using the specified name. The first layer added to 
 the map is treated as a <i>basemap</i> layer. It defines the full extent and 
 #spatialReference of the map.
 @param mapLayer Map Layer to be added to the map.
 @param name Name of layer. You can pass nil, in which case a name will be provided.
 If specified and the name is not unique, the layer will be given a uniqe name.
 @agssince{1.0, 10.2}
 */
- (void)addMapLayer:(AGSLayer *)mapLayer withName:(NSString *)name;

/** Remove a layer from the map with specified name. Even when the <i>basemap</i> 
 layer is removed, the map's #visibleArea , #maxEnvelope, and #spatialReference  
 properties remain unchanged. 
 @param name Name of the layer to be removed.
 @agssince{1.0, 10.2}
 */
- (void)removeMapLayerWithName: (NSString *)name;

/** Inserts a layer to the map with specified name at @p index.
 @param mapLayer Map Layer of type @c AGSLayer to be added to map.
 @param name Name of layer. You can pass nil, in which case a name will be provided.
 If specified and the name is not unique, the layer will be given a uniqe name.
 @param index Index where layer will be inserted.
 @agssince{1.0, 10.2}
 */
- (void)insertMapLayer:(AGSLayer *)mapLayer withName:(NSString *)name atIndex:(NSUInteger)index;

/** Adds a layer to the map. The layer is added on top of existing layers.
 @param lyr layer to add
 @agssince{10.1.1, 10.2}
 */
-(void)addMapLayer:(AGSLayer*)lyr;

/** Inserts a layer at the specified index
 @param lyr Layer to insert
 @param index at which to insert. 0 is bottom most.
 @agssince{10.1.1, 10.2}
 */
-(void)insertMapLayer:(AGSLayer*)lyr atIndex:(NSInteger)index;

/** Removes the given layer from the map
 @param lyr Layer to remove
 @agssince{10.1.1, 10.2}
 */
-(void)removeMapLayer:(AGSLayer*)lyr;

/** A convenience method to retrieve a layer in the map based on its name.
 @param name of layer to retrieve from the map
 @agssince{10.1.1, 10.2}
 */
-(AGSLayer*)mapLayerForName:(NSString*)name;

/**
 Attempts to enable wrap around on the map. Please check the wrapAroundStatus to see if
 the attempt was successful.
 @agssince{10.1.1, 10.2}
 */
-(void)enableWrapAround;

/**
 Disables wrap around on the map.
 @agssince{10.1.1, 10.2}
 */
-(void)disableWrapAround;

/**
 Returns the wrap around status of the map.
 @agssince{10.1.1, 10.2}
 */
-(AGSMapViewWrapAroundStatus)wrapAroundStatus;

#if (TARGET_OS_IPHONE)
/** If set to YES then all the hardware resources will be released when the application is backgrounded.
This will default to NO because it takes a few seconds to recreate these resources.
Based on this document http://developer.apple.com/library/ios/#documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/ImplementingaMultitasking-awareOpenGLESApplication/ImplementingaMultitasking-awareOpenGLESApplication.html
you should not set this to YES except under extreme cases.
@agssince{10.1.1, 10.2}
*/
@property (nonatomic, assign) BOOL releaseHardwareResourcesWhenBackgrounded;
#endif


#if (TARGET_OS_MAC && !TARGET_OS_IPHONE)

/** Specifies the copyright text to be displayed on the map.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) NSString *copyright;

/** Specifies the alignment of the copyright text.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) NSTextAlignment copyrightAlignment;

/** Specifies whether the logo is hidden or not.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL logoHidden;

/**
 Determines whether or not mouse movements are tracked.
 Because tracking mouse movements is potentially expensive you will need 
 to set this to YES if you want to respond to the AGSMapViewTouchDelegate method
 mapView:didMoveMouseToPoint:mapPoint:
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL trackMouseMovement;

#endif

@end



