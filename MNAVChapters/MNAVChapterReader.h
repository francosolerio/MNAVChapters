//
//  MNAVChapters.h
//  MNAVChapters
//
//  Created by Michael Nisi on 02.08.13.
//  Copyright (c) 2013 Michael Nisi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <AVFoundation/AVFoundation.h>

@interface MNAVChapter : NSObject
@property (nonatomic, copy, nullable) NSString *identifier;
@property (nonatomic, assign) BOOL hidden;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *url;
@property (nonatomic) CMTime time;
@property (nonatomic) CMTime duration;
@property (nonatomic, nullable) UIImage *artwork;
- (BOOL)isEqualToChapter:(nullable MNAVChapter *)aChapter;
- (nonnull MNAVChapter *)initWithTime:(CMTime)time duration:(CMTime)duration;
+ (nonnull MNAVChapter *)chapterWithTime:(CMTime)time duration:(CMTime)duration;
@end

@interface MNAVChapterReader : NSObject
+ (nonnull NSArray *)chaptersFromAsset:(nonnull AVAsset *)asset;
@end

# pragma mark - Internal

@protocol MNAVChapterReader <NSObject>
- (nonnull NSArray *)chaptersFromAsset:(nonnull AVAsset *)asset;
@end

@interface MNAVChapterReaderMP3 : NSObject <MNAVChapterReader>
- (nonnull MNAVChapter *)chapterFromFrame:(nonnull NSData *)data;
@end

@interface MNAVChapterReaderMP4 : NSObject <MNAVChapterReader>
@end
