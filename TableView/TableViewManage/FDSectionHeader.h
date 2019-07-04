//
//  FDSectionHeader.h
//  TestAPP
//
//  Created by 飞渡 on 2019/7/1.
//  Copyright © 2019 freedo. All rights reserved.
//

#ifndef FDSectionHeader_h
#define FDSectionHeader_h
#import <Foundation/Foundation.h>

typedef void (^FDSectionViewForHeader)(UIView *headerView ,NSInteger section); 

typedef void *(^FDSectionViewForFooter)(UIView *headerView ,NSInteger section);

typedef NSString *(^FDSectionTitleForHeader)(NSInteger section); //header

typedef NSString * (^FDSectionTitleForFooter)(NSInteger section); //footer

typedef UIView * (^FDSectionCustomViewForHeader)(NSInteger section); //headerView

typedef UIView * (^FDSectionCustomViewForFooter)(NSInteger section); //footerView

typedef void (^FDSectionWillDisplayHeaderView)(NSInteger section,UIView *view);

typedef void (^FDSectionWillDisplayFooterView)(NSInteger section,UIView *view);

typedef void (^FDSectionDidEndDisplayingHeaderView)(NSInteger section,UIView *view);

typedef void (^FDSectionDidEndDisplayingFooterView)(NSInteger section,UIView *view);

#endif /* FDSectionHeader_h */
