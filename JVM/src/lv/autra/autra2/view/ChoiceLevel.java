
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.util.ArrayList;

import javax.swing.JLabel;
import javax.swing.JPanel;

import lv.autra.autra2.game.ChoiceLevelExecutor;
import lv.autra.autra2.game.Level;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class ChoiceLevel extends LevelView
{
    private static final long serialVersionUID = 1L;

    private ArrayList<Button> triggerButtons;

    public ChoiceLevel(final Level level)
    {
        super(AutraView.Background.LEVEL, level);
        executor = new ChoiceLevelExecutor(level);
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
    }

    private JPanel createControlPanel()
    {
        JPanel controlPanel = new JPanel(new GridBagLayout());
        controlPanel.setBackground(new Color(0, 0, 0, 100));
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(15, 15, 15, 15);

        Button startButton = new Button(Button.Type.Wood180, Text.get("Level.Start"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                setEnabled(false);
                executor.start();
            }
        };
        controlPanel.add(startButton, c);

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

        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 0;
        c.gridwidth = 4;
        c.insets = new Insets(30, 30, 30, 30);
        actionPanel.add(createTriggerPanel(), c);

        return actionPanel;
    }

    private JPanel createTriggerPanel()
    {
        JPanel triggerPanel = new JPanel(new GridBagLayout());
        triggerButtons = new ArrayList<Button>();

        GridBagConstraints c = new GridBagConstraints();
        c.gridx = 0;
        c.insets = new Insets(20, 10, 20, 20);
        String triggerNames[] = level.getTriggerNames();
        for (int i = 0; i < triggerNames.length; ++i)
        {
            final int triggerId = i;
            Button triggerButton = new Button(Button.Type.Wood180, triggerNames[i])
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    ((ChoiceLevelExecutor)executor).processClick(triggerId);
                }
            };
            triggerPanel.add(triggerButton, c);
            triggerButtons.add(triggerButton);
        }

        return triggerPanel;
    }

    @Override
    public void toogleButtons(boolean enabled)
    {
        for (Button triggerButton : triggerButtons)
        {
            triggerButton.setEnabled(enabled);
        }
        repaint();
    }
}
