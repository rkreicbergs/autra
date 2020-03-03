#include "RhythmPhrase.h"
#include "Game/Common/RhythmPattern.h"

namespace AutraLib
{
    RhythmPhrase::RhythmPhrase(int r1, int r2, int r3)
        :Phrase{ r1, r2, r3 }
    {
    }

    //public static final int PULSE_TIMBRE = 115;
    //public static final int PULSE_VOLUME = 60;
    //public static final int PULSE_PITCH = 50;
    
    static const int RhythmNotePitch = 70;

    void RhythmPhrase::AddNotes(MidiWriter &midiWriter) const
    {
        for (auto& rhythmId : ids)
        {
            for (auto& length : *RhythmPattern::getLengthsVector(rhythmId))
            {
                if (length < 0) // pause
                {
                    midiWriter.AddEvent(PauseEvent(0 - length));
                }
                else
                {
                    midiWriter.AddEvent(NoteEvent(RhythmNotePitch, length));
                }
            }
        }
    }
}
