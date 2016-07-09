//
//  MXSoundVibrateUtils.m
//  WeiZi
//
//  Created by Meniny on 16/6/20.
//  Copyright © 2016年 YiBeacon. All rights reserved.
//

#import "MXSoundVibrateUtils.h"

@interface MXSoundVibrateUtils ()
@property (assign, nonatomic) SystemSoundID soundID;
@end

@implementation MXSoundVibrateUtils

- (instancetype)initForVibrate {
    self = [super init];
    if (self) {
        self.soundID = kSystemSoundID_Vibrate;
    }
    return self;
}

- (instancetype)initForDefault {
    self = [super init];
    if (self) {
        self.soundID = MXSystemSoundIDDefault;
    }
    return self;
}

- (instancetype)initForPlayingSystemSoundEffectWithSoundID:(SystemSoundID)soundID {
    self = [super init];
    if (self) {
        self.soundID = soundID;
    }
    return self;
}

- (instancetype)initForPlayingSystemSoundEffectWithSoundIDEnum:(MXSystemSoundID)soundID {
    self = [super init];
    if (self) {
        self.soundID = soundID;
    }
    return self;
}

- (instancetype)initForPlayingSystemSoundEffectWithResourceName:(NSString *)resourceName
                                                         ofType:(NSString *)type {
    self = [super init];
    if (self) {
        NSString *path = [[NSBundle bundleWithIdentifier:@"com.apple.UIKit"] pathForResource:resourceName ofType:type];
        if (path) {
            NSURL *fileURL = [NSURL fileURLWithPath:path];
            [self setupForSOundEffectWithURL:fileURL];
        }
    }
    return self;
}

- (instancetype)initForPlayingSoundEffectWithFilePath:(NSString *)filePath {
    self = [super init];
    if (self) {
        if (filePath != nil) {
            NSURL *fileURL = [NSURL fileURLWithPath:filePath];
            [self setupForSOundEffectWithURL:fileURL];
        }
    }
    return self;
}

- (instancetype)initForPlayingSoundEffectWithFileName:(NSString *)fileName {
    self = [super init];
    if (self) {
        NSURL *fileURL = [[NSBundle mainBundle] URLForResource:fileName withExtension:nil];
        [self setupForSOundEffectWithURL:fileURL];
    }
    return self;
}

- (void)setupForSOundEffectWithURL:(NSURL *)fileURL {
    if (fileURL != nil) {
        SystemSoundID theSoundID;
        OSStatus error = AudioServicesCreateSystemSoundID((__bridge CFURLRef)fileURL, &theSoundID);
        if (error == kAudioServicesNoError) {
            self.soundID = theSoundID;
        } else {
            NSLog(@"ERROR: Failed to create sound");
        }
    }
}

- (void)play {
    __weak typeof(self) weakSelf = self;
    AudioServicesPlaySystemSoundWithCompletion(self.soundID, ^{
        AudioServicesDisposeSystemSoundID(weakSelf.soundID);
    });
}
@end
