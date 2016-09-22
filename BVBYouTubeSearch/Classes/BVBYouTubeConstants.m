//
//  BVBYoutubeConstants.m
//  Pods
//
//  Created by Svyat Zubyak MacBook on 13.07.16.
//
//

#import "BVBYouTubeConstants.h"

//BVBYoutubeQuery - Method Name
NSString * const kBVBYouTubeTypeSearch = @"search";
NSString * const kBVBYouTubeTypeChannels = @"channels";
NSString * const kBVBYouTubeTypePlaylistItems = @"playlistItems";
NSString * const kBVBYouTubeTypePlaylists = @"playlists";
NSString * const kBVBYouTubeTypeVideos = @"videos";
NSString * const kBVBYouTubeTypeCommentThreads = @"commentThreads";
NSString * const kBVBYouTubeTypeComments  = @"comments";

//BVBYoutubeQuery - Part
NSString * const kBVBYouTubePartSnippet = @"snippet";
NSString * const kBVBYouTubePartContentDetails = @"contentDetails";
NSString * const kBVBYouTubePartContentDetailsSnippet = @"contentDetails,snippet";



#pragma VIDEO QUERY

//BVBYoutubeQuery - Chart
NSString * const kBVBYouTubeChartMostPopular = @"mostPopular";


#pragma CommentThreads QUERY

//BVBYoutubeQuery - TextFormat
 NSString * const kBVBYouTubeTextFormatHtml = @"html";
 NSString * const kBVBYouTubeTextFormatPlainText = @"plainText";


#pragma SEARCH QUERY

//BVBYoutubeQuery - Type
 NSString * const  kBVBYouTubeTypeVideoChannelPlaylist  = @"video,channel,playlist";
 NSString * const  kBVBYouTubeTypeVideo  = @"video";
 NSString * const  kBVBYouTubeTypeChannel  = @"channel";
 NSString * const  kBVBYouTubeTypePlayList  = @"playlist";

//BVBYoutubeQuery - Channel Type
 NSString * const kBVBYouTubeChannelTypeAny  = @"any";
 NSString * const  kBVBYouTubeChannelTypeShows  = @"shows";

//BVBYoutubeQuery - Event Type
 NSString * const kBVBYouTubeEventTypeLive  = @"live";
 NSString * const kBVBYouTubeTypeEventTypeCompleted  = @"completed";
 NSString * const  kBVBYouTubeTypeEventTypeUpcoming  = @"upcoming";

//BVBYoutubeQuery - Order
 NSString * const  kBVBYouTubeOrderRelevance  = @"relevance";
 NSString * const  kBVBYouTubeOrderDate  = @"date";
 NSString * const  kBVBYouTubeOrderTitle  = @"title";
 NSString * const  kBVBYouTubeOrderRating  = @"rating";
 NSString * const  kBVBYouTubeOrderViewCount  = @"viewCount";
 NSString * const  kBVBYouTubeOrderVideoCaount  = @"videoCount";

//BVBYoutubeQuery - Safe Search
 NSString * const  kBVBYouTubeSafeSearchNone  = @"none";
 NSString * const  kBVBYouTubeSafeSearchStrict  = @"strict";
 NSString * const  kBVBYouTubeSafeSearchModerate  = @"moderate";

//BVBYoutubeQuery - Video Caption
 NSString * const  kBVBYouTubeVideoCaptionAny  = @"any";
 NSString * const  kBVBYouTubeVideoCaptionNone  = @"none";
 NSString * const  kBVBYouTubeVideoCaptionClosedCaption  = @"closedCaption";

//BVBYoutubeQuery - Video Dimension
 NSString * const  kBVBYouTubeVideoDimensionAny  = @"any";
 NSString * const  kBVBYouTubeVideoDimension2d  = @"2d";
 NSString * const  kBVBYouTubeVideoDimension3d  = @"3d";

//BVBYoutubeQuery - Video Definition
 NSString * const  kBVBYouTubeVideoDefinitionAny  = @"any";
 NSString * const  kBVBYouTubeVideoDefinitionHigh  = @"high";
 NSString * const  kBVBYouTubeVideoDefinitionStandard  = @"standard";

//BVBYoutubeQuery - Video Duration
 NSString * const  kBVBYouTubeVideoDurationAny  = @"any";
 NSString * const  kBVBYouTubeVideoDurationLong  = @"long";
 NSString * const  kBVBYouTubeVideoDurationMedium  = @"medium";
 NSString * const  kBVBYouTubeVideoDurationShort  = @"short";

//BVBYoutubeQuery - Video License
 NSString * const  kBVBYouTubeVideoLicenseAny  = @"any";
 NSString * const  kBVBYouTubeVideoLicenseYoutube  = @"youtube";
 NSString * const  kBVBYouTubeVideoLicenseCreativeCommon  = @"creativeCommon";

//BVBYoutubeQuery - Video Type
 NSString * const  kBVBYouTubeVideoTypeAny  = @"any";
 NSString * const  kBVBYouTubeVideoTypeMovie  = @"movie";
 NSString * const  kBVBYouTubeVideoTypeEpisode  = @"episode";
