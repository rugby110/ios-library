/*
 Copyright 2009-2015 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

@class UAInboxMessage;
@class UAInboxMessageList;

NS_ASSUME_NONNULL_BEGIN

/**
 * This protocol defines a delegate method that is called
 * when a push notification arrives with a rich push message ID
 * embedded in its payload.
 */
 __attribute__((deprecated("As of version 6.1.0. Implement UAInboxDelegate and set it directly on the UAInbox.")))
@protocol UAInboxPushHandlerDelegate <NSObject>

@required

/**
 * Handle an incoming rich push notification.
 * @param notification An NSDictionary with the push notification contents.
 */
- (void)richPushNotificationArrived:(NSDictionary *)notification;


/**
 * Handle a rich push notification that launched the application.
 * @param notification An NSDictionary with the push notification contents.
 */
- (void)applicationLaunchedWithRichPushNotification:(NSDictionary *)notification;


/**
 * Called when a new Rich Push message is available for viewing.
 * @param richPushMessage The Rich Push message
 */
- (void)richPushMessageAvailable:(UAInboxMessage *)richPushMessage;

/**
 * Called when a Rich Push message associated with the push that launched the application
 * is available for viewing.
 *
 * @param richPushMessage The Rich Push message
 */
- (void)launchRichPushMessageAvailable:(UAInboxMessage *)richPushMessage;

/**
 * Called when the inbox message is requested to be displayed.
 * @param inboxMessage The inbox message.
 */
- (void)showInboxMessage:(UAInboxMessage *)inboxMessage;

/**
 * Called when the inbox is requested to be displayed.
 */
- (void)showInbox;

@end

/**
 * This class handles incoming rich push messages that are sent with
 * an APNS notification.
 */
__attribute__((deprecated("As of version 6.1.0.")))
@interface UAInboxPushHandler : NSObject

/**
 * YES if the most recent rich push launched the app, NO otherwise.
 */
@property (nonatomic, assign) BOOL hasLaunchMessage;

/**
 * The message ID of the most recent rich push as an NSString.
 */
@property (nonatomic, copy, readonly, nullable) NSString *viewingMessageID;

/**
 * The delegate that should be notified when an incoming push is handled,
 * as an object conforming to the UAInboxPushHandlerDelegate protocol.
 * NOTE: The delegate is not retained.
 */
@property (nonatomic, weak, nullable) id <UAInboxPushHandlerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
