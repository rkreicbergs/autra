// File: MidiWriter.cpp

//TODO: remove this
#define _CRT_SECURE_NO_DEPRECATE

#include "AutraLib.h"
#include "MidiWriter.h"

#include "jdksmidi/world.h"
#include "jdksmidi/track.h"
#include "jdksmidi/multitrack.h"
#include "jdksmidi/filereadmultitrack.h"
#include "jdksmidi/fileread.h"
#include "jdksmidi/fileshow.h"
#include "jdksmidi/filewritemultitrack.h"
using namespace jdksmidi;

namespace AutraLib
{
    static const char MIDI_FILE_NAME[] = "autra.mid";

    const int MidiWriter::ClickPerBeat = 1000;
    const int MidiWriter::USecsPerBeats = 1000000;
    const int MidiWriter::TrackCount = 2;

    std::string MidiWriter::MidiFilePath;

    void MidiWriter::Init(std::string outputFolder)
    {
        MidiFilePath = outputFolder + "/" + MIDI_FILE_NAME;
    }

    MidiWriter::MidiWriter()
        : tracks(TrackCount)
    {
        midiMsg.SetTime(0);

        // Reset the state at the end
        AddEvent(VolumeEvent(VolumeEvent::DEFAULT_VOLUME));
        AddEvent(ResetEvent());

        midiMsg.SetTimeSig(4, 2);
        tracks.GetTrack(0)->PutEvent(midiMsg);

        tracks.SetClksPerBeat(ClickPerBeat);
        midiMsg.SetTempo(USecsPerBeats);
        tracks.GetTrack(0)->PutEvent(midiMsg);
        tracks.GetTrack(1)->PutEvent(midiMsg);
    }

    void MidiWriter::AddEvent(const MidiEvent& midiEvent)
    {
        midiEvent.AddToTrack(tracks.GetTrack(0), midiMsg, 0);
    }

    MIDIClockTime MidiWriter::GetTime() const
    {
        return midiMsg.GetTime();
    }

    void MidiWriter::Write()
    {
        // TODO: remove hack for winamp
        //AddEvent(VolumeEvent(0));

        //AddEvent(NoteEvent(60, 0));

        //// Reset the state at the end
        //AddEvent(ResetEvent());

        //tracks.SortEventsOrder(); // it is necessary to do this before write step

        MIDIFileWriteStreamFileName out_stream(MidiFilePath.c_str());
        if (!out_stream.IsValid())
        {
            throw "Error opening file";
        }

        MIDIFileWriteMultiTrack writer(&tracks, &out_stream);
        if (!writer.Write(TrackCount))
        {
            throw "Error writing file";
        }
    }
}
