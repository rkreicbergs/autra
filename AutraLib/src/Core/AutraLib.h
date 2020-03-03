#pragma once

#include <string>
#include <vector>

namespace AutraLib
{
    enum class GameType : int
    {
        Pitch = 0,
        Rhythm = 1,
        Interval = 2,
        Scale = 3,
        Chord = 4,
        Count = 5,
    };

    void InitLibrary(const std::string& dataFolder, const std::string& username);

    size_t GetLevelCount(GameType type);
    const bool IsExam(GameType type, int levelId);
    const bool IsTriggerLevel(GameType type, int levelId);
    const std::vector<const std::string*> GetGameTabNames(GameType type);
    const std::vector<int> GetGameTabSizes(GameType type);
    const std::vector<int> GetGameTabStartLevelIds(GameType type);

    void LoadLevel(GameType type, int levelId);
    const std::vector<const std::string*>* GetTriggerNames();

    void GenerateMelody();
    void GenerateTrigger(int triggerId);

    int GetLevelLength();
    int CheckMultichoiceAnswer(int triggerId);
    int CheckTriggerAnswer(int relTimeMiliseconds);

    void ReloadScore(const std::string& username);
    int GetScore(GameType type, int levelId);
    void SetScore(GameType type, int levelId, int score);
    int GetStarCount(GameType type, int levelId, int score);
}
