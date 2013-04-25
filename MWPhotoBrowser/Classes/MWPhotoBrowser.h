//
//  MWPhotoBrowser.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "MWPhoto.h"
#import "MWPhotoProtocol.h"
#import "MWCaptionView.h"
#import "MWZoomingScrollView.h"

// Debug Logging
#if 0 // Set to 1 to enable debug logging
#define MWLog(x, ...) NSLog(x, ## __VA_ARGS__);
#else
#define MWLog(x, ...)
#endif

// Delgate
@class MWPhotoBrowser;
@protocol MWPhotoBrowserDelegate <NSObject>
- (NSUInteger)numberOfPhotosInPhotoBrowser:(MWPhotoBrowser *)photoBrowser;
- (id<MWPhoto>)photoBrowser:(MWPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index;
@optional
- (MWCaptionView *)photoBrowser:(MWPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
@end

// MWPhotoBrowser
@interface MWPhotoBrowser : UIViewController <UIScrollViewDelegate, UIActionSheetDelegate, MFMailComposeViewControllerDelegate> {

@protected
    UIToolbar *_toolbar;
    UIBarButtonItem *_previousButton, *_nextButton, *_actionButton;
    UIActionSheet *_actionsSheet;
    UIView *_overlayView;

}

// Properties
@property (nonatomic) BOOL displayActionButton;

// Init
- (id)initWithPhotos:(NSArray *)photosArray  __attribute__((deprecated)); // Depreciated
- (id)initWithDelegate:(id <MWPhotoBrowserDelegate>)delegate;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setInitialPageIndex:(NSUInteger)index;

// Override this if you want a custom toolbar
- (void)setupToolbar;

// Custom zooming pages
- (void)configurePage:(MWZoomingScrollView *)page forIndex:(NSUInteger)index;

- (NSUInteger)numberOfPhotos;
- (NSUInteger)currentIndex;
- (UIActionSheet*)showActionSheet:(UIActionSheet*)actionSheet invokedFromButton:(UIBarButtonItem*)sender;
- (id<MWPhoto>)photoAtIndex:(NSUInteger)index;

// Controls
- (void)cancelControlHiding;
- (void)hideControlsAfterDelay;
- (void)resetControlHidingTimer;
- (void)setControlsHidden:(BOOL)hidden animated:(BOOL)animated permanent:(BOOL)permanent;
- (void)toggleControls;
- (BOOL)areControlsHidden;

- (NSArray*)getActionSheetItems;
- (void)actionSheetItemTapped:(NSUInteger)index;

- (void)didStartViewingPageAtIndex:(NSUInteger)index;

@end


