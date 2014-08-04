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

@class AGSTask;
@class AGSLocalTiledLayer;
@class AGSTileCacheServiceInfo;
@class AGSGenerateTileCacheParams;

/** Notification to indicate the task loaded @c AGSTileCacheTask#tiledServiceInfo
 @since 10.2
 */
AGS_EXTERN NSString *const AGSTileCacheTaskDidLoadNotification;

/** Notification to indicate the task failed to load @c AGSTileCacheTask#tiledServiceInfo
 @since 10.2
 */
AGS_EXTERN NSString *const AGSTileCacheTaskDidFailToLoadNotification;

/** @file AGSTileCacheTask.h */ //Required for Globals API doc

/** @brief A task to download a basemap tiles
 
 This class represents a task that can be used to download tiles (as a tile package) from
 supporting ArcGIS Map services. The service could be hosted on ArcGIS Online (Esri's cloud platform) or
 published on your own on-premise ArcGIS servers.
 
 @see @sample{e830608c5cba45309d7f1b1fe812848f, Download Tile Cache }
 @define{AGSTileCacheTask.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */

@interface AGSTileCacheTask : AGSTask

/** The interval at which status for jobs are checked.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) NSTimeInterval interval;

/** Information about the tile service such as scale visibility, tiling scheme, etc.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSTileCacheServiceInfo *tiledServiceInfo;

/** Whether or not the @c #tiledServiceInfo has been retrieved. You do not have to wait for this property to be
 YES before calling methods on the task. But it's helpful if you need to generate parameters based on the service information.
 @see @c #loadCompletion
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** The error, if any, while retrieving tiledServiceInfo.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) NSError *loadError;

/** The block that is executed when the task loads or fails to load the @c #featureServiceInfo.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

#if TARGET_OS_IPHONE

/** Whether or not the status and completion blocks are allowed to be called when the app is in the background.
 Otherwise the task will wait until the app is back in the foreground. Defaults to YES.
 Useful when you want to show a local notification if your task completes when the app is in
 the background.
 NOTE: If the app goes in the background while the job was polling there is no way to continue polling,
 so we won't start downloading results or finishing the job until the app comes back in the foreground.
 Situations where you can get called in the background are when the app gets backgrounded while results are
 being fetched, in which case if it finishes before 10 minutes, you can get a callback while the app is
 in the background.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL allowCallbackWhenAppInBackground;
#endif

/** Initialize the task with a URL and credential to a secured resource.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new task object.
 @agssince{1.0, 10.2}
 */
-(id)initWithURL:(NSURL *)url credential:(AGSCredential *)cred;

/**
 Retrieves the estimated size of the TPK file for the given parameters
 @param parameters The parameters used to create the estimate
 NOTE: The result is returned as an AGSTileCacheSizeEstimate in the status block.
 */
-(void)estimateSizeWithParameters:(AGSGenerateTileCacheParams *)params
                           status:(AGSTileCacheTaskStatusBlock)statusBlock;


/**
 All-in-one method to call to ask the server to create a tile cache with specified parameters
 and download it after it's created.
 If you have an existing tile cache that matches those parameters then it will use that one unless
 the useExisting parameter is NO.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param parameters The parameters with which the tile cache will be generated. This can be nil in which
 case it will download all the LODs in the service and at the full extent.
 @param downloadFolderPath The path to the folder that you want the tile cache downloaded to. This can be nil in
 which case a default folder (ie. documents directory) is chosen.
 @param useExisting Whether or not to use an existing tile cache which parameters match the one you are asking for.
 @agssince{10.2, 10.2}
 */
-(id<AGSCancellable>)generateTileCacheAndDownloadWithParameters:(AGSGenerateTileCacheParams*)parameters
                                                   downloadFolderPath:(NSString*)downloadFolderPath
                                                    useExisting:(BOOL)useExisting
                                                         status:(void(^)(AGSAsyncServerJobStatus status, NSDictionary *userInfo))statusBlock
                                                     completion:(void(^)(AGSLocalTiledLayer *localTiledLayer, NSError* error))completionBlock;

@end
