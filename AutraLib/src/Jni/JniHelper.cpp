// File: JniHelper.cpp

#include "JniHelper.h"

#ifdef __ANDROID__
#   include <android/log.h> 
#endif

void log(const char *msg)
{
#ifdef __ANDROID__
    __android_log_print(ANDROID_LOG_ERROR, "AUTRA_JNI", "JNI: %s", msg);
#endif
}

static const int PITCH_GAME = 0;
static const int RHYTHM_GAME = 1;
static const int INTERVAL_GAME = 2;
static const int SCALE_GAME = 3;
static const int CHORD_GAME = 4;

AutraLib::GameType getGameType(jint jGameType)
{
    switch ((int)jGameType)
    {
        case PITCH_GAME:
            return AutraLib::GameType::Pitch;
        case RHYTHM_GAME:
            return AutraLib::GameType::Rhythm;
        case INTERVAL_GAME:
            return AutraLib::GameType::Interval;
        case SCALE_GAME:
            return AutraLib::GameType::Scale;
        case CHORD_GAME:
            return AutraLib::GameType::Chord;
        default:
            throw "Invalid game type";
    }
}

jobjectArray CreateStringArray(JNIEnv* env, const std::vector<const std::string*> strings)
{
    jobjectArray jStrings = (jobjectArray)env->NewObjectArray((jsize)strings.size(),
                                                               env->FindClass("java/lang/String"),
                                                               env->NewStringUTF(""));
    int i = 0;
    for (auto& aString : strings)
    {
        env->SetObjectArrayElement(jStrings, i++, env->NewStringUTF(aString->c_str()));
    }
    return jStrings;
}

jintArray CreateIntArray(JNIEnv* env, const std::vector<int> integers)
{
    jintArray jIntegers = env->NewIntArray((jsize)integers.size());
    std::vector<jint> jInts;
    for (int i : integers)
    {
        jInts.push_back((jint)i);
    }
    env->SetIntArrayRegion(jIntegers, 0, (jsize)jInts.size(), jInts.data());
    return jIntegers;

}
