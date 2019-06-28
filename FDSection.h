//
//  FDSection.h
//  TSTST
//
//  Created by 飞渡 on 2019/6/27.
//  Copyright © 2019 freedo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FDItem.h"
NS_ASSUME_NONNULL_BEGIN

@interface FDSection : NSObject

@property (nonatomic, strong, readonly) NSArray <FDItem *> *itemList;

@property (nonatomic, assign) CGFloat headerHeight; //headerView高度

@property (nonatomic, copy) UIView * (^sectionHeaderView)(NSInteger section);//与系统注册对应headerView

@property (nonatomic, assign) CGFloat footerHeight; //footerView高度

@property (nonatomic, copy) UIView * (^sectionFooterView)(NSInteger section);//与系统注册对应footerView

@property (nonatomic, copy) NSString * (^sectionHeaderTitle)(NSInteger section); //header

@property (nonatomic, copy) NSString * (^sectionFooterTitle)(NSInteger section); //footer

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
