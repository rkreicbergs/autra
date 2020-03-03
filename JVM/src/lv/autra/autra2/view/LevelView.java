
package lv.autra.autra2.view;

import java.awt.Color;

import javax.swing.JLabel;

import lv.autra.autra2.game.Executor;
import lv.autra.autra2.game.Level;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraGui;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.ILevelView;

abstract class LevelView extends AutraView implements ILevelView
{
    private static final long serialVersionUID = 1L;

    protected final Level level;
    protected Executor executor;
    protected JLabel timeLabel, textLabel;

    protected LevelView(Background background, final Level level)
    {
        super(background);
        this.level = level;
    }

    @Override
    public void displayTime(final long time)
    {
        long mins = time / (1000 * 60);
        long secs = (time / 1000) % 60;
        timeLabel.setText(String.format("%02d:%02d", mins, secs));
        repaint();
    }

    @Override
    public void displayPoints(final int totalPoints, final int points)
    {
        boolean correct = points > 0;
        textLabel.setForeground(correct ? Color.GREEN : Color.RED);
        textLabel.setText(String.format("%d (%s%d)", totalPoints, correct ? "+" : "", points));
        repaint();
    }

    @Override
    public void displayPoints(final int totalPoints)
    {
        textLabel.setForeground(Color.GRAY);
        textLabel.setText(Integer.toString(totalPoints));
    }

    @Override
    public void onLevelDone(final int points)
    {
        AutraGui.get().replaceView(new Result(level, points));
    }

    @Override
    public void onHide()
    {
        executor.stop(false);
    }

    @Override
    public void onBack()
    {
        executor.stop(false);
    };

    @Override
    public String getTitle()
    {
        return String.format("%s, %s %d", Text.get("Game." + level.gameType), Text.get("Level.Number"), level.levelId);
    }
}
