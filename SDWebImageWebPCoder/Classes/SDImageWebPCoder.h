/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#if __has_include(<SDWebImage/SDWebImage.h>)
#import <SDWebImage/SDWebImage.h>
#else
@import SDWebImage;
#endif
/*
#if __has_include("webp/decode.h") && __has_include("webp/encode.h") && __has_include("webp/demux.h") && __has_include("webp/mux.h")
#import "webp/decode.h"
#import "webp/encode.h"
#import "webp/demux.h"
#import "webp/mux.h"
#elif __has_include(<libwebp/decode.h>) && __has_include(<libwebp/encode.h>) && __has_include(<libwebp/demux.h>) && __has_include(<libwebp/mux.h>)
#import <libwebp/decode.h>
#import <libwebp/encode.h>
#import <libwebp/demux.h>
#import <libwebp/mux.h>
#else
@import libwebp;
#endif
*/
typedef struct _EncodeParam {
    void * _Nullable mux;
} EncodeParam;

@protocol WebPEncodeEx
- (EncodeParam* _Nullable) beginEncodeWith: (SDImageFormat)format;
- (BOOL) addFrameWith:(SDImageFrame* _Nonnull)frame parameter:(EncodeParam* _Nonnull)param options:(nullable SDImageCoderOptions *)options;
- (NSData* _Nullable) endEncode: (EncodeParam* _Nonnull) param :(int)loopCount;
@end

/**
 Built in coder that supports WebP and animated WebP
 */
@interface SDImageWebPCoder : NSObject <SDProgressiveImageCoder, SDAnimatedImageCoder, WebPEncodeEx>

@property (nonatomic, class, readonly, nonnull) SDImageWebPCoder *sharedCoder;

@end
