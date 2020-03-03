#pragma once

#include <vector>
#include <unordered_set>
#include <initializer_list>

#include "TriggerLevel.h"
#include "Game/Common/IntervalBatch.h"

namespace AutraLib
{
    class IntervalLevel : public TriggerLevel
    {
        std::vector<int> rsIntLengthBatch;
        const int rsCount;
        std::vector<int> isIntLengthBatch;
        const int isCount;
        const int pauseCount;
        const int pauseLength;
        const int noteCount;
        const int noteLength;
        const char direction;
        const int registerId;
        const int scaleId;
        const std::vector<int> tonalities;
        const std::vector<int> timbres;

        int length;
        int timbre;
        Scale* scale;
        IntervalBatch* rsIntervalBatch;
        IntervalBatch* isIntervalBatch;

        bool hasRsBefore(const std::vector<int> &notes, int idx, int pitch) const;
        bool hasRsAfter(const std::vector<int> &notes, int idx, int pitch) const;
        std::unordered_set<int> addRandomIntervals(std::vector<int> &notes, const IntervalBatch* intervalBatch, int count) const;

        IntervalLevel(const bool &isExam,
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
                      const std::initializer_list<int> &timbres);

    public:
        void Load();
        void Unload();

        void GenerateMelody();
        void GenerateTrigger(int triggerId) const;
        int GetLevelLength() const;

        static void LoadData();
    };
}
