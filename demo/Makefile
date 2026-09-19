# Portable Theos demo. Works on macOS, Linux, WSL, and on-device Theos.
# Links the prebuilt libKeyAuth.a — do not run OLLVM on this dylib.
#
# Copyright © 2026 Zexis. All rights reserved.

ifneq ($(origin THEOS),command line)
  ifneq ($(wildcard $(THEOS)/makefiles/common.mk),)
    
  else ifneq ($(wildcard $(HOME)/theos/makefiles/common.mk),)
    export THEOS := $(HOME)/theos
  else ifneq ($(wildcard /opt/theos/makefiles/common.mk),)
    export THEOS := /opt/theos
  else ifneq ($(wildcard /var/mobile/theos/makefiles/common.mk),)
    export THEOS := /var/mobile/theos
  else ifneq ($(wildcard /usr/local/theos/makefiles/common.mk),)
    export THEOS := /usr/local/theos
  else
    $(error Install Theos and set THEOS)
  endif
endif

ARCHS ?= arm64
DEBUG ?= 0
FINALPACKAGE ?= 1
TARGET ?= iphone:clang:latest:16.0
override STRIPFLAGS = -x
include $(THEOS)/makefiles/common.mk

KA_SDK ?= $(THEOS_PROJECT_DIR)/..
LIBRARY_NAME = ka_demo
$(LIBRARY_NAME)_FILES = Tweak.mm
$(LIBRARY_NAME)_CFLAGS += -I$(THEOS_PROJECT_DIR)
$(LIBRARY_NAME)_CCFLAGS += -I$(THEOS_PROJECT_DIR)
$(LIBRARY_NAME)_INSTALL_PATH = /usr/lib
include $(KA_SDK)/theos/keyauth.mk
include $(THEOS_MAKE_PATH)/library.mk
