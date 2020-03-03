#pragma once

#include <vector>

#include "TriggerLevel.h"
#include "Game/Common/Phrase.h"

namespace AutraLib
{
    class AttentionLevel : public TriggerLevel
    {
        const std::vector<int> TCount;
        const int tCountSum;
        const int pauseCount;
        const int pauseLength;
        const int noteCount;
        const int noiseTimbre;
        const int noiseCount;
        const int noiseLength;
        const int noiseVolume;
        const std::vector<int> phrasePool;

        int length;

    protected:
        AttentionLevel(const bool &isExam,
                       const int &T1Count,
                       const int &T2Count,
                       const int &T3Count,
                       const int &pauseCount,
                       const int &pauseLength,
                       const int &noteCount,
                       const int &noiseTimbre,
                       const int &noiseCount,
                       const int &noiseLength,
                       const int &noiseVolume,
                       const std::vector<int> &phrasePool);

        void GenerateMelody(const std::vector<Phrase*>& AllPhrases, int timbre);
        void GenerateTrigger(Phrase* phrase, int timbre) const;

    public:
        static const int DEFAULT_NOTE_LENGTH = 500;

        int GetLevelLength() const;
    };
}
