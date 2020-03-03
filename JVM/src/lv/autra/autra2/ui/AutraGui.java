
package lv.autra.autra2.ui;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.util.Stack;

import javax.swing.JLabel;
import javax.swing.JPanel;

import lv.autra.autra2.User;
import lv.autra.autra2.view.MainMenu;

public class AutraGui extends JPanel
{
    private static final long serialVersionUID = 1L;

    public static final int GUI_WIDTH = 1000;
    public static final int CONTENT_HEIGHT = 600;
    public static final Color BACKGROUND_COLOR = new Color(0, 0, 0, 255);

    private static final int FOOTER_HEIGHT = 60;

    private JLabel titleLabel, userNameLabel;
    private Button backButton;
    private JPanel contentPane;
    private final Stack<AutraView> viewStack;

    private static AutraGui singleton = null;

    AutraGui()
    {
        viewStack = new Stack<AutraView>();

        this.setBackground(BACKGROUND_COLOR);
        setLayout(new BorderLayout());

        this.setMinimumSize(new Dimension(GUI_WIDTH, CONTENT_HEIGHT + FOOTER_HEIGHT));

        // Make a transparent content panel
        contentPane = new JPanel();

        add(contentPane, BorderLayout.CENTER);

        add(createFooterPanel(), BorderLayout.PAGE_END);

        reloadGui();
    }

    public static AutraGui get()
    {
        if (singleton == null)
        {
            singleton = new AutraGui();
        }
        return singleton;
    }

    public void reloadGui()
    {
        while (viewStack.size() > 0)
        {
            AutraView view = viewStack.pop();
            view.setVisible(false);
        }
        openView(new MainMenu());
    }

    private JPanel createFooterPanel()
    {
        JPanel footerPanel = new JPanel(new BorderLayout());
        footerPanel.setBackground(new Color(0, 0, 0, 255));
        footerPanel.setPreferredSize(new Dimension(GUI_WIDTH, FOOTER_HEIGHT));

        backButton = new Button(Button.Type.Back, "")
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                closeView(true);
            }
        };
        footerPanel.add(backButton, BorderLayout.LINE_START);

        titleLabel = new JLabel("", JLabel.CENTER);
        titleLabel.setFont(new Font("Arial", 0, 40));
        footerPanel.add(titleLabel, BorderLayout.CENTER);

        userNameLabel = new JLabel("", JLabel.CENTER);
        userNameLabel.setFont(new Font("Arial", 0, 25));
        footerPanel.add(userNameLabel, BorderLayout.LINE_END);

        return footerPanel;
    }

    /** Replace current view with */
    public void replaceView(AutraView view)
    {
        AutraView curView = viewStack.pop();
        viewStack.push(view);
        showTopView();
        curView.setVisible(false);
        repaint();
    }

    /** Open a new view (leave the current view in the stack) */
    public void openView(AutraView view)
    {
        AutraView curView = null;
        if (!viewStack.empty())
        {
            curView = viewStack.peek();
        }
        viewStack.push(view);
        showTopView();
        if (curView != null)
        {
            curView.setVisible(false);
        }
        repaint();
    }

    /** Close the view and remove it from the stack
     *  and show the top-of-the-stack view.
     * @param onBack True if "Back" button was pressed
     */
    public void closeView(boolean onBack)
    {
        AutraView curView = viewStack.pop();
        curView.onHide();
        if (onBack)
        {
            curView.onBack();
        }
        showTopView();
        curView.setVisible(false);
        repaint();
    }

    /** Show the view on top of the stack */
    private void showTopView()
    {
        backButton.setEnabled(viewStack.size() > 1);
        userNameLabel.setText(User.activeUser != null ? User.activeUser.username : "");
        contentPane.removeAll();

        AutraView view = viewStack.peek();
        view.prepare();
        view.setVisible(true);
        titleLabel.setText(view.getTitle());
        contentPane.add(view);
    }

    public void resetTitle()
    {
        titleLabel.setText(viewStack.peek().getTitle());
    }
}
