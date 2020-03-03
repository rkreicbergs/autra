package lv.autra.autra2.ui;

import java.awt.Color;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.UIManager;

public final class GuiManager
{
    public static void RegisterGui()
    {
        javax.swing.SwingUtilities.invokeLater(new Runnable()
        {
            @Override
            public void run()
            {
                createAndShowGui();
            }
        });
    }
    
    private static void createAndShowGui()
    {
        setUiDefaults();

        JFrame frame = new JFrame();
        frame.setTitle("AuTra - Aural Training Program");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.add(AutraGui.get());
        frame.setVisible(true);
        frame.setMinimumSize(frame.getPreferredSize());
        frame.pack();
        frame.setLocationRelativeTo(null);
    }

    private static void setUiDefaults()
    {
        Font defaultFont = new Font("Comic Sans MS", Font.BOLD, 16);
        UIManager.put("Button.font", defaultFont);
        UIManager.put("ComboBox.font", defaultFont);
        UIManager.put("Label.font", defaultFont);
        UIManager.put("Panel.font", defaultFont);
        UIManager.put("TextField.font", defaultFont);
        UIManager.put("TitledBorder.font", defaultFont);

        UIManager.put("Panel.background", new Color(0, 0, 0, 0));
        UIManager.put("Label.foreground", new Color(250, 250, 250));
    }
}
