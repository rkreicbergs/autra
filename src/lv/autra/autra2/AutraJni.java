package lv.autra.autra2;

public class AutraJni
{
    public static final int PITCH_GAME = 0;
    public static final int RHYTHM_GAME = 1;
    public static final int INTERVAL_GAME = 2;
    public static final int SCALE_GAME = 3;
    public static final int CHORD_GAME = 4;

    public static final String MIDI_FILE_NAME = "autra.mid";

    private static native void initLibrary(String dataFolder, String username);

    public static native int getLevelCount(int gameType);
    public static native boolean isExam(int gameType, int levelId);
    public static native boolean isTriggerLevel(int gameType, int levelId);

    public static native String[] getGameTabNames(int gameType);
    public static native int[] getGameTabSizes(int gameType);
    public static native int[] getGameTabStartLevelIds(int gameType);

    public static native void loadLevel(int gameType, int levelId);
    public static native String[] getTriggerNames();

    public static native void generateMelody();
    public static native void generateTrigger(int triggerId);

    public static native int getLevelLength();
    public static native int checkMultichoiceAnswer(int triggerId);
    public static native int checkTriggerAnswer(int relTimeMiliseconds);

    public static native void reloadScore(String username);
    public static native int getScore(int gameType, int levelId);
    public static native void setScore(int gameType, int levelId, int score);
    public static native int getStarCount(int gameType, int levelId, int score);

    public static void loadJniLibrary(String dataFolder, String username) 
    {
        System.loadLibrary("AutraJni");
        initLibrary(dataFolder, username);
    }
}
