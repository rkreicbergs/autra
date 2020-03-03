import common

DATA_TEMPLATE = """// This is a generated file

#include "Game/Common/CTYPE.h"

namespace AutraLib
{
    DECL

    void CTYPE::LoadData()
    {ENTRY_DATA
    }
}
""" 

class DataProcessor(common.Processor):
  def __init__(self, ctype, gStr):
    super(DataProcessor, self).__init__(ctype, DATA_TEMPLATE)
    self.gStr = gStr

  def ParseRawLine(self, raw_line):
    entries = raw_line.strip().split('\t')
    params, vVal = common.FormatArgs(self.gStr, entries)
    return self.getLine(params, vVal)

  def MakeReplacements(self, code):
    code = code.replace("DECL", self.getDECL())
    return super(DataProcessor, self).MakeReplacements(code)

################################

class MapPoolPro(DataProcessor):
  def getLine(self, params, vVal):
    return "\n        CTYPEPool[%s] = std::vector<int>{%s};" % (vVal, params)
  def getDECL(self):
    return "std::map<int, std::vector<int>> CTYPE::CTYPEPool;"

class VectorPoolPro(DataProcessor):
  def getLine(self, params, vVal):
    return "\n        CTYPEPool.push_back(CTYPE(%s));" % params
  def getDECL(self):
    return "std::vector<CTYPE> CTYPE::CTYPEPool;"

class DescProcessor(DataProcessor):
  def getLine(self, params, vVal):
    return "\n        Descriptors.push_back(CTYPE::Desc(%s));" % params
  def getDECL(self):
    return "std::vector<CTYPE::Desc> CTYPE::Descriptors;"

################################

PROCESSORS = [
    DescProcessor("Chord", "SS{.}"),
    DescProcessor("Scale", "SIS{.}"),
    VectorPoolPro("Register", ".."),
    MapPoolPro("RhythmPattern", "V{.}"),
]
