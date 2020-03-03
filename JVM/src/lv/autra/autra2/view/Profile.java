
package lv.autra.autra2.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import lv.autra.autra2.User;
import lv.autra.autra2.User.Avatar;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.ui.AutraGui;
import lv.autra.autra2.ui.AutraView;
import lv.autra.autra2.ui.Button;

public class Profile extends AutraView
{
    private static final long serialVersionUID = 1L;

    private JComboBox<User> userComboBox;
    private JTextField searchField;
    private User selectedUser;

    private JTextField usernameField, nameField, surnameField, teacherEmailField;
    private JLabel avatarLabel;
    private User.Avatar selectedAvatar;

    public Profile()
    {
        super(AutraView.Background.LEFT_TREE);
        setLayout(new GridBagLayout());

        GridBagConstraints c = new GridBagConstraints();
        c.gridx = 0;

        JPanel editorPanel = new JPanel(new GridBagLayout());
        editorPanel.setBackground(new Color(0, 0, 0, 100));
        editorPanel.add(createUserSelectionPanel(), c);
        editorPanel.add(createEditUserForm(), c);
        editorPanel.add(createButtonPanel(), c);

        c.insets = new Insets(20, 20, 20, 20);
        c.gridx = GridBagConstraints.RELATIVE;
        c.anchor = GridBagConstraints.SOUTHWEST;
        add(editorPanel, c);
        c.anchor = GridBagConstraints.SOUTHEAST;
        c.weighty = 1;
        c.insets = new Insets(0, 20, 0, 50);
        add(createSelectAvatarPanel(), c);
    }

    private JPanel createUserSelectionPanel()
    {
        JPanel userSelectionPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.weightx = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(10, 5, 5, 5);

        userComboBox = new JComboBox<User>();
        userComboBox.setFont(new Font("Arial", 0, 20));
        userComboBox.addItemListener(new ItemListener()
        {
            @Override
            public void itemStateChanged(ItemEvent event)
            {
                if (event.getStateChange() == ItemEvent.SELECTED)
                {
                    onSelectedUser((User)event.getItem());
                }
            }
        });
        userSelectionPanel.add(userComboBox, c);

        Button deleteButton = new Button(Button.Type.Wood120, Text.get("Profile.Delete"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                if (selectedUser != null)
                {
                    if (User.activeUser == selectedUser)
                    {
                        User.activeUser = null;
                    }
                    selectedUser.delete();
                    reloadUserList();
                }
            }
        };
        userSelectionPanel.add(deleteButton, c);

        c.gridx = 0;
        searchField = new JTextField(10);
        userSelectionPanel.add(searchField, c);
        Button searchButton = new Button(Button.Type.Wood120, Text.get("Profile.Search"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                reloadUserList();
            }
        };
        c.gridx = 1;
        userSelectionPanel.add(searchButton, c);

        return userSelectionPanel;
    }

    private JPanel createEditUserForm()
    {
        JPanel inputPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.weightx = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(5, 5, 5, 5);

        c.gridx = 0;
        inputPanel.add(new JLabel(Text.get("Profile.UsernameLabel"), JLabel.RIGHT), c);
        inputPanel.add(new JLabel(Text.get("Profile.NameLabel"), JLabel.RIGHT), c);
        inputPanel.add(new JLabel(Text.get("Profile.SurnameLabel"), JLabel.RIGHT), c);
        inputPanel.add(new JLabel(Text.get("Profile.TeacherEmailLabel"), JLabel.RIGHT), c);

        c.gridx = 1;
        usernameField = new JTextField(20);
        nameField = new JTextField(20);
        surnameField = new JTextField(20);
        teacherEmailField = new JTextField(20);
        inputPanel.add(usernameField, c);
        inputPanel.add(nameField, c);
        inputPanel.add(surnameField, c);
        inputPanel.add(teacherEmailField, c);

        return inputPanel;
    }

    private JPanel createSelectAvatarPanel()
    {
        JPanel avatarPanel = new JPanel(new GridBagLayout());

        Button prevButton = new Button(Button.Type.Wood60, "<")
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                int cnt = User.Avatar.values().length;
                int prevIdx = (selectedAvatar.ordinal() - 1 + cnt) % cnt;
                selectAvatar(User.Avatar.values()[prevIdx]);
            }
        };
        avatarPanel.add(prevButton);

        avatarLabel = new JLabel();
        avatarPanel.add(avatarLabel);

        Button nextButton = new Button(Button.Type.Wood60, ">")
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                int cnt = User.Avatar.values().length;
                int nextIdx = (selectedAvatar.ordinal() + 1) % cnt;
                selectAvatar(User.Avatar.values()[nextIdx]);
            }
        };
        avatarPanel.add(nextButton);

        return avatarPanel;
    }

    private JPanel createButtonPanel()
    {
        JPanel buttonPanel = new JPanel(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();
        c.weightx = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(5, 5, 5, 5);

        Button addUserButton = new Button(Button.Type.Wood120, Text.get("Profile.New"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                userComboBox.setSelectedItem(null);
                clearInputForm();
            }
        };
        buttonPanel.add(addUserButton, c);

        Button saveButton = new Button(Button.Type.Wood180, Text.get("Profile.SaveAndClose"))
        {
            private static final long serialVersionUID = 1L;

            @Override
            public void processMouseClick()
            {
                try
                {
                    if (selectedUser == null)
                    {
                        User.activeUser = User.registerUser(usernameField.getText(),
                                                            nameField.getText(),
                                                            surnameField.getText(),
                                                            teacherEmailField.getText(),
                                                            selectedAvatar,
                                                            true);
                    }
                    else
                    {
                        selectedUser.update(nameField.getText(),
                                            surnameField.getText(),
                                            teacherEmailField.getText(),
                                            selectedAvatar);
                        User.activeUser = selectedUser;
                    }
                    AutraGui.get().closeView(false);
                }
                catch (Exception e)
                {
                    JOptionPane.showMessageDialog(null,
                                                  e.getMessage(),
                                                  Text.get("Profile.FailedToEdit"),
                                                  JOptionPane.ERROR_MESSAGE);
                }
            }
        };
        buttonPanel.add(saveButton, c);

        return buttonPanel;
    }

    private void selectAvatar(User.Avatar avatar)
    {
        selectedAvatar = avatar;
        String avatarFile = String.format("/images/avatars/%s.png", selectedAvatar);
        avatarLabel.setIcon(new ImageIcon(this.getClass().getResource(avatarFile)));
        repaint();
    }

    private void onSelectedUser(User user)
    {
        selectedUser = user;
        usernameField.setText(user.username);
        usernameField.setEnabled(false);
        nameField.setText(user.name);
        surnameField.setText(user.surname);
        teacherEmailField.setText(user.teacherEmail);
        selectAvatar(user.avatar);
    }

    private void clearInputForm()
    {
        selectedUser = null;
        usernameField.setText("");
        usernameField.setEnabled(true);
        nameField.setText("");
        surnameField.setText("");
        teacherEmailField.setText("");
        selectAvatar(Avatar.Violin);
    }

    private void reloadUserList()
    {
        String searchFilter = searchField.getText();
        userComboBox.removeAllItems();
        for (User user : User.userList.values())
        {
            if (user.name.contains(searchFilter) || user.surname.contains(searchFilter))
            {
                userComboBox.addItem(user);
            }
        }

        userComboBox.setSelectedItem(User.activeUser);
        if (userComboBox.getSelectedIndex() == -1)
        {
            selectAvatar(Avatar.Violin);
            if (userComboBox.getItemCount() > 0)
            {
                userComboBox.setSelectedIndex(0);
            }
        }
    }

    @Override
    public void prepare()
    {
        reloadUserList();
    }

    @Override
    public String getTitle()
    {
        return Text.get("Profile.ViewTitle");
    }
}
