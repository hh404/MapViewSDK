//
//  HttpRequestManager.h
//  MapViewSDK
//
//  Created by huangjianwu on 14-8-16.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HttpRequestManager : NSObject

+ (instancetype)shareInstance;

- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                       dataset:(NSString*)aDataset
                          type:(NSString*)aType
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;


- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                     admincode:(NSString*)aAdmincode
                       dataset:(NSString*)aDataset
                          type:(NSString*)aType
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;


- (void)httpSearchWithKeywords:(NSString*)aKeywords
                      searchtype: (NSString*)aSearchtype
                        Circle:(NSString*)aCircle
                         dataset:(NSString*)aDataset
                            type:(NSString*)aType
                            page:(NSNumber*)apage
                            size:(NSNumber*)asize;


- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                        bbox:(NSString*)aBbox
                       dataset:(NSString*)aDataset
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;

- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                          bbox:(NSString*)aBbox
                       dataset:(NSString*)aDataset
                          type:(NSString*)aType
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;


- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                      geometry:(NSString*)aGeometry
                       dataset:(NSString*)aDataset
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;

- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                      geometry:(NSString*)aGeometry
                       dataset:(NSString*)aDataset
                          type:(NSString*)aType
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;

@end
