//
//  BVBYouTubeApiManager.m
//  Pods
//
//  Created by Svyat Zubyak MacBook on 11.07.16.
//
//

#import "BVBYouTubeApiManager.h"

@implementation BVBYouTubeApiManager

#pragma mark - init singletone

+ (BVBYouTubeApiManager *)sharedInstance {
  static BVBYouTubeApiManager *sharedInstance = nil;
  static dispatch_once_t oncePredicate;
  dispatch_once(&oncePredicate, ^{
    sharedInstance = [[self alloc] init];
  });

  return sharedInstance;
}

- (void)fetchDataViaURL:(NSURL *)url
      completionHandler:(void (^)(id object, NSError *error))handler {
    
  void (^requestHandler)(id object, NSError *error) = handler;

  NSURLSessionDataTask *downloadTask = [[NSURLSession sharedSession]
        dataTaskWithURL:url
      completionHandler:^(NSData *data, NSURLResponse *response,
                          NSError *error) {
       
        NSError *errorJson;
        NSDictionary *json;
          
        if (!error) {

          json = [NSJSONSerialization JSONObjectWithData:data
                                                 options:kNilOptions
                                                   error:&errorJson];
        }

        if (requestHandler) {
          requestHandler(json, error);
        }

      }];

  [downloadTask resume];
}

@end
