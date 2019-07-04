//
//  FDItemHeader.h
//  BuildGuard
//
//  Created by 飞渡 on 2019/7/4.
//  Copyright © 2019 com.ddg. All rights reserved.
//

#ifndef FDItemHeader_h
#define FDItemHeader_h
@class FDTableViewManage,FDItem;
#import <Foundation/Foundation.h>

typedef void (^FDItemCellConfiguration)(__kindof FDTableViewManage *tableVieManager,__kindof UITableViewCell *cell,__kindof FDItem *item);

typedef void (^FDItemDidSelectRow)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item);

typedef void (^FDItemDidDeselectRow)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item);

typedef void (^FDItemWillDisplayCellRow)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item,__kindof UITableViewCell *cell);

typedef NSArray <UITableViewRowAction *> *(^FDItemEditActions)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item);

typedef void (^FDItemDidEndDisplayingCell)(__kindof FDTableViewManage *tableVieManager, __kindof NSIndexPath *indexPath,__kindof FDItem *item,__kindof UITableViewCell *cell);

#endif /* FDItemHeader_h */
