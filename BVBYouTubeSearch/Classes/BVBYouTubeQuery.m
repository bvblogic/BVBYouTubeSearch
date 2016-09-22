//
//  BVBYoutubeQuery.m
//  Pods
//
//  Created by Svyat Zubyak MacBook on 13.07.16.
//
//

#import "BVBYouTubeQuery.h"
@interface BVBYouTubeQuery ()

@property (strong, nonatomic, readwrite) NSString *methodName;

@end

@implementation BVBYouTubeQuery

+ (instancetype)queryForSearchWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypeSearch;
     BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryForChannelDetailsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypeChannels;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartContentDetailsSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;

}

+ (instancetype)queryForPlaylistItemsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypePlaylistItems;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryForPlaylistsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypePlaylists;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryForVideoDetailsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypeVideos;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryForCommentThreadsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypeCommentThreads;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryForCommentsWithAPIKey:(NSString *)apiKey{
    NSString *methodName = kBVBYouTubeTypeComments;
    BVBYouTubeQuery *query = [self queryWithMethodName:methodName];
    NSString * part = kBVBYouTubePartSnippet;
    query.part = part;
    query.key = apiKey;
    query.maxResults = 5;
    return query;
}

+ (instancetype)queryWithMethodName:(NSString *)methodName{
    return [[self alloc] initWithMethodName:methodName];
}

- (instancetype)initWithMethodName:(NSString *)methodName{
    self = [super init];
    if (self) {
        
        self.methodName = [methodName copy];
       
        if ([self.methodName length] == 0) {
            self = nil;
        }
    }
    return self;
}

- (void)setMaxResults:(NSInteger)maxResults{

    if (maxResults < 0 || maxResults > 50) {
        NSLog(@"Acceptable maxResult values are 0 to 50, inclusive. The default value is 5.");
    }
    _maxResults = maxResults;
}

-(void)setLocation:(NSString *)location{
    
    if (!_locationRadius) {
        NSLog(@"You specifie a value for the location parameter. Dont forget to specify a value for the locationRadius parameter.");
    }
    _location = location;
}

-(void)setLocationRadius:(NSString *)locationRadius{
    if (!_location) {
    NSLog(@"You specifie a value for the locationRadius parameter. Dont forget to specify a value for the location parameter.");
    }
    _locationRadius = locationRadius;
}

- (void)dealloc {
    _methodName = nil;
    _key = nil;
    _q = nil;
    _pageToken = nil;
    _regionCode = nil;
    _relevanceLanguage = nil;
    _locationRadius = nil;
    _location = nil;
    _type = nil;
    _channelType = nil;
    _order = nil;
    _eventType = nil;
    _safeSearch = nil;
    _videoCaption = nil;
    _videoDimension = nil;
    _videoDuration = nil;
    _videoLicense = nil;
    _videoType = nil;
    _videoDefinition = nil;
    _publishedAfter = nil;
    _publishedBefore = nil;
    _id = nil;
    _categoryId = nil;
    _forUsername = nil;
    _h1 = nil;
    _playlistId = nil;
    _videoId = nil;
    _channelId= nil;
    _chart = nil;
    _videoCategoryId= nil;
}

@end
