#pragma once

#include <vector>
#include <string>
#include <initializer_list>

#include "PitchSet.h"

namespace AutraLib
{
    class Chord : public PitchSet
    {
        struct Desc : public PitchSet::Desc
        {
            const std::string shortName;
            const std::string fullName;
            Desc(const char* shortName, const char* fullName, const std::initializer_list<int>& relPitches);
        };
        static std::vector<Desc> Descriptors;

    public:
        Chord(int chordId, int tonality, int registerId);

        const std::vector<int> getPitches(int salikums) const;

        static std::vector<const std::string*> getChordShortNames(const std::initializer_list<int> chordIds);

        static void LoadData();
    };
}
