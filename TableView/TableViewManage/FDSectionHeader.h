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

typedef CGFloat (^FDSectionHeaderHeight)(NSInteger section);//header高

typedef CGFloat (^FDSectionFooterHeight)(NSInteger section);//footer高

typedef void (^FDSectionHeaderView)(UIView *headerView ,NSInteger section);

typedef void *(^FDSectionFooterView)(UIView *headerView ,NSInteger section);

typedef NSString *(^FDSectionHeaderTitle)(NSInteger section); //header

typedef NSString * (^FDSectionFooterTitle)(NSInteger section); //footer


#endif /* FDSectionHeader_h */
