//
//  KAConfig.h
//  KeyAuth iOS SDK
//
//  Copyright © 2026 Zexis. All rights reserved.
//
//  Fill this in. Include it from EXACTLY one .mm in your project
//  (the file that also links libKeyAuth.a).
//
//  KA_ENABLED must stay 1. 0 is NOT a skip switch — the engine treats
//  it as tamper and fail-closes (error + crash). Auth always runs.
//

#ifndef KA_CONFIG_H
#define KA_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef KA_ENABLED
#define KA_ENABLED 1
#endif

#ifndef KA_PACKAGE_ID
#define KA_PACKAGE_ID ""
#endif

#ifndef KA_APP_ID
#define KA_APP_ID ""
#endif

#ifndef KA_PACKAGE_NAME
#define KA_PACKAGE_NAME ""
#endif

#ifndef KA_PACKAGE_VERSION
#define KA_PACKAGE_VERSION ""
#endif

#ifndef KA_PACKAGE_TOKEN
#define KA_PACKAGE_TOKEN "PUT_YOUR_PACKAGE_TOKEN_HERE"
#endif

#ifndef KA_DISPLAY_NAME
#define KA_DISPLAY_NAME "MyProduct"
#endif

#ifndef KA_LICENSE_KEY
#define KA_LICENSE_KEY ""
#endif

#ifndef KA_USE_OFFSETS
#define KA_USE_OFFSETS 1
#endif

#ifndef KA_OFFSET_NAMES
#define KA_OFFSET_NAMES ""
#endif

typedef struct {
    const char *package_id;
    const char *app_id;
    const char *package_name;
    const char *version;
    const char *token;
    const char *display_name;
    const char *license_key;
    const char *offset_names;
    int use_offsets;
    int enabled;
} KAUserConfig;

#ifdef KA_CONFIG_IMPL
extern const KAUserConfig KA_USER_CONFIG;
__attribute__((used, visibility("default")))
const KAUserConfig KA_USER_CONFIG = {
    KA_PACKAGE_ID,
    KA_APP_ID,
    KA_PACKAGE_NAME,
    KA_PACKAGE_VERSION,
    KA_PACKAGE_TOKEN,
    KA_DISPLAY_NAME,
    KA_LICENSE_KEY,
    KA_OFFSET_NAMES,
    KA_USE_OFFSETS,
    (KA_ENABLED == 1 ? (int)0xA91C7E55 : (int)0x51DEAD00)
};
#else
extern const KAUserConfig KA_USER_CONFIG;
#endif

#ifdef __cplusplus
}
#endif

#endif
