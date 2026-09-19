//
//  KAConfig.h
//  KeyAuth iOS SDK — demo
//
//  Copyright © 2026 Zexis. All rights reserved.
//
//  Copy this pattern into your own project.
//  Token stays in THIS header (never baked into libKeyAuth.a).
//  Include from EXACTLY one .mm with #define KA_CONFIG_IMPL 1 first.
//

#ifndef KA_ENABLED
#define KA_ENABLED 1
#endif

#define KA_PACKAGE_ID      "your_package"
#define KA_APP_ID          "com.yourname.com"
#define KA_PACKAGE_NAME    "YourProduct"
#define KA_PACKAGE_VERSION "1.0"
#define KA_PACKAGE_TOKEN   "PUT_YOUR_PACKAGE_TOKEN_HERE"
#define KA_DISPLAY_NAME    "YourProduct"
#define KA_LICENSE_KEY     ""
#define KA_USE_OFFSETS     1

#import "../include/KAConfig.h"
