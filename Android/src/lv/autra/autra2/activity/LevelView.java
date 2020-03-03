
package lv.autra.autra2.activity;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import lv.autra.autra2.R;
import lv.autra.autra2.game.Executor;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.game.Level;
import lv.autra.autra2.ui.ILevelView;

abstract class LevelView extends Activity implements ILevelView
{
    // Note: when rotating, new instances are created, so we need static variables...
    private static Level prevLevel; // Used to check if level has changed
    protected static Executor executor;
    
    static boolean patternButtonsEnabled;
    static boolean controlButtonsEnabled;

    protected Level level;
    
    protected TextView timeView, textView;
    protected ArrayList<Button> controlButtons = new ArrayList<Button>();
    protected ArrayList<Button> patternButtons = new ArrayList<Button>();

    protected boolean checkForNewLevel(boolean enablePatternBtnsOnNew)
    {
        if (level == prevLevel)
        {
            return false;
        }

        if (executor != null)
        {
            executor.stop(false);
        }
        prevLevel = level;
        patternButtonsEnabled = enablePatternBtnsOnNew; 
        controlButtonsEnabled = true; 
        return true;
    }

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        Bundle b = getIntent().getExtras();
        int gameType = b.getInt("gameType");
        int levelId = b.getInt("levelId");
        level = Game.get(gameType).levels[levelId];

        String gameName = getResources().getStringArray(R.array.GameNames)[level.gameType];
        String titleFmt = getResources().getString(R.string.act_level);
        setTitle(String.format(titleFmt, gameName, level.levelId + 1));
    }

    protected abstract void prepareControlButtons();
    protected abstract void preparePatternButtons();

    protected void prepareButtons()
    {
        final Button endButton = (Button)findViewById(R.id.btn_level_end);
        endButton.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View view)
            {
                executor.stop(executor.hasStarted());
                finish();
            }
        });

        prepareControlButtons();
        preparePatternButtons();
        toogleButtons(patternButtonsEnabled);
        toogleControlButtons(controlButtonsEnabled);
    }

    protected void toogleControlButtons(final boolean enabled)
    {
        controlButtonsEnabled = enabled;
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                for (final Button button : controlButtons)
                {
                  button.setEnabled(enabled);
                }
            }
        });
    }
    
    @Override
    public void toogleButtons(final boolean enabled)
    {
        patternButtonsEnabled = enabled;
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                for (final Button button : patternButtons)
                {
                    button.setEnabled(enabled);
                }
            }
        });
    }
    
    @Override
    public void displayTime(final long time)
    {
        final long mins = time / (1000 * 60);
        final long secs = (time / 1000) % 60;
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                timeView.setText(String.format("%02d:%02d", mins, secs));
            }
        });
    }

    @Override
    public void displayPoints(final int totalPoints, final int points)
    {
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                boolean correct = points > 0;
                textView.setTextColor(correct ? Color.GREEN : Color.RED);
                textView.setText(String.format("%d (%s%d)", totalPoints, correct ? "+" : "", points));
            }
        });
    }

    @Override
    public void displayPoints(final int totalPoints)
    {
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                textView.setTextColor(Color.GRAY);
                textView.setText(Integer.toString(totalPoints));
            }
        });
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus)
    {
        if (!hasFocus)
        {
            executor.stop(false);
            finish();
        }
        super.onPause();
    }

    @Override
    public void onLevelDone(final int points)
    {
        runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                Intent i = new Intent(LevelView.this, ResultScreen.class);
                i.putExtra("gameType", level.gameType);
                i.putExtra("levelId", level.levelId);
                i.putExtra("points", points);
                finish();
                startActivity(i);
            }
        });
    }
}
