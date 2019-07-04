//
//  FDItem.h
//  TSTST
//
//  Created by lihongliang on 2019/6/27.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "FDItemHeader.h"
@class FDTableViewManage;
NS_ASSUME_NONNULL_BEGIN

@interface FDItem : NSObject

@property (nonatomic, copy, readonly) NSString *cellIdentifier;

@property (nonatomic, assign) CGFloat rowHeight;

@property (nonatomic, copy) FDItemCellConfiguration cellConfiguration; //加载数据

@property (nonatomic, copy) FDItemDidSelectRow didSelectRow; //点击

@property (nonatomic, copy) FDItemDidDeselectRow didDeselectRow; //已经点击

@property (nonatomic, copy) FDItemWillDisplayCellRow willDisplayCellRow;

@property (nonatomic, copy) FDItemDidEndDisplayingCell didEndDisplayingCellRow;

@property (nonatomic, copy) FDItemEditActions editActions; //侧滑

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 初始化

 @param data 数据源
 @param cellClass cell类
 @return return
 */
- (instancetype)initWithData:(nullable id)data cellClass:(nullable Class)cellClass;

/**
 返回数据
 */
- (id)data;

@end

NS_ASSUME_NONNULL_END
