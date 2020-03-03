#include "Game.h"

namespace AutraLib
{
    Level* Game::CurLevel = NULL;
    std::map<GameType, Game*> Game::AllGames;

    Game::Game(const std::vector<Level*>* allLevels)
        : allLevels(allLevels)
    {
    }

    size_t Game::GetLevelCount() const
    {
        return allLevels->size();
    }

    bool Game::IsExam(int levelId) const
    {
        return allLevels->at(levelId)->isExam;
    }

    bool Game::IsTriggerLevel(int levelId) const
    {
        return allLevels->at(levelId)->IsTriggerLevel();
    }

    void Game::LoadLevel(int levelId) const
    {
        if (CurLevel != NULL)
        {
            CurLevel->Unload();
            CurLevel = NULL;
        }
        if (levelId < 0 || levelId >= (int)allLevels->size())
        {
            throw "Invalid levelId!";
        }
        CurLevel = allLevels->at(levelId);
        CurLevel->Load();
    }

    int Game::GetScore(int levelId)
    {
        return gameScore->GetScore(levelId);
    }

    void Game::SetScore(int levelId, int points)
    {
        gameScore->SetScore(levelId, points);
    }

    int Game::GetStarCount(int levelId, int score)
    {
        return allLevels->at(levelId)->GetStarCount(score);
    }

    Game* Game::Get(GameType gameType)
    {
        if (AllGames.find(gameType) == AllGames.end())
        {
            throw "No game was registered!";
        }
        return AllGames[gameType];
    }

    Level* Game::GetCurLevel()
    {
        if (CurLevel == NULL)
        {
            throw "No level loaded!";
        }
        return CurLevel;
    }

    const std::vector<const std::string*> Game::GetGameTabNames(GameType type)
    {
        std::vector<const std::string*> names;
        for (const auto& tab : LevelTabs.at(type))
        {
            names.push_back(&tab.name);
        }
        return names;
    }

    const std::vector<int> Game::GetGameTabSizes(GameType type)
    {
        std::vector<int> sizes;
        for (const auto& tab : LevelTabs.at(type))
        {
            sizes.push_back(tab.size);
        }
        return sizes;
    }

    const std::vector<int> Game::GetGameTabStartLevelIds(GameType type)
    {
        std::vector<int> sizes;
        for (const auto& tab : LevelTabs.at(type))
        {
            sizes.push_back(tab.startLevelId);
        }
        return sizes;
    }

    void Game::Register(GameType gameType, const std::vector<Level*>* allLevels)
    {
        if (AllGames.find(gameType) != AllGames.end())
        {
            throw "Game already registered!";
        }
        AllGames[gameType] = new Game(allLevels);
    }

    void Game::LoadScores()
    {
        for (auto& entry : AllGames)
        {
            entry.second->gameScore = Score::GetGameScore(entry.first, entry.second->allLevels->size());
        }
    }
}
