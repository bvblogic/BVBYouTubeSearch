//
//  BVBContent.m
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak MacBook on 16.08.16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import "BVBContent.h"

@implementation BVBContent
+(BVBContent*)createContentFormData:(NSDictionary*)data{
    BVBContent* c = [[BVBContent alloc]init];
    c.kind = data[@"id"][@"kind"];
    c.overview = data[@"snippet"][@"description"];
    c.title = data[@"snippet"][@"title"];
    c.thumbnailURL = data[@"snippet"][@"thumbnails"][@"default"][@"url"];
    c.publishedAt = data[@"snippet"][@"publishedAt"];
    if ([c.kind isEqualToString:@"youtube#video"]) {
        c.contentId = data[@"id"][@"videoId"];
    }
    return c;
}

@end
