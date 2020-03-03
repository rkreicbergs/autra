
package lv.autra.autra2.game;

import lv.autra.autra2.AutraJni;
import lv.autra.autra2.tools.Midi;

public class ChoiceLevelExecutor extends Executor
{
    protected static final int lateClickDelay = 2000;
    protected static final int regenerationPauseLength = 1000;

    public ChoiceLevelExecutor(final Level level)
    {
        super(level);
    }

    @Override
    protected boolean onButtonEnable()
    {
        if (hasStarted())
        {
            AutraJni.generateMelody();
            int length = Midi.loadAndStart();
            scheduleReset(length + lateClickDelay, regenerationPauseLength);
        }
        return true;
    }
    
    public void processClick(int triggerId)
    {
        if (hasStarted())
        {
            int newPoints = AutraJni.checkMultichoiceAnswer(triggerId);
            addPoints(newPoints);
            Midi.stop();
            scheduleReset(0, regenerationPauseLength);
        }
        else
        {
            AutraJni.generateTrigger(triggerId);
            int length = Midi.loadAndStart();
            scheduleReset(0, length + regenerationPauseLength);
        }
    }
}
