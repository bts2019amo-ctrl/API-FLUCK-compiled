# KeyAuth iOS SDK

License validation for iOS jailbreak tweaks. **Binary only** — engine source is not in this repository.

The engine lives in `lib/libKeyAuth.a` and **starts itself**. You do not add a constructor or bootstrap file. Fill in the headers, `-force_load` the archive, done.

---

## Buy a package / subscription

Get a package, keys, and a dashboard at **[fluckv2.org](https://fluckv2.org)**.

That site is where you create the package, copy `KA_PACKAGE_ID` / `KA_APP_ID` / version / token, and issue license keys. This GitHub repo is the iOS SDK only — it does not sell plans.

---

## What you get

| Path | What it is |
|------|------------|
| `lib/libKeyAuth.a` | Prebuilt engine (fat **arm64** + **arm64e**). Auto-runs package check, key UI, seals, offset download. |
| `include/KAConfig.h` | **Your** package id / app id / version / token. Include from **exactly one** `.mm` with `#define KA_CONFIG_IMPL 1`. Token is never inside the `.a`. |
| `include/KALicense.h` | Public status API: `KAIsLicensed`, `KAIsReady`, expiry, ban, `KAGetOffset`. |
| `include/getoffset.h` | `GetOffset("name")` / `OffsetsReady()` / `OffsetLoadedCount()`. Names are whatever **your** package stored on the server. |
| `theos/keyauth.mk` | Optional Theos include: force-load + frameworks. |
| `demo/` | Sample Theos dylib. Copy the pattern; replace placeholders. |

Do **not** expect engine `.mm` files. There are none.

---

## Headers (the only API)

### `KAConfig.h`

Macros you set **before** the import (or in a small wrapper header like the demo):

| Macro | Required | Example |
|-------|----------|---------|
| `KA_PACKAGE_ID` | yes | `"your_package"` |
| `KA_APP_ID` | yes | `"com.yourname.com"` |
| `KA_PACKAGE_NAME` | yes | `"YourProduct"` |
| `KA_PACKAGE_VERSION` | yes | `"1.0"` |
| `KA_PACKAGE_TOKEN` | yes | HMAC token from **your** dashboard — per package, never share one bake |
| `KA_DISPLAY_NAME` | no | shown in the built-in UI |
| `KA_LICENSE_KEY` | no | leave empty; user enters / keychain saves a **valid** key |
| `KA_USE_OFFSETS` | no | `1` download offsets, `0` skip |
| `KA_ENABLED` | yes | **must be `1`**. `0` is tamper (crash), not a skip switch |

### `KALicense.h`

```objc
KASetLicenseKey(@"YOURKEY");   // persist + re-validate
KAIsLicensed();                // package + key ok
KAIsReady();                   // licensed, and offsets if enabled
KACurrentKey();
KAExpiryString();
KARemainingSeconds();
KAStatusText();
KAPackageName();
KADisplayName();
KAGetOffset("your_name");      // 0 until ready
KAOffsetCount();
IsDeviceBanned();
```

Gate your menu on `KAIsLicensed()` / `KAIsReady()`, not on a local flag.

### `getoffset.h`

```objc
uintptr_t v = GetOffset("your_name");  // 0 until package + key (+ offsets) succeed
BOOL OffsetsReady(void);
int OffsetLoadedCount(void);
```

There is no shared `offsets.h`. Each package has its own names on the server.

---

## Integrate (Theos)

In **exactly one** `.mm`:

```objc
#define KA_CONFIG_IMPL 1
#import "KAConfig.h"
#import "KALicense.h"
#import "getoffset.h"
```

Makefile:

```make
TWEAK_NAME = YourTweak
$(TWEAK_NAME)_FILES = Tweak.mm
include path/to/sdk/theos/keyauth.mk
```

Or without the helper:

```make
$(TWEAK_NAME)_CFLAGS  += -fobjc-arc -Ipath/to/sdk/include
$(TWEAK_NAME)_CCFLAGS += -std=c++17 -fobjc-arc -Ipath/to/sdk/include
$(TWEAK_NAME)_LDFLAGS += -Wl,-force_load,path/to/sdk/lib/libKeyAuth.a -lc++
$(TWEAK_NAME)_FRAMEWORKS += UIKit Foundation Security CoreGraphics QuartzCore
```

`-force_load` is required so the constructor is not dropped.

Do **not** run OLLVM / obfuscator passes on **your** dylib for this SDK. The `.a` is already processed.

Works on macOS, Linux, WSL, and on-device Theos.

---

## Demo

```bash
# edit demo/KAConfig.h — put YOUR token and com.yourname.com style app id
cd demo && make
```

Placeholders in `demo/KAConfig.h`:

```objc
#define KA_PACKAGE_ID      "your_package"
#define KA_APP_ID          "com.yourname.com"
#define KA_PACKAGE_NAME    "YourProduct"
#define KA_PACKAGE_VERSION "1.0"
#define KA_PACKAGE_TOKEN   "PUT_YOUR_PACKAGE_TOKEN_HERE"
```

On GitHub clones, use the shipped `lib/libKeyAuth.a`. Do not look for engine source.

---

## Kill switch

Package status is checked on the server. Disable the package or rotate the token and clients fail closed even if someone patches a local BOOL.

---

## MYDash

**MYDash.ipa** — dashboard for developers. Keys, bans, packages.

| Loading | Login |
|:-------:|:-----:|
| ![Loading](Images/Loading.jpg) | ![Login](Images/Login.jpg) |

| Key Creation | Home |
|:-------------:|:----:|
| ![Key Creation](Images/KeyCreation.jpg) | ![Home](Images/Home.jpg) |

---

## Contact

- **Website / buy:** [fluckv2.org](https://fluckv2.org)
- **Discord:** @zexisyy_
- **Telegram:** @zexisyy

---

## Credits

See [CREDITS.md](CREDITS.md).

---

## License

Copyright © 2026 Zexis. All rights reserved. Proprietary. Use only as permitted by the provider.
