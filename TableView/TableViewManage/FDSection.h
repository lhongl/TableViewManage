//
//  FDSection.h
//  TSTST
//
//  Created by lihongliang on 2019/6/27.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FDItem.h"
#import "FDSectionHeader.h"
NS_ASSUME_NONNULL_BEGIN

@interface FDSection : NSObject

@property (nonatomic, strong, readonly) NSArray <FDItem *> *itemList;

@property (nonatomic, assign) CGFloat headerHeight; //headerView高度

@property (nonatomic, assign) CGFloat footerHeight; //footerView高度

@property (nonatomic, copy) FDSectionHeaderView sectionHeaderView;//返回对应headerView

@property (nonatomic, copy) FDSectionFooterView sectionFooterView;//返回对应footerView

@property (nonatomic, copy) FDSectionHeaderTitle sectionHeaderTitle; //headerTitle

@property (nonatomic, copy) FDSectionFooterTitle sectionFooterTitle; //footerTitle

/**
 初始化section
 */

+ (instancetype)section;

/**
 @param headerClass header类
 @param footerClass footer类
 */
- (void)dequeueReusableHeaderClass:(nullable Class)headerClass footerClass:(nullable Class)footerClass;

/**
 删除item
 */
- (void)removeAllItem;

- (void)removeItemWithIndex:(NSInteger)index;

- (void)remoVeItemWithArray:(NSArray <FDItem *>*)array;

- (void)removeItem:(nullable FDItem *)item;


/**
 添加item
 */
- (void)addItem:(nullable FDItem *)item;

- (void)insertItem:(nullable FDItem *)item atIndex:(NSUInteger)idx;

- (void)addItemFromArray:(NSArray <FDItem *>*)array;

/**
 获取section footer 注册idnet
 */
- (NSString *)sectionFooterIdent;

/**
 获取section header 注册idnet
 */
- (NSString *)sectionHeaderIdent;
@end

NS_ASSUME_NONNULL_END
