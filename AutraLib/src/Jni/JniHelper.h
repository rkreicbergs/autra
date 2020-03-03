// File: JniHelper.h

#pragma once

#include "AutraLib.h"
#include <jni.h>

void log(const char *msg);
AutraLib::GameType getGameType(jint jGameType);

jobjectArray CreateStringArray(JNIEnv* env, const std::vector<const std::string*> strings);

jintArray CreateIntArray(JNIEnv* env, const std::vector<int> integers);
