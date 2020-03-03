#pragma once

#include <vector>
#include <string>

namespace AutraLib
{
    class Level
    {
    protected:
        Level(const bool isExam, const std::vector<const std::string*> triggerNames);

    public:
        const bool isExam;
        const std::vector<const std::string*> triggerNames;

        virtual void Load();
        virtual void Unload();

        virtual bool IsTriggerLevel() const = 0;

        virtual int CheckMultichoiceAnswer(int triggerId) const;
        virtual int CheckTriggerAnswer(int relTimeMiliseconds);
        virtual int GetStarCount(int score) const = 0;

        virtual void GenerateMelody() = 0;
        virtual void GenerateTrigger(int triggerId) const = 0;
        virtual int GetLevelLength() const  = 0;
    };
}
