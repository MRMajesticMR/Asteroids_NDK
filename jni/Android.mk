LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Asteroids_NDK
LOCAL_SRC_FILES := Asteroids_NDK.cpp GameObject.cpp MoveableGameObject.cpp

include $(BUILD_SHARED_LIBRARY)
