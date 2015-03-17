//
//  WPAppAnalytics.h
//  WordPress
//
//  Created by Diego E. Rey Mendez on 3/16/15.
//  Copyright (c) 2015 WordPress. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString*(^WPAppAnalyticsLastVisibleScreenCallback)();

extern NSString* const WPAppAnalyticsDefaultsKeyUsageTracking;

/**
 *  @class      WPAppAnalytics
 *  @brief      This is a container for the app-specific analytics logic.
 *  @details    WPAnalytics is a generic component.  This component acts as a container for all
 *              of the WPAnalytics code that's specific to WordPress, interfacing with WPAnalytics
 *              where appropiate.  This is mostly useful to remove such app-specific logic from
 *              our app delegate class.
 */
@interface WPAppAnalytics : NSObject

#pragma mark - Init

- (instancetype)initWithLastVisibleScreenBlock:(WPAppAnalyticsLastVisibleScreenCallback)lastVisibleScreenCallback;

#pragma mark - App Tracking Events

/**
 *  @brief      Tracks that the application has been closed.
 *  
 *  @param      lastVisibleScreen       The name of the last visible screen.  Can be nil.
 */
- (void)trackApplicationClosed:(NSString*)lastVisibleScreen;

/**
 *  @brief      Tracks that the application has been opened.
 */
- (void)trackApplicationOpened;

#pragma mark - Usage tracking

/**
 *  @brief      Call this method to know if usage is being tracked.
 *
 *  @returns    YES if usage is being tracked, NO otherwise.
 */
- (BOOL)isTrackingUsage;

/**
 *  @brief      Sets usage tracking ON or OFF
 *
 *  @param      trackingUsage   The new status for usage tracking.
 */
- (void)setTrackingUsage:(BOOL)trackingUsage;

@end
