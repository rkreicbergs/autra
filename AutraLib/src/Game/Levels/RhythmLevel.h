#pragma once

#include <initializer_list>

#include "AttentionLevel.h"

namespace AutraLib
{
    class RhythmLevel : public AttentionLevel
    {
        const int noPulseCount;
        const int minNoPulseNoteLength;
        const int maxNoPulseNoteLength;
        const int minNoPulseNotePlace;
        const int maxNoPulseNotePlace;

        RhythmLevel(const bool &isExam,
                    const int &T1Count,
                    const int &T2Count,
                    const int &T3Count,
                    const int &pauseCount,
                    const int &pauseLength,
                    const int &noteCount,
                    const int &noPulseCount,
                    const int &minNoPulseNoteLength,
                    const int &maxNoPulseNoteLength,
                    const int &minNoPulseNotePlace,
                    const int &maxNoPulseNotePlace,
                    const int &noiseTimbre,
                    const int &noiseCount,
                    const int &noiseLength,
                    const int &noiseVolume,
                    const std::initializer_list<bool> &groups);

    public:
        void GenerateMelody();
        void GenerateTrigger(int triggerId) const;

        static void LoadData();
    };
}
