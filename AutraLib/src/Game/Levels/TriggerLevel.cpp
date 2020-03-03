#include "TriggerLevel.h"
#include "Game/Score.h"
#include <algorithm>

namespace AutraLib
{
    TriggerLevel::TriggerLevel(const bool &isExam, const std::vector<const std::string*> &triggerNames, const int &tCount)
        : Level(isExam, triggerNames)
        , maxPoints(tCount * Score::CorrectClickPoints)
    {
    }

    void TriggerLevel::Load()
    {
        lastCorrectClickTime = -1000;
        timestamps.clear();
    }

    void TriggerLevel::Unload()
    {
        timestamps.clear();
    }

    bool TriggerLevel::IsTriggerLevel() const
    {
        return true;
    }

    void TriggerLevel::addTimestamp(int timestamp)
    {
        timestamps.push_back(timestamp);
    }

    int TriggerLevel::CheckTriggerAnswer(int relTimeMiliseconds)
    {
        auto it = std::upper_bound(timestamps.begin(), timestamps.end(), relTimeMiliseconds);
        if (it == timestamps.begin())
        {
            return Score::WrongClickPoints;
        }

        int sinceLastCorrectClick = relTimeMiliseconds - lastCorrectClickTime;
        int timeSince = relTimeMiliseconds - *(--it);
        if (timeSince > 1200 || sinceLastCorrectClick < 1200)
        {
            return Score::WrongClickPoints;
        }
        lastCorrectClickTime = relTimeMiliseconds;
        if (timeSince > 700)
        {
            return Score::LateClickPoints;
        }
        return Score::CorrectClickPoints;
    }

    int TriggerLevel::GetStarCount(int score) const
    {
        int percentage = (score * 100) / maxPoints;
        if (percentage == 100)
        {
            return 3;
        }
        if (percentage > 70)
        {
            return 2;
        }
        if (percentage > 40)
        {
            return 1;
        }
        return 0;
    }
}
