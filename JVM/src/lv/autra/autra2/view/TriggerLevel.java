
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.util.ArrayList;

import javax.swing.JLabel;
import javax.swing.JPanel;

import lv.autra.autra2.game.Level;
import lv.autra.autra2.game.TriggerLevelExecutor;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class TriggerLevel extends LevelView
{
    private static final long serialVersionUID = 1L;

    private ArrayList<Button> controlButtons;
    private Button recognizeButton;

    public TriggerLevel(final Level level)
    {
        super(AutraView.Background.LEVEL, level);
        executor = new TriggerLevelExecutor(level);
        executor.assignView(this);

        setLayout(new GridBagLayout());

        GridBagConstraints c = new GridBagConstraints();
        c.fill = GridBagConstraints.HORIZONTAL;
        c.weighty = 1;
        c.insets = new Insets(50, 50, 0, 0);

        c.anchor = GridBagConstraints.NORTHWEST;
        add(createControlPanel(), c);

        c.anchor = GridBagConstraints.NORTH;
        add(createActionPanel(), c);

        recognizeButton.setEnabled(false);
    }

    private JPanel createControlPanel()
    {
        controlButtons = new ArrayList<Button>();

        JPanel controlPanel = new JPanel(new GridBagLayout());
        controlPanel.setBackground(new Color(0, 0, 0, 100));
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(15, 15, 15, 15);
        c.gridwidth = 2;

        controlPanel.add(new JLabel(Text.get("Level.Recognizable")), c);

        c.gridwidth = 1;
        String triggerNames[] = level.getTriggerNames();
        for (int i = 0; i < triggerNames.length; ++i)
        {
            final int triggerId = i;
            c.gridx = 0;
            controlPanel.add(new JLabel(triggerNames[i]), c);

            Button testMelodyButton = new Button(Button.Type.Wood60, Text.get("Level.Play"))
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    ((TriggerLevelExecutor)executor).playTrigger(triggerId);
                }
            };
            c.gridx = 1;
            controlPanel.add(testMelodyButton, c);
            controlButtons.add(testMelodyButton);
        }

        Button startButton = new Button(Button.Type.Wood180, Text.get("Level.Start"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                disableControlButtons();
                executor.start();
            }
        };
        c.gridx = 0;
        c.gridwidth = 2;
        controlPanel.add(startButton, c);
        controlButtons.add(startButton);
        
        Button endButton = new Button(Button.Type.Wood180, Text.get("Level.End"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                executor.stop(true);
            }
        };
        controlPanel.add(endButton, c);        

        return controlPanel;
    }

    private JPanel createActionPanel()
    {
        JPanel actionPanel = new JPanel(new GridBagLayout());
        actionPanel.setBackground(new Color(0, 0, 0, 100));

        GridBagConstraints c = new GridBagConstraints();
        Font font = new Font("Comic Sans MS", Font.BOLD, 20);

        JLabel timeLeftLabel = new JLabel(Text.get("Level.TimeLeft"));
        timeLeftLabel.setFont(font);
        c.anchor = GridBagConstraints.LINE_START;
        c.insets = new Insets(20, 20, 20, 5);
        actionPanel.add(timeLeftLabel, c);

        timeLabel = new JLabel("");
        timeLabel.setFont(font);
        c.insets = new Insets(20, 5, 20, 10);
        actionPanel.add(timeLabel, c);

        textLabel = new JLabel("");
        textLabel.setFont(font);
        textLabel.setForeground(new Color(255, 230, 0));
        c.anchor = GridBagConstraints.LINE_END;
        c.insets = new Insets(20, 10, 20, 20);
        c.weightx = 1;
        actionPanel.add(textLabel, c);

        recognizeButton = new Button(Button.Type.BigButton, Text.get("Level.RecognizeButton"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMousePressed()
            {
                ((TriggerLevelExecutor)executor).processClick();
            }
        };
        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 0;
        c.gridwidth = 4;
        c.insets = new Insets(30, 30, 30, 30);
        actionPanel.add(recognizeButton, c);

        return actionPanel;
    }

    private void disableControlButtons()
    {
        for (Button button : controlButtons)
        {
            button.setEnabled(false);
        }
        repaint();
    }
    
    @Override
    public void toogleButtons(boolean enabled)
    {
        recognizeButton.setEnabled(enabled);
        repaint();
    }
}
