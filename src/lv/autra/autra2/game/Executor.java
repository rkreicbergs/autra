
package lv.autra.autra2.game;

import java.util.TimerTask;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import lv.autra.autra2.AutraJni;
import lv.autra.autra2.tools.Midi;
import lv.autra.autra2.ui.ILevelView;

public abstract class Executor
{
    private static final int initialDelay = 400;

    private final ScheduledExecutorService displayScheduler;
    private ScheduledExecutorService resetScheduler;

    private ILevelView levelView;

    private int points;
    private boolean started = false;

    public Executor(final Level level)
    {
        AutraJni.loadLevel(level.gameType, level.levelId);
        points = 0;
        displayScheduler = Executors.newScheduledThreadPool(1);
        resetScheduler = Executors.newScheduledThreadPool(1);
    }
    
    public void assignView(final ILevelView levelView)
    {
        this.levelView = levelView;
    }

    protected void addPoints(int points)
    {
        this.points += points;
        levelView.displayPoints(this.points, points);
    }

    public boolean hasStarted()
    {
        return started;
    }

    public void stop(boolean gracefully)
    {
        displayScheduler.shutdown();
        resetScheduler.shutdown();
        Midi.stop();
        if (gracefully)
        {
          levelView.onLevelDone(points);
        }
    }

    public void start()
    {
        started = true;
        Midi.stop();
        scheduleReset(0, initialDelay);

        int length = AutraJni.getLevelLength();

        levelView.displayTime(length);
        final long endTime = System.currentTimeMillis() + length + initialDelay;
        displayScheduler.scheduleAtFixedRate(new Runnable()
        {
            public void run()
            {
                long timeLeft = Math.max(0, endTime - System.currentTimeMillis());
                levelView.displayTime(timeLeft);
                if (timeLeft == 0)
                {
                    stop(true);
                }
            }
        }, 0, 10, TimeUnit.MILLISECONDS);
    }

    // Process button re-enabling and return delay for next reset
    protected abstract boolean onButtonEnable();

    /// Disable buttons for @length@ miliseconds after @delay@ miliseconds
    protected void scheduleReset(final int delay, final int length)
    {
        resetScheduler.shutdownNow();
        resetScheduler = Executors.newScheduledThreadPool(1);

        TimerTask resetTask = new TimerTask()
        {
            @Override
            public void run()
            {
                levelView.toogleButtons(false);
                TimerTask enableTask = new TimerTask()
                {
                    @Override
                    public void run()
                    {
                        
                        if (onButtonEnable())
                        {
                            levelView.toogleButtons(true);
                            levelView.displayPoints(points);
                        }
                    };
                };
                resetScheduler.schedule(enableTask, length, TimeUnit.MILLISECONDS);
            }
        };
        resetScheduler.schedule(resetTask, delay, TimeUnit.MILLISECONDS);
    }
}
