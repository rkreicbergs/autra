#pragma once

#include "Game/Level.h"

namespace AutraLib
{
    class TriggerLevel : public Level
    {
        int lastCorrectClickTime;
        std::vector<int> timestamps;

        const int maxPoints;

    protected:
        TriggerLevel(const bool &isExam, const std::vector<const std::string*> &triggerNames, const int &tCount);

        void addTimestamp(int timestamp);

    public:
        void Load();
        void Unload();

        bool IsTriggerLevel() const;
        int CheckTriggerAnswer(int relTimeMiliseconds);
        int GetStarCount(int score) const;
    };
}
