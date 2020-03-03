#pragma once

#include "Game/Level.h"

namespace AutraLib
{
    class MultichoiceLevel : public Level
    {
    protected:
        MultichoiceLevel(const bool isExam, const std::vector<const std::string*> triggerNames);

        int answerId;
        void setAnswer(int answerId);
        virtual int GetExpectedAnswerCount() const = 0;

    public:
        bool IsTriggerLevel() const;
        int CheckMultichoiceAnswer(int triggerId) const;
        int GetStarCount(int score) const;

        int GetLevelLength() const;
    };
}
