//
//  FDTableViewManage.h
//  TSTST
//
//  Created by lihongliang on 2019/6/28.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FDSection.h"
#import "FDItem.h"
NS_ASSUME_NONNULL_BEGIN

@interface FDTableViewManage : NSObject

@property (nonatomic, weak) UITableView *tableView;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 初始化tableView
 
 @param tableView tableView
 */
- (instancetype)initTableViewManage:(UITableView *)tableView;

/**
 cell注册
 
 @param nibName nib名字
 */
- (void)registerCellWithNibName:(nonnull NSString *)nibName;

/**
 cell注册
 
 @param cellClass 类名
 */
- (void)registerCellWithClass:(nullable Class)cellClass;

/**
 header和footer注册
 
 @param nibName nib名字
 */
- (void)registerHeaderFooterViewWithNibName:(nonnull NSString *)nibName;

/**
 header和footer注册
 
 @param aClass 类名
 */
- (void)registerHeaderFooterViewWithClass:(nullable Class)aClass;


/**
 添加section
 
 @param section 添加section
 */
- (void)addSection:(nullable FDSection *)section;

- (void)addSection:(nullable FDSection *)section atIndex:(NSUInteger)idx;

/**
 删除
 */
- (void)remoVeSection:(nullable FDSection *)section;

- (void)removeAllSection;

- (void)remoVeSectionatIndex:(NSUInteger)idx;

@end

NS_ASSUME_NONNULL_END
