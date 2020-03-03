#pragma once

#include <vector>
#include <unordered_set>
#include <initializer_list>

#include "MultichoiceLevel.h"

namespace AutraLib
{
    class ChordLevel : public MultichoiceLevel
    {
        const std::vector<int> rChords;
        const int salikums;
        const std::vector<int> tonalities;
        const int registerId;
        const std::vector<int> timbres;

        ChordLevel(const bool &isExam,
                   const std::initializer_list<int> &rChords,
                   const int &salikums,
                   const std::initializer_list<int> &tonalities,
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
