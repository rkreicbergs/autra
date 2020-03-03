#pragma once

#include <map>
#include <vector>

namespace AutraLib
{
    class RhythmPattern
    {
        static std::map<int, std::vector<int>> RhythmPatternPool;

    public:
        static const std::vector<int>* getLengthsVector(int rhythmId);
        static void LoadData();
    };
}
