//
//  NSString+MSBornPlumeExtended.h
//  Pods
//
//  Created by admin on 2019/12/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface NSString (MSBornPlumeExtended)

+ (instancetype)stringWithCurrentTime:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration;

@end
NS_ASSUME_NONNULL_END
