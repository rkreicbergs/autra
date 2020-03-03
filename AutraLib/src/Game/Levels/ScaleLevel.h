#pragma once

#include <vector>
#include <unordered_set>
#include <initializer_list>

#include "MultichoiceLevel.h"

namespace AutraLib
{
    class ScaleLevel : public MultichoiceLevel
    {
        const std::vector<int> rScales;
        const std::vector<int> tonalities;
        const std::vector<int> resources;
        const std::vector<int> rhythmGroups;
        const int rhythmGroupLength;
        const int direction;
        const int registerId;
        const std::vector<int> timbres;

        ScaleLevel(const bool &isExam,
                   const std::initializer_list<int> &rScales,
                   const std::initializer_list<int> &tonalities,
                   const std::initializer_list<int> &resources,
                   const std::initializer_list<int> &rhythmGroups,
                   const int &rhythmGroupLength,
                   const int &direction,
                   const int &registerId,
                   const std::initializer_list<int> &timbres);

    protected:
        int GetExpectedAnswerCount() const;

    public:
        void GenerateMelody();
        void GenerateTrigger(int triggerId) const;

        static void LoadData();
    };
}
