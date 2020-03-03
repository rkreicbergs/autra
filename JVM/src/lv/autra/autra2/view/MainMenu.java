
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.Insets;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

import lv.autra.autra2.User;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.tools.Text.Language;
import lv.autra.autra2.ui.AutraGui;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class MainMenu extends AutraView
{
    private static final long serialVersionUID = 1L;

    private ArrayList<Button> gameButtons;
    private JLabel avatarLabel;

    public MainMenu()
    {
        super(AutraView.Background.NONE);
        setLayout(new GridBagLayout());

        GridBagConstraints c = new GridBagConstraints();
        c.fill = GridBagConstraints.BOTH;
        c.weighty = 1;

        c.weightx = 0.6;
        c.anchor = GridBagConstraints.LINE_START;
        add(createAvatarPanel(), c);

        c.weightx = 0;
        c.anchor = GridBagConstraints.CENTER;
        add(createMenuPanel(), c);

        c.weightx = 1;
        c.anchor = GridBagConstraints.LINE_END;
        add(createRightSidePanel(), c);
    }

    private JPanel createAvatarPanel()
    {
        final Image backgroundImage = getBackgroundImage(Background.LEFT_TREE);
        JPanel avatarPanel = new JPanel(new GridBagLayout())
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void paintComponent(Graphics g)
            {
                int width = this.getWidth();
                int imageWidth = backgroundImage.getWidth(this);
                g.drawImage(backgroundImage,
                            0,
                            0,
                            width,
                            AutraGui.CONTENT_HEIGHT,
                            imageWidth - width,
                            0,
                            imageWidth,
                            AutraGui.CONTENT_HEIGHT,
                            this);
            }
        };

        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.SOUTHWEST;
        c.weighty = 1;
        c.weightx = 1;
        c.insets = new Insets(0, 5, 0, 0);

        avatarLabel = new JLabel();
        avatarPanel.add(avatarLabel, c);
        return avatarPanel;
    }

    private JPanel createMenuPanel()
    {
        JPanel menuPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 0;
        c.insets = new Insets(4, 4, 4, 4);
        c.fill = GridBagConstraints.HORIZONTAL;

        Button profileButton = new Button(Button.Type.Wood180, Text.get("MainMenu.Profile"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                AutraGui.get().openView(new Profile());
            }
        };
        menuPanel.add(profileButton, c);

        gameButtons = new ArrayList<Button>();
        for (final Game game : Game.getAllGames())
        {
            Button gameButton = new Button(Button.Type.Wood180, Text.get(game.nameId))
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    AutraGui.get().openView(new LevelSelect(game));
                }
            };
            gameButtons.add(gameButton);
            menuPanel.add(gameButton, c);
        }

        Button aboutButton = new Button(Button.Type.Wood180, Text.get("MainMenu.About"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                AutraGui.get().openView(new About());
            }
        };
        menuPanel.add(aboutButton, c);

        Button quitButton = new Button(Button.Type.Wood180, Text.get("MainMenu.Quit"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                System.exit(0);
            }
        };
        menuPanel.add(quitButton, c);

        menuPanel.setPreferredSize(menuPanel.getPreferredSize());

        return menuPanel;
    }

    private JPanel createRightSidePanel()
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

        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.SOUTHEAST;
        c.weighty = 1;
        c.weightx = 1;
        c.gridx = 0;
        c.insets = new Insets(5, 5, 5, 5);

        JPanel languagePanel = new JPanel(new GridBagLayout());
        languagePanel.setBackground(new Color(0, 0, 0, 100));
        for (final Language language : Language.values())
        {
            Button languageButton = new Button(language.toString(), "")
            {
                private static final long serialVersionUID = 1L;

                @Override
                public void processMouseClick()
                {
                    if (language != Text.getLanguage())
                    {
                        Text.setLanguage(language);
                        AutraGui.get().reloadGui();
                    }
                }
            };
            languagePanel.add(languageButton, c);
        }

        rightSidePanel.add(languagePanel, c);
        return rightSidePanel;
    }

    @Override
    public void prepare()
    {
        boolean activeUserSet = User.activeUser != null;

        if (activeUserSet)
        {
            String avatarFile = String.format("/images/avatars/%s.png", User.activeUser.avatar);
            avatarLabel.setIcon(new ImageIcon(this.getClass().getResource(avatarFile)));
        }
        for (Button gameButton : gameButtons)
        {
            gameButton.setEnabled(activeUserSet);
        }
    }

    @Override
    public String getTitle()
    {
        return Text.get("MainMenu.Title");
    }
}
