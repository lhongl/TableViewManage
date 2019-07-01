//
//  UITableView+DARefresh.m
//  ProjectTemplate
//
//  Created by lihongliang on 2019/6/28.
//  Copyright © 2019年 李宏亮. All rights reserved.
//

#import "UITableView+DARefresh.h"

@implementation UITableView (DARefresh)

- (void)addHeaderRefresh:(void(^)(void))headerBlock {
    MJRefreshNormalHeader *header = [MJRefreshNormalHeader headerWithRefreshingBlock:headerBlock];
    header.lastUpdatedTimeLabel.hidden = YES;
    [header setTitle:@"全力加载中 ..." forState:MJRefreshStateRefreshing];
    self.mj_header = header;
}

- (void)addFooterRefresh:(void(^)(void))footerBlock{
    MJRefreshBackNormalFooter *footer = [MJRefreshBackNormalFooter footerWithRefreshingBlock:footerBlock];
    [footer setTitle:@"" forState:MJRefreshStateNoMoreData];
     [footer setTitle:@"" forState:MJRefreshStateRefreshing];
    [footer setTitle:@"下拉加载更多" forState:MJRefreshStateIdle];
    [footer setTitle:@"全力加载中 ..." forState:MJRefreshStateWillRefresh];
    self.mj_footer = footer;
}

- (void)addHeaderRefresh:(void (^)(void))headerBlock footerRefresh:(void (^)(void))footerBlock{
    [self addHeaderRefresh:headerBlock];
    [self addFooterRefresh:footerBlock];
}

- (void)stopRefresh{
    [self.mj_footer endRefreshing];
    [self.mj_header endRefreshing];
}
@end
