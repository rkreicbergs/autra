#include "Scale.h"

#include <algorithm>

namespace AutraLib
{
    Scale::Desc::Desc(const char* nameEN, const char* nameLV, const std::initializer_list<int>& relPitches)
        : PitchSet::Desc(relPitches)
        , nameEN(nameEN)
        , nameLV(nameLV)
    {
    };

    Scale::Scale(int scaleId, int tonality, int registerId)
        : PitchSet(Descriptors[scaleId], tonality, registerId)
    {
    }

    const std::vector<int> Scale::getSkipPitches(int tonic, int aStepSize, const std::initializer_list<int>& bSteps) const
    {
        const int lastIdx = (int)desc->relPitches.size() - 1;

        int a = 0;
        std::vector<int> pitches;
        while (true)
        {
            for (int bStep : bSteps)
            {
                int idx = a * aStepSize + bStep;
                if (idx <= lastIdx)
                {
                    pitches.push_back(tonic + desc->relPitches[idx]);
                }
                if (idx >= lastIdx)
                {
                    return pitches;
                }
            }
            ++a;
        }
    }

    const std::vector<int> Scale::getResource1Pitches(int tonic) const
    {
        std::vector<int> pitches;
        pitches.push_back(tonic);
        pitches.push_back(tonic + desc->relPitchesOctave.back() - NOTES_PER_OCTAVE);
        pitches.push_back(tonic);
        pitches.push_back(tonic + desc->relPitchesOctave[1]);
        pitches.push_back(tonic);
        return pitches;
    }

    const std::vector<int> Scale::getResource8Pitches(int tonic) const
    {
        std::vector<int> pitches;
        for (int relPitch : desc->relPitches)
        {
            pitches.push_back(tonic + relPitch);
        }
        std::random_shuffle(pitches.begin() + 1, pitches.end() - 1);
        return pitches;
    }

    const std::vector<int> Scale::getPitches(int resource) const
    {
        const int idxOffset = (resource == 1) ? 1 : 0;
        const int highReserve = (resource == 1) ? 0 : desc->relPitches.back();
        const int tonic = PitchSet::getRandomTonic(idxOffset, highReserve);
        switch (resource)
        {
            case 0: return getSkipPitches(tonic, 1, { 0 });
            case 1: return getResource1Pitches(tonic);
            case 2: return getSkipPitches(tonic, 1, { 0, 2, 4 });
            case 3: return getSkipPitches(tonic, 1, { 0, 3, 5 });
            case 4: return getSkipPitches(tonic, 1, { 1, 0 });
            case 5: return getSkipPitches(tonic, 1, { 0, 2 });
            case 6: return getSkipPitches(tonic, 1, { 0, 3 });
            case 7: return getSkipPitches(tonic, 1, { 0, 4 });
            case 8: return getResource8Pitches(tonic);
            case 9: return getSkipPitches(tonic, 3, { 0, 1, 2 });
            case 10: return getSkipPitches(tonic, 1, { 0 });
            case 11: return getSkipPitches(tonic, 1, { 0, 2, 4, 6 });
            default:
                throw "Invalid resource!";
        }
    }

    std::vector<const std::string*> Scale::getScaleNames(const std::initializer_list<int> scaleIds)
    {
        std::vector<const std::string*> scaleNames;
        for (int scaleId : scaleIds)
        {
            scaleNames.push_back(&Descriptors[scaleId].nameLV);
        }
        return scaleNames;
    }
}
