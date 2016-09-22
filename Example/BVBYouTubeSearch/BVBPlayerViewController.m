//
//  BVBPlayerViewController.m
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak on 9/20/16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import "BVBPlayerViewController.h"

@interface BVBPlayerViewController ()

@end

@implementation BVBPlayerViewController

- (void)viewDidLoad {
    
    // Do any additional setup after loading the view.
    [super viewDidLoad];
    [self.titleLabel setText:self.content.title];
    self.playerView.delegate = self;
    [self.playerView loadWithVideoId:self.content.contentId];
    
}

- (void)playerView:(YTPlayerView *)playerView didChangeToState:(YTPlayerState)state {
    
    switch (state) {
        case kYTPlayerStatePlaying:
            NSLog(@"Started playback");
            break;
        case kYTPlayerStatePaused:
            NSLog(@"Paused playback");
            break;
        default:
            break;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
