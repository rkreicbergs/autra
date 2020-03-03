#include "MultichoiceLevel.h"
#include "Game/Score.h"

namespace AutraLib
{
    MultichoiceLevel::MultichoiceLevel(const bool isExam, const std::vector<const std::string*> triggerNames)
        : Level(isExam, triggerNames)
    {
    }

    bool MultichoiceLevel::IsTriggerLevel() const
    {
        return false;
    }

    void MultichoiceLevel::setAnswer(int answer)
    {
        answerId = answer;
    }

    int MultichoiceLevel::CheckMultichoiceAnswer(int triggerId) const
    {
        if (answerId == triggerId)
            return Score::CorrectClickPoints;
        return Score::WrongClickPoints;
    }

    int MultichoiceLevel::GetStarCount(int score) const
    {
        int percentage = (score * 100) / (GetExpectedAnswerCount() * Score::CorrectClickPoints);
        if (percentage > 90)
        {
            return 3;
        }
        if (percentage > 65)
        {
            return 2;
        }
        if (percentage > 35)
        {
            return 1;
        }
        return 0;
    }

    int MultichoiceLevel::GetLevelLength() const
    {
        return 120 * 1000; // 2 minutes
    }
}
