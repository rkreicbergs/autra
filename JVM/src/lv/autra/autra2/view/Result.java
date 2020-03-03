
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

import lv.autra.autra2.User;
import lv.autra.autra2.game.Level;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraGui;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class Result extends AutraView
{
    private static final long serialVersionUID = 1L;

    private final int levelId;
    private final int points;
    private final int starCount;
    private final boolean highscore;
    
    public Result(Level level, int points)
    {
        super(AutraView.Background.PLAIN);
        levelId = level.levelId;
        this.points = points;
        highscore = level.updateScore(points);
        starCount = level.getStarCount(points);

        setLayout(new GridBagLayout());

        GridBagConstraints c = new GridBagConstraints();
        c.fill = GridBagConstraints.HORIZONTAL;
        c.weighty = 1;
        c.insets = new Insets(0, 50, 0, 50);

        add(createSummaryPanel(), c);

        c.anchor = GridBagConstraints.SOUTH;
        add(createAvatarPanel(starCount), c);
    }

    private JPanel createSummaryPanel()
    {
        JPanel summaryPanel = new JPanel(new GridBagLayout());
        summaryPanel.setBackground(new Color(0, 0, 0, 100));

        GridBagConstraints c = new GridBagConstraints();
        c.insets = new Insets(10, 10, 10, 10);

        c.gridx = 0;
        summaryPanel.add(new JLabel(Text.get("Result.Level"), JLabel.RIGHT), c);
        summaryPanel.add(new JLabel(Text.get("Result.Points"), JLabel.RIGHT), c);
        summaryPanel.add(new JLabel(Text.get("Result.StarCount"), JLabel.RIGHT), c);
        c.gridx = 1;
        summaryPanel.add(new JLabel(Integer.toString(levelId)), c);
        summaryPanel.add(new JLabel(Integer.toString(points)), c);
        summaryPanel.add(new JLabel(String.format("%d / 3", starCount)), c);

        c.gridx = 0;
        c.gridwidth = 2;
        if (highscore)
        {
            summaryPanel.add(new JLabel(Text.get("Result.Highscore"), JLabel.RIGHT), c);
        }

        for (Component comp : summaryPanel.getComponents())
        {
            comp.setFont(new Font("Arial", 0, 50));
        }

        Button closeButton = new Button(Button.Type.Wood120, Text.get("Result.Close"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                AutraGui.get().closeView(false);
            }
        };
        summaryPanel.add(closeButton, c);

        return summaryPanel;
    }

    private JLabel createAvatarPanel(int starCount)
    {
        String avatarFile = String.format("/images/avatars/%s_%s.png", User.activeUser.avatar, starCount);
        return new JLabel(new ImageIcon(this.getClass().getResource(avatarFile)));
    }

    @Override
    public String getTitle()
    {
        return Text.get("Result.ViewTitle");
    }
}
