//
//  MWPhoto.h
//  MWPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MWPhotoProtocol.h"
#import "SDWebImageDecoder.h"
#import "SDWebImageManager.h"

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to MWPhotoProtocol
@interface MWPhoto : NSObject <MWPhoto, SDWebImageManagerDelegate, SDWebImageDecoderDelegate>

// Properties
@property (nonatomic, retain) NSString *caption;

// Class
+ (MWPhoto *)photoWithImage:(UIImage *)image andId:(NSString*)identifier;
+ (MWPhoto *)photoWithFilePath:(NSString *)path andId:(NSString*)identifier;
+ (MWPhoto *)photoWithURL:(NSURL *)url andId:(NSString*)identifier;

// Init
- (id)initWithImage:(UIImage *)image andId:(NSString*)identifier;
- (id)initWithFilePath:(NSString *)path andId:(NSString*)identifier;
- (id)initWithURL:(NSURL *)url andId:(NSString*)identifier;

@end

