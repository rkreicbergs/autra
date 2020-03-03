
package lv.autra.autra2.ui;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public abstract class AutraView extends JPanel
{
    private static final long serialVersionUID = 1L;
    
    public static enum Background
    {
        NONE,
        LEFT_TREE,
        RIGHT_TREE,
        LEVEL,
        PLAIN
    }

    final Image backgroundImage;

    protected AutraView(Background background)
    {
        setPreferredSize(new Dimension(AutraGui.GUI_WIDTH, AutraGui.CONTENT_HEIGHT));
        backgroundImage = getBackgroundImage(background);
    }

    protected Image getBackgroundImage(Background background)
    {
        if (background == Background.NONE)
        {
            return null;
        }

        String imagePath = String.format("/images/%s.jpg", background);
        ImageIcon imageIcon = new ImageIcon(this.getClass().getResource(imagePath));
        return imageIcon.getImage();
    }

    @Override
    public void paintComponent(Graphics g)
    {
        g.drawImage(backgroundImage, 0, 0, this);
    }

    public void prepare()
    {
    };

    public void onBack()
    {
    };

    public void onHide()
    {
    };

    public abstract String getTitle();
}
