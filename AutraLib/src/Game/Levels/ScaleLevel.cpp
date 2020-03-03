#include "ScaleLevel.h"
#include "Core/MidiWriter.h"
#include "Core/Rnd.h"
#include "Game/Score.h"
#include "Game/Common/Scale.h"
#include "Game/Common/RhythmPattern.h"

namespace AutraLib
{
    ScaleLevel::ScaleLevel(const bool &isExam,
                           const std::initializer_list<int> &rScales,
                           const std::initializer_list<int> &tonalities,
                           const std::initializer_list<int> &resources,
                           const std::initializer_list<int> &rhythmGroups,
                           const int &rhythmGroupLength,
                           const int &direction,
                           const int &registerId,
                           const std::initializer_list<int> &timbres)
        : MultichoiceLevel(isExam, Scale::getScaleNames(rScales))
        , rScales(rScales)
        , tonalities(tonalities)
        , resources(resources)
        , rhythmGroups(rhythmGroups)
        , rhythmGroupLength(rhythmGroupLength)
        , direction(direction)
        , registerId(registerId)
        , timbres(timbres)
    {
#if _DEBUG
        for (int rhythmId : rhythmGroups)
        {
            RhythmPattern::getLengthsVector(rhythmId);
        }
        for (int scaleId : rScales)
        {
            for (int ton = 0; ton < 12; ++ton)
            {
                for (int res : resources)
                {
                    Scale scale(scaleId, ton, registerId);
                    scale.getPitches(res);
                }
            }
        }
#endif
    }

    int ScaleLevel::GetExpectedAnswerCount() const
    {
        return GetLevelLength() / 5000;
    }

    void ScaleLevel::GenerateMelody()
    {
        int triggerId = RndInt(rScales.size());
        MultichoiceLevel::setAnswer(triggerId);
        GenerateTrigger(triggerId);
    }

    void ScaleLevel::GenerateTrigger(int triggerId) const
    {
        int scaleId = rScales[triggerId];
        int tonality = PitchSet::GetRandomTonality(tonalities);
        int resource = GetRandomElement(resources);
        int rhythmId = GetRandomElement(rhythmGroups);

        Scale scale(scaleId, tonality, registerId);
        auto& pitches = scale.getPitches(resource);
        const auto lengths = *RhythmPattern::getLengthsVector(rhythmId);

        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbres));
        int lenIdx = 0;
        for (int pitch : pitches)
        {
            midiWriter.AddEvent(NoteEvent(pitch, lengths[lenIdx] * rhythmGroupLength / 1000));
            lenIdx = (lenIdx + 1) % lengths.size();
        }
        midiWriter.Write();
    }
}
