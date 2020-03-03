#include "ChordLevel.h"
#include "Core/MidiWriter.h"
#include "Core/Rnd.h"
#include "Game/Score.h"
#include "Game/Common/Chord.h"

namespace AutraLib
{

    ChordLevel::ChordLevel(const bool &isExam,
                           const std::initializer_list<int> &rChords,
                           const int &salikums,
                           const std::initializer_list<int> &tonalities,
                           const int &registerId,
                           const std::initializer_list<int> &timbres)
        : MultichoiceLevel(isExam, Chord::getChordShortNames(rChords))
        , rChords(rChords)
        , salikums(salikums)
        , tonalities(tonalities)
        , registerId(registerId)
        , timbres(timbres)
    {
#if _DEBUG
        static int levelnum = 0;
        ++levelnum;
        for (int chordId : rChords)
        {
            for (int ton = 0; ton < 12; ++ton)
            {
                Chord chord(chordId, ton, registerId);
                chord.getPitches(salikums);
            }
        }
#endif
    }

    int ChordLevel::GetExpectedAnswerCount() const
    {
        return GetLevelLength() / 5000;
    }

    void ChordLevel::GenerateMelody()
    {
        int triggerId = RndInt(rChords.size());
        MultichoiceLevel::setAnswer(triggerId);
        GenerateTrigger(triggerId);
    }

    void ChordLevel::GenerateTrigger(int triggerId) const
    {
        int chordId = rChords[triggerId];
        int tonality = PitchSet::GetRandomTonality(tonalities);

        Chord chord(chordId, tonality, registerId);
        auto& pitches = chord.getPitches(salikums);

        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbres));
        midiWriter.AddEvent(ChordEvent(pitches));
        midiWriter.Write();
    }
}