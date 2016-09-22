//
//  BVBViewController.m
//  YoutubeSDKLite
//
//  Created by szubyak on 07/07/2016.
//  Copyright (c) 2016 szubyak. All rights reserved.
//

#import "BVBViewController.h"
#import "BVBExampleViewController.h"
@interface BVBViewController ()
{
    NSArray *queryNames;
    BVBYouTubeService * service;
    NSString * apiKey;
}
@end

@implementation BVBViewController

- (void)viewDidLoad{
    
    // Do any additional setup after loading the view, typically from a nib.
    [super viewDidLoad];
    
    
     queryNames = @[@"Search Query",@"Channel Details Query",@"Playlist Items Query",@"Playlists Query", @"Video Deatils Query", @"Comment Threads Query", @"Comments Query",@"Custom Query"];
    
    self.requestsTableView.delegate = self;
    self.requestsTableView.dataSource = self;
    
   apiKey = @"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"; // Your API key here
        
   service = [[BVBYouTubeService alloc] init];
    
	
}

#pragma mark - TableView Delegate/DataSource

-(NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    if (section == 0) {
        return @"Please select row and check console logs for response";
    }else{
        return @"Project example";
    }
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    
    if (section == 0) {
        return queryNames.count;
    }else{
        return 1;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    if(!cell){
        cell=[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
        
    }
    
    // Configure the cell...
    if (indexPath.section == 0) {
    [cell.textLabel setText:queryNames[indexPath.row]];
    }else{
        [cell.textLabel setText:@"Example"];
    }
    
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    
    if (indexPath.section == 0) {
      
   BVBYouTubeQuery  * query;
    
    switch (indexPath.row) {
        case 0:
        {
            query = [BVBYouTubeQuery queryForSearchWithAPIKey:apiKey];
            query.type = kBVBYouTubeTypeChannel; // BVBYouTubeTypeVideoChannelPlaylist BVBYouTubeTypeVideo  BVBYouTubeTypePlayList
            query.maxResults = 10;
            query.q = @"apple";
        }
            break;
            
        case 1:
        {
            query = [BVBYouTubeQuery queryForChannelDetailsWithAPIKey:apiKey];
            query.maxResults = 10;
            query.id = @"UCE_M8A5yxnLfW0KghEeajjw";
        }
            break;
            
        case 2:
        {
             query = [BVBYouTubeQuery queryForPlaylistItemsWithAPIKey:@"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"];
             query.maxResults = 10;
             query.playlistId = @"PLaXpNjkL11Pk3dY7BNzYz7zu2XA416Hj8";
            
        }
            break;
            
        case 3:
        {
             query = [BVBYouTubeQuery queryForPlaylistsWithAPIKey:@"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"];
             query.maxResults = 10;
             query.channelId = @"UCE_M8A5yxnLfW0KghEeajjw";
            
         }
            break;
            
        case 4:
        {
             query = [BVBYouTubeQuery queryForVideoDetailsWithAPIKey:@"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"];
             query.maxResults = 10;
             query.id = @"RA0Ajgy-jmU";
            
        }
            break;
            
        case 5:
        {
            
             query = [BVBYouTubeQuery queryForCommentThreadsWithAPIKey:@"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"];
             query.maxResults = 10;
             query.channelId = @"UCj34AOIMl_k1fF7hcBkD_dw";
             query.textFormat = kBVBYouTubeTextFormatPlainText;
            
         }
            break;
            
        case 6:
        {
            
            query = [BVBYouTubeQuery queryForCommentsWithAPIKey:@"AIzaSyBJXRLYSw5-gkMERH-RlqROxQGaYlqCQzU"];
            query.maxResults = 10;
            query.id = @"z13lh1iizkr2s10hi04cixxjkyzwhn34vzo0k";
            query.textFormat = kBVBYouTubeTextFormatPlainText;
            
        }
            break;
            
        case 7:
        {
            
            query = [BVBYouTubeQuery queryWithMethodName:@"search"];
            query.key = apiKey;
            query.part = @"snippet";
            query.type = kBVBYouTubeTypeChannel; // BVBYouTubeTypeVideoChannelPlaylist BVBYouTubeTypeVideo  BVBYouTubeTypePlayList
            query.maxResults = 10;
            query.q = @"apple";
            
        }
            break;

        default:
            break;
    }
    
    [service executeQuery:query completionHandler:^(id object, NSError *error){
        
        NSLog(@" object %@  error %@",object,error);
        
    }];
        
    }else{
        [self performSegueWithIdentifier:@"toExampleViewController" sender:self];
    }
}

- (void)prepareForSegue:(UIStoryboardSegue*)segue sender:(id)sender{
    
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    if ([segue.identifier isEqualToString:@"toExampleViewController"]) {
        BVBExampleViewController* controller = (BVBExampleViewController*)segue.destinationViewController;
        controller.apiKey = apiKey;
        
    }
}

- (void)didReceiveMemoryWarning{
    
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
