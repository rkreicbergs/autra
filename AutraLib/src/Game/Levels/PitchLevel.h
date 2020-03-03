#pragma once

#include <vector>
#include <initializer_list>

#include "AttentionLevel.h"

namespace AutraLib
{
    class PitchLevel : public AttentionLevel
    {
        const std::vector<int> timbres;
        const int minReverb;
        const int maxReverb;
        const int minVolume;

        int timbre;

        PitchLevel(const bool &isExam,
                   const int &T1Count,
                   const int &T2Count,
                   const int &T3Count,
                   const int &pauseCount,
                   const int &pauseLength,
                   const int &noteCount,
                   const std::initializer_list<int> &timbres,
                   const int &minReverb,
                   const int &maxReverb,
                   const int &minVolume,
                   const int &noiseTimbre,
                   const int &noiseCount,
                   const int &noiseLength,
                   const int &noiseVolume,
                   const std::initializer_list<bool> &groups);

    public:
        void Load();

        void GenerateMelody();
        void GenerateTrigger(int triggerId) const;

        static void LoadData();
    };
}
