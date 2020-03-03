
package lv.autra.autra2.ui;

import java.awt.Font;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.net.URL;

import javax.swing.ImageIcon;
import javax.swing.JLabel;

public abstract class Button extends JLabel
{
    private static final long serialVersionUID = 1L;
    private static final Font enabledFont = new Font("Comic Sans MS", Font.BOLD, 18);
    private static final Font disabledFont = new Font("Comic Sans MS", 0, 16);

    public static enum Type
    {
        Back,
        BigButton,
        Wood60,
        Wood120,
        Wood150,
        Wood160,
        Wood180,
        PASSED,
        GOOD,
        PERFECT,
        EN,
        LV,
        RU
    }

    private static enum Status
    {
        NORMAL,
        FOCUS,
        CLICK,
        DISABLED,
    }

    //TODO: read images once

    private final Type type;
    private boolean pressed = false;
    private boolean mouseOver = false;

    public Button(String typeStr, String textToShow)
    {
        this(Type.valueOf(typeStr), textToShow);
    }

    static private Type starCountToType(int starCount)
    {
        switch (starCount)
        {
        case 3:
            return Type.PERFECT;
        case 2:
            return Type.GOOD;
        case 1:
            return Type.PASSED;
        default:
            return Type.Wood150;
        }
    }

    public Button(int starCount, String textToShow)
    {
        this(starCountToType(starCount), textToShow);
    }

    public Button(Type type, String textToShow)
    {
        this.type = type;
        this.setText(textToShow);
        setHorizontalTextPosition(JLabel.CENTER);
        addMouseListener(createMouseListener());
        setEnabled(true);
        URL disabledIconURL = getImageUrl(Status.DISABLED);
        if (disabledIconURL != null)
        {
            setDisabledIcon(new ImageIcon(disabledIconURL));
        }
    }

    private Status getStatus()
    {
        if (pressed)
        {
            return Status.CLICK;
        }
        if (mouseOver)
        {
            return Status.FOCUS;
        }
        return Status.NORMAL;
    }

    private URL getImageUrl(Status status)
    {
        String imagePath = String.format("/images/buttons/%s_%s.png", type, status);
        URL imageURL = this.getClass().getResource(imagePath);
        if (imageURL == null)
        {
            imagePath = String.format("/images/buttons/%s.png", type);
            imageURL = this.getClass().getResource(imagePath);
        }
        return imageURL;
    }

    private void resetImage()
    {
        Status status = getStatus();
        URL imageURL = getImageUrl(status);
        setIcon(new ImageIcon(imageURL));
        repaint();
    }

    @Override
    public void setEnabled(boolean enabled)
    {
        super.setEnabled(enabled);
        setFont(enabled ? enabledFont : disabledFont);
        resetImage();
    }

    private MouseListener createMouseListener()
    {
        return new MouseListener()
        {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                if (isEnabled())
                {
                    processMouseClick();
                }
            }

            @Override
            public void mouseEntered(MouseEvent e)
            {
                mouseOver = true;
                resetImage();
            }

            @Override
            public void mouseExited(MouseEvent e)
            {
                mouseOver = false;
                resetImage();
            }

            @Override
            public void mousePressed(MouseEvent e)
            {
                pressed = true;
                resetImage();
                if (isEnabled())
                {
                    processMousePressed();
                }
            }

            @Override
            public void mouseReleased(MouseEvent e)
            {
                pressed = false;
                resetImage();
            }
        };
    }

    public void processMouseClick()
    {
    }

    public void processMousePressed()
    {
    }
}
