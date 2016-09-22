<p align="center" >
<img src="https://api.monosnap.com/rpc/file/download?id=ORaERYpwbSJrn4hUsQkmEqN9di9l2c" alt="bvblogic" title="bvblogic">
</p>
# BVBYouTubeSearch

Lite Youtube library let you search necessary content without authentication

## Installation

[CocoaPods](http://cocoapods.org)  is a dependency manager for Objective-C, which simplifies and make automated the process of the uasge of 3rd-party libraries like BVBYouTubeSearch in your projects. To install it you need the following command:

```bash
$ gem install cocoapods
```

#### Podfile

To integrate BVBYouTubeSearch into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '8.0'

target 'TargetName' do
pod "BVBYouTubeSearch”, :git => 'git@github.com:bvblogic/BVBYouTubeSearch.git’
end
```

Then, run the following command:

```bash
$ pod install
```

## Usage
### Creating an API Key

We are going to begin our YouTube API exploration with the next step: To create a new record (a new project) for the application in the Google Developers Console, in this way we have access to the YouTube API. After creating a new project in the Console, you need to do the followig issues:

- to enable the YouTube API to use it in the application.
- to create an API key to perform requests to the API.

Take into consideration that the requests that we are going to make to the YouTube API are not authorized, it means that we will not ask the users to sign in with their Google accounts to the app. Usage of API key allows to perform only limited amount of requests, and to get full access we need to complete authorization.

You need to connect to the [Developers Console](https://console.developers.google.com/project)
and then to create a new record for the project. You need to be signed in via Google. You will get the following screen after getting access:

<p align="center" >
<img src="https://www.appcoda.com/wp-content/uploads/2015/07/t39_2_console_projects.png" alt="bvblogic" title="bvblogic">
</p>

Then you need to press blue button Create Project in the top-left corner, and to write a name for the new project in the new modal window.

Then you need to enable the YouTube API for the project.

To enable the YouTube API, you need to click to the **APIs & auth > APIs** menu options are in the left side of the window. You need to locate the **YouTube Data API** on the main window, then you need to press its link.

<p align="center" >
<img src="https://www.appcoda.com/wp-content/uploads/2015/07/t39_4_console_youtube_api.png" alt="bvblogic" title="bvblogic">
</p>

You need to click to the  button **Enable API** to the upper side, and you are ready to go.

After you have enabled the API, you need to create the necessary API key.  You need to go to the **APIs & auth > Credentials** menu, and in the new window in the browser you need to press the button **Create new Key**. In the next modal window you have to choose the platform of the project. **Do not click iOS key button**.

<p align="center" >
<img src="http://www.appcoda.com/wp-content/uploads/2015/07/t39_5_console_key_options.png" alt="bvblogic" title="bvblogic">
</p>

Instead you need to click to the **Browser key** button. In the new modal window, you need to click **Create** buton without any typing into the box. When you get back to the credentials window, you’ll notice the new key created for you.

### Creating a Simple Search request

```objective-c

#import <BVBYouTubeSearch/BVBYouTubeService.h>


BVBYouTubeQuery *  query = [BVBYouTubeQuery queryForSearchWithAPIKey:@"Your API Key"];
query.type = kBVBYouTubeTypeChannel; // BVBYouTubeTypeVideoChannelPlaylist BVBYouTubeTypeVideo  BVBYouTubeTypePlayList
query.maxResults = 10;
query.q = @"apple";
BVBYouTubeService * service = [[BVBYouTubeService alloc] init];
[service executeQuery:query completionHandler:^(id object, NSError *error){

NSLog(@" object %@  error %@",object,error);

}];

```



## Author

[[bvblogic]](http://bvblogic.com), s.zubyak@bvblogic.com

## License

BVBYouTubeSearch is available under the GNU General Public License. See the LICENSE file for more info.
