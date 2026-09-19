//
//  Tweak.mm
//  KeyAuth iOS SDK — demo
//
//  Copyright © 2026 Zexis. All rights reserved.
//

#define KA_CONFIG_IMPL 1
#import "KAConfig.h"
#import "KALicense.h"
#import "getoffset.h"

// After KAIsReady(), look up whatever names YOUR package stored on the server:
//   uintptr_t v = GetOffset("your_name");
//
// Gate your menu / features:
//   if (!KAIsReady()) return;
