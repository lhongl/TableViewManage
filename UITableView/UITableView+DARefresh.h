//
//  UITableView+DARefresh.h
//  ProjectTemplate
//
//  Created by lihongliang on 2019/6/28.
//  Copyright © 2019年 李宏亮. All rights reserved.
//



NS_ASSUME_NONNULL_BEGIN

@interface UITableView (DARefresh)

/**
 带下拉刷新的tableView
 
 @param headerBlock 刷新事件
 */
- (void)addHeaderRefresh:(void(^)(void))headerBlock;

/**
 带上拉加载的tableView
 
 @param footerBlock 刷新事件
 */
- (void)addFooterRefresh:(void(^)(void))footerBlock;

//带下拉和上拉的tableView

/**
 下拉上拉刷新

 @param headerBlock 下拉刷新
 @param footerBlock 上拉刷新
 */
- (void)addHeaderRefresh:(void (^)(void))headerBlock footerRefresh:(void (^)(void))footerBlock;

/**
 停止刷新
 */
- (void)stopRefresh;
@end

NS_ASSUME_NONNULL_END
