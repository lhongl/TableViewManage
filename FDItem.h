//
//  FDItem.h
//  TSTST
//
//  Created by 飞渡 on 2019/6/27.
//  Copyright © 2019 freedo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class FDTableViewManage;
NS_ASSUME_NONNULL_BEGIN

@interface FDItem : NSObject

@property (nonatomic, assign) CGFloat rowHeight;

@property (nonatomic, copy) NSString *cellIdentifier;

@property (nonatomic, copy) void (^cellConfiguration)(__kindof FDTableViewManage *tableVieManager,__kindof UITableViewCell *cell,__kindof FDItem *item); //加载数据

@property (nonatomic, copy) void (^didSelectRow)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item); //点击

@property (nonatomic, copy) void (^didDeselectRow)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item); //点击

@property (nonatomic, copy) NSArray <UITableViewRowAction *> *(^editActions)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item); //侧滑

- (instancetype)init UNAVAILABLE_ATTRIBUTE;

- (instancetype)initWithData:(id)data cellClass:(nullable Class)cellClass;

/**
 返回数据
 */
- (id)data;
@end

NS_ASSUME_NONNULL_END
