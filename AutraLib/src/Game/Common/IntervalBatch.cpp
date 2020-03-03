#include "IntervalBatch.h"
#include "Core/Rnd.h"
#include <algorithm>

namespace AutraLib
{
    static const std::string IntervalNames[] =
    {
        "T1", "M2", "L2", "M3", "L3", "T4", "T", "T5", "M6", "L6", "M7",
        "L7", "T8", "M9", "L9", "M10", "L10", "T11", "T11.5", "T12", "M13", "L13"
    };
    static std::map<const std::string, int> IntervalLengths;

    static void InitIntervals()
    {
        static bool initialized = false;
        if (!initialized)
        {
            int i = 0;
            for (auto& name : IntervalNames)
            {
                IntervalLengths[name] = i++;
            }
            initialized = true;
        }
    }

    std::vector<const std::string*> Interval::getIntervalNames(const std::initializer_list<int> intLengthBatch)
    {
        InitIntervals();
        std::vector<const std::string*> intervalNames;

        for (int intLength : intLengthBatch)
        {
            intervalNames.push_back(&IntervalNames[intLength]);
        }

        return intervalNames;
    }

    Interval::Interval(int first, int second) : first(first), second(second)
    {
    }

    int Interval::getLength() const
    {
        return std::abs(first - second);
    }

    void IntervalBatch::addInterval(int firstPitch, int secondPitch)
    {
        const Interval* interval = new Interval(firstPitch, secondPitch);
        intervals.push_back(interval);

        intervalsOfLength[interval->getLength()].push_back(interval);
        intervalsFromPitch[firstPitch].push_back(interval);
        intervalsToPitch[secondPitch].push_back(interval);
    }

    IntervalBatch::IntervalBatch(const std::vector<int>& intLengthBatch, const Scale& scale, const char& direction)
    {
        bool up = direction == 'A' || direction == 'P';
        bool down = direction == 'L' || direction == 'P';
        if (!up && !down)
        {
            throw "Invalid batch";
        }

        for (int intLength : intLengthBatch)
        {
            bool added = false;
            for (int pitch : *scale.getPitchSet())
            {
                if (up && scale.containsPitch(pitch + intLength))
                {
                    added = true;
                    addInterval(pitch, pitch + intLength);
                }
                if (down && scale.containsPitch(pitch - intLength))
                {
                    added = true;
                    addInterval(pitch, pitch - intLength);
                }
            }
            if (!added)
            {
                throw "No intervals added!";
            }
        }
    }

    IntervalBatch::~IntervalBatch()
    {
        for (auto interval : intervals)
        {
            delete interval;
        }
    }

    const Interval* IntervalBatch::getInterval(int id) const
    {
        return intervals.at(id);
    }

    const Interval* IntervalBatch::getRndInterval() const
    {
        return GetRandomElement(intervals);
    }

    const Interval* IntervalBatch::getRndIntervalOfLength(int length) const
    {
        return GetRandomElement(intervalsOfLength.at(std::abs(length)));
    }

    const Interval* IntervalBatch::getRndIntervalFromPitch(int pitch) const
    {
        if (intervalsFromPitch.find(pitch) != intervalsFromPitch.end())
        {
            return GetRandomElement(intervalsFromPitch.at(pitch));
        }
        return NULL;
    }

    const Interval* IntervalBatch::getRndIntervalToPitch(int pitch) const
    {
        if (intervalsToPitch.find(pitch) != intervalsToPitch.end())
        {
            return GetRandomElement(intervalsToPitch.at(pitch));
        }
        return NULL;
    }

    bool IntervalBatch::containsInterval(int length) const
    {
        return intervalsOfLength.find(std::abs(length)) != intervalsOfLength.end();
    }
}
