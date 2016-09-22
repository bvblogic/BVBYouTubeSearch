//
//  BVBYouTubeService.h
//  Pods
//
//  Created by Svyat Zubyak on 9/22/16.
//
//

#import <Foundation/Foundation.h>
#import "BVBYouTubeQuery.h"
#import "BVBYouTubeApiManager.h"
#import <CoreLocation/CoreLocation.h>
#import <objc/runtime.h>

@interface BVBYouTubeService : NSObject

// Easy change from CLLocation to parameter value that specifies latitude/longitude coordinates e.g. (37.42307,-122.08427)
-(NSString*)locationFormater:(CLLocation*)location;

// Easy change from NSdate to an RFC 3339 formatted date-time value (1970-01-01T00:00:00Z)
-(NSString*)dateFormater:(NSDate*)date;


// Clients should create a standard query with any of the class methods in
// BVBYouTubeQuery.h. The query can the be sent with BVBYouTubeService's execute
// method
-(void)executeQuery:(BVBYouTubeQuery*)query completionHandler:(void (^)(id object, NSError *error))handler;
// If an error occurs, the error parameter will be non-nil.  Otherwise,
// the object parameter will point to a NSDictionary, if any was returned by
// the fetch.

@end
