//
//  BVBYouTubeService.m
//  Pods
//
//  Created by Svyat Zubyak on 9/22/16.
//
//

#import "BVBYouTubeService.h"

@implementation BVBYouTubeService

-(void)executeQuery:(BVBYouTubeQuery*)query completionHandler:(void (^)(id object, NSError *error))handler{
    
    NSURL* url = [self composeURLFromQuery:query];
    
    void (^requestHandler)(id object, NSError *error) = handler;
    
    [[BVBYouTubeApiManager sharedInstance] fetchDataViaURL:url completionHandler:requestHandler];
}

-(NSURL*)composeURLFromQuery:(BVBYouTubeQuery*)query{
    
    NSDictionary* queryDictionary = [self dictionaryWithPropertiesOfObject:query];
    
    NSURLComponents *components = [[NSURLComponents alloc] init];
    components.scheme = @"https";
    components.host = @"www.googleapis.com";
    components.path = [NSString stringWithFormat:@"/youtube/v3/%@",queryDictionary[@"methodName"]];
    components.queryItems = [self composeQueryItemsFromDictionary:queryDictionary];
    
    NSURL *url = components.URL;
    
    return url;
}

-(NSMutableArray*)composeQueryItemsFromDictionary:(NSDictionary*)query{
    
    NSMutableArray *queryItems = [[NSMutableArray alloc]init];
    for (NSString *key in query.allKeys) {
        if (![key isEqualToString:@"methodName"]) {
            NSURLQueryItem *queryItem = [NSURLQueryItem queryItemWithName:[NSString stringWithFormat:@"%@", key] value:[NSString stringWithFormat:@"%@", query[key]]];
            [queryItems addObject:queryItem];
        }
        
    }
    
    return queryItems;
}

-(NSDictionary *) dictionaryWithPropertiesOfObject:(id)obj{
    
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    
    unsigned count;
    objc_property_t *properties = class_copyPropertyList([obj class], &count);
    
    for (int i = 0; i < count; i++) {
        NSString *key = [NSString stringWithUTF8String:property_getName(properties[i])];
        if ([obj valueForKey:key]) {
            [dict setObject:[obj valueForKey:key] forKey:key];
        }
        
    }
    
    free(properties);
    
    return [NSDictionary dictionaryWithDictionary:dict];
}

-(NSString*)locationFormater:(CLLocation*)location{
    
    return [NSString stringWithFormat:@"%.8f,%.8f",location.coordinate.latitude,location.coordinate.longitude];
}

-(NSString*)dateFormater:(NSDate*)date{
    
    NSDateFormatter *rfc3339DateFormatter = [[NSDateFormatter alloc] init];
    [rfc3339DateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss'Z'"];
    NSString* formatedDate = [rfc3339DateFormatter stringFromDate:date];
    return formatedDate;
}

@end
