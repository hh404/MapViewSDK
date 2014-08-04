//
//  AGSFeatureTableLayer.h
//  ArcGISRT
//
//  Created by Ryan Olson on 4/25/13.
//
//

@class AGSLayer;
@class AGSQuery;
@class AGSSymbol;
@class AGSFeatureTable;
@protocol AGSGDBFeatureSourceInfo;
@protocol AGSInfoTemplateDelegate;
@protocol AGSFeature;

/** @brief A layer that can display features from local datasets
 
 Instances of this class represent layers that can display features from a local dataset on a map.
 The local dataset is typically accessed through instances of @c AGSFeatureTable
 
 @see @c AGSFeatureTable to access the local dataset
 @define{AGSFeatureTableLayer.h, ArcGIS}
 @since 10.2
 @note This class is Beta at 10.2
 */
@interface AGSFeatureTableLayer : AGSLayer <AGSHitTestable>

/** Initialize the layer with the given @c AGSFeatureTable
 @param table The backing dataset whose features need to be drawn on the map by this layer.
 @agssince{10.2, 10.2}
 */
-(id)initWithFeatureTable:(AGSFeatureTable*)table;

/** The backing dataset whose features are drawn on the map by this layer.
 @agssince{10.2, 10.2}
*/
@property (nonatomic, strong, readonly) AGSFeatureTable *table;

/** Indicates whether features should be displayed with labels on the map.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readwrite) BOOL showLabels;

/** Property that determines if the layer allows it to be hit tested or if it is bypassed.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL allowHitTest;

/** Property that determines if the layer allows callouts to be shown for its features.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL allowCallout;

/** The symbol to use for drawing selected features
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSSymbol *selectionSymbol;

/** The color to use for drawing a halo around selected features
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) AGSColor *selectionColor;

/** Delegate that allows the layer to react to when a callout is shown for one of it's features.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, weak) id<AGSLayerCalloutDelegate> calloutDelegate;

/** Selects or un-selects the feature.
 Features with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the feature.
 @param selected If YES, feature will be selected. Else it will be un-selected
 @param feature
 @agssince{10.2, 10.2}
 */
-(void)setSelected:(BOOL)selected forFeature:(id<AGSFeature>)feature;

/** Returns whether a given feature is selected or not.
 Features with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the feature.
 @param feature
 @agssince{10.2, 10.2}
 */
-(BOOL)isFeatureSelected:(id<AGSFeature>)feature;

/** Clears selection on all features
 @agssince{10.2, 10.2}
 */
-(void)clearSelection;

/** An array of @c AGSGDBFeature objects representing features that have selection enabled
 Features with selection enabled will be drawn using #selectionSymbol.
 If #selectionSymbol is not specified, then #selectionColor will be used to draw a halo around the feature.
 @agssince{10.2, 10.2}
 */
-(NSArray*)selectedFeatures;
@end
