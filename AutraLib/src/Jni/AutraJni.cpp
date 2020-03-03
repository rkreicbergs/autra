// File: AutraJni.cpp

#include "JniHelper.h"

#define JNI_FUN_NAME(fun_name) Java_lv_autra_autra2_AutraJni_ ## fun_name

#ifdef __ANDROID__
#   define DEFINE_JNI_FUN(type, fun_name, ...) JNIEXPORT type JNICALL JNI_FUN_NAME(fun_name) (JNIEnv* env, jclass jclass, __VA_ARGS__)
#   define DEFINE_JNI_FUN2(type, fun_name) JNIEXPORT type JNICALL JNI_FUN_NAME(fun_name) (JNIEnv* env, jclass jclass)
#else
#   define DEFINE_JNI_FUN(type, fun_name, ...) JNIEXPORT type JNICALL JNI_FUN_NAME(fun_name) ## (JNIEnv* env, jclass jclass, __VA_ARGS__)
#   define DEFINE_JNI_FUN2 DEFINE_JNI_FUN
#endif

using namespace AutraLib;

extern "C"
{
    DEFINE_JNI_FUN(void, initLibrary, jstring jDataFolder, jstring jUsername)
    {
        const char *dataFolder = env->GetStringUTFChars(jDataFolder, 0);
        const char *username = env->GetStringUTFChars(jUsername, 0);

        InitLibrary(dataFolder, username);

        env->ReleaseStringUTFChars(jUsername, username);
        env->ReleaseStringUTFChars(jDataFolder, dataFolder);
    }


    DEFINE_JNI_FUN(jint, getLevelCount, jint jGameType)
    {
        GameType gameType = getGameType(jGameType);
        return (jint)GetLevelCount(gameType);
    }
    DEFINE_JNI_FUN(jboolean, isExam, jint jGameType, jint jLevelId)
    {
        GameType gameType = getGameType(jGameType);
        return IsExam(gameType, (int)jLevelId) ? JNI_TRUE : JNI_FALSE;
    }
    DEFINE_JNI_FUN(jboolean, isTriggerLevel, jint jGameType, jint jLevelId)
    {
        GameType gameType = getGameType(jGameType);
        return IsTriggerLevel(gameType, (int)jLevelId) ? JNI_TRUE : JNI_FALSE;
    }


    DEFINE_JNI_FUN(jobjectArray, getGameTabNames, jint jGameType)
    {
        GameType gameType = getGameType(jGameType);
        const auto& tabNames = GetGameTabNames(gameType);
        return CreateStringArray(env, tabNames);
    }
    DEFINE_JNI_FUN(jintArray, getGameTabSizes, jint jGameType)
    {
        GameType gameType = getGameType(jGameType);
        const auto& tabSizes = GetGameTabSizes(gameType);
        return CreateIntArray(env, tabSizes);
    }
    DEFINE_JNI_FUN(jintArray, getGameTabStartLevelIds, jint jGameType)
    {
        GameType gameType = getGameType(jGameType);
        const auto& levelIds = GetGameTabStartLevelIds(gameType);
        return CreateIntArray(env, levelIds);
    }


    DEFINE_JNI_FUN(void, loadLevel, jint jGameType, jint jLevelId)
    {
        GameType gameType = getGameType(jGameType);
        LoadLevel(gameType, (int)jLevelId);
    }
    DEFINE_JNI_FUN2(jobjectArray, getTriggerNames)
    {
        auto triggerNames = GetTriggerNames();
        return CreateStringArray(env, *triggerNames);
    }


    DEFINE_JNI_FUN2(void, generateMelody)
    {
        GenerateMelody();
    }
    DEFINE_JNI_FUN(void, generateTrigger, jint jTriggerId)
    {
        GenerateTrigger((int)jTriggerId);
    }

    
    DEFINE_JNI_FUN2(jint, getLevelLength)
    {
        return GetLevelLength();
    }
    DEFINE_JNI_FUN(jint, checkMultichoiceAnswer, jint jTriggerId)
    {
        return CheckMultichoiceAnswer((int)jTriggerId);
    }
    DEFINE_JNI_FUN(jint, checkTriggerAnswer, jint jRelTimeMiliseconds)
    {
        return CheckTriggerAnswer((int)jRelTimeMiliseconds);
    }


    DEFINE_JNI_FUN(void, reloadScore, jint jGameType, jstring jUsername)
    {
        const char *username = env->GetStringUTFChars(jUsername, 0);
        ReloadScore(username);
        env->ReleaseStringUTFChars(jUsername, username);
    }
    DEFINE_JNI_FUN(jint, getScore, jint jGameType, jint jLevelId)
    {
        GameType gameType = getGameType(jGameType);
        return GetScore(gameType, (int)jLevelId);
    }
    DEFINE_JNI_FUN(void, setScore, jint jGameType, jint jLevelId, jint jScore)
    {
        GameType gameType = getGameType(jGameType);
        SetScore(gameType, (int)jLevelId, (int)jScore);
    }
    DEFINE_JNI_FUN(jint, getStarCount, jint jGameType, jint jLevelId, jint jScore)
    {
        GameType gameType = getGameType(jGameType);
        return GetStarCount(gameType, (int)jLevelId, (int)jScore);
    }
}
