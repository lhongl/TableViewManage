//
//  FDItem.m
//  TSTST
//
//  Created by 飞渡 on 2019/6/27.
//  Copyright © 2019 freedo. All rights reserved.
//

#import "FDItem.h"
#import "FDSection.h"
@interface FDItem ()
{
    id _data;
}
@end

@implementation FDItem

- (instancetype)initWithData:(id)data cellClass:(nullable Class)cellClass{
    if (self = [super init]) {
        self.rowHeight = 44;
        _data = data;
        NSString *cellIdent = NSStringFromClass(cellClass);
        self.cellIdentifier = cellIdent;
    }
    return self;
}

- (id)data{
    return _data;
}
@end
