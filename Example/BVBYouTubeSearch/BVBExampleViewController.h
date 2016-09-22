//
//  BVBExampleViewController.h
//  YoutubeSDKLite
//
//  Created by Svyat Zubyak MacBook on 15.08.16.
//  Copyright © 2016 szubyak. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BVBExampleViewController : UIViewController <UITableViewDataSource,UITableViewDelegate,UISearchBarDelegate>

@property (weak, nonatomic) IBOutlet UISegmentedControl *searchTypeSegmentedControll;
@property (weak, nonatomic) IBOutlet UISearchBar *searchTextField;
@property (weak, nonatomic) IBOutlet UITableView *resultsTableView;
@property( strong, nonatomic) NSString * apiKey;

@end
