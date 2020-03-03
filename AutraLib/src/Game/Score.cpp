#include "Score.h"
#include "Game.h"
#include <fstream>

namespace AutraLib
{
    static const char USERFILE_EXT[] = ".bin";
    static const char USERFILE_TMP_EXT[] = ".bin.tmp";
    static const int UserdataFileVersion = 1;
    static std::string UserdataFile;
    static std::string UserdataTmpFile;

    std::map<GameType, Score*> Score::GameScores;

    Score::Score(size_t levelCount)
        : Points(levelCount, 0)
    {
    };

    Score::Score(std::istream& serialized)
    {
        int levelCount, score;
        serialized >> levelCount;
        for (int i = 0; i < levelCount; ++i)
        {
            serialized >> score;
            Points.push_back(score);
        };
    };

    void Score::Serialize(std::ostream& serialized)
    {
        serialized << " " << Points.size();
        for (auto &score : Points)
        {
            serialized << " " << score;
        };
    }

    int Score::GetScore(int levelId)
    {
        return Points.at(levelId);
    }

    void Score::SetScore(int levelId, int score)
    {
        if (Points.at(levelId) > score)
        {
            throw("Trying to set lower score!");
        }
        Points.at(levelId) = score;
        SaveData();
    }

    static void MoveTmpFile(std::string tmpFile, std::string dst)
    {
        std::ifstream fin(tmpFile, std::ios::binary);
        std::ofstream fout(dst, std::ios::binary);
        fout << fin.rdbuf();
        fin.close();
        fout.close();

        if (fin.bad() || fout.bad())
        {
            throw("Failed to save score file!");
        }
        remove(tmpFile.c_str());
    }

    void Score::SaveData()
    {
        std::ofstream serialized;
        serialized.open(UserdataTmpFile, std::ios::out | std::ios::trunc);
        serialized << UserdataFileVersion;
        for (auto const &gameScore : GameScores)
        {
            int gameTypeInt = (int)gameScore.first;
            serialized << std::endl << gameTypeInt;
            gameScore.second->Serialize(serialized);
        }
        serialized.close();
        MoveTmpFile(UserdataTmpFile, UserdataFile);
    }

    void Score::LoadData(const std::string& dataFolder, const std::string& username, bool reload)
    {
        UserdataFile = dataFolder + "/" + username + USERFILE_EXT;
        UserdataTmpFile = dataFolder + "/" + username + USERFILE_TMP_EXT;

        std::ifstream serialized;
        serialized.open(UserdataFile);

        int version;
        serialized >> version;
        if (serialized.good() && version != UserdataFileVersion)
        {
            throw "Invalid user data file!";
        }

        if (reload)
        {
            for (auto& entry : GameScores)
            {
                delete entry.second;
            }
            GameScores.clear();
        }

        while (serialized.peek() && serialized.good())
        {
            int gameTypeInt;
            serialized >> gameTypeInt;
            GameType gameType = (GameType)gameTypeInt;

            if (GameScores.find(gameType) != GameScores.end())
            {
                throw "Game score already exists!";
            }
            GameScores[gameType] = new Score(serialized);
        }
        serialized.close();
    }

    Score* Score::GetGameScore(GameType gameType, size_t levelCount)
    {
        if (GameScores.find(gameType) == GameScores.end())
        {
            GameScores[gameType] = new Score(levelCount);
        }
        return GameScores[gameType];
    }
}
