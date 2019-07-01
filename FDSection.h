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

@property (nonatomic, copy) NSString *sectionHeaderIdent; //header的ident

@property (nonatomic, copy) NSString *sectionFooterIdent; //footer的ident

@property (nonatomic, copy) FDSectionHeaderHeight headerHeight; //headerView高度

@property (nonatomic, copy) FDSectionFooterHeight footerHeight; //footerView高度

@property (nonatomic, copy) FDSectionHeaderView sectionHeaderView;//返回对应headerView

@property (nonatomic, copy) FDSectionFooterView sectionFooterView;//返回对应footerView

@property (nonatomic, copy) FDSectionHeaderTitle sectionHeaderTitle; //headerTitle

@property (nonatomic, copy) FDSectionFooterTitle sectionFooterTitle; //footerTitle

/**
 初始化section

 @param headerClass header类
 @param footerClass footer类
 @return  instancetype
 */
- (instancetype)initSectionWithSectionHeaderClass:(nullable Class)headerClass sectionFooterClass:(nullable Class)footerClass;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 删除item
 */
- (void)removeAllItem;

- (void)removeItemWithIndex:(NSInteger)index;

- (void)remoVeItemWithArray:(NSArray <FDItem *>*)array;

- (void)removeItem:(FDItem *)item;


/**
 添加item
 */
- (void)addItem:(FDItem *)item;

- (void)insertItem:(FDItem *)item atIndex:(NSUInteger)idx;

- (void)addItemFromArray:(NSArray <FDItem *>*)array;


@end

NS_ASSUME_NONNULL_END
