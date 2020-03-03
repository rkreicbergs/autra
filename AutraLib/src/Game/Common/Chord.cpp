#include "Chord.h"
#include "Core/Rnd.h"

namespace AutraLib
{
    Chord::Desc::Desc(const char* shortName, const char* fullName, const std::initializer_list<int>& relPitches)
        : PitchSet::Desc(relPitches)
        , shortName(shortName)
        , fullName(fullName)
    {
    };

    Chord::Chord(int chordId, int tonality, int registerId)
        : PitchSet(Descriptors[chordId], tonality, registerId)
    {
    }

    const std::vector<int> Chord::getPitches(int salikums) const
    {
        int highReserve = desc->relPitches.back();
        if (salikums != 0)
        {
            highReserve += NOTES_PER_OCTAVE;
        }
        const int tonic = PitchSet::getRandomTonic(0, highReserve);

        std::vector<int> notes;
        notes.push_back(tonic + desc->relPitches[0]);
        for (int i = 1; i < (int)desc->relPitches.size(); ++i)
        {
            int pitch = tonic + desc->relPitches[i];
            if (salikums == 1 || RndBool())
            {
                pitch += NOTES_PER_OCTAVE;
            }
            notes.push_back(pitch);
        }

        return notes;
    }

    std::vector<const std::string*> Chord::getChordShortNames(const std::initializer_list<int> chordIds)
    {
        std::vector<const std::string*> chordNames;
        for (int chordId : chordIds)
        {
            chordNames.push_back(&Descriptors[chordId].shortName);
        }
        return chordNames;
    }
}
