
package lv.autra.autra2.activity;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import lv.autra.autra2.R;
import lv.autra.autra2.game.ChoiceLevelExecutor;

public class ChoiceLevel extends LevelView
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.choice_level);
        textView = (TextView)findViewById(R.id.choice_level_text);
        timeView = (TextView)findViewById(R.id.choice_level_time);

        if (checkForNewLevel(true))
        {
          executor = new ChoiceLevelExecutor(level);
        }
        executor.assignView(this);

        prepareButtons();
    }

    @Override
    protected void prepareControlButtons()
    {
        final Button startButton = (Button)findViewById(R.id.choice_level_start);
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
        LinearLayout layout = (LinearLayout)findViewById(R.id.choice_level_triggers);
        LayoutParams layoutParams = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);

        String tNames[] = level.getTriggerNames();
        for (int i = 0; i < tNames.length; ++i)
        {
            final int triggerId = i;
            final Button triggerButton = new Button(ChoiceLevel.this);
            triggerButton.setText(tNames[i]);
            triggerButton.setOnClickListener(new View.OnClickListener()
            {
                public void onClick(View view)
                {
                    ((ChoiceLevelExecutor)executor).processClick(triggerId);
                }
            });
            triggerButton.setAllCaps(false);
            layout.addView(triggerButton, layoutParams);
            patternButtons.add(triggerButton);
        }
    }  
}
