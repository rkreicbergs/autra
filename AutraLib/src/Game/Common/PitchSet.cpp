#include "PitchSet.h"
#include "Register.h"
#include "Core/Rnd.h"

namespace AutraLib
{
    static const std::vector<int> getRelPitchOctave(const std::vector<int>& relPitchVector)
    {
        bool relPitches[PitchSet::NOTES_PER_OCTAVE] = { false };
        for (auto& relPitch : relPitchVector)
        {
            relPitches[relPitch % PitchSet::NOTES_PER_OCTAVE] = true;
        }

        std::vector<int> relPitchOctave;
        for (int i = 0; i < PitchSet::NOTES_PER_OCTAVE; ++i)
        {
            if (relPitches[i])
            {
                relPitchOctave.push_back(i);
            }
        }
        return relPitchOctave;
    }

    PitchSet::Desc::Desc(const std::initializer_list<int>& relPitches)
        : relPitches(relPitches)
        , relPitchesOctave(getRelPitchOctave(relPitches))
    {
    };

    const std::vector<int> PitchSet::Desc::getAbsPitchVector(int tonality, int registerId) const
    {
        std::vector<int> absPitchVector;

        const auto& noteRegister = Register::RegisterPool[registerId];
        int basePitch = noteRegister.from + ((tonality - noteRegister.from) % NOTES_PER_OCTAVE);
        if (basePitch >= noteRegister.from)
        {
            basePitch -= NOTES_PER_OCTAVE;
        }

        while (basePitch <= noteRegister.to)
        {
            for (auto& relPitch : relPitchesOctave)
            {
                int pitch = basePitch + relPitch;
                if (pitch > noteRegister.to)
                {
                    break;
                }
                if (pitch >= noteRegister.from)
                {
                    absPitchVector.push_back(pitch);
                }
            }
            basePitch += NOTES_PER_OCTAVE;
        }
        return absPitchVector;
    }

    PitchSet::PitchSet(const Desc& desc, int tonality, int registerId)
        : desc(&desc)
        , tonality(tonality)
        , absPitches(desc.getAbsPitchVector(tonality, registerId))
        , absPitchSet(absPitches.begin(), absPitches.end())
    {
    }

    int PitchSet::getRandomTonic(int idxOffset, int highReserve) const
    {
        std::vector<int> tonicPitches;

        const int maxIdx = (int)absPitches.size() - idxOffset;
        const int maxPitch = (int)absPitches.back() - highReserve;

        for (int idx = idxOffset; idx < maxIdx && absPitches[idx] <= maxPitch; ++idx)
        {
            if (absPitches[idx] % NOTES_PER_OCTAVE == tonality)
            {
                tonicPitches.push_back(absPitches[idx]);
            }
        }

        if (tonicPitches.size() == 0)
        {
            throw("Invalid level restrictions");
        }
        return GetRandomElement(tonicPitches);
    }

    int PitchSet::GetRandomTonality(const std::vector<int>& tonalities)
    {
        if (tonalities.size() == 1 && tonalities[0] == NOTES_PER_OCTAVE)
        {
            return RndInt(NOTES_PER_OCTAVE);
        }
        return GetRandomElement(tonalities);
    }

    const std::unordered_set<int>* PitchSet::getPitchSet() const
    {
        return &absPitchSet;
    }

    bool PitchSet::containsPitch(int pitch) const
    {
        return absPitchSet.find(pitch) != absPitchSet.end();
    }

    int PitchSet::getRandomPitch() const
    {
        return GetRandomElement(absPitches);
    }
}
