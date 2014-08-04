/*
 COPYRIGHT 2010 ESRI
 
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

@class AGSCredential;
@protocol AGSSecuredResource;

/** @file AGSTask.h */ //Required for Globals API doc

/** @brief Base class for all ArcGIS task objects
 
 Base class to hold common objects among ArcGIS tasks. You should never
 instantiate an <code>%AGSTask</code> object directly.
 
 @see @concept{tasks-overview.htm, Overview of Tasks}
 @agssince{1.0, 10.2}
 */
@interface AGSTask : NSObject <AGSSecuredResource>

/** URL to a task resource in the ArcGIS Server REST Services Directory.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** The credential to be used to access secured resources.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The cache policy that should be used for making the web request.
 Default value is NSURLRequestUseProtocolCachePolicy
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) NSURLRequestCachePolicy requestCachePolicy;

/** The timeout interval (in seconds) for this request. Default value is 60.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign, readwrite) NSTimeInterval timeoutInterval;

/** Initialize the task.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @return A new task object.
 @agssince{1.0, 10.2}
 */
- (id)initWithURL:(NSURL *)url;

/** Initialize the task with a URL and credential to a secured resource.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new task object.
 @agssince{1.0, 10.2}
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

@end
