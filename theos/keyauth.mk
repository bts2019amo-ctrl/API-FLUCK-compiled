# KeyAuth iOS SDK
#
# Copyright © 2026 Zexis. All rights reserved.
#
# Include from any Theos host (macOS, Linux, WSL, on-device).
# The .a is prebuilt — do NOT pass -mllvm / -fpass-plugin here.
#
#   KA_SDK ?= path/to/this/sdk
#   include $(KA_SDK)/theos/keyauth.mk
#
# Then one of: TWEAK_NAME / LIBRARY_NAME / TOOL_NAME / BUNDLE_NAME

KA_SDK ?= $(THEOS_PROJECT_DIR)/..

ifeq ($(KA_NAME),)
KA_NAME := $(firstword $(TWEAK_NAME) $(LIBRARY_NAME) $(TOOL_NAME) $(BUNDLE_NAME))
endif

ifeq ($(KA_NAME),)
  $(error Set TWEAK_NAME/LIBRARY_NAME or KA_NAME before including keyauth.mk)
endif

KA_A := $(KA_SDK)/lib/libKeyAuth.a
ifeq ($(wildcard $(KA_A)),)
  $(error missing $(KA_A) — use the shipped archive, do not rebuild it)
endif

$(KA_NAME)_CFLAGS  += -fobjc-arc -I$(KA_SDK)/include
$(KA_NAME)_CCFLAGS += -std=c++17 -fobjc-arc -fno-exceptions -fno-rtti -I$(KA_SDK)/include
$(KA_NAME)_LDFLAGS += -Wl,-force_load,$(KA_A) -lc++
$(KA_NAME)_FRAMEWORKS += UIKit Foundation Security CoreGraphics QuartzCore
$(KA_NAME)_LIBRARIES += c++
