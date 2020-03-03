#include "AutraLib.h"

#include "Game/Score.h"
#include "Game/Game.h"

#include "Game/Common/PitchPhrase.h"
#include "Game/Common/RhythmPhrase.h"
#include "Game/Common/RhythmPattern.h"
#include "Game/Common/Scale.h"
#include "Game/Common/Chord.h"
#include "Game/Common/Register.h"

#include "Game/Levels/PitchLevel.h"
#include "Game/Levels/RhythmLevel.h"
#include "Game/Levels/IntervalLevel.h"
#include "Game/Levels/ScaleLevel.h"
#include "Game/Levels/ChordLevel.h"

namespace AutraLib
{
    static std::string autraDataFolder;

    void InitLibrary(const std::string& dataFolder, const std::string& username)
    {
        autraDataFolder = dataFolder;
        MidiWriter::Init(dataFolder);
        Score::LoadData(dataFolder, username);

        PitchPhrase::LoadData();
        RhythmPhrase::LoadData();
        RhythmPattern::LoadData();
        Scale::LoadData();
        Chord::LoadData();
        Register::LoadData();

        PitchLevel::LoadData();
        RhythmLevel::LoadData();
        IntervalLevel::LoadData();
        ScaleLevel::LoadData();
        ChordLevel::LoadData();

        Game::LoadLevelTabs();
        Game::LoadScores();
    }

    size_t GetLevelCount(GameType type)
    {
        return Game::Get(type)->GetLevelCount();
    }

    const bool IsExam(GameType type, int levelId)
    {
        return Game::Get(type)->IsExam(levelId);
    }

    const bool IsTriggerLevel(GameType type, int levelId)
    {
        return Game::Get(type)->IsTriggerLevel(levelId);
    }

    const std::vector<const std::string*> GetGameTabNames(GameType type)
    {
        return Game::GetGameTabNames(type);
    }

    const std::vector<int> GetGameTabStartLevelIds(GameType type)
    {
        return Game::GetGameTabStartLevelIds(type);
    }

    const std::vector<int> GetGameTabSizes(GameType type)
    {
        return Game::GetGameTabSizes(type);
    }

    void LoadLevel(GameType type, int levelId)
    {
        Game::Get(type)->LoadLevel(levelId);
    }

    const std::vector<const std::string*>* GetTriggerNames()
    {
        return &Game::GetCurLevel()->triggerNames;
    }

    void GenerateMelody()
    {
        return Game::GetCurLevel()->GenerateMelody();
    }

    void GenerateTrigger(int triggerId)
    {
        return Game::GetCurLevel()->GenerateTrigger(triggerId);
    }

    int GetLevelLength()
    {
        return Game::GetCurLevel()->GetLevelLength();
    }

    int CheckMultichoiceAnswer(int triggerId)
    {
        return Game::GetCurLevel()->CheckMultichoiceAnswer(triggerId);
    }

    int CheckTriggerAnswer(int relTimeMiliseconds)
    {
        return Game::GetCurLevel()->CheckTriggerAnswer(relTimeMiliseconds);
    }

    void ReloadScore(const std::string& username)
    {
        Score::LoadData(autraDataFolder, username);
        Game::LoadScores();
    }

    int GetScore(GameType type, int levelId)
    {
        return Game::Get(type)->GetScore(levelId);
    }

    void SetScore(GameType type, int levelId, int score)
    {
        Game::Get(type)->SetScore(levelId, score);
    }

    int GetStarCount(GameType type, int levelId, int score)
    {
        return Game::Get(type)->GetStarCount(levelId, score);
    }
}
