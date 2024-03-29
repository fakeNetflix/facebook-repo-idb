/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class FBCrashLogInfo;
@class FBTestBundleResult;
@class FBTestDaemonResult;
@class XCTestBootstrapError;

/**
 A Value Representing the end-result of a Test Run.
 The success or failure of a test run says nothing about the results of each individual test case.
 */
@interface FBTestManagerResult : NSObject

/**
 A Successful Test Run.

 @return a Successful Result.
 */
+ (instancetype)success;

/**
 A Result that indicates the client requested disconnection before the test manager had concluded.

 @return a Client Requested Disconnect Result.
 */
+ (instancetype)clientRequestedDisconnect;

/**
 A Test Run that Timed Out.

 @param timeout the Timeout in seconds.
 @return a Timeout Result
 */
+ (instancetype)timedOutAfter:(NSTimeInterval)timeout;

/**
 A Test Run in which the Bundle Connection Failed

 @param bundleResult the Bundle Result
 @return a Test Manger Result.
 */
+ (instancetype)bundleConnectionFailed:(FBTestBundleResult *)bundleResult;

/**
 A Test Run in which the Daemon Connection Failed

 @param daemonResult the Daemon Result
 @return a Test Manger Result.
 */
+ (instancetype)daemonConnectionFailed:(FBTestDaemonResult *)daemonResult;

/**
 A Test Run in which an internal error occured.

 @param error the internal error.
 @return an Internal Error Result.
 */
+ (instancetype)internalError:(XCTestBootstrapError *)error;

/**
 YES if the Test Manager finished successfully, NO otherwise.
 */
@property (nonatomic, assign, readonly) BOOL didEndSuccessfully;

/**
 The Underlying error, if an error occurred.
 */
@property (nonatomic, strong, nullable, readonly) NSError *error;

/**
 A Diagnostic for the Crash of a Test Host, if relevant.
 */
@property (nonatomic, strong, nullable, readonly) FBCrashLogInfo *crash;

@end

NS_ASSUME_NONNULL_END
