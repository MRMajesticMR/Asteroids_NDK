LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Asteroids_NDK
LOCAL_SRC_FILES := Asteroids_NDK.cpp objects/GameObject.cpp objects/MoveableGameObject.cpp objects/Ship.cpp objects/Bullet.cpp objects/Asteroid.cpp
LOCAL_LDLIBS    := -llog -lGLESv2
LOCAL_CFLAGS    := -Werror

include $(BUILD_SHARED_LIBRARY)
