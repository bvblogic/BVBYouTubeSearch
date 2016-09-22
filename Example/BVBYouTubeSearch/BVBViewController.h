//
//  BVBViewController.h
//  YoutubeSDKLite
//
//  Created by szubyak on 07/07/2016.
//  Copyright (c) 2016 szubyak. All rights reserved.
//

@import UIKit;

#import <CoreLocation/CoreLocation.h>
#import <BVBYouTubeSearch/BVBYouTubeService.h>

@interface BVBViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic) IBOutlet UITableView *requestsTableView;

@end
