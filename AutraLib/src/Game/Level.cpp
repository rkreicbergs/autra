#include "Level.h"

namespace AutraLib
{
    Level::Level(const bool isExam, const std::vector<const std::string*> triggerNames)
        : isExam(isExam)
        , triggerNames(triggerNames)
    {
    }

    void Level::Load()
    {
    }

    void Level::Unload()
    {
    }

    int Level::CheckMultichoiceAnswer(int triggerId) const
    {
        throw("Invalid level type");
    }

    int Level::CheckTriggerAnswer(int relTimeMiliseconds)
    {
        throw("Invalid level type");
    }
}
