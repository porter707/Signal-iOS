//
//  Copyright (c) 2017 Open Whisper Systems. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class OWSTableItem;
@class OWSTableSection;

@interface OWSTableContents : NSObject

@property (nonatomic) NSString *title;

- (void)addSection:(OWSTableSection *)section;

@end

#pragma mark -

@interface OWSTableSection : NSObject

@property (nonatomic, nullable) NSString *headerTitle;
@property (nonatomic, nullable) NSString *footerTitle;

+ (OWSTableSection *)sectionWithTitle:(nullable NSString *)title items:(NSArray<OWSTableItem *> *)items;

- (void)addItem:(OWSTableItem *)item;

@end

#pragma mark -

typedef NS_ENUM(NSInteger, OWSTableItemType) {
    OWSTableItemTypeDefault,
    OWSTableItemTypeAction,
};

typedef void (^OWSTableActionBlock)();
typedef UITableViewCell *_Nonnull (^OWSTableCustomCellBlock)();

@interface OWSTableItem : NSObject

+ (OWSTableItem *)itemWithTitle:(NSString *)title actionBlock:(nullable OWSTableActionBlock)actionBlock;

+ (OWSTableItem *)itemWithCustomCell:(UITableViewCell *)customCell
                     customRowHeight:(CGFloat)customRowHeight
                         actionBlock:(nullable OWSTableActionBlock)actionBlock;

+ (OWSTableItem *)itemWithCustomCellBlock:(OWSTableCustomCellBlock)customCellBlock
                          customRowHeight:(CGFloat)customRowHeight
                              actionBlock:(nullable OWSTableActionBlock)actionBlock;

+ (OWSTableItem *)itemWithCustomCellBlock:(OWSTableCustomCellBlock)customCellBlock
                              actionBlock:(nullable OWSTableActionBlock)actionBlock;

- (nullable UITableViewCell *)customCell;
- (NSNumber *)customRowHeight;

@end

#pragma mark -

@interface OWSTableViewController : UITableViewController

@property (nonatomic) OWSTableContents *contents;

#pragma mark - Presentation

- (void)presentFromViewController:(UIViewController *)fromViewController;

@end

NS_ASSUME_NONNULL_END
