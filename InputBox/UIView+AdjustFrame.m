//
//  UIView+AdjustFrame.m
//  xib练习
//
//  Created by LOLITA on 17/6/14.
//  Copyright © 2017年 LOLITA. All rights reserved.
//

#import "UIView+AdjustFrame.h"

@implementation UIView (AdjustFrame)

#pragma mark Frame
-(CGPoint)viewOrigin{
    return self.frame.origin;
}
-(void)setViewOrigin:(CGPoint)viewOrigin{
    CGRect newFrame = self.frame;
    newFrame.origin = viewOrigin;
    self.frame = newFrame;
}


-(CGSize)viewSize{
    return self.frame.size;
}
-(void)setViewSize:(CGSize)viewSize{
    CGRect newFrame = self.frame;
    newFrame.size = viewSize;
    self.frame = newFrame;
}



#pragma mark Frame Origin
-(CGFloat)x{
    return self.frame.origin.x;
}
-(void)setX:(CGFloat)x{
    CGRect newFrame = self.frame;
    newFrame.origin.x = x;
    self.frame = newFrame;
}

-(CGFloat)y{
    return self.frame.origin.y;
}
-(void)setY:(CGFloat)y{
    CGRect newFrame = self.frame;
    newFrame.origin.y = y;
    self.frame = newFrame;
}




#pragma mark Frame Size
- (CGFloat)viewHeight{
    return self.frame.size.height;
}
- (void)setViewHeight:(CGFloat)newHeight{
    CGRect newFrame = self.frame;
    newFrame.size.height = newHeight;
    self.frame = newFrame;
}

- (CGFloat)viewWidth{
    return self.frame.size.width;
}
- (void)setViewWidth:(CGFloat)newWidth{
    CGRect newFrame = self.frame;
    newFrame.size.width = newWidth;
    self.frame = newFrame;
}



#pragma mark Frame Borders
-(CGFloat)left{
    return self.x;
}
-(void)setLeft:(CGFloat)left{
    self.x = left;
}

-(CGFloat)right{
    return self.x + self.viewWidth;
}
-(void)setRight:(CGFloat)right{
    self.x = right - self.viewWidth;
}

-(CGFloat)top{
    return self.y;
}
-(void)setTop:(CGFloat)top{
    self.y = top;
}

-(CGFloat)bottom{
    return self.y + self.viewHeight;
}
-(void)setBottom:(CGFloat)bottom{
    self.y = bottom - self.viewHeight;
}



#pragma mark Center Point
-(CGFloat)centerX{
    return self.center.x;
}
-(void)setCenterX:(CGFloat)newCenterX{
    self.center = CGPointMake(newCenterX, self.centerY);
}

-(CGFloat)centerY{
    return self.center.y;
}
-(void)setCenterY:(CGFloat)newCenterY{
    self.center = CGPointMake(self.centerX, newCenterY);
}



#pragma mark Middle Point
- (CGPoint)middlePoint{
    return CGPointMake(self.middleX, self.middleY);
}
- (CGFloat)middleX{
    return self.viewWidth / 2;
}
- (CGFloat)middleY
{
    return self.viewHeight / 2;
}






#pragma mark AdjustFrame

-(void)adjustFrame{
    self.frame = CGRectMake(kAdjust(self.x), kAdjust(self.y), kAdjust(self.viewWidth), kAdjust(self.viewHeight));
    [self adjustSubViewsFrameWithView:self];
}


-(void)adjustSubViewsFrameWithView:(UIView*)view{
    
    [view.subviews enumerateObjectsUsingBlock:^(__kindof UIView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        obj.frame = CGRectMake(kAdjust(obj.x), kAdjust(obj.y), kAdjust(obj.viewWidth), kAdjust(obj.viewHeight));
        
        [self adjustSubViewsFrameWithView:obj];
        
    }];

}

-(void)adjustFrameWithX:(BOOL)x Y:(BOOL)y W:(BOOL)w H:(BOOL)h AdjustSubViews:(BOOL)adjust{
    self.x      = x?kAdjust(self.x):self.x;
    self.y      = y?kAdjust(self.y):self.y;
    self.viewWidth  = w?kAdjust(self.viewWidth):self.viewWidth;
    self.viewHeight = h?kAdjust(self.viewHeight):self.viewHeight;
    if (adjust) {
        [self adjustSubViewsFrameWithView:self];
    }
}





-(void)adjustAllViewsX:(BOOL)x W:(BOOL)w
{
    self.x      = x?kAdjust(self.x):self.x;
    self.viewWidth  = w?kAdjust(self.viewWidth):self.viewWidth;
    
    [self adjustSubViewsX:x W:w withSuperView:self];
}


-(void)adjustSubViewsX:(BOOL)x W:(BOOL)w withSuperView:(UIView*)view{
    
    [view.subviews enumerateObjectsUsingBlock:^(__kindof UIView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        obj.x      = x?kAdjust(obj.x):obj.x;
        obj.viewWidth  = w?kAdjust(obj.viewWidth):obj.viewWidth;
        
        [self adjustSubViewsX:x W:w withSuperView:obj];
        
    }];
    
}







-(void)adjustFrameWithXScale:(CGFloat)scaleX YScale:(CGFloat)scaleY WScale:(CGFloat)scaleW HScale:(CGFloat)scaleH{
    [self.subviews enumerateObjectsUsingBlock:^(__kindof UIView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        obj.frame = CGRectMake(obj.x*scaleX, obj.y*scaleY, obj.viewWidth*scaleW, obj.viewHeight*scaleH);
    }];
}








@end
