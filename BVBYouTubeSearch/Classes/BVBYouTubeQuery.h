//
//  BVBYouTubeQuery.h
//  Pods
//
//  Created by Svyat Zubyak MacBook on 13.07.16.
//
//

#import <Foundation/Foundation.h>
#import "BVBYouTubeConstants.h"
@interface BVBYouTubeQuery : NSObject

// The rpc method name.
@property (strong, nonatomic, readonly) NSString *methodName;
@property (strong, nonatomic) NSString *key;
@property (strong, nonatomic) NSString *part;
@property (strong, nonatomic) NSString *q;
@property (strong, nonatomic) NSString *pageToken;
@property (strong, nonatomic) NSString *regionCode;
@property (strong, nonatomic) NSString *relevanceLanguage;
@property (strong, nonatomic) NSString *locationRadius;
@property (strong, nonatomic) NSString *location;
@property (nonatomic) NSInteger maxResults;
@property (strong, nonatomic) NSString* type;
@property (strong, nonatomic) NSString* channelType;
@property (strong, nonatomic) NSString* order;
@property (strong, nonatomic) NSString* eventType;
@property (strong, nonatomic) NSString* safeSearch;
@property (strong, nonatomic) NSString* videoCaption;
@property (strong, nonatomic) NSString* videoDimension;
@property (strong, nonatomic) NSString* videoDuration;
@property (strong, nonatomic) NSString* videoLicense;
@property (strong, nonatomic) NSString* videoType;
@property (strong, nonatomic) NSString* videoDefinition;
@property (strong, nonatomic) NSString* publishedAfter;
@property (strong, nonatomic) NSString* publishedBefore;
@property (strong, nonatomic) NSString* id;
@property (strong, nonatomic) NSString* categoryId;
@property (strong, nonatomic) NSString* forUsername;
@property (strong, nonatomic) NSString* h1;
@property (strong, nonatomic) NSString* playlistId;
@property (strong, nonatomic) NSString* channelId;
@property (strong, nonatomic) NSString* videoId;
@property (strong, nonatomic) NSString* chart;
@property (strong, nonatomic) NSString* videoCategoryId;
@property (strong, nonatomic) NSString* allThreadsRelatedToChannelId;
@property (strong, nonatomic) NSString* searchTerms;
@property (strong, nonatomic) NSString* textFormat;
@property (strong, nonatomic) NSString* parentId;






// Method: youtube.search.list
// Returns a collection of search results that match the query parameters
// specified in the API request. By default, a search result set identifies
// matching video, channel, and playlist resources, but you can also configure
// queries to only retrieve a specific type of resource.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     search resource properties that the API response will include. Set the
//     parameter value to snippet.
//     (Default "snippet" kBVBYouTubePartSnippet)
//  Optional:
//   channelId: The channelId parameter indicates that the API response should
//     only contain resources created by the channel
//   channelType: The channelType parameter lets you restrict a search to a
//     particular type of channel.
//      kBVBYouTubeChannelTypeAny: Return all channels.
//      kBVBYouTubeChannelTypeShows: Only retrieve shows.
//   eventType: The eventType parameter restricts a search to broadcast events.
//     If you specify a value for this parameter, you must also set the type
//     parameter's value to video.
//      kBVBYouTubeTypeEventTypeCompleted: Only include completed broadcasts.
//      kBVBYouTubeEventTypeLive: Only include active broadcasts.
//      kBVBYouTubeTypeEventTypeUpcoming: Only include upcoming broadcasts.
//   location: The location parameter, in conjunction with the locationRadius
//     parameter, defines a circular geographic area and also restricts a search
//     to videos that specify, in their metadata, a geographic location that
//     falls within that area. The parameter value is a string that specifies
//     latitude/longitude coordinates e.g. (37.42307,-122.08427).
//     - The location parameter value identifies the point at the center of the
//     area.
//     - The locationRadius parameter specifies the maximum distance that the
//     location associated with a video can be from that point for the video to
//     still be included in the search results.The API returns an error if your
//     request specifies a value for the location parameter but does not also
//     specify a value for the locationRadius parameter.
//   locationRadius: The locationRadius parameter, in conjunction with the
//     location parameter, defines a circular geographic area.
//     The parameter value must be a floating point number followed by a
//     measurement unit. Valid measurement units are m, km, ft, and mi. For
//     example, valid parameter values include 1500m, 5km, 10000ft, and 0.75mi.
//     The API does not support locationRadius parameter values larger than 1000
//     kilometers.
//     Note: See the definition of the location parameter for more information.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set. (0..50, default 5)
//   order: The order parameter specifies the method that will be used to order
//     resources in the API response. (Default "SEARCH_SORT_RELEVANCE")
//      kBVBYouTubeOrderDate: Resources are sorted in reverse chronological
//        order based on the date they were created.
//      kBVBYouTubeOrderRating: Resources are sorted from highest to lowest
//        rating.
//      kBVBYouTubeOrderRelevance: Resources are sorted based on their relevance
//        to the search query. This is the default value for this parameter.
//      kBVBYouTubeOrderTitle: Resources are sorted alphabetically by title.
//      kBVBYouTubeOrderVideoCaount: Channels are sorted in descending order of
//        their number of uploaded videos.
//      kBVBYouTubeOrderViewCount: Resources are sorted from highest to lowest
//        number of views.
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
//   publishedAfter: The publishedAfter parameter indicates that the API
//     response should only contain resources created after the specified time.
//     The value is an RFC 3339 formatted date-time value
//     (1970-01-01T00:00:00Z).
//   publishedBefore: The publishedBefore parameter indicates that the API
//     response should only contain resources created before the specified time.
//     The value is an RFC 3339 formatted date-time value
//     (1970-01-01T00:00:00Z).
//   q: The q parameter specifies the query term to search for.
//     Your request can also use the Boolean NOT (-) and OR (|) operators to
//     exclude videos or to find videos that are associated with one of several
//     search terms. For example, to search for videos matching either "boating"
//     or "sailing", set the q parameter value to boating|sailing. Similarly, to
//     search for videos matching either "boating" or "sailing" but not
//     "fishing", set the q parameter value to boating|sailing -fishing. Note
//     that the pipe character must be URL-escaped when it is sent in your API
//     request. The URL-escaped value for the pipe character is %7C.
//   regionCode: The regionCode parameter instructs the API to return search
//     results for the specified country. The parameter value is an ISO 3166-1
//     alpha-2 country code.
//   relevanceLanguage: The relevanceLanguage parameter instructs the API to
//     return search results that are most relevant to the specified language.
//     The parameter value is typically an ISO 639-1 two-letter language code.
//     However, you should use the values zh-Hans for simplified Chinese and
//     zh-Hant for traditional Chinese. Please note that results in other
//     languages will still be returned if they are highly relevant to the
//     search query term.
//   safeSearch: The safeSearch parameter indicates whether the search results
//     should include restricted content as well as standard content.
//      kBVBYouTubeSafeSearchModerate: YouTube will filter some content from
//        search results and, at the least, will filter content that is
//        restricted in your locale. Based on their content, search results
//        could be removed from search results or demoted in search results.
//        This is the default parameter value.
//      kBVBYouTubeSafeSearchNone: YouTube will not filter the search result
//        set.
//      kBVBYouTubeSafeSearchStrict: YouTube will try to exclude all restricted
//        content from the search result set. Based on their content, search
//        results could be removed from search results or demoted in search
//        results.
//   topicId: The topicId parameter indicates that the API response should only
//     contain resources associated with the specified topic. The value
//     identifies a Freebase topic ID.
//   type: The type parameter restricts a search query to only retrieve a
//     particular type of resource. The value is a comma-separated list of
//     resource types. (Default video,channel,playlist)
//   videoCaption: The videoCaption parameter indicates whether the API should
//     filter video search results based on whether they have captions. If you
//     specify a value for this parameter, you must also set the type
//     parameter's value to video.
//      kBVBYouTubeVideoCaptionAny: Do not filter results based on caption
//        availability.
//      kBVBYouTubeVideoCaptionClosedCaption: Only include videos that have
//        captions.
//      kBVBYouTubeVideoCaptionNone: Only include videos that do not have
//        captions.
//   videoCategoryId: The videoCategoryId parameter filters video search results
//     based on their category. If you specify a value for this parameter, you
//     must also set the type parameter's value to video.
//   videoDefinition: The videoDefinition parameter lets you restrict a search
//     to only include either high definition (HD) or standard definition (SD)
//     videos. HD videos are available for playback in at least 720p, though
//     higher resolutions, like 1080p, might also be available. If you specify a
//     value for this parameter, you must also set the type parameter's value to
//     video.
//      kBVBYouTubeVideoDefinitionAny: Return all videos, regardless of their
//        resolution.
//      kBVBYouTubeVideoDefinitionHigh: Only retrieve HD videos.
//      kBVBYouTubeVideoDefinitionStandard: Only retrieve videos in standard
//        definition.
//   videoDimension: The videoDimension parameter lets you restrict a search to
//     only retrieve 2D or 3D videos. If you specify a value for this parameter,
//     you must also set the type parameter's value to video.
//      kBVBYouTubeVideoDimension2d: Restrict search results to exclude 3D
//        videos.
//      kBVBYouTubeVideoDimension3d: Restrict search results to only include 3D
//        videos.
//      kBVBYouTubeVideoDimensionAny: Include both 3D and non-3D videos in
//        returned results. This is the default value.
//   videoDuration: The videoDuration parameter filters video search results
//     based on their duration. If you specify a value for this parameter, you
//     must also set the type parameter's value to video.
//      kBVBYouTubeVideoDurationAny: Do not filter video search results based on
//        their duration. This is the default value.
//      kBVBYouTubeVideoDurationLong: Only include videos longer than 20
//        minutes.
//      kBVBYouTubeVideoDurationMedium: Only include videos that are between
//        four and 20 minutes long (inclusive).
//      kBVBYouTubeVideoDurationShort: Only include videos that are less than
//        four minutes long.
//   videoLicense: The videoLicense parameter filters search results to only
//     include videos with a particular license. YouTube lets video uploaders
//     choose to attach either the Creative Commons license or the standard
//     YouTube license to each of their videos. If you specify a value for this
//     parameter, you must also set the type parameter's value to video.
//      kBVBYouTubeVideoLicenseAny: Return all videos, regardless of which
//        license they have, that match the query parameters.
//      kBVBYouTubeVideoLicenseCreativeCommon: Only return videos that have a
//        Creative Commons license. Users can reuse videos with this license in
//        other videos that they create. Learn more.
//      kBVBYouTubeVideoLicenseYoutube: Only return videos that have the
//        standard YouTube license.
//   videoType: The videoType parameter lets you restrict a search to a
//     particular type of videos. If you specify a value for this parameter, you
//     must also set the type parameter's value to video.
//      kBVBYouTubeVideoTypeAny: Return all videos.
//      kBVBYouTubeVideoTypeEpisode: Only retrieve episodes of shows.
//      kBVBYouTubeVideoTypeMovie: Only retrieve movies.
+ (instancetype)queryForSearchWithAPIKey:(NSString *)apiKey;


// Method: youtube.channels.list
// Returns a collection of zero or more channel resources that match the request
// criteria.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     channel resource properties that the API response will include.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     channel resource, the contentDetails property contains other properties,
//     such as the uploads properties. As such, if you set part=contentDetails,
//     the API response will also contain all of those nested properties.
//     (Default "contentDetails,snippet" kBVBYouTubePartContentDetailsSnippet)
//  Optional:
//   categoryId: The categoryId parameter specifies a YouTube guide category,
//     thereby requesting YouTube channels associated with that category.
//   forUsername: The forUsername parameter specifies a YouTube username,
//     thereby requesting the channel associated with that username.
//   hl: The hl parameter should be used for filter out the properties that are
//     not in the given language. Used for the brandingSettings part.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube channel ID(s) for the resource(s) that are being retrieved. In a
//     channel resource, the id property specifies the channel's YouTube channel
//     ID.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set. (0..50, default 5)
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
+ (instancetype)queryForChannelDetailsWithAPIKey:(NSString *)apiKey;



// Method: youtube.playlistItems.list
// Returns a collection of playlist items that match the API request parameters.
// You can retrieve all of the playlist items in a specified playlist or
// retrieve one or more playlist items by their unique IDs.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     playlistItem resource properties that the API response will include.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     playlistItem resource, the snippet property contains numerous fields,
//     including the title, description, position, and resourceId properties. As
//     such, if you set part=snippet, the API response will contain all of those
//     properties.
//     (Default "snippet" kBVBYouTubePartSnippet)
//  Optional:
//   identifier: The id parameter specifies a comma-separated list of one or
//     more unique playlist item IDs.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set. (0..50, default 5)
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
//   playlistId: The playlistId parameter specifies the unique ID of the
//     playlist for which you want to retrieve playlist items. Note that even
//     though this is an optional parameter, every request to retrieve playlist
//     items must specify a value for either the id parameter or the playlistId
//     parameter.
//   videoId: The videoId parameter specifies that the request should return
//     only the playlist items that contain the specified video.
+ (instancetype)queryForPlaylistItemsWithAPIKey:(NSString *)apiKey;






// Method: youtube.playlists.list
// Returns a collection of playlists that match the API request parameters. For
// example, you can retrieve all playlists that the authenticated user owns, or
// you can retrieve one or more playlists by their unique IDs.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     playlist resource properties that the API response will include.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     playlist resource, the snippet property contains properties like author,
//     title, description, tags, and timeCreated. As such, if you set
//     part=snippet, the API response will contain all of those properties.
//     (Default "snippet" kBVBYouTubePartSnippet)
//  Optional:
//   channelId: This value indicates that the API should only return the
//     specified channel's playlists.
//   hl: The hl parameter should be used for filter out the properties that are
//     not in the given language. Used for the snippet part.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube playlist ID(s) for the resource(s) that are being retrieved. In a
//     playlist resource, the id property specifies the playlist's YouTube
//     playlist ID.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set. (0..50, default 5)
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
+ (instancetype)queryForPlaylistsWithAPIKey:(NSString *)apiKey;



// Method: youtube.videos.list
// Returns a list of videos that match the API request parameters.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     video resource properties that the API response will include.
//     If the parameter identifies a property that contains child properties,
//     the child properties will be included in the response. For example, in a
//     video resource, the snippet property contains the channelId, title,
//     description, tags, and categoryId properties. As such, if you set
//     part=snippet, the API response will contain all of those properties.
//     (Default "snippet" kBVBYouTubePartSnippet)
//  Optional:
//   chart: The chart parameter identifies the chart that you want to retrieve.
//     Acceptable values are:
//     mostPopular – Return the most popular videos for the specified content region and video category.
//   hl: The hl parameter instructs the API to retrieve localized resource
//     metadata for a specific application language that the YouTube website
//     supports. The parameter value must be a language code included in the
//     list returned by the i18nLanguages.list method.
//     If localized resource details are available in that language, the
//     resource's snippet.localized object will contain the localized values.
//     However, if localized details are not available, the snippet.localized
//     object will contain resource details in the resource's default language.
//   identifier: The id parameter specifies a comma-separated list of the
//     YouTube video ID(s) for the resource(s) that are being retrieved. In a
//     video resource, the id property specifies the video's ID.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set.
//     Note: This parameter is supported for use in conjunction with the
//     myRating parameter, but it is not supported for use in conjunction with
//     the id parameter. (1..50, default 5)
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken and
//     prevPageToken properties identify other pages that could be retrieved.
//     Note: This parameter is supported for use in conjunction with the
//     myRating parameter, but it is not supported for use in conjunction with
//     the id parameter.
//   regionCode: The regionCode parameter instructs the API to select a video
//     chart available in the specified region. This parameter can only be used
//     in conjunction with the chart parameter. The parameter value is an ISO
//     3166-1 alpha-2 country code.
//   videoCategoryId: The videoCategoryId parameter identifies the video
//     category for which the chart should be retrieved. This parameter can only
//     be used in conjunction with the chart parameter. By default, charts are
//     not restricted to a particular category. (Default 0)
+ (instancetype)queryForVideoDetailsWithAPIKey:(NSString *)apiKey;





// Method: youtube.commentThreads.list
// Returns a list of comment threads that match the API request parameters.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     commentThread resource properties that the API response will include.
//     (Default "snippet" kBVBYouTubePartSnippet)
//  Optional:
//   allThreadsRelatedToChannelId: The allThreadsRelatedToChannelId parameter
//     instructs the API to return all comment threads associated with the
//     specified channel. The response can include comments about the channel or
//     about the channel's videos.
//   channelId: The channelId parameter instructs the API to return comment
//     threads containing comments about the specified channel. (The response
//     will not include comments left on videos that the channel uploaded.)
//   identifier: The id parameter specifies a comma-separated list of comment
//     thread IDs for the resources that should be retrieved.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set.
//     Note: This parameter is not supported for use in conjunction with the id
//     parameter. (1..100, default 20)
//   order: The order parameter specifies the order in which the API response should list comment threads.
//     Valid values are:
//     - time - Comment threads are ordered by time. This is the default behavior.
//     kBVBYouTubeOrderRelevance: Comment threads are ordered by relevance.
//     Note: This parameter is not supported for use in conjunction with the id parameter.
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken
//     property identifies the next page of the result that can be retrieved.
//     Note: This parameter is not supported for use in conjunction with the id
//     parameter.
//   searchTerms: The searchTerms parameter instructs the API to limit the API
//     response to only contain comments that contain the specified search
//     terms.
//     Note: This parameter is not supported for use in conjunction with the id
//     parameter.
//   textFormat: This parameter indicates whether the API should return comments formatted as HTML or as plain text.
//     The default value is html.
//     Acceptable values are:
//     kBVBYouTubeTextFormatHtml: Returns the comments in HTML format. This is the default value.
//     kBVBYouTubeTextFormatPlainText: Returns the comments in plain text format.
//   videoId: The videoId parameter instructs the API to return comment threads
//     associated with the specified video ID.
+ (instancetype)queryForCommentThreadsWithAPIKey:(NSString *)apiKey;





// Method: youtube.comments.list
// Returns a list of comments that match the API request parameters.
//  Required:
//   part: The part parameter specifies a comma-separated list of one or more
//     comment resource properties that the API response will include.
//     (Default "snippet" )
//  Optional:
//   identifier: The id parameter specifies a comma-separated list of comment
//     IDs for the resources that are being retrieved. In a comment resource,
//     the id property specifies the comment's ID.
//   maxResults: The maxResults parameter specifies the maximum number of items
//     that should be returned in the result set.
//     Note: This parameter is not supported for use in conjunction with the id
//     parameter. (1..100, default 20)
//   pageToken: The pageToken parameter identifies a specific page in the result
//     set that should be returned. In an API response, the nextPageToken
//     property identifies the next page of the result that can be retrieved.
//     Note: This parameter is not supported for use in conjunction with the id
//     parameter.
//   parentId: The parentId parameter specifies the ID of the comment for which
//     replies should be retrieved.
//     Note: YouTube currently supports replies only for top-level comments.
//     However, replies to replies may be supported in the future.
//   textFormat: This parameter indicates whether the API should return comments formatted as HTML or as plain text. The default value is html.
//     Acceptable values are:
//     kBVBYouTubeTextFormatHtml: Returns the comments in HTML format. This is the default value.
//     kBVBYouTubeTextFormatPlainText: Returns the comments in plain text format.
+ (instancetype)queryForCommentsWithAPIKey:(NSString *)apiKey;




// methodName is the RPC method name to use.
+ (instancetype)queryWithMethodName:(NSString *)methodName;
@end
