//
//  MSRunLoopTaskQueue.h
//  MSUIKit
//
//  Created by changsanjiang@gmail.com on 07/17/2018.
//  Copyright (c) 2018 changsanjiang@gmail.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^MSRunLoopTaskHandler)(void);

@interface MSRunLoopTaskQueue : NSObject
@property (class, nonatomic, copy, readonly) MSRunLoopTaskQueue *(^queue)(NSString *name);
@property (class, nonatomic, copy, readonly) MSRunLoopTaskQueue *main;
@property (class, nonatomic, copy, readonly) void(^destroy)(NSString *name);

/// 每执行一次任务, 延迟多少次RunLoop
@property (nonatomic, copy, readonly) MSRunLoopTaskQueue *_Nullable(^delay)(NSUInteger num);
@property (nonatomic, copy, readonly) MSRunLoopTaskQueue *_Nullable(^update)(CFRunLoopRef rlr, CFRunLoopMode mode);
/// enqueue, Add a task to the queue.
///
/// - This task will be execute when the corresponding RunLoop is idle
@property (nonatomic, copy, readonly) MSRunLoopTaskQueue *_Nullable(^enqueue)(MSRunLoopTaskHandler task);
/// dequeue, This method will delete the first task in the queue.
///
/// - The first task will not be executed.
@property (nonatomic, copy, readonly) MSRunLoopTaskQueue *_Nullable(^dequeue)(void);
/// empty the tasks in the queue.
@property (nonatomic, copy, readonly) MSRunLoopTaskQueue *_Nullable(^empty)(void);
/// destroy queue.
@property (nonatomic, copy, readonly) void(^destroy)(void); 

@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic, readonly) NSInteger count;
@end
NS_ASSUME_NONNULL_END
