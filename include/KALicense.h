//
//  KALicense.h
//  KeyAuth iOS SDK
//
//  Copyright © 2026 Zexis. All rights reserved.
//
//  Read-only license / offset status. Implementation lives in libKeyAuth.a
//

#ifndef KA_LICENSE_H
#define KA_LICENSE_H

#import <Foundation/Foundation.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL KAIsLicensed(void);
BOOL KAIsReady(void);
BOOL IsLicenseValid(void);
BOOL IsDeviceBanned(void);
void KASetLicenseKey(NSString *key);

NSString *KACurrentKey(void);
NSString *KAExpiryString(void);
NSTimeInterval KARemainingSeconds(void);
NSString *KAStatusText(void);
NSString *KAPackageName(void);
NSString *KADisplayName(void);

uintptr_t KAGetOffset(const char *name);
int KAOffsetCount(void);

#ifdef __cplusplus
}
#endif

#endif
