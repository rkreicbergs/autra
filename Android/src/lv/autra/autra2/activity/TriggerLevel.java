
package lv.autra.autra2.activity;

import android.util.Log;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import lv.autra.autra2.R;
import lv.autra.autra2.game.TriggerLevelExecutor;

public class TriggerLevel extends LevelView
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.trigger_level);
        textView = (TextView)findViewById(R.id.trigger_level_text);
        timeView = (TextView)findViewById(R.id.trigger_level_time);

        if (checkForNewLevel(false))
        {
        	executor = new TriggerLevelExecutor(level);
        }
        executor.assignView(this);

        prepareButtons();
    }

    @Override
    protected void prepareControlButtons()
    {
        LinearLayout layout = (LinearLayout)findViewById(R.id.trigger_level_triggers);
        LayoutParams layoutParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);

        String tNames[] = level.getTriggerNames();
        for (int i = 0; i < tNames.length; ++i)
        {
            final int triggerId = i;
            Button triggerButton = new Button(TriggerLevel.this);
            triggerButton.setText(tNames[i]);
            triggerButton.setOnClickListener(new View.OnClickListener()
            {
                public void onClick(View view)
                {
                    ((TriggerLevelExecutor)executor).playTrigger(triggerId);
                }
            });
            triggerButton.setAllCaps(false);
            layout.addView(triggerButton, layoutParams);
            controlButtons.add(triggerButton);
        }

        Button startButton = (Button)findViewById(R.id.trigger_level_start);
        startButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View view)
            {
            	toogleControlButtons(false);
                executor.start();
            }
        });
        controlButtons.add(startButton);
    }
    
    @Override
    protected void preparePatternButtons()
    {
        Button recognizeButton = (Button)findViewById(R.id.trigger_level_recognize);
        recognizeButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View view)
            {
                ((TriggerLevelExecutor)executor).processClick();
            }
        });
        patternButtons.add(recognizeButton);
    }    
}
