#include <unordered_set>

#include "AttentionLevel.h"
#include "Game/Score.h"
#include "Core/Rnd.h"

namespace AutraLib
{
    static const std::string T1Name = "T1";
    static const std::string T2Name = "T2";
    static const std::string T3Name = "T3";
    static const int TriggerNameCount = 3;

    const std::vector<const std::string*> GetTriggerNames(const int &T1Count, const int &T2Count, const int &T3Count)
    {
        std::vector<const std::string*> names;
        if (T1Count > 0)
        {
            names.push_back(&T1Name);
        }
        if (T2Count > 0)
        {
            names.push_back(&T2Name);
        }
        if (T3Count > 0)
        {
            names.push_back(&T3Name);
        }
        return names;
    }

    AttentionLevel::AttentionLevel(const bool &isExam,
                                   const int &T1Count,
                                   const int &T2Count,
                                   const int &T3Count,
                                   const int &pauseCount,
                                   const int &pauseLength,
                                   const int &noteCount,
                                   const int &noiseTimbre,
                                   const int &noiseCount,
                                   const int &noiseLength,
                                   const int &noiseVolume,
                                   const std::vector<int> &phrasePool)
        : TriggerLevel(isExam, GetTriggerNames(T1Count, T2Count, T3Count), T1Count + T2Count + T3Count)
        , TCount({ T1Count, T2Count, T3Count })
        , tCountSum(T1Count + T2Count + T3Count)
        , pauseCount(pauseCount)
        , pauseLength(pauseLength)
        , noteCount(noteCount)
        , noiseTimbre(noiseTimbre)
        , noiseCount(noiseCount)
        , noiseLength(noiseLength)
        , noiseVolume(noiseVolume)
        , phrasePool(phrasePool)
    {
        if (TCount.size() != TriggerNameCount)
        {
            throw("Trigger counts don't match!");
        }
    }

    static void AddTPhrases(std::vector<int> &phrases, std::unordered_set<int>& indeces, int tCount, int tNum)
    {
        size_t maxPos = phrases.size() - 1;
        while (tCount > 0)
        {
            int idx = RndInt(maxPos);
            if (phrases[idx] == -1 &&
                phrases[idx + 1] == -1 &&
                (idx == 0 || phrases[idx - 1] != tNum) &&
                (idx + 2 > (int)maxPos || phrases[idx + 2] != tNum))
            {
                indeces.insert(idx + 1);
                phrases[idx] = tNum;
                phrases[idx + 1] = tNum;
                --tCount;
            }
        }
    }

    static void FillWithRandom(std::vector<int> &phrases, const std::vector<int> &phrasePool, int pCnt, int pauseCount)
    {
        const int size = (int)phrases.size();
        for (int idx = 0; idx < size; ++idx)
        {
            if (phrases[idx] != -1) // T-phrase
            {
                continue;
            }
            if (RndBool(pauseCount, pCnt)) // Pause
            {
                --pauseCount;
                continue;
            }
            --pCnt; // Random phrase
            do
            {
                phrases[idx] = phrasePool[RndInt(phrasePool.size())];
            } while ((idx > 0 && phrases[idx - 1] == phrases[idx]) ||
                     (idx < size - 1 && phrases[idx + 1] == phrases[idx]));
        }
    }

    void AttentionLevel::GenerateMelody(const std::vector<Phrase*>& AllPhrases, int timbre)
    {
        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbre));

        int tPhraseCount = (TCount[0] + TCount[1] + TCount[2]) * 2;
        int phraseCount = noteCount / 3 - tPhraseCount;
        if (phraseCount < 0)
        {
            throw "Invalid phrase count";
        }

        // Will with pauses (-1)
        std::vector<int> phrases(tPhraseCount + phraseCount + pauseCount, -1);
        // Add test phrases
        std::unordered_set<int> tIndeces;
        for (int i = 0; i < TriggerNameCount; ++i)
        {
            AddTPhrases(phrases, tIndeces, TCount[i], i);
        }
        // Fill the rest
        FillWithRandom(phrases, phrasePool, phraseCount, pauseCount);

        for (unsigned int idx = 0; idx < phrases.size(); ++idx)
        {
            const int phraseId = phrases[idx];
            if (phraseId == -1)
            {
                midiWriter.AddEvent(PauseEvent(pauseLength));
                continue;
            }
            AllPhrases[phraseId]->AddNotes(midiWriter);
            if (tIndeces.find(idx) != tIndeces.end())
            {
                TriggerLevel::addTimestamp(midiWriter.GetTime() - DEFAULT_NOTE_LENGTH);
            }
        }
        length = midiWriter.GetTime();
        midiWriter.Write();
    }

    void AttentionLevel::GenerateTrigger(Phrase* phrase, int timbre) const
    {
        MidiWriter midiWriter;
        midiWriter.AddEvent(TimbreEvent(timbre));
        phrase->AddNotes(midiWriter);
        phrase->AddNotes(midiWriter);
        midiWriter.Write();
    }

    int AttentionLevel::GetLevelLength() const
    {
        return length;
    }
}
