#include "RhythmPattern.h"

namespace AutraLib
{
    const std::vector<int>* RhythmPattern::getLengthsVector(int rhythmId)
    {
        auto it = RhythmPatternPool.find(rhythmId);
        if (it == RhythmPatternPool.end())
        {
            throw "Invalid rhythm ID!";
        }
        return &(it->second);
    }
}
