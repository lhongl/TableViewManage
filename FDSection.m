//
//  FDSection.m
//  TSTST
//
//  Created by lihongliang on 2019/6/27.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import "FDSection.h"
@interface FDSection ()

@property (nonatomic, strong) NSMutableArray <FDItem *> *dataArray;

@end

@implementation FDSection

- (instancetype)initSectionWithSectionHeaderClass:(nullable Class)headerClass sectionFooterClass:(nullable Class)footerClass{
    if (self = [super init]) {
        if (headerClass) {
          NSString *headerIdentifier = NSStringFromClass(headerClass);
          self.sectionHeaderIdent = headerIdentifier;
        }
        if (footerClass) {
            NSString *footerIdentifier = NSStringFromClass(footerClass);
            self.sectionFooterIdent = footerIdentifier;
        }
    }
    return self;
}

#pragma mark 删除item
- (void)removeAllItem{
    [self.dataArray removeAllObjects];
}

- (void)removeItemWithIndex:(NSInteger)index{
    if (self.dataArray.count < index) {
        [self.dataArray removeObjectAtIndex:index];
    }
}

- (void)remoVeItemWithArray:(NSArray <FDItem *>*)array{
    if (array.count == 0) {
        return;
    }
    [self.dataArray removeObjectsInArray:array];
}

- (void)removeItem:(FDItem *)item{
    
    if (!item) {
#ifdef DEBUG
      NSAssert(item, @"item not Null");
#endif
        return;
    }
    [self.dataArray removeObject:item];
}

#pragma mark itemList
- (NSArray <FDItem *> *)itemList{

    return _dataArray;
}

#pragma mark 添加item
- (void)addItem:(FDItem *)item{
#ifdef DEBUG
   NSAssert(item, @"item not Null");
#endif
    if (!item) {
        return;
    }
    [self.dataArray addObject:item];
}

- (void)insertItem:(FDItem *)item atIndex:(NSUInteger)idx{
    if (!item) {
#ifdef DEBUG
        NSAssert(item, @"item Not Null");
#endif
        return;
    }
    
    if (self.dataArray.count < idx) {
#ifdef DEBUG
        NSAssert(NO, @"idx Not problem");
#endif
        return;
    }
    [self.dataArray insertObject:item atIndex:idx];
}

- (void)addItemFromArray:(NSArray <FDItem *>*)array{
    if (array.count == 0) {
        return;
    }
    [self.dataArray addObjectsFromArray:array];
}

#pragma mark 懒加载
- (NSMutableArray <FDItem *>*)dataArray{
    if (!_dataArray) {
        _dataArray = [NSMutableArray array];
    }
    return _dataArray;
}

@end
