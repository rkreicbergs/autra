LOCAL_PATH := $(call my-dir)
MY_ROOT = ../../AutraLib
JDKSMIDI_ROOT = $(MY_ROOT)/ThirdParty/jdksmidi

include $(CLEAR_VARS)
LOCAL_MODULE     := jdksmidi
LOCAL_C_INCLUDES := $(JDKSMIDI_ROOT)/include
LOCAL_SRC_FILES  := $(wildcard $(JDKSMIDI_ROOT)/src/*.cpp)

ifeq ($(TARGET_ARCH),arm)
    LOCAL_ARM_MODE   := arm
endif
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE           := Autra
LOCAL_STATIC_LIBRARIES := jdksmidi
LOCAL_CPP_FEATURES     := exceptions
LOCAL_C_INCLUDES       := $(JDKSMIDI_ROOT)/include $(MY_ROOT)/src
LOCAL_SRC_FILES        += $(wildcard $(MY_ROOT)/src/Core/*.cpp)
LOCAL_SRC_FILES        += $(wildcard $(MY_ROOT)/src/Data/*.cpp)
LOCAL_SRC_FILES        += $(wildcard $(MY_ROOT)/src/Game/*.cpp)
LOCAL_SRC_FILES        += $(wildcard $(MY_ROOT)/src/Game/*/*.cpp)

ifeq ($(TARGET_ARCH),arm)
    LOCAL_ARM_MODE   := arm
endif
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE           := AutraJni
LOCAL_STATIC_LIBRARIES := Autra
LOCAL_LDLIBS           := -llog
LOCAL_C_INCLUDES       := $(MY_ROOT)/src/Core
LOCAL_SRC_FILES        := $(wildcard $(MY_ROOT)/src/Jni/*.cpp)

ifeq ($(TARGET_ARCH),arm)
    LOCAL_ARM_MODE   := arm
endif
include $(BUILD_SHARED_LIBRARY)
