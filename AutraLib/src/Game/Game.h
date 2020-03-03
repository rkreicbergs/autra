#pragma once

#include <map>
#include <vector>

#include "Core/AutraLib.h"
#include "Level.h"
#include "Score.h"

namespace AutraLib
{
    class Game
    {
        struct LevelTab
        {
            int startLevelId;
            int size;
            std::string name;
        };

        const std::vector<Level*>* allLevels;
        Score* gameScore = NULL;


        static std::map<GameType, std::vector<LevelTab>> LevelTabs;

        static std::map<GameType, Game*> AllGames;
        static Level* CurLevel;

        Game(const std::vector<Level*>* allLevels);

    public:
        size_t GetLevelCount() const;
        bool IsExam(int levelId) const;
        bool IsTriggerLevel(int levelId) const;
        void LoadLevel(int levelId) const;

        int GetScore(int levelId);
        void SetScore(int levelId, int score);
        int GetStarCount(int levelId, int score);

        static Game* Get(GameType gameType);
        static Level* GetCurLevel();

        static const std::vector<const std::string*> GetGameTabNames(GameType type);
        static const std::vector<int> GetGameTabSizes(GameType type);
        static const std::vector<int> GetGameTabStartLevelIds(GameType type);

        static void Register(GameType gameType, const std::vector<Level*>* allLevels);
        static void LoadLevelTabs();
        static void LoadScores();
    };
}
