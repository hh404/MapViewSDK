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

@protocol AGSPopupsContainer;

@class AGSPopup;

/** @file AGSPopupsContainerDelegate.h */ //Required for Globals API doc

/** @brief A delegate of @c AGSPopupsContainerViewController
 
  A protocol that must be adopted by any class wishing to be notified when @c AGSPopupsContainerViewController detects user interaction with popups or if a user tries to edit a popup. An instance of the class must then be set as @c AGSPopupsContainerViewController#delegate .
 
 All methods of this protocol are optional.
 @agssince{2.0, 10.2}
 */
@protocol AGSPopupsContainerDelegate <NSObject>
@optional

/** Tells the delegate that a new mutable geometry is required for a graphic that currently has no geometry.
 Must return a mutable geometry.
 @param popupsContainer The popup view controller
 @param popup Popup for who's graphic we need a geometry for.
 @agssince{2.0, 10.2}
 */
-(AGSGeometry*)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsNewMutableGeometryForPopup:(AGSPopup*)popup;

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for 
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins.
 @param popupsContainer The popup view controller
 @param geometry If you are using an @c AGSSketchGraphicsLayer, this will be the same geometry that
 you give the AGSSketchGraphicsLayer.
 @param popup whose graphic's geometry needs to be edited
 @deprecated Deprecated at 10.2. Please use @c AGSPopupsContainerDelegate#popupsContainer:readyToEditGeometry:forPopup: instead.
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer readyToEditGraphicGeometry:(AGSGeometry*)geometry forPopup:(AGSPopup*)popup __attribute__((deprecated));

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins.
 @param popupsContainer The popup view controller
 @param geometry If you are using an @c AGSSketchGraphicsLayer, this will be the same geometry that
 you give the AGSSketchGraphicsLayer.
 @param popup whose feature's geometry needs to be edited
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer readyToEditGeometry:(AGSGeometry*)geometry forPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user begins editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be edited
 @deprecated Deprecated at 10.2. Please use @c AGSPopupsContainerDelegate#popupsContainer:didStartEditingForPopup: instead.
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didStartEditingGraphicForPopup:(AGSPopup*)popup __attribute((deprecated));

/** The method called by the AGSPopupsContainer when the user begins editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose feature needs to be edited
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didStartEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user is done editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was edited
 @deprecated Deprecated at 10.2. Please use @c AGSPopupsContainerDelegate#popupsContainer:didFinishEditingForPopup: instead.
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFinishEditingGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user is done editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose feature was edited
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFinishEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user cancels editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was started to be edited but later cancelled
 @deprecated Deprecated at 10.2. Please use @c AGSPopupsContainerDelegate#popupsContainer:didCancelEditingForPopup: instead.
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didCancelEditingGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user cancels editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose feature was started to be edited but later cancelled
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didCancelEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user presses the delete button.
 The implementer of this method must actually delete the graphic.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be deleted
 @deprecated Deprecated at 10.2. Please use @c AGSPopupsContainerDelegate#popupsContainer:wantsToDeleteForPopup: instead.
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToDeleteGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user presses the delete button.
 The implementer of this method must actually delete the feature.
 @param popupsContainer The popup view controller
 @param popup whose feature needs to be deleted
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToDeleteForPopup:(AGSPopup*)popup;

/** The method that is called when the user is done viewing the popups.
 @param popupsContainer The popup view controller
 @agssince{2.0, 10.2}
 */
-(void)popupsContainerDidFinishViewingPopups:(id<AGSPopupsContainer>)popupsContainer;

#if TARGET_OS_IPHONE

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be presented.
 This method is optional, but if you want to show view controllers in different ways than the standard modal way,
 then you need to implement this method.
 @param popupsContainer The popup view controller
 @param svc The view controller that needs to be displayed
 @param viewType The predefined type of the view controller
 @param fvc The view controller that is currently being displayed
 @param rect The rect is in the coordinate space of the fromViewController. Only applicable if viewType is @c AGSPopupViewTypeUIImagePicker
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToShowViewController:(AGSViewController *)svc ofType:(AGSPopupViewType)viewType fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be hidden.
 You need to implement this if you implement popupsContainer:wantsToShowViewController:fromViewController:atRect,
 so that you can hide a view controller in the proper way if you've shown it in a custom manner.
 @param popupsContainer The popup view controller
 @param vc The view controller that needs to be hidden
 @param viewType the predefined type of the view controller
 
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToHideViewController:(AGSViewController*)vc ofType:(AGSPopupViewType)viewType;

/** The AGSPopupsContainer will call this delegate method when it one of it's view controllers
 needs to know if it can auto-rotate to an certain interface orientation. If you don't implement this
 method then we just always return YES.
 @param popupsContainer The popup view controller
 @param interfaceOrientation The orientation to change to
 @param vc The view controller that needs to respond to orientation change
 @param viewType the predefined type of the view controller  
 @agssince{2.0, 10.2}
 */
-(BOOL)popupsContainer:(id<AGSPopupsContainer>)popupsContainer shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation forViewController:(UIViewController*)vc ofType:(AGSPopupViewType)viewType;

#endif

/** The AGSPopupsContainer will call this method when the currently showing popup changes.
 @param popupsContainer The popup view controller
 @param popup which is currently being displayed
 @agssince{2.0, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeToCurrentPopup:(AGSPopup*)popup;

/** The AGSPopupsContainer will call this method when there is a document that it wants to preview. 
 By default, if this method is not implemented, it will preview the document with a UIDocumentInteractionController. 
 If you have need to hide or show popovers before previewing you should implement this method and 
 create the UIDocumentInteractionController manually.
 @agssince{2.3, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToPreviewDocumentAtURL:(NSURL*)documentURL fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this when the user switches a feature type for the current popup.
 Potentially at this point symbology will change for the feature.
 @agssince{10.1.1, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeFeatureTypeForPopup:(AGSPopup *)popup;

#if TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** The AGSPopupsContainer will call this when the user opens a window containing an attachment or media object.
 If this method is not implemented, the window will close when the popup is removed from the container.
 @agssince{10.2, 10.2}
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didShowWindow:(NSWindow *)window forPopup:(AGSPopup *)popup;

#endif

@end

