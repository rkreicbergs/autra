#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_set>

#include "Game/Common/Scale.h"

namespace AutraLib
{
    class Interval
    {
    public:
        static std::vector<const std::string*> getIntervalNames(const std::initializer_list<int> intLengthBatch);

        const int first;
        const int second;

        Interval(int first, int second);
        int getLength() const;
    };

    class IntervalBatch
    {
        std::vector<const Interval*> intervals;

        std::map<int, std::vector<const Interval*>> intervalsOfLength;
        std::map<int, std::vector<const Interval*>> intervalsFromPitch;
        std::map<int, std::vector<const Interval*>> intervalsToPitch;

        void addInterval(int firstPitch, int secondPitch);

    public:
        IntervalBatch(const std::vector<int>& intLengthBatch, const Scale& scale, const char& direction);
        ~IntervalBatch();

        const Interval* getInterval(int id) const;
        const Interval* getRndInterval() const;
        const Interval* getRndIntervalOfLength(int length) const;
        const Interval* getRndIntervalFromPitch(int pitch) const;
        const Interval* getRndIntervalToPitch(int pitch) const;

        bool containsInterval(int length) const;
    };
}
