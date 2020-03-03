#include "MidiEvent.h"
#include "Rnd.h"
#include "Check.h"

namespace AutraLib
{
    PauseEvent::PauseEvent(int length)
        : length(length)
    {
    }

    void PauseEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        (void)track;
        (void)channel;
        m.SetTime(m.GetTime() + length);
    }

    static const int DEFAULT_VELOCITY = 100;

    NoteEvent::NoteEvent(int pitch, int length)
        : pitch(pitch), length(length)
    {
        CHECK_TRUE(pitch >= 40, "Note too low!");
    }

    void NoteEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        m.SetNoteOn(channel, pitch, DEFAULT_VELOCITY);
        track->PutEvent(m);

        m.SetTime(m.GetTime() + length);
        m.SetNoteOff(channel, pitch, DEFAULT_VELOCITY);
        track->PutEvent(m);
    }

    ChordEvent::ChordEvent(const std::vector<int>& pitches, int length)
        : pitches(pitches), length(length)
    {
    }

    void ChordEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        for (int pitch : pitches)
        {
            m.SetNoteOn(channel, pitch, DEFAULT_VELOCITY);
            track->PutEvent(m);
        }

        m.SetTime(m.GetTime() + length);

        for (int pitch : pitches)
        {
            m.SetNoteOff(channel, pitch, DEFAULT_VELOCITY);
            track->PutEvent(m);
        }
    }

    TimbreEvent::TimbreEvent(int timbre)
        : timbre(timbre)
    {
    }

    TimbreEvent::TimbreEvent(const std::vector<int>& timbres)
        : timbre(chooseTimbre(timbres))
    {
    }

    void TimbreEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        m.SetProgramChange(channel, timbre);
        track->PutEvent(m);
    }

    int TimbreEvent::chooseTimbre(const std::vector<int>& timbres)
    {
        static const std::vector<int> DEFAULT_TIMBRE_SET = { 42, 70, 57, 0, 19, 32, 12, 26, 71, 11, 13, 9, 40, 60, 73, 65, 68 };
        if (timbres.size() == 1 && timbres[0] == RANDOM_TIMBRE)
        {
            return GetRandomElement(DEFAULT_TIMBRE_SET);
        }
        return GetRandomElement(timbres);
    }

    VolumeEvent::VolumeEvent(int volume)
        : volume(volume)
    {
    }

    void VolumeEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        m.SetControlChange(channel, C_MAIN_VOLUME, volume);
        track->PutEvent(m);
    }

    void ResetEvent::AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const
    {
        m.SetControlChange(channel, C_RESET, 0);
        track->PutEvent(m);
    }
}
