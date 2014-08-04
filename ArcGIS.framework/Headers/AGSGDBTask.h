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
@class AGSGeometry;
@class AGSGDBGenerateParameters;
@class AGSFeatureServiceInfo;
@class AGSGDBGeodatabase;
@class AGSGDBSyncParameters;
@class AGSGDBTaskStatusInfo;
@protocol AGSCancellable;

/** Notification to indicate the task loaded @c AGSGDBTask#featureServiceInfo
 @since 10.2
 */
AGS_EXTERN NSString *const AGSGDBTaskDidLoadNotification;

/** Notification to indicate the task failed to load @c AGSGDBTask#featureServiceInfo
 @since 10.2
 */
AGS_EXTERN NSString *const AGSGDBTaskDidFailToLoadNotification;

/** @file AGSGDBTask.h */ //Required for Globals API doc

/** @brief A task to download a replica geodatabase
 
 This class represents a task that can be used to create and download a replica geodatabase from
 a sync-enabled ArcGIS Feature service. The service could be hosted on ArcGIS Online (Esri's cloud platform) or
 published on your own on-premise ArcGIS servers.
 
 @see @concept{create-an-offline-map.htm, Create an offline map}
 @see @concept{sync-offline-edits.htm, Sync offline edits}
 @see @sample{a90b40f537e84e3aa1c36b10bd2c7c4d, Offline Feature Editing}
 @define{AGSGDBTask.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBTask : AGSTask

/** The interval at which status for jobs are checked.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) NSTimeInterval interval;

/** Whether or not the featureServiceInfo has been retrieved. You do not have to wait for this property to be 
 YES before calling methods on the task.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** The service information for the URL that this task was instantiated with.
 This is nil until that task has completed loading.
 @see @c #loaded
 @see @c #loadCompletion
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong) AGSFeatureServiceInfo *featureServiceInfo;

/** The block that is executed when the task loads or fails to load the @c #featureServiceInfo.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

/** The error, if any, that occurred when trying to load the task.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) NSError *loadError;

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

/** Register the local geodatabase as a new replica on the service. The geodatabase can then sync changes with the service indepedently of any other copies of the geodatabase that may exist.
 @param geoadatabase to register
 @param completion The block that will be invoked when the operation completes.
 @return A handle to the operation incase you want to cancel it
 @since 10.2
 */
-(id<AGSCancellable>)registerSyncEnabledGeodatabase:(AGSGDBGeodatabase*)geodatabase completion:(void (^)(NSError *error))completion;

/** Unregister a local replica geodatabase from the service. The replica will not be able to sync with the service hereafter.
 The local geodatabase will be left behind, but all information about the replica on the service will be removed.
 @param geodatabase to unregister
 @param completion The block that will be invoked when the operation completes.
 @return A handle to the operation incase you want to cancel it
 @since 10.2
 */
-(id<AGSCancellable>)unregisterSyncEnabledGeodatabase:(AGSGDBGeodatabase*)geodatabase completion:(void (^)(NSError *error))completion;


#pragma mark -
#pragma mark All-in-one methods

/**
 All-in-one method to call to ask the server to create a geodatabase with specified parameters
 and download it after it's created.
 If you have an existing geodatabase that matches those parameters then it will use that one unless
 the useExisting parameter is NO.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param parameters The parameters with which the geodatabase will be generated. This can be nil in which 
 case it will download all the layers and tables and at the full extent. However if it is initialized, its extent and layerIDs must be set.
 @param downloadFolderPath The path to the folder that you want the geodatabase downloaded to. This can be nil in
 which case a default folder (ie. documents directory) is chosen.
 @param useExisting Whether or not to use an existing geodatabase which parameters match the one you are asking for.
 @agssince{10.2, 10.2}
 */
-(id<AGSCancellable>)generateGeodatabaseAndDownloadWithParameters:(AGSGDBGenerateParameters*)parameters
                                                     downloadFolderPath:(NSString*)downloadFolderPath
                                                      useExisting:(BOOL)useExisting
                                                           status:(void(^)(AGSAsyncServerJobStatus status, NSDictionary *userInfo))statusBlock
                                                       completion:(void(^)(AGSGDBGeodatabase *geodatabase, NSError* error))completionBlock;

/**
 All-in-one method to upload changes, apply them to the server, and download server changes.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param geodatabase to synchronize with the service
 @param params describing which changes should be sync'ed in which direction
 @param statusBlock is called at every @c #interval with the status of the operation and any related info
 @param completionBlock is called when the operation completes.
 @agssince{10.2, 10.2}
 */
-(id<AGSCancellable>)syncGeodatabase:(AGSGDBGeodatabase*)geodatabase
                              params:(AGSGDBSyncParameters*)params
                              status:(void(^)(AGSAsyncServerJobStatus status, NSDictionary *userInfo))statusBlock
                          completion:(void(^)(NSError* error))completionBlock;

@end

/** @brief A category with debugging options for @c AGSGDBTask
 
 Debugging options when sync operations on @c AGSGDBTask fail mysteriously.
 
 @define{AGSGDBTask.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
*/

@interface AGSGDBTask (DebugSync)

//
// TODO: synchronize in/out deltas names with server terminology
/** Delta files will be created here named with <epoch time>.geodatabase
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *deltaDirectory;

/** Defaults to @c YES.
 Set this to @c NO to leave the deltas on the device for debugging.
 @since 10.2
 */
@property (nonatomic, assign) BOOL deleteDeltas;

@end

