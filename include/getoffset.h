//
//  getoffset.h
//  KeyAuth iOS SDK
//
//  Copyright © 2026 Zexis. All rights reserved.
//
//  Server offset lookup. Names are whatever YOUR package stored on the server.
//

#ifndef GETOFFSET_H
#define GETOFFSET_H

#include <stdint.h>
#include <objc/objc.h>

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

uintptr_t GetOffset(const char *name);
int OffsetLoadedCount(void);
BOOL OffsetsReady(void);
void clearOffsets(void);

#ifdef __cplusplus
}
#endif

#endif
