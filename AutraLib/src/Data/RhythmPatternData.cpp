// This is a generated file

#include "Game/Common/RhythmPattern.h"

namespace AutraLib
{
    std::map<int, std::vector<int>> RhythmPattern::RhythmPatternPool;

    void RhythmPattern::LoadData()
    {
        RhythmPatternPool[-1] = std::vector<int>{{-500}};
        RhythmPatternPool[1] = std::vector<int>{{500}};
        RhythmPatternPool[22] = std::vector<int>{{250,250}};
        RhythmPatternPool[244] = std::vector<int>{{250,125,125}};
        RhythmPatternPool[424] = std::vector<int>{{125,250,125}};
        RhythmPatternPool[442] = std::vector<int>{{125,125,250}};
        RhythmPatternPool[4444] = std::vector<int>{{125,125,125,125}};
        RhythmPatternPool[34] = std::vector<int>{{375,125}};
        RhythmPatternPool[43] = std::vector<int>{{125,375}};
        RhythmPatternPool[3] = std::vector<int>{{167,166,167}};
        RhythmPatternPool[5] = std::vector<int>{{100,100,100,100,100}};
        RhythmPatternPool[7] = std::vector<int>{{71,72,71,72,71,72,71}};
        RhythmPatternPool[9] = std::vector<int>{{56,55,56,55,56,55,56,55,56}};
    }
}
