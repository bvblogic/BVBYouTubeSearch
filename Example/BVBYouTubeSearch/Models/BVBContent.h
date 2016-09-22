//
//  BVBContent.h
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak MacBook on 16.08.16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BVBContent : NSObject
@property (nonatomic, strong) NSString * kind;
@property (nonatomic, strong) NSString * contentId;
@property (nonatomic, strong) NSString * overview;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * publishedAt;
@property (nonatomic, strong) NSString * thumbnailURL;
+(BVBContent*)createContentFormData:(NSDictionary*)data;
@end
