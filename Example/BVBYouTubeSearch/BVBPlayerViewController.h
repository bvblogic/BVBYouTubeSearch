//
//  BVBPlayerViewController.h
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak on 9/20/16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YTPlayerView.h"
#import "BVBContent.h"
@interface BVBPlayerViewController : UIViewController <YTPlayerViewDelegate>

@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet YTPlayerView *playerView;
@property(nonatomic) BVBContent * content;

@end
