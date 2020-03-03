import sys

timbremap = [None] * 18

with open('timbremap.txt', 'r') as fin:
  for raw_line in fin.readlines():
    e = raw_line.split()
    timbremap[int(e[0])] = int(e[1])

with open('in.txt', 'r') as fin:
  i = 0
  with open('out.txt', 'w+') as fout:
    for raw_line in fin.readlines():
      i += 1
      entries = raw_line.strip().split(",")
      timbres = []
      for e in entries:
        timbres += [timbremap[int(e)]]
      if timbres[0] == None and len(timbres) == 1:
        timbres = [-1]

      l = ""
      for t in sorted(timbres):
        l += str(t) + ","
      fout.write(l[:-1] + "\n")
