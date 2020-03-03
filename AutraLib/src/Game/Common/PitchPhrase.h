#pragma once

#include <vector>
#include "Game/Common/Phrase.h"

namespace AutraLib
{
    class PitchPhrase : public Phrase
    {
        PitchPhrase(int id1, int id2, int id3);

    public:
        void AddNotes(MidiWriter &midiWriter) const;

        static std::vector<std::vector<int>> AllGroups;
        static std::vector<Phrase*> AllPhrases;

        static void LoadData();
    };
}
