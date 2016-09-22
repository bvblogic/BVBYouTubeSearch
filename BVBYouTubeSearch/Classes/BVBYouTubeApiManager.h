//
//  BVBYouTubeApiManager.h
//  Pods
//
//  Created by Svyat Zubyak MacBook on 11.07.16.
//
//

#import <Foundation/Foundation.h>


@interface BVBYouTubeApiManager : NSObject

// singleton of API manager
+ (BVBYouTubeApiManager *)sharedInstance;

// Fetch data via URL request
-(void)fetchDataViaURL:(NSURL*)url completionHandler:(void (^)(id object, NSError *error))handler;
@end
