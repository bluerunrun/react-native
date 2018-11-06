/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <React/RCTView.h>

@class RCTWebView;

/**
 * Special scheme used to pass messages to the injectedJavaScript
 * code without triggering a page load. Usage:
 *
 *   window.location.href = RCTJSNavigationScheme + '://hello'
 */
extern NSString *const RCTJSNavigationScheme;

@protocol RCTWebViewDelegate <NSObject>

- (BOOL)webView:(RCTWebView *)webView
shouldStartLoadForRequest:(NSMutableDictionary<NSString *, id> *)request
   withCallback:(RCTDirectEventBlock)callback;

@end

static NSString *BRIDGE_NAME = @"__REACT_WEB_VIEW_BRIDGE";

@interface RCTWebView : RCTView

@property (nonatomic, weak) id<RCTWebViewDelegate> delegate;

@property (nonatomic, copy) NSDictionary *source;
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) BOOL automaticallyAdjustContentInsets;
@property (nonatomic, assign) BOOL messagingEnabled;
@property (nonatomic, copy) NSString *injectedJavaScript;
@property (nonatomic, assign) BOOL scalesPageToFit;

- (void)goForward;
- (void)goBack;
- (void)reload;
- (void)stopLoading;
- (void)postMessage:(NSString *)message;
- (void)injectJavaScript:(NSString *)script;

@end


/**
 * webview 加载的离线资源的单例  用于存储webview应加载离线资源的路径
 */

@interface RCTWebViewPathSingleton : NSObject
// 添加新属性 资源加载路径
@property (nonatomic,copy) NSString *srcPath;
+ (RCTWebViewPathSingleton *)sharedSingleton;

@end
