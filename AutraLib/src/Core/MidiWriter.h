// File: MidiWriter.h

#pragma once

#include <string>
#include "MidiEvent.h"

#include "jdksmidi/multitrack.h"

namespace AutraLib
{
    class MidiWriter
    {
        static const int ClickPerBeat;
        static const int USecsPerBeats;
        static const int TrackCount;

        static std::string MidiFilePath;

        jdksmidi::MIDIMultiTrack tracks;
        jdksmidi::MIDITimedBigMessage midiMsg;

    public:
        static void Init(std::string storageFolder);

        MidiWriter();

        void AddEvent(const MidiEvent& midiEvent);
        MIDIClockTime GetTime() const;

        void Write();
    };
}
