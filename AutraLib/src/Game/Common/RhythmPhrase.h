#pragma once

#include <vector>

#include "Game/Common/Phrase.h"

namespace AutraLib
{
    class RhythmPhrase : public Phrase
    {
        RhythmPhrase(int r1, int r2, int r3);

    public:
        void AddNotes(MidiWriter &midiWriter) const;

        static std::vector<std::vector<int>> AllGroups;
        static std::vector<Phrase*> AllPhrases;

        static void LoadData();
    };
}
