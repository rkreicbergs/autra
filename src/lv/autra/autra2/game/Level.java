
package lv.autra.autra2.game;

import lv.autra.autra2.AutraJni;

public class Level
{
    public final int gameType;
    public final int levelId;
    public final boolean isExam;

    public int maxScore;
    public int starCount;
    public String triggerNames[];

    public Level(int gameType, int levelId)
    {
        this.gameType = gameType;
        this.levelId = levelId;
        maxScore = AutraJni.getScore(gameType, levelId);
        starCount = AutraJni.getStarCount(gameType, levelId, maxScore);
        isExam = AutraJni.isExam(gameType, levelId);
    }

    public boolean isTriggerLevel()
    {
        return AutraJni.isTriggerLevel(gameType, levelId);
    }

    public boolean updateScore(int points)
    {
        if (points <= maxScore)
        {
            return false;
        }
        maxScore = points;
        AutraJni.setScore(gameType, levelId, maxScore);
        starCount = AutraJni.getStarCount(gameType, levelId, maxScore);
        return true;
    }

    public int getStarCount(int points)
    {
        return AutraJni.getStarCount(gameType, levelId, points);
    }

    public String[] getTriggerNames()
    {
        return AutraJni.getTriggerNames();
    }
}
