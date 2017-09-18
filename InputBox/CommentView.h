//
//  CommentView.h
//  GuDaShi
//
//  Created by LOLITA on 2017/9/4.
//  Copyright © 2017年 songzhaojie. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+AdjustFrame.h"
#import "MyMacro.h"

@protocol CommentViewDelegate;

@interface CommentView : UIView

@property (weak, nonatomic) IBOutlet UITextView *commentTV;

@property (weak, nonatomic) IBOutlet UILabel *tipLabel; // 提示

@property (weak, nonatomic) IBOutlet UIButton *senderBtn;

@property (nonatomic,weak) id <CommentViewDelegate> delegate;

@end


@protocol CommentViewDelegate <NSObject>

@optional
-(void)commentView:(CommentView*)commentView sendMessage:(NSString*)message complete:(void(^)(BOOL success))completeBlock;

@end
