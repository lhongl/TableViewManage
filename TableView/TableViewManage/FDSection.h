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

@property (nonatomic, copy, readonly) NSString *sectionHeaderIdent;

@property (nonatomic, copy, readonly) NSString *sectionFooterIdent;

@property (nonatomic, assign) CGFloat heightForHeader; //headerView高度

@property (nonatomic, assign) CGFloat heightForFooter; //footerView高度

@property (nonatomic, copy) FDSectionTitleForHeader titleForHeader; //headerTitle

@property (nonatomic, copy) FDSectionTitleForFooter titleForFooter; //footerTitle

@property (nonatomic, copy) FDSectionWillDisplayHeaderView willDisplayHeaderView;

@property (nonatomic, copy) FDSectionWillDisplayFooterView willDisplayFooterView;

@property (nonatomic, copy) FDSectionDidEndDisplayingHeaderView didEndDisplayingHeaderView;

@property (nonatomic, copy) FDSectionDidEndDisplayingFooterView didEndDisplayingFooterView;

@property (nonatomic, copy) FDSectionCustomViewForHeader customViewForHeader;

@property (nonatomic, copy) FDSectionCustomViewForFooter customViewForFooter;


/**
 初始化section
 */

+ (instancetype)section;

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


// ***************************复用 返回headerView和footerView【下方法和属性配合使用】********************

/**
  FDSectionHeaderView和FDSectionFooterView
 【说明】- (void)dequeueReusableHeaderClass:(nullable Class)headerClass footerClass:(nullable Class)footerClass; 属性则无效
 */
@property (nonatomic, copy) FDSectionViewForHeader viewForHeader;//返回对应headerView

@property (nonatomic, copy) FDSectionViewForFooter viewForFooter;//返回对应footerView

/**
  复用header和footer
 @param headerClass header类
 @param footerClass footer类
 */
- (void)dequeueReusableHeaderClass:(nullable Class)headerClass footerClass:(nullable Class)footerClass;

@end

NS_ASSUME_NONNULL_END
