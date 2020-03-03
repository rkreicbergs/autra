import codecs

def GetBool(s):
  if s == "0" or s == "-":
    return "false"
  return "true"

def FormatArgs(gStr, args):
  it = iter(args)
  res = ""
  vVal = None
  for c in gStr:
    if c == "S":
      res += "\"%s\"" % next(it)
    elif c == "C":
      res += "'%s'" % next(it)
    elif c == "B":
      res += GetBool(next(it))
    elif c == "V":
      vVal = next(it)
      continue
    elif c == "I":
      next(it)
      continue
    elif c == ".":
      res += "%s" % next(it)
    elif c == "}":
      res = res[:-2] + c
    elif c == "{":
      res += c
      continue
    else:
      raise "Invalid char: %s" %c
    res += ", "

  n = next(it, None)
  if n != None:
    print "n:", n
    print args
    print res
    print "\n"
  assert(None == n)
  return res[:-2], vVal


class Processor(object):
  def __init__(self, ctype, template):
    self.ctype = ctype
    self.template = template
    assert("CTYPE" in template)
    assert("ENTRY_DATA" in template)

  def ParseRawLine(self, raw_line):
    raise "Not implemented"

  def MakeReplacements(self, code):
    code = code.replace("ENTRY_DATA", self.entryData)
    return code.replace("CTYPE", self.ctype)

  def Process(self):
    self.entryData = ""

    with open('raw/%s.txt' % self.ctype, 'r') as input_file:
      for raw_line in input_file.readlines():
        self.entryData += self.ParseRawLine(raw_line)
 
    code = self.template
    code = self.MakeReplacements(code)

    with open('processed/%sData.cpp' % self.ctype, 'w+') as output_file:
      output_file.write(codecs.BOM_UTF8)
      output_file.write(code)
