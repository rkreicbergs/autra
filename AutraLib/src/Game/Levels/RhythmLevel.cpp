#include "RhythmLevel.h"
#include "Game/Common/RhythmPhrase.h"

namespace AutraLib
{
    RhythmLevel::RhythmLevel(const bool &isExam,
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
                             const std::initializer_list<bool> &groups)
        : AttentionLevel(isExam, T1Count, T2Count, T3Count, pauseCount, pauseLength, noteCount,
                         noiseTimbre, noiseCount, noiseLength, noiseVolume,
                         GetPhrases<RhythmPhrase>(groups))
        , noPulseCount(noPulseCount)
        , minNoPulseNoteLength(minNoPulseNoteLength)
        , maxNoPulseNoteLength(maxNoPulseNoteLength)
        , minNoPulseNotePlace(minNoPulseNotePlace)
        , maxNoPulseNotePlace(maxNoPulseNotePlace)
    {
    }

    void RhythmLevel::GenerateMelody()
    {
        return AttentionLevel::GenerateMelody(RhythmPhrase::AllPhrases, TimbreEvent::AGOGO_TIMBRE);
    }

    void RhythmLevel::GenerateTrigger(int triggerId) const
    {
        return AttentionLevel::GenerateTrigger(RhythmPhrase::AllPhrases[triggerId], TimbreEvent::AGOGO_TIMBRE);
    }
}
