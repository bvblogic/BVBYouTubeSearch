//
//  BVBExampleViewController.m
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak MacBook on 15.08.16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import "BVBContent.h"
#import "BVBExampleViewController.h"
#import <BVBYouTubeSearch/BVBYouTubeService.h>
#import "BVBPlayerViewController.h"

@interface BVBExampleViewController () {
    
    NSString* searchType;
    BVBYouTubeService* service;
    NSString* nextPageToken;
    NSMutableArray* results;
    BVBContent * selectedContent;
    
}
@end

@implementation BVBExampleViewController

- (void)viewDidLoad{
    
    // Do any additional setup after loading the view.
    [super viewDidLoad];
    searchType = kBVBYouTubeTypeVideoChannelPlaylist;
    results = [[NSMutableArray alloc] init];
    self.searchTextField.delegate = self;
    self.resultsTableView.delegate = self;
    self.resultsTableView.dataSource = self;
    service = [[BVBYouTubeService alloc] init];
    nextPageToken = @"";
    [self handleSearch];
    
}

- (void)didReceiveMemoryWarning{
    
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)searchTypeselection:(UISegmentedControl*)sender{
    
    [results removeAllObjects];
    nextPageToken = @"";

    switch (sender.selectedSegmentIndex) {
    case 0:
        searchType = kBVBYouTubeTypeVideoChannelPlaylist;
        break;
    case 1:
        searchType = kBVBYouTubeTypeVideo;
        break;
    case 2:
        searchType = kBVBYouTubeTypeChannel;
        break;
    case 3:
        searchType = kBVBYouTubeTypePlayList;
        break;

    default:
        break;
    }
    
    [self handleSearch];
}

//search button was tapped
- (void)searchBarSearchButtonClicked:(UISearchBar*)searchBar{
    
    [results removeAllObjects];
    nextPageToken = @"";
    [self handleSearch];
    [searchBar resignFirstResponder];
    
}

- (void)searchBarCancelButtonClicked:(UISearchBar*)searchBar{
    
    [searchBar resignFirstResponder];
}

- (void)handleSearch{

    BVBYouTubeQuery* query = [BVBYouTubeQuery queryForSearchWithAPIKey:self.apiKey];
    query.maxResults = 10;
    query.q = self.searchTextField.text;
    if (nextPageToken.length > 0) {
        query.pageToken = nextPageToken;
    }
    query.type = searchType;

    UIActivityIndicatorView* activityView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    [self.view addSubview:activityView];
    activityView.center = CGPointMake(self.view.frame.size.width / 2, self.view.frame.size.height / 2);
    [activityView startAnimating];
    [service executeQuery:query completionHandler:^(NSDictionary* object, NSError* error) {

             dispatch_async(dispatch_get_main_queue(), ^{
            [activityView stopAnimating];

            if (!error) {
                nextPageToken = object[@"nextPageToken"];
                [self parseResponse:object];
            }
            else {
                NSLog(@"ERROR %@", error);
            }

        });

    }];
}

//parse our JSON response from the server and load the NSMutableArray of countries
- (void)parseResponse:(NSDictionary*)data{
    
    for (NSDictionary* d in data[@"items"]) {
        [results addObject:[BVBContent createContentFormData:d]];
    }
    [self.resultsTableView reloadData];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section{
    return results.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
       return 80;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    BVBContent* c = results[indexPath.row];
    if (c.contentId) {
        selectedContent = c;
       [self performSegueWithIdentifier:@"toPlayerViewController" sender:self];
    }
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath{
    
    static NSString* CellIdentifier = @"Cell";
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];

    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }

    // Configure the cell...
    BVBContent* c = results[indexPath.row];

    [cell.textLabel setText:c.title];
    [cell.detailTextLabel setText:c.overview];

    NSURL* url = [NSURL URLWithString:c.thumbnailURL];

    NSURLSessionTask* task = [[NSURLSession sharedSession] dataTaskWithURL:url completionHandler:^(NSData* _Nullable data, NSURLResponse* _Nullable response, NSError* _Nullable error) {
        if (data) {
            UIImage* image = [UIImage imageWithData:data];
            if (image) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    UITableViewCell* updateCell = (id)[tableView cellForRowAtIndexPath:indexPath];
                    if (updateCell)
                        updateCell.imageView.image = image;
                });
            }
        }
    }];
    [task resume];
    return cell;
}
- (void)scrollViewDidScroll:(UIScrollView*)scrollView{
    
    if (scrollView.contentOffset.y == (scrollView.contentSize.height - scrollView.bounds.size.height)) {

        [self handleSearch];
    }
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    // Make sure your segue name in storyboard is the same as this line
    if ([[segue identifier] isEqualToString:@"toPlayerViewController"])
    {
        // Get reference to the destination view controller
        BVBPlayerViewController *vc = [segue destinationViewController];
        
        // Pass any objects to the view controller here, like...
        vc.content = selectedContent;
    }
}


@end
