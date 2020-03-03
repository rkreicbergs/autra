#include "PitchLevel.h"
#include "Game/Common/PitchPhrase.h"
#include "Core/Rnd.h"

namespace AutraLib
{
    PitchLevel::PitchLevel(const bool &isExam,
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
                           const std::initializer_list<bool> &groups)
        : AttentionLevel(isExam, T1Count, T2Count, T3Count, pauseCount, pauseLength, noteCount,
                         noiseTimbre, noiseCount, noiseLength, noiseVolume,
                         GetPhrases<PitchPhrase>(groups))
        , timbres(timbres)
        , minReverb(minReverb)
        , maxReverb(maxReverb)
        , minVolume(minVolume)
    {
    }

    void PitchLevel::Load()
    {
        TriggerLevel::Load();
        timbre = TimbreEvent::chooseTimbre(timbres);
    }

    void PitchLevel::GenerateMelody()
    {
        AttentionLevel::GenerateMelody(PitchPhrase::AllPhrases, timbre);
    }

    void PitchLevel::GenerateTrigger(int triggerId) const
    {
        AttentionLevel::GenerateTrigger(PitchPhrase::AllPhrases[triggerId], timbre);
    }
}
