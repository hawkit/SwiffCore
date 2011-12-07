/*
    SwiftMovieView.h
    Copyright (c) 2011, musictheory.net, LLC.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of musictheory.net, LLC nor the names of its contributors
          may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL MUSICTHEORY.NET, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <SwiftImport.h>
#import <SwiftBase.h>
#import <SwiftMovieLayer.h>

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR || TARGET_HAS_UIKIT
#define SwiftMovieViewUsesUIKit 1
#endif

#if SwiftMovieViewUsesUIKit
#import <UIKit/UIKit.h>
#define SwiftMovieViewSuperclass UIView
#else
#import <AppKit/AppKit.h>
#define SwiftMovieViewSuperclass NSView
#endif


@class SwiftLayer, SwiftMovie, SwiftFrame, SwiftPlayhead;
@class SwiftMovieLayer, SwiftSpriteLayer;

@protocol SwiftMovieViewDelegate;

@interface SwiftMovieView : SwiftMovieViewSuperclass <SwiftMovieLayerDelegate> {
@private
    id<SwiftMovieViewDelegate> m_delegate;
    SwiftMovieLayer *m_movieLayer;
    
    BOOL m_delegate_movieView_willDisplayFrame;
    BOOL m_delegate_movieView_didDisplayFrame;
    BOOL m_delegate_movieView_spriteLayer_shouldInterpolateFromFrame_toFrame;
}

@property (nonatomic, retain) SwiftMovie *movie;

@property (nonatomic, assign) id<SwiftMovieViewDelegate> delegate;
@property (nonatomic, assign) BOOL drawsBackground;
@property (nonatomic, assign) BOOL usesSublayers;
@property (nonatomic, assign) CGAffineTransform baseAffineTransform;
@property (nonatomic, assign) SwiftColorTransform baseColorTransform;

@property (nonatomic, retain, readonly) SwiftMovieLayer *layer;
@property (nonatomic, retain, readonly) SwiftPlayhead *playhead;


@end


@protocol SwiftMovieViewDelegate <NSObject>
@optional
- (void) movieView:(SwiftMovieView *)movieView willDisplayFrame:(SwiftFrame *)frame;
- (void) movieView:(SwiftMovieView *)movieView didDisplayFrame:(SwiftFrame *)frame;
- (BOOL) movieView:(SwiftMovieView *)movieView spriteLayer:(SwiftSpriteLayer *)spriteLayer shouldInterpolateFromFrame:(SwiftFrame *)fromFrame toFrame:(SwiftFrame *)toFrame;
@end
