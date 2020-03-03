HEADER = """// This is a generated file

#include "Game/Common/GAMEPhrase.h"
#include <vector>

namespace AutraLib
{
    std::vector<std::vector<int>> GAMEPhrase::AllGroups;
    std::vector<Phrase*> GAMEPhrase::AllPhrases;

    void GAMEPhrase::LoadData()
    {
"""

#################################################################

  # NOTE: First 3 phrases must be test phrases
def PrintLoadData(phrases, groups, game):
  code = HEADER
  code += "        AllPhrases.reserve(%d);\n" % len(phrases)
  for phrase in phrases:
    code += "        AllPhrases.push_back(new GAMEPhrase(%s));\n" % ", ".join(phrase)

  code += "\n        AllGroups.reserve(%d);\n" % len(groups)
  for group in groups:
    gPhrases = sorted(group[1])
    code += "        AllGroups.push_back(std::vector<int>({%s}));\n" % ", ".join(map(str, gPhrases))

  code += "    }\n}\n"
  code = code.replace("GAME", game)

  with open('processed/%sPhraseData.cpp' % game, "w+") as fout:
    fout.write(code)

###########################################

def ParsePhrases(line, phrases):
  notes = line[2:]
  ids = []  
  for phrase in [notes[x:x+3] for x in xrange(0, len(notes), 3)]:
    if phrase in phrases:
      ids += [phrases.index(phrase)]
    else:
      phrases += [phrase]
      ids += [len(phrases) - 1]
  return [line[1], ids]


def Process():
  pitch_phrases = []
  pitch_groups = []
  rhythm_phrases = []
  rhythm_groups = []

  with open('raw/AttGroups.txt', 'r') as raw_file:
    for raw_line in raw_file.readlines():
      line = raw_line.split()
      if not line:
        continue

      if line[0] == "PitchTest":
        ParsePhrases(line, pitch_phrases)
      if line[0] == "Pitch":
        pitch_groups += [ParsePhrases(line, pitch_phrases)]

      if line[0] == "RhythmTest":
        ParsePhrases(line, rhythm_phrases)
      if line[0] == "Rhythm":
        rhythm_groups += [ParsePhrases(line, rhythm_phrases)]

  assert(len(pitch_groups) == len(rhythm_groups))
  PrintLoadData(pitch_phrases, pitch_groups, "Pitch")
  PrintLoadData(rhythm_phrases, rhythm_groups, "Rhythm")
