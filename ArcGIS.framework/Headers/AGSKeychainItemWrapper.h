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


/** @brief A convenience class to store and retrieve objects in the keychain.
 
 This class represents a generic keychain wrapper to store an object (or part of it) securely in the keychain.
 The object must implement @c NSCoding. For example, you can store an @c AGSCredential representing a user's identity 
 and retrieve it when the app is restarted so that the user does not have to log in again.
 
 @define{AGSKeychainItemWrapper, ArcGIS}
 @since 10.2
 */
@interface AGSKeychainItemWrapper : NSObject

/** Initialize the wrapper 
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup
 @since 10.2
*/
- (id)initWithIdentifier: (NSString *)identifier accessGroup:(NSString *) accessGroup;

/** Set an archivable object as the @c kSecValueData in the keychain item
 @since 10.2
 */
- (void)setKeychainObject:(id<NSCoding>)obj;

/** Retrieve the archivable object from the kSecValueData in the keychain item
 @since 10.2
 */
- (id<NSCoding>)keychainObject;

/** Initializes and resets the default generic keychain item data.
 @since 10.2
 */
- (void)reset;

@end
