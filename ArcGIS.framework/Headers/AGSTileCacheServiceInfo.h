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
@class AGSSpatialReference;
@class AGSEnvelope;
@class AGSTileInfo;
@class AGSMapServiceDocumentInfo;

/** @file AGSTileCacheServiceInfo.h */ //Required for Globals API doc

/** @brief Information about a tiled ArcGIS Map service.
 
 This class holds information about a tiled ArcGIS Map service.
 
 @define{AGSTileCacheServiceInfo.h, ArcGIS}
 @since 10.2
 */
@interface AGSTileCacheServiceInfo : NSObject <AGSCoding>

/** Copyright information of the service.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *copyrightText;

/** Information about the backing map document used to create the service.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSMapServiceDocumentInfo *documentInfo;

/** Indicates whether the service allows tiles to be exported and downloaded for
 offline use
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL exportTilesAllowed;

/** The default extent of geographic data available in the service
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The default extent of geographic data available in the service
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *initialExtent;

/** Available layers in the service and their default visibility as an array of
 @c AGSMapServiceLayerInfo objects.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *layerInfos;

/** The maximum number of tiles that will be exported in a tile cache by the service.
 Only applicable if @c #exportTilesAllowed is YES.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger maxExportTilesCount;

/** The maximum height of a map image that can be generated by the service.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger maxImageHeight;

/** The maximum width of a map image that can be generated by the service.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger maxImageWidth;

/** The maximum number of features that will be returned by the service for
 any query operation. Applications should handle re-querying the omitted results when
 this limit is reached.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger maxRecordCount;

/** The maximum scale at which this layer is visible. If the map is zoomed in
 beyond this scale, the layer will not be visible.
@since 10.2
 */
@property (nonatomic, assign, readonly) CGFloat maxScale;

/** The minimum scale at which this layer is visible. If the map is zoomed out
 beyond this scale, the layer will not be visible.
@since 10.2
 */
@property (nonatomic, assign, readonly) CGFloat minScale;

/** User-friendly description about the service.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** Indicates whether the service contains a tile cache.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL singleFusedMapCache;

/** The spatial reference used by the service.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Indicates whether the service supports layers to be dynamically added, removed, reordered, or reconfigured.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL supportsDynamicLayers;

/** Available stand-alone tables in the service as an array of
 @c AGSMapServiceTableInfo objects. Stand-alone tables are just like layers
 except they don't have a geometry column.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *tableInfos;

/** Tiling scheme used by the service. Only available if @c singleFusedMapCache is YES.
@since 10.2
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/** The units of measurement for geographic data available in the service
 @since 10.2
 */
@property (nonatomic, assign, readonly) AGSUnits units;

/*
 {
 "currentVersion": 10.2,
 "serviceDescription": "",
 "mapName": "Layers",
 "description": "",
 "copyrightText": "",
 "supportsDynamicLayers": false,
 "layers": [
 {
 "id": 0,
 "name": "States",
 "parentLayerId": -1,
 "defaultVisibility": true,
 "subLayerIds": null,
 "minScale": 0,
 "maxScale": 0
 }
 ],
 "tables": [],
 "spatialReference": {
 "wkid": 102100,
 "latestWkid": 3857
 },
 "singleFusedMapCache": true,
 "tileInfo": {
 "rows": 256,
 "cols": 256,
 "dpi": 96,
 "format": "PNG",
 "compressionQuality": 0,
 "origin": {
 "x": -2.0037508342787E7,
 "y": 2.0037508342787E7
 },
 "spatialReference": {
 "wkid": 102100,
 "latestWkid": 3857
 },
 "lods": [
 {
 "level": 0,
 "resolution": 156543.03392800014,
 "scale": 5.91657527591555E8
 },
 {
 "level": 1,
 "resolution": 78271.51696399994,
 "scale": 2.95828763795777E8
 },
 {
 "level": 2,
 "resolution": 39135.75848200009,
 "scale": 1.47914381897889E8
 },
 {
 "level": 3,
 "resolution": 19567.87924099992,
 "scale": 7.3957190948944E7
 },
 {
 "level": 4,
 "resolution": 9783.93962049996,
 "scale": 3.6978595474472E7
 },
 {
 "level": 5,
 "resolution": 4891.96981024998,
 "scale": 1.8489297737236E7
 },
 {
 "level": 6,
 "resolution": 2445.98490512499,
 "scale": 9244648.868618
 },
 {
 "level": 7,
 "resolution": 1222.992452562495,
 "scale": 4622324.434309
 },
 {
 "level": 8,
 "resolution": 611.4962262813797,
 "scale": 2311162.217155
 },
 {
 "level": 9,
 "resolution": 305.74811314055756,
 "scale": 1155581.108577
 },
 {
 "level": 10,
 "resolution": 152.87405657041106,
 "scale": 577790.554289
 },
 {
 "level": 11,
 "resolution": 76.43702828507324,
 "scale": 288895.277144
 },
 {
 "level": 12,
 "resolution": 38.21851414253662,
 "scale": 144447.638572
 },
 {
 "level": 13,
 "resolution": 19.10925707126831,
 "scale": 72223.819286
 },
 {
 "level": 14,
 "resolution": 9.554628535634155,
 "scale": 36111.909643
 },
 {
 "level": 15,
 "resolution": 4.77731426794937,
 "scale": 18055.954822
 },
 {
 "level": 16,
 "resolution": 2.388657133974685,
 "scale": 9027.977411
 },
 {
 "level": 17,
 "resolution": 1.1943285668550503,
 "scale": 4513.988705
 },
 {
 "level": 18,
 "resolution": 0.5971642835598172,
 "scale": 2256.994353
 },
 {
 "level": 19,
 "resolution": 0.29858214164761665,
 "scale": 1128.497176
 }
 ]
 },
 "initialExtent": {
 "xmin": -2.0037507067161843E7,
 "ymin": -327870.61711598845,
 "xmax": 2.0037507067161843E7,
 "ymax": 3.0240971958386205E7,
 "spatialReference": {
 "wkid": 102100,
 "latestWkid": 3857
 }
 },
 "fullExtent": {
 "xmin": -1.9838806041208178E7,
 "ymin": 2146082.1891816254,
 "xmax": -7455049.44832817,
 "ymax": 1.1542768518263144E7,
 "spatialReference": {
 "wkid": 102100,
 "latestWkid": 3857
 }
 },
 "minScale": 5.91657527591555E8,
 "maxScale": 288895.277144,
 "units": "esriMeters",
 "supportedImageFormatTypes": "PNG32,PNG24,PNG,JPG,DIB,TIFF,EMF,PS,PDF,GIF,SVG,SVGZ,BMP",
 "documentInfo": {
 "Title": "",
 "Author": "",
 "Comments": "",
 "Subject": "",
 "Category": "",
 "AntialiasingMode": "None",
 "TextAntialiasingMode": "Force",
 "Keywords": ""
 },
 "capabilities": "Map,Query,Data",
 "supportedQueryFormats": "JSON, AMF",
 "exportTilesAllowed": true,
 "maxExportTilesCount": 100000,
 "maxRecordCount": 1000,
 "maxImageHeight": 4096,
 "maxImageWidth": 4096
 }
 */
@end
