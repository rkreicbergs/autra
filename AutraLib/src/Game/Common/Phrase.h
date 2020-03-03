#pragma once

#include <vector>
#include <string>
#include "Core/MidiWriter.h"

namespace AutraLib
{
    class Phrase
    {
    protected:
        int ids[3];
        Phrase(int id1, int id2, int id3);

    public:
        virtual void AddNotes(MidiWriter &midiWriter) const = 0;
    };

    template <class T>
    const std::vector<int> GetPhrases(std::initializer_list<bool> allowedGroups)
    {
        std::vector<int> phrases;

        int i = 0;
        for (auto it = allowedGroups.begin(); it != allowedGroups.end(); ++it, ++i)
        {
            if (*it)
            {
                phrases.insert(phrases.end(), T::AllGroups[i].begin(), T::AllGroups[i].end());
            }
        }
        return phrases;
    }
}
