//
//  FDItem.m
//  TSTST
//
//  Created by lihongliang on 2019/6/27.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import "FDItem.h"
#import "FDSection.h"
#import "FDTableViewManage.h"
@interface FDItem ()
{
    id _data;
}

@property (nonatomic, copy) NSString *identifier;

@end

@implementation FDItem

- (instancetype)initWithData:(nullable id)data cellClass:(Class)cellClass{
    if (self = [super init]) {
        self.rowHeight = 44;
        _data = data;
        NSString *cellIdent = NSStringFromClass(cellClass);
        self.identifier = cellIdent;
    }
    return self;
}

- (id)data{
    return _data;
}

- (NSString *)cellIdentifier{
    
    return self.identifier;
}

- (NSIndexPath *)indexPath{
  
    return [NSIndexPath indexPathForRow:[self.section.itemList indexOfObject:self] inSection:[self.section.tableManage.sections indexOfObject:self.section]];
}

/**
 如果使用可以在子类中调用
 */
- (void)tableViewManage:(FDTableViewManage *)tableViewManage cell:(__kindof UITableViewCell *)cell{
    
}
@end
