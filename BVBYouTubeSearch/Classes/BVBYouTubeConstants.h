//
//  BVBYoutubeConstants.h
//  Pods
//
//  Created by Svyat Zubyak MacBook on 13.07.16.
//
//

#import <Foundation/Foundation.h>



//BVBYoutubeQuery - Method Name
extern NSString * const kBVBYouTubeTypeSearch;   // "search"
extern NSString * const kBVBYouTubeTypeChannels;  //"channels"
extern NSString * const kBVBYouTubeTypePlaylistItems;// "playlistItems"
extern NSString * const kBVBYouTubeTypePlaylists;// "playlists"
extern NSString * const kBVBYouTubeTypeVideos;// "videos"
extern NSString * const kBVBYouTubeTypeCommentThreads;// "commentThreads"
extern NSString * const kBVBYouTubeTypeComments;// "comments"



//BVBYoutubeQuery - Part
extern NSString * const kBVBYouTubePartSnippet;   // "snippet"
extern NSString * const kBVBYouTubePartContentDetails;   // "contentDetails"
extern NSString * const kBVBYouTubePartContentDetailsSnippet; //"contentDetails,snippet"

#pragma VIDEO QUERY

//BVBYoutubeQuery - Chart
extern NSString * const kBVBYouTubeChartMostPopular;   // "mostPopular"


#pragma CommentThreads QUERY

//BVBYoutubeQuery - TextFormat
extern NSString * const kBVBYouTubeTextFormatHtml;   // "html"
extern NSString * const kBVBYouTubeTextFormatPlainText;   // "plainText"


#pragma SEARCH QUERY

//BVBYoutubeQuery - Type
extern NSString * const  kBVBYouTubeTypeVideoChannelPlaylist;   // "video,channel,playlist"
extern NSString * const  kBVBYouTubeTypeVideo;      // "video"
extern NSString * const  kBVBYouTubeTypeChannel;      // "channel"
extern NSString * const  kBVBYouTubeTypePlayList;      // "playlist"

//BVBYoutubeQuery - Channel Type
extern NSString * const kBVBYouTubeChannelTypeAny;   // "any"
extern NSString * const  kBVBYouTubeChannelTypeShows;      // "shows"

//BVBYoutubeQuery - Event Type
extern NSString * const kBVBYouTubeEventTypeLive;   // "live"
extern NSString * const  kBVBYouTubeTypeEventTypeCompleted;      // "completed"
extern NSString * const  kBVBYouTubeTypeEventTypeUpcoming;      // "upcoming"

//BVBYoutubeQuery - Order
extern NSString * const  kBVBYouTubeOrderRelevance;   // "relevance"
extern NSString * const  kBVBYouTubeOrderDate;      // "date"
extern NSString * const  kBVBYouTubeOrderTitle;      // "title"
extern NSString * const  kBVBYouTubeOrderRating;      // "rating"
extern NSString * const  kBVBYouTubeOrderViewCount;      // "viewCount"
extern NSString * const  kBVBYouTubeOrderVideoCaount;      // "videoCount"

//BVBYoutubeQuery - Safe Search
extern NSString * const  kBVBYouTubeSafeSearchNone;   // "none"
extern NSString * const  kBVBYouTubeSafeSearchStrict;      // "strict"
extern NSString * const  kBVBYouTubeSafeSearchModerate;      // "moderate"

//BVBYoutubeQuery - Video Caption
extern NSString * const  kBVBYouTubeVideoCaptionAny;   // "any"
extern NSString * const  kBVBYouTubeVideoCaptionNone;      // "none"
extern NSString * const  kBVBYouTubeVideoCaptionClosedCaption;      // "closedCaption"

//BVBYoutubeQuery - Video Dimension
extern NSString * const  kBVBYouTubeVideoDimensionAny;   // "any"
extern NSString * const  kBVBYouTubeVideoDimension2d;      // "2d"
extern NSString * const  kBVBYouTubeVideoDimension3d;      // "3d"

//BVBYoutubeQuery - Video Definition
extern NSString * const  kBVBYouTubeVideoDefinitionAny;   // "any"
extern NSString * const  kBVBYouTubeVideoDefinitionHigh;      // "high"
extern NSString * const  kBVBYouTubeVideoDefinitionStandard;      // "standard"

//BVBYoutubeQuery - Video Duration
extern NSString * const  kBVBYouTubeVideoDurationAny;   // "any"
extern NSString * const  kBVBYouTubeVideoDurationLong;      // "long"
extern NSString * const  kBVBYouTubeVideoDurationMedium;      // "medium"
extern NSString * const  kBVBYouTubeVideoDurationShort;      // "short"

//BVBYoutubeQuery - Video License
extern NSString * const  kBVBYouTubeVideoLicenseAny;   // "any"
extern NSString * const  kBVBYouTubeVideoLicenseYoutube;      // "youtube"
extern NSString * const  kBVBYouTubeVideoLicenseCreativeCommon;      // "creativeCommon"

//BVBYoutubeQuery - Video Type
extern NSString * const  kBVBYouTubeVideoTypeAny;   // "any"
extern NSString * const  kBVBYouTubeVideoTypeMovie;      // "movie"
extern NSString * const  kBVBYouTubeVideoTypeEpisode;      // "episode"










