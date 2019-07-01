//
//  FDItem.m
//  TSTST
//
//  Created by lihongliang on 2019/6/27.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import "FDItem.h"
#import "FDSection.h"
@interface FDItem ()
{
    id _data;
}

@property (nonatomic, copy) NSString *cellIdentifier;

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

- (NSString *)cellIdentifier{
    
    return _cellIdentifier;
}
@end
