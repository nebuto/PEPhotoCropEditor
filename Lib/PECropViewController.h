//
//  PECropViewController.h
//  PhotoCropEditor
//
//  Created by kishikawa katsumi on 2013/05/19.
//  Copyright (c) 2013 kishikawa katsumi. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PECropViewControllerDelegate;

@interface PECropViewController : UIViewController

@property (nonatomic, weak) id<PECropViewControllerDelegate> delegate;
@property (nonatomic) UIImage *image;

@property (nonatomic) BOOL keepingCropAspectRatio;
@property (nonatomic) CGFloat cropAspectRatio;

@property (nonatomic) CGRect cropRect;
@property (nonatomic) CGRect imageCropRect;
@property (nonatomic) CGSize minimumImageCropRectSize;

@property (nonatomic) BOOL toolbarHidden;

- (void)resetCropRect;
- (void)resetCropRectAnimated:(BOOL)animated;

@end

@protocol PECropViewControllerDelegate <NSObject>

@optional
- (void)cropViewController:(PECropViewController *)controller didFinishCroppingImage:(UIImage *)croppedImage;
- (void)cropViewControllerDidCancel:(PECropViewController *)controller;
- (void)cropViewController:(PECropViewController *)controller didFinishCroppingImage:(UIImage *)croppedImage withFullImage:(UIImage*)fullImage andCropRect:(CGRect)cropRect;
- (void)cropViewDidHitMinimumCappedSize;

@end
