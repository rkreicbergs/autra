#include "IntervalLevel.h"
#include "Core/MidiWriter.h"
#include "Core/Rnd.h"
#include "Game/Score.h"
#include "Game/Common/Scale.h"

namespace AutraLib
{
    IntervalLevel::IntervalLevel(const bool &isExam,
                                 const std::initializer_list<int> &rsIntLengthBatch,
                                 const int &rsCount,
                                 const std::initializer_list<int> &isIntLengthBatch,
                                 const int &isCount,
                                 const int &pauseCount,
                                 const int &pauseLength,
                                 const int &noteCount,
                                 const int &noteLength,
                                 const char &direction,
                                 const int &registerId,
                                 const int &scaleId,
                                 const std::initializer_list<int> &tonalities,
                                 const std::initializer_list<int> &timbres)
        : TriggerLevel(isExam, Interval::getIntervalNames(rsIntLengthBatch), rsCount)
        , rsIntLengthBatch(rsIntLengthBatch)
        , rsCount(rsCount)
        , isIntLengthBatch(isIntLengthBatch)
        , isCount(isCount)
        , pauseCount(pauseCount)
        , pauseLength(pauseLength)
        , noteCount(noteCount)
        , noteLength(noteLength)
        , direction(direction)
        , registerId(registerId)
        , scaleId(scaleId)
        , tonalities(tonalities)
        , timbres(timbres)
        , rsIntervalBatch(NULL)
        , isIntervalBatch(NULL)
    {
#if _DEBUG
        for (int tonality : tonalities)
        {
            Scale scale(scaleId, tonality, registerId);
            IntervalBatch TS(this->rsIntLengthBatch, scale, direction);
            IntervalBatch TI(this->isIntLengthBatch, scale, direction);
        }
#endif
    }

    void IntervalLevel::Load()
    {
        TriggerLevel::Load();
        timbre = TimbreEvent::chooseTimbre(timbres);

        int tonality = PitchSet::GetRandomTonality(tonalities);
        scale = new Scale(scaleId, tonality, registerId);
        rsIntervalBatch = new IntervalBatch(rsIntLengthBatch, *scale, direction);
        isIntervalBatch = new IntervalBatch(isIntLengthBatch, *scale, direction);
    }

    void IntervalLevel::Unload()
    {
        delete scale;
        delete rsIntervalBatch;
        delete isIntervalBatch;
    }

    bool IntervalLevel::hasRsBefore(const std::vector<int> &notes, int idx, int pitch) const
    {
        return idx != 0 && notes[idx - 1] != -1 && rsIntervalBatch->containsInterval(pitch - notes[idx - 1]);
    }

    bool IntervalLevel::hasRsAfter(const std::vector<int> &notes, int idx, int pitch) const
    {
        return idx != notes.size() - 1
            && notes[idx + 1] != -1
            && rsIntervalBatch->containsInterval(pitch - notes[idx + 1]);
    }

    std::unordered_set<int> IntervalLevel::addRandomIntervals(std::vector<int> &notes, const IntervalBatch* intervalBatch, int count) const
    {
        std::unordered_set<int> indeces;
        while (count > 0)
        {
            int idx = RndInt(notes.size() - 1);
            const Interval* interval = NULL;
            if (notes[idx] == -1 && notes[idx + 1] == -1)
            {
                interval = intervalBatch->getRndInterval();
            }
            else if (notes[idx + 1] == -1)
            {
                interval = intervalBatch->getRndIntervalFromPitch(notes[idx]);
            }
            else if (notes[idx] == -1)
            {
                interval = intervalBatch->getRndIntervalToPitch(notes[idx + 1]);
            }

            if (interval == NULL
                || (notes[idx] == -1 && hasRsBefore(notes, idx, interval->first))
                || (notes[idx + 1] == -1 && hasRsAfter(notes, idx + 1, interval->second)))
            {
                continue;
            }

            indeces.insert(idx);
            notes[idx] = interval->first;
            notes[idx + 1] = interval->second;
            --count;
        }
        return indeces;
    }

    void IntervalLevel::GenerateMelody()
    {
        std::vector<int> notes(noteCount + pauseCount, -1);

        // First, add RS and IS intervals
        auto rsIndeces = addRandomIntervals(notes, rsIntervalBatch, rsCount);
        addRandomIntervals(notes, isIntervalBatch, isCount);

        // Add remaining notes
        for (unsigned int idx = 0; idx < notes.size(); ++idx)
        {
            if (notes[idx] == -1)
            {
                notes[idx] = scale->getRandomPitch();
                while (hasRsBefore(notes, idx, notes[idx]) || hasRsAfter(notes, idx, notes[idx]))
                {
                    notes[idx] = scale->getRandomPitch();;
                }
            }
        }

        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbre));
        for (unsigned int idx = 0; idx < notes.size(); ++idx)
        {
            if (notes[idx] == -1)
            {
                midiWriter.AddEvent(PauseEvent(pauseLength));
            }
            else
            {
                midiWriter.AddEvent(NoteEvent(notes[idx], noteLength));
            }
            if (rsIndeces.find(idx) != rsIndeces.end())
            {
                TriggerLevel::addTimestamp(midiWriter.GetTime());
            }
        }
        length = midiWriter.GetTime();
        return midiWriter.Write();
    }

    void IntervalLevel::GenerateTrigger(int triggerId) const
    {
        const Interval* interval = rsIntervalBatch->getInterval(triggerId);

        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbre));
        midiWriter.AddEvent(NoteEvent(interval->first, noteLength));
        midiWriter.AddEvent(NoteEvent(interval->second, noteLength));
        midiWriter.Write();
    }

    int IntervalLevel::GetLevelLength() const
    {
        return length;
    }
}