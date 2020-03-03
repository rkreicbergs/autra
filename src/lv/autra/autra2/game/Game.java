
package lv.autra.autra2.game;

import java.util.Collection;
import java.util.TreeMap;

import lv.autra.autra2.AutraJni;

public class Game
{
    /** Use TreeMap to preserve order */
    private static final TreeMap<Integer, Game> gameMap = new TreeMap<Integer, Game>();

    public static Game get(int gameType)
    {
        return gameMap.get(gameType);
    }

    public static Collection<Game> getAllGames()
    {
        return gameMap.values();
    }

    public static void registerGames()
    {
        new Game(AutraJni.PITCH_GAME, "Game.PITCH");
        new Game(AutraJni.RHYTHM_GAME, "Game.RHYTHM");
        new Game(AutraJni.INTERVAL_GAME, "Game.INTERVAL");
        new Game(AutraJni.SCALE_GAME, "Game.SCALE");
        new Game(AutraJni.CHORD_GAME, "Game.CHORD");
    }

    public final int gameType;
    public final String nameId;

    public final int tabStartLevelId[];
    public final int tabSizes[];
    public final String tabNames[];
    public final Level levels[];

    public static native String[] getGameTabNames(int gameType);

    public static native int[] getGameTabSizes(int gameType);

    private Game(int gameType, String nameId)
    {
        this.gameType = gameType;
        this.nameId = nameId;

        tabStartLevelId = AutraJni.getGameTabStartLevelIds(gameType);
        tabSizes = AutraJni.getGameTabSizes(gameType);
        tabNames = AutraJni.getGameTabNames(gameType);
        
        int levelCount = AutraJni.getLevelCount(gameType);
        levels = new Level[levelCount];

        for (int i = 0; i < levelCount; ++i)
        {
            levels[i] = new Level(gameType, i);
        }
        gameMap.put(gameType, this);
    }
}
