import os, glob, shutil
import common, helper_data, levels, att_data, level_tabs

DEST_FOLDER = "../src/Data"

def CopyDataFiles():
  for filename in glob.glob(os.path.join("processed", '*.*')):
    shutil.copy(filename, DEST_FOLDER)

def ResetDir(path):
  if os.path.exists(path):
    shutil.rmtree(path)
  os.mkdir(path)


if __name__ == "__main__":
  ResetDir("processed")
  ResetDir(DEST_FOLDER)

  att_data.Process()
  for processor in helper_data.PROCESSORS:
    processor.Process()
  for processor in levels.PROCESSORS:
    processor.Process()
  level_tabs.PROCESSOR.Process()

  CopyDataFiles()
