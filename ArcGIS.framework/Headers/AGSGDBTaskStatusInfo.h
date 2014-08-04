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

@protocol AGSCoding;

/** @file AGSGDBTaskStatusInfo.h */ //Required for Globals API doc

/** @brief Status information operations related to geodatabase replicas
 
 This class holds information pertaining to operations such as downloading or syncing a geodatabase replica.
 
 @define{AGSGDBTaskStatusInfo.h, ArcGIS}
 @agssince{10.2, 10.2}
 @note This class is Beta at 10.2.
 */
@interface AGSGDBTaskStatusInfo : NSObject<AGSCoding>

/** The id of the job in which this status object corresponds to.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *jobID;

/** The date this geodatabase was last updated.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) NSDate *lastUpdatedTime;

/** The name of the geodatabase corresponding to this status object.
 This name will report the <code>prefixName</code> specified in the @c AGSGDBGenerateParameters
 until the geodatabase creation has been completed, at which point, the name may change if a 
 geodatabase with that name already exists on the server.
 For example: prefixName="my_geodatabase" and upon completion, if "my_geodatabase" already existed, 
 it may return "my_geodatabase_0001"
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *geodatabaseName;

/** The URL in which the results (changes or error information) from the server can be downloaded from.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) NSURL *resultURL;

/** The status of this particular job.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign, readonly) AGSGDBTaskJobStatus status;

/** The date in which this job was submitted to the server.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) NSDate *submissionTime;

@end
