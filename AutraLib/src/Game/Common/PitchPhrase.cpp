#include "PitchPhrase.h"
#include "Core/MidiEvent.h"
#include "Game/Levels/AttentionLevel.h"

namespace AutraLib
{
    PitchPhrase::PitchPhrase(int p1, int p2, int p3)
        :Phrase{ p1, p2, p3 }
    {
    }

    void PitchPhrase::AddNotes(MidiWriter &midiWriter) const
    {
        for (auto& pitch : ids)
        {
            if (pitch == -1) // pause
            {
                midiWriter.AddEvent(PauseEvent(AttentionLevel::DEFAULT_NOTE_LENGTH));
            }
            else
            {
                midiWriter.AddEvent(NoteEvent(pitch, AttentionLevel::DEFAULT_NOTE_LENGTH));
            }
        }
    }

    static std::vector<std::vector<int>> AllGroups;
    static std::vector<PitchPhrase*> AllPhrases;
}
