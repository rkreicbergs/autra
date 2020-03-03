#pragma once

#include "jdksmidi/world.h"
#include "jdksmidi/track.h"
using namespace jdksmidi;

namespace AutraLib
{
    struct MidiEvent
    {
        virtual void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const = 0;
    };

    struct PauseEvent : MidiEvent
    {
        const int length;
        PauseEvent(int length);
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;
    };

    struct NoteEvent : MidiEvent
    {
        const int pitch;
        const int length;
        NoteEvent(int pitch, int length);
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;
    };

    struct ChordEvent : MidiEvent
    {
        static const int DEFAULT_CHORD_LENGTH = 3000;

        const std::vector<int> pitches;
        const int length;
        ChordEvent(const std::vector<int>& pitches, int length = DEFAULT_CHORD_LENGTH);
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;
    };

    struct TimbreEvent : MidiEvent
    {
        static const int RANDOM_TIMBRE = -1;
        static const int AGOGO_TIMBRE = 113;

        const int timbre;
        TimbreEvent(int timbre);
        TimbreEvent(const std::vector<int>& timbres);
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;

        static int chooseTimbre(const std::vector<int>& timbres);
    };

    struct VolumeEvent : MidiEvent
    {
        static const int DEFAULT_VOLUME = 127;
        const int volume;
        VolumeEvent(int volume);
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;
    };

    struct ResetEvent : MidiEvent
    {
        void AddToTrack(MIDITrack* track, MIDITimedBigMessage& m, int channel) const;
    };
}
