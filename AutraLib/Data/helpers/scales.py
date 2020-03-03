import sys

intScales = []
with open('IntScales.txt', 'r') as fin:
  for raw_line in fin.readlines():
    entries = [int(x) for x in raw_line.split(',')]

    scale = "0,"
    for i in xrange(1, len(entries)):
      scale += str(entries[i] - entries[i-1]) + ","

    intScales += [scale[:-1]]

with open('raw/Scale.txt', 'w+') as fin:
  for scale in intScales:
    fin.write(scale + "\n")


scaScales = []
origScaScales = []
with open('ScaScales.txt', 'r') as fin:
  for raw_line in fin.readlines():
    line = raw_line.split()[0]
    notes = line.split(",")
    s = 0
    for n in notes:
      s += int(n)
    origScaScales += [line]
    if s == 12:
      line = line[:-2]
    scaScales += [line]

parsed = set()
for i in xrange(len(origScaScales)):
  sc = [i]
  if i in parsed:
    continue
  for j in xrange(i + 1, len(origScaScales)):
    if origScaScales[i] == origScaScales[j] and j not in parsed:
      sc += [j]
      parsed.add(j)
  if len(sc) > 1:
    print "<%s>:\t" % origScaScales[i], sc

m = [None] * len(intScales)
t = []
for i in xrange(len(intScales)):
  for j in xrange(len(scaScales)):
    if intScales[i] == scaScales[j]:
      m[i] = j
      t += [j]
      break
#print sorted(t)

with open('intlvl.txt', 'r') as fin:
  for raw_line in fin.readlines():
    sca = raw_line.split()[0]
    print m[int(sca)]
