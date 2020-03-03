#pragma once

#include <map>
#include <vector>

#include "Core/AutraLib.h"

namespace AutraLib
{
    class Score
    {
        static std::map<GameType, Score*> GameScores;

        std::vector<int> Points;

        Score(size_t levelCount);
        Score(std::istream& serialized);
        void Serialize(std::ostream& serialized);

        static void SaveData();

    public:
        static const int CorrectClickPoints = 100;
        static const int LateClickPoints = 70;
        static const int WrongClickPoints = -50;

        int GetScore(int levelId);
        void SetScore(int levelId, int score);

        // Score must be loaded before loading games
        static void LoadData(const std::string& dataFolder, const std::string& username, bool reload = false);
        static Score* GetGameScore(GameType gameType, size_t levelCount);
    };
}
