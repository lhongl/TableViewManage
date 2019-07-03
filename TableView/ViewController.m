//
//  ViewController.m
//  TableView
//
//  Created by 飞渡 on 2019/7/3.
//  Copyright © 2019 freedo. All rights reserved.
//

#import "ViewController.h"
#import "FDTableViewManage.h"
#import "FDSection.h"
#import "FDItem.h"
@interface ViewController ()

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) FDTableViewManage *tableManager;

@property (nonatomic, strong) FDSection *section;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.tableView = [[UITableView alloc] init];
    self.tableView.tableFooterView = [UIView new];
    self.tableView.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    self.tableManager = [[FDTableViewManage alloc] initTableViewManage:self.tableView];
    [self.tableManager registerCellWithClass:[UITableViewCell class]];
    self.section = [FDSection section];
    [self.tableManager addSection:self.section];
    [self.view addSubview:self.tableView];
    [self loadData];
    // Do any additional setup after loading the view.
}

- (void)loadData{
    for (NSInteger i = 0; i < 10; i++) {
        FDItem *item = [[FDItem alloc] initWithData:nil cellClass:[UITableViewCell class]];
        item.rowHeight = 50;
        [self.section addItem:item];
    }
    [self.tableView reloadData];
}


@end
