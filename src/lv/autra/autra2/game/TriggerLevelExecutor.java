
package lv.autra.autra2.game;

import lv.autra.autra2.AutraJni;
import lv.autra.autra2.tools.Midi;

public class TriggerLevelExecutor extends Executor
{
    private static final int triggerDelay = 400;

    private boolean melodyLoaded = false;
    
    public TriggerLevelExecutor(final Level level)
    {
        super(level);
    }

    @Override
    public void start()
    {
        AutraJni.generateMelody();
        super.start();
    }

    @Override
    protected boolean onButtonEnable()
    {
        if (!melodyLoaded && hasStarted())
        {
            Midi.loadAndStart();
            melodyLoaded = true;
        }
        return hasStarted();
    }

    public void processClick()
    {
        int passedTime = Midi.getPassedTime();
        int points = AutraJni.checkTriggerAnswer(passedTime);
        addPoints(points);
        scheduleReset(0, triggerDelay);
    }

    public void playTrigger(int triggerId)
    {
        AutraJni.generateTrigger(triggerId);
        int length = Midi.loadAndStart();
        scheduleReset(0, length + triggerDelay);
    }
}
