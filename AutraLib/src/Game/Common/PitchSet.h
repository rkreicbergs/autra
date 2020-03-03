#pragma once

#include <vector>
#include <set>
#include <unordered_set>
#include <initializer_list>

namespace AutraLib
{
    class PitchSet
    {
    protected:
        class Desc
        {
        public:
            const std::vector<int> relPitches;
            const std::vector<int> relPitchesOctave;
            Desc(const std::initializer_list<int>& relPitches);
            
            const std::vector<int> getAbsPitchVector(int tonality, int registerId) const;
        };

        PitchSet(const Desc& desc, int tonality, int registerId);

        const Desc* desc;
        const int tonality;

        const std::vector<int> tonicPitches;
        const std::vector<int> absPitches;
        const std::unordered_set<int> absPitchSet;

        int getRandomTonic(int idxOffset, int highReserve) const;

    public:
        static const int NOTES_PER_OCTAVE = 12;

        static int GetRandomTonality(const std::vector<int>& tonalities);

        const std::unordered_set<int>* getPitchSet() const;
        bool containsPitch(int pitch) const;
        int getRandomPitch() const;
    };
}
