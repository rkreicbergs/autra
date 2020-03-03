import os, glob, shutil, re
import common

LEVEL_TEMPLATE = """// This is a generated file

#include "Game/Levels/CTYPE.h"
#include "Game/Game.h"

namespace AutraLib
{
    static const int ExamIds[] = {14, 34, 59, 74, 99, 119};

    void CTYPE::LoadData()
    {
        std::vector<Level*>* allLevels = new std::vector<Level*>();
        allLevels->reserve(LEVEL_COUNT);
ENTRY_DATA

        Game::Register(GameType::GAME, allLevels);
    }
}
"""

INTERVALS = ["T1", "M2", "L2", "M3", "L3", "T4", "_6_", "T5", "M6", "L6", "M7", "L7", "T8", "M9", "L9", "M10", "L10", "T11", "_18", "T12", "M13", "L13",]

def IsExam(S):
  if S == "-" or S == "0":
    return False
  return True


class LevelProcessor(common.Processor):
  def __init__(self, game, gStr):
    super(LevelProcessor, self).__init__(game + "Level", LEVEL_TEMPLATE)
    self.game = game
    self.gStr = gStr
    self.levelId = 0

  def ParseRawLine(self, raw_line):
    entries = raw_line.split()
    self.levelId += 1
    params, dummy = common.FormatArgs(self.gStr, entries)
    return "\n        /* %d */ allLevels->push_back(new CTYPE(%s));" % (self.levelId, params)

  def MakeReplacements(self, code):
    code = super(LevelProcessor, self).MakeReplacements(code)
    code = code.replace("LEVEL_COUNT", str(self.levelId))
    code = code.replace("GAME", self.game)
    code = code.replace("-,", "0,")
    code = code.replace("-)", "0)")
    code = code.replace("-}", "0}")
    return code


class IntLevelProcessor(LevelProcessor):
  def ParseRawLine(self, raw_line):
    for INT in INTERVALS:
      raw_line = raw_line.replace(INT, str(INTERVALS.index(INT)))
    raw_line = raw_line.replace("T", "6")
    return super(IntLevelProcessor, self).ParseRawLine(raw_line)

PROCESSORS = [
    IntLevelProcessor("Interval", "B{.}.{.}.....C..{.}{.}"),
    LevelProcessor("Scale", "B{.}{.}{.}{.}.{.}.{.}"),
    LevelProcessor("Chord", "B{.}.{.}.{.}"),
    LevelProcessor("Pitch", "B......{.}.......{..........................}"),
    LevelProcessor("Rhythm", "B...............{..........................}"),
]
