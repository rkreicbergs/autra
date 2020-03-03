
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraView;

public class About extends AutraView
{
    private static final long serialVersionUID = 1L;

    public About()
    {
        super(AutraView.Background.RIGHT_TREE);

        setLayout(new GridBagLayout());

        GridBagConstraints c = new GridBagConstraints();
        c.anchor = GridBagConstraints.WEST;
        c.fill = GridBagConstraints.BOTH;
        c.gridx = 0;
        c.weightx = 1;
        c.weighty = 1;

        c.insets = new Insets(30, 70, 10, 70);
        add(createAboutPanel("description"), c);
        c.insets = new Insets(10, 70, 10, 70);
        add(createAboutPanel("history"), c);
        c.insets = new Insets(10, 70, 30, 70);
        add(createAboutPanel("team"), c);
    }

    private static JPanel createAboutPanel(String part)
    {
        JPanel aboutPanel = new JPanel(new GridBagLayout());
        aboutPanel.setBackground(new Color(0, 0, 0, 175));
        
        GridBagConstraints c = new GridBagConstraints();
        c.weightx = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.anchor = GridBagConstraints.WEST;
        c.insets = new Insets(10, 30, 10, 10);
        c.gridx = 0;
        JLabel titleLabel = new JLabel(Text.get("About." + part + "Title"));
        titleLabel.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
        aboutPanel.add(titleLabel, c);

        c.insets = new Insets(0, 10, 10, 10);
        JTextArea textArea = new JTextArea(Text.get("About." + part + "Text"));
        textArea.setBackground(new Color(0, 0, 0, 0));
        textArea.setForeground(new Color(230, 230, 230));
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        textArea.setFont(new Font("Comic Sans MS", 0, 16));
        aboutPanel.add(textArea, c);
        
        return aboutPanel;
    }

    @Override
    public String getTitle()
    {
        return Text.get("About.Title");
    }
}
