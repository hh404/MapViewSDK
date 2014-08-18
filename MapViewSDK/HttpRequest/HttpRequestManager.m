//
//  HttpRequestManager.m
//  MapViewSDK
//
//  Created by huangjianwu on 14-8-16.
//  Copyright (c) 2014年 zhangke. All rights reserved.
//

#import "HttpRequestManager.h"


@implementation HttpRequestManager

static HttpRequestManager *gHttpRequestManager = nil;

+ (instancetype)shareInstance
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        gHttpRequestManager = [[HttpRequestManager alloc] init];
    });
    return gHttpRequestManager;
}

- (BOOL)isReachable{
    return [[AFNetworkReachabilityManager sharedManager] isReachable];
}

- (void)httpSearchWithKeywords:(NSString*)aKeywords
                    searchtype: (NSString*)aSearchtype
                       dataset:(NSString*)aDataset
                          type:(NSString*)aType
                          page:(NSNumber*)apage
                          size:(NSNumber*)asize;
{
    
}

@end
