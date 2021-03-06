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

@class AGSCredential;

/** @file AGSRequest.h */ //Required for Globals API doc

/** @brief Wrapper class request for synchronous requests to URLs
 
 This class provides some simple methods for requesting data from a URL
 synchronously. 
 
 @agssince{1.0, 10.2}
 */
@interface AGSRequest : NSObject

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p post is set to <code>YES</code> the method used will be AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @agssince{1.0, 10.2}
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p post is set to <code>YES</code> the method used will be AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or <code>POST</code>
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @agssince{10.1.1, 10.2}
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)queryParams doPOST:(BOOL)post cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p httpMethod is specified as AGSRequestHTTPMethodGet and the length of the URL + query causes a POST or
 [AGSRequest setForcePostForAllRequests] has been set to <code>YES</code>, then the httpMethod will switch to AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param method The method by which the request will be made.
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @agssince{10.2, 10.2}
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url
                     credential:(AGSCredential*)cred
                       resource:(NSString *)operation
                queryParameters:(NSDictionary *)queryParams
                         method:(AGSRequestHTTPMethod)httpMethod
                    cachePolicy:(NSURLRequestCachePolicy)cachePolicy
                timeoutInterval:(NSTimeInterval)timeoutInterval;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p httpMethod is specified as AGSRequestHTTPMethodGet and the length of the URL + query causes a POST or
 [AGSRequest setForcePostForAllRequests] has been set to <code>YES</code>, then the httpMethod will switch to AGSRequestHTTPMethodPostFormEncodeParameters. 
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param httpMethod The method by which the request will be made.
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @param userHeaders Any custom headers you would like to set on the request with the exception of User-Agent, Referer, and Content-Type. If you need to add info to the User-Agent header use  @c #setAdditionalUserAgentInfo: .
 @agssince{10.2, 10.2}
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url
                     credential:(AGSCredential *)cred
                       resource:(NSString *)operation
                queryParameters:(NSDictionary *)queryParams
                         method:(AGSRequestHTTPMethod)httpMethod
                    cachePolicy:(NSURLRequestCachePolicy)cachePolicy
                timeoutInterval:(NSTimeInterval)timeoutInterval
                    userHeaders:(NSDictionary *)userHeaders;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information about the request if it fails
 @agssince{1.0, 10.2}
 */
+ (NSData *)dataForURL:(NSURL *)url resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param cred <code>AGSCredential</code> to access the secured resource
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information passed back if the request fails
 @agssince{1.0, 10.2}
 */
+ (NSData *)dataForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously for the specified request.
 @param request object containing url and query parameters
 @param error Information passed back if the request fails
 @agssince{1.0, 10.2}
 */
+ (NSData *)dataForRequest:(NSURLRequest *)request error:(NSError**)error;

/** Used to set some specific user agent information. This is useful for 
 analytics.
 @param additionalInfo to send along in the user agent string
 @agssince{1.0, 10.2}
 */
+ (void) setAdditionalUserAgentInfo:(NSString*)additionalInfo;

/** Class method to retrieve the user agent string
 @agssince{1.0, 10.2}
 */
+ (NSString*)userAgent;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @agssince{2.2, 10.2}
 */
+(BOOL)forcePostForAllRequests;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @agssince{2.2, 10.2}
 */
+(void)setForcePostForAllRequests:(BOOL)forcePost;

@end
