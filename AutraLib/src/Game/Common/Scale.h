#pragma once

#include <vector>
#include <string>
#include <initializer_list>

#include "PitchSet.h"

namespace AutraLib
{

    class Scale : public PitchSet
    {
        struct Desc : public PitchSet::Desc
        {
            const std::string nameEN;
            const std::string nameLV;
            Desc(const char* nameEN, const char* nameLV, const std::initializer_list<int>& incRelPitches);
        };
        static std::vector<Desc> Descriptors;

        const std::vector<int> getSkipPitches(int basePitch, int aStepSize, const std::initializer_list<int>& bSteps) const;
        const std::vector<int> getResource1Pitches(int basePitch) const;
        const std::vector<int> getResource8Pitches(int basePitch) const;

    public:
        Scale(int scaleId, int tonality, int registerId);

        const std::vector<int> getPitches(int resource) const;

        static std::vector<const std::string*> getScaleNames(const std::initializer_list<int> scaleIds);

        static void LoadData();
    };
}
