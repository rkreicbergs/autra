
package lv.autra.autra2.view;

import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.Insets;

import javax.swing.JPanel;

import lv.autra.autra2.Main;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.game.Level;
import lv.autra.autra2.ui.AutraGui;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class LevelSelect extends AutraView
{
    private static final long serialVersionUID = 1L;

    private final Game game;
    private int curTabIdx = 0;

    private final JPanel contentPanel = new JPanel();
    private final JPanel rightSidePanel;

    public LevelSelect(Game game)
    {
        super(AutraView.Background.NONE);
        this.game = game;

        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(0, 0, 0, 0);
        c.fill = GridBagConstraints.BOTH;
        c.weighty = 1;

        c.weightx = 0.1;
        c.anchor = GridBagConstraints.WEST;
        add(createTabPanel(), c);

        c.weightx = 1;
        c.anchor = GridBagConstraints.EAST;
        rightSidePanel = createLevelPanel();
        add(rightSidePanel, c);

        resetLevels();
    }

    private JPanel createTabPanel()
    {
        JPanel tabSelectorPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        int pad = (game.tabSizes.length > 4) ? 3 : 20;
        c.insets = new Insets(pad, 0, pad, 0);
        c.gridx = 0;

        for (int i = 0; i < game.tabSizes.length; ++i)
        {
            final int tabIdx = i;
            Button tabSelectButton = new Button(Button.Type.Wood60, Integer.toString(tabIdx + 1))
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    curTabIdx = tabIdx;
                    resetLevels();
                }
            };
            tabSelectorPanel.add(tabSelectButton, c);
        }

        return tabSelectorPanel;
    }

    private JPanel createLevelPanel()
    {
        final Image backgroundImage = getBackgroundImage(Background.RIGHT_TREE);
        JPanel rightSidePanel = new JPanel(new GridBagLayout())
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void paintComponent(Graphics g)
            {
                g.drawImage(backgroundImage, 0, 0, this);
            }
        };
        rightSidePanel.add(contentPanel);
        return rightSidePanel;
    }

    private void resetLevels()
    {
        contentPanel.setVisible(false);
        contentPanel.removeAll();

        contentPanel.setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(10, 10, 10, 10);
        c.gridx = 0;

        for (int i = 0; i < game.tabSizes[curTabIdx]; ++i)
        {
            final Level level = game.levels[game.tabStartLevelId[curTabIdx] + i];
            boolean available = true;
            if (Main.enableAllLevels)
            {
                available = true;
            }

            String labelStr = String.format("%d (%d*)", level.levelId + 1, level.starCount);
            Button levelButton = new Button(level.starCount, labelStr)
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    if (level.isTriggerLevel())
                    {
                        AutraGui.get().openView(new TriggerLevel(level));
                    }
                    else
                    {
                        AutraGui.get().openView(new ChoiceLevel(level));
                    }
                }
            };
            levelButton.setEnabled(available);
            contentPanel.add(levelButton, c);
            c.gridx = (c.gridx + 1) % 5;
        }
        contentPanel.setVisible(true);
        rightSidePanel.repaint();
        AutraGui.get().resetTitle();
    }

    @Override
    public void prepare()
    {
        resetLevels();
    };

    @Override
    public String getTitle()
    {
        return String.format(game.tabNames[curTabIdx]);
    }
}
