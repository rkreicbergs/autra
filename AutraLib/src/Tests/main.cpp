#include "AutraLib.h"
#include <iostream>

using namespace AutraLib;

void check(bool expected, bool act)
{
    if (expected != act)
    {
        throw("shit");
    }
}

void CheckLevelTypes()
{
    check(IsTriggerLevel(GameType::Pitch, 0), true);
    check(IsTriggerLevel(GameType::Rhythm, 0), true);
    check(IsTriggerLevel(GameType::Interval, 0), true);
    check(IsTriggerLevel(GameType::Scale, 0), false);
    check(IsTriggerLevel(GameType::Chord, 0), false);
}

void LoadAllLevels(GameType gameType)
{
    for (int i = 0; i < (int)GetLevelCount(gameType); ++i)
    {
        LoadLevel(gameType, i);
        GenerateMelody();
        GetLevelLength();
        //SetScore(gameType, i, i + 100);
        //printf("%d, ", GetScore(gameType, i));

        auto triggerNames = GetTriggerNames();
        for (int i = 0; i < (int)triggerNames->size(); ++i)
        {
            GenerateTrigger(i);
        }
    }
 
    const int test_level = 17;

    printf("<");
    LoadLevel(gameType, test_level);
    for (int i = 0; i < 100; ++i)
    {
        GenerateMelody();
    }
    printf("> \n");
}

void safe_main()
{
    InitLibrary(".", "profile");

    CheckLevelTypes();

    LoadAllLevels(GameType::Pitch);
    LoadAllLevels(GameType::Rhythm);
    LoadAllLevels(GameType::Scale);
    LoadAllLevels(GameType::Interval);
    LoadAllLevels(GameType::Chord);
}
int main(int argc, char **argv)
{
    //try
    {
        safe_main();
    }
    //catch (const std::exception &exc)
    {
      //  std::cerr << exc.what();
    }
    return 0;
}
