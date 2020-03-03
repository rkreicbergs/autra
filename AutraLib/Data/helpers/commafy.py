import sys

with open('in.txt', 'r') as fin:
  i = 0
  with open('out.txt', 'w+') as fout:
    for raw_line in fin.readlines():
      entries = [int(x) for x in raw_line.split()]
      i += 1

      l = ""
      s = 0
      for x in entries:
        s += x
        l += str(s) + ","

      fout.write(l[:-1] + "\n")      
#      l = "%d(%d):\t%s" % (i, len(entries), l)
#      if s > 12:
#        fout.write(l[:-1] + "\n")
