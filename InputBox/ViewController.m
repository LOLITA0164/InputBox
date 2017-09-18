//
//  ViewController.m
//  InputBox
//
//  Created by LOLITA on 2017/9/18.
//  Copyright © 2017年 LOLITA0164. All rights reserved.
//

#import "ViewController.h"
#import "CommentView.h"

@interface ViewController ()<CommentViewDelegate>

@property (strong ,nonatomic) CommentView *commentTool;
@property (strong ,nonatomic) UILabel *label;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.view addSubview:self.label];
    
    [self.view addSubview:self.commentTool];
}





-(UILabel *)label{
    if (_label==nil) {
        _label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, kScreenWidth, kScreenHeight/2.0)];
        _label.numberOfLines = 0;
        _label.textAlignment = NSTextAlignmentCenter;
    }
    return _label;
}







-(CommentView *)commentTool{
    if (_commentTool==nil) {
        NSArray *itemArray = [[NSBundle mainBundle] loadNibNamed:@"CommentView" owner:nil options:nil];
        for (id item in itemArray) {
            if ([item isMemberOfClass:[CommentView class]]) {
                _commentTool = item;
                _commentTool.y = kScreenHeight - _commentTool.viewHeight;
                _commentTool.delegate = self;
            }
        }
    }
    return _commentTool;
}


// !!!: 评论的代理
-(void)commentView:(CommentView *)commentView sendMessage:(NSString *)message complete:(void (^)(BOOL))completeBlock{
    DLog(@"评论：%@",message);
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.label.text = message;
        // 收起键盘
        completeBlock(YES); // 发送成功时
//        completeBlock(NO); // 发送失败时
    });
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
