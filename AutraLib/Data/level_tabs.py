import common

LVL_GROUPS_TEMPLATE = """// This is a generated file

#include "Game/Game.h"

namespace AutraLib
{
    std::map<GameType, std::vector<Game::CTYPE>> Game::CTYPEs;

    void Game::LoadLevelTabs()
    {ENTRY_DATA
        });
    }
}
""" 

class LevelGroupPro(common.Processor):
  def __init__(self, ctype, gStr):
    super(LevelGroupPro, self).__init__(ctype, LVL_GROUPS_TEMPLATE)
    self.gStr = gStr
    self.suffix = ""

  def ParseRawLine(self, raw_line):
    entries = raw_line.strip().split('\t')
    if (len(entries) == 1):
      line = self.suffix + "\n        CTYPEs[GameType::%s] = std::vector<CTYPE>({" % entries[0]
      self.suffix = "\n        });\n"
      return line
    params, vVal = common.FormatArgs(self.gStr, entries)
    return "\n            { %s }," % params

PROCESSOR = LevelGroupPro("LevelTab", "..S")
