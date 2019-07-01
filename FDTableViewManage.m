//
//  FDTableViewManage.m
//  TSTST
//
//  Created by lihongliang on 2019/6/28.
//  Copyright © 2019 lihongliang. All rights reserved.
//

#import "FDTableViewManage.h"
@interface FDTableViewManage ()<UITableViewDataSource,UITableViewDelegate>

@property (nonatomic, strong) NSMutableArray <FDSection *>*dataArray;

@end
@implementation FDTableViewManage

#pragma mark 初始化
- (instancetype)initTableViewManage:(UITableView *)tableView {
    if (self = [super init]) {
        self.tableView = tableView;
        tableView.delegate = self;
        tableView.dataSource = self;
    }
    return self;
}

#pragma mark cell注册
- (void)registerCellWithNibName:(nonnull NSString *)nibName{
    [self.tableView registerNib:[UINib nibWithNibName:nibName bundle:nil] forCellReuseIdentifier:nibName];
}

- (void)registerCellWithClass:(nullable Class)cellClass{
    NSString *identifier = NSStringFromClass(cellClass);
    [self.tableView registerClass:cellClass forCellReuseIdentifier:identifier];
}

#pragma mark header和footer注册
- (void)registerHeaderFooterViewWithNibName:(nonnull NSString *)nibName{
    [self.tableView registerNib:[UINib nibWithNibName:nibName bundle:nil] forHeaderFooterViewReuseIdentifier:nibName];
}

- (void)registerHeaderFooterViewWithClass:(nullable Class)aClass{
    NSString *identifier = NSStringFromClass(aClass);
    [self.tableView registerClass:aClass forHeaderFooterViewReuseIdentifier:identifier];
}

#pragma mark 添加section
- (void)addSection:(FDSection *)section{
    if (!section) {
#ifdef DEBUG
        NSAssert(section, @"section Not Null");
#endif
        return;
    }
    [self.dataArray addObject:section];
}

- (void)addSection:(FDSection *)section atIndex:(NSUInteger)idx{
    if (!section) {
#ifdef DEBUG
        NSAssert(section, @"section Not Null");
#endif
        return;
    }
    
    if (self.dataArray.count < idx) {
#ifdef DEBUG
        NSAssert(NO, @"idx problem");
#endif
        return;
    }
     [self.dataArray insertObject:section atIndex:idx];
}

#pragma mark 删除section
- (void)removeAllSection{
    [self.dataArray removeAllObjects];
}

- (void)remoVeSection:(FDSection *)section{
    if (!section) {
        return;
    }
    [self.dataArray removeObject:section];
}

- (void)remoVeSectionatIndex:(NSUInteger)idx{
    if (self.dataArray.count <= idx) {
        return;
    }
    [self.dataArray removeObjectAtIndex:idx];
}

#pragma mark tableView代理
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    FDSection *fdSection = self.dataArray[section];
    return fdSection.itemList.count;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:item.cellIdentifier forIndexPath:indexPath];
    if (item.cellConfiguration) {
        item.cellConfiguration(self, cell, item);
    }
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    return item.rowHeight;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    if (item.didSelectRow) {
        item.didSelectRow(self, indexPath, item);
    }
}

- (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    if (item.didDeselectRow) {
        item.didDeselectRow(self, indexPath, item);
    }
}

- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    FDSection *fdSection = self.dataArray[section];
    if (fdSection.sectionHeaderIdent.length != 0) {
        UIView *headerView = [tableView dequeueReusableHeaderFooterViewWithIdentifier:fdSection.sectionHeaderIdent];
        if (fdSection.sectionHeaderView) {
            fdSection.sectionHeaderView(headerView, section);
        }
        return headerView;
    }
    return nil;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section{
    FDSection *fdSection = self.dataArray[section];
    if (fdSection.sectionHeaderTitle) {
        return fdSection.sectionHeaderTitle(section);
    }
    return nil;
}


- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    
    FDSection *fdSection = self.dataArray[section];
    return fdSection.headerHeight;
}


- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section{
    
    FDSection *fdSection = self.dataArray[section];
    if (fdSection.sectionFooterIdent.length != 0) {
        UIView *headerView = [tableView dequeueReusableHeaderFooterViewWithIdentifier:fdSection.sectionFooterIdent];
        if (fdSection.sectionFooterView) {
            fdSection.sectionFooterView(headerView, section);
        }
        return headerView;
    }
    
    return nil;
}

- (NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section{
    FDSection *fdSection = self.dataArray[section];
    if (fdSection.sectionFooterTitle) {
        return fdSection.sectionFooterTitle(section);
    }
    return nil;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section{
    
    FDSection *fdSection = self.dataArray[section];
    return fdSection.footerHeight;
}

- (NSArray*)tableView:(UITableView *)tableView editActionsForRowAtIndexPath:(nonnull NSIndexPath *)indexPath
{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    if (item.editActions) {
        return item.editActions(self,indexPath,item);
    }
    return nil;
}

- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath{
    FDSection *fdSection = self.dataArray[indexPath.section];
    FDItem *item  = fdSection.itemList[indexPath.row];
    if (item.editActions) {
        return YES;
    }
    return NO;
}

#pragma mark 懒加载
- (NSMutableArray <FDSection *>*)dataArray{
    if (!_dataArray) {
        _dataArray = [NSMutableArray array];
    }
    return _dataArray;
}


@end
