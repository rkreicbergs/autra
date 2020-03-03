
package lv.autra.autra2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.TreeMap;

import lv.autra.autra2.tools.Text;

public class User
{
    private static final String USER_FOLDER_NAME = "Profiles";
    private static final String PROFILE_EXTENSION = ".txt";

    public static enum Avatar
    {
        Flute,
        Violin,
    }

    public static User activeUser;
    private static String userProfileFolderPath;

    /** Map usernames to users */
    public static final TreeMap<String, User> userList = new TreeMap<String, User>();

    public static void init()
    {
        userProfileFolderPath = Paths.get(Main.appDataFolder, USER_FOLDER_NAME).toString();
        File userProfileFolder = new File(userProfileFolderPath);
        if (!userProfileFolder.exists() && !userProfileFolder.mkdir())
        {
            System.out.println("Failed to create log folder!");
            System.exit(-1);
        }

        loadProfiles();
        if (User.userList.size() > 0)
        {
            activeUser = User.userList.firstEntry().getValue();
        }
    }

    public final String username;
    public String name, surname, teacherEmail;
    public Avatar avatar;

    private String getProfileFilePath()
    {
        return Paths.get(userProfileFolderPath, username + PROFILE_EXTENSION).toString();
    }

    private User(String username, String name, String surname, String teacherEmail, Avatar avatar) throws Exception
    {
        validateUserData(username, name, surname, teacherEmail);
        this.username = username;
        this.name = name;
        this.surname = surname;
        this.teacherEmail = teacherEmail;
        this.avatar = avatar;
    }

    public void update(String name, String surname, String teacherEmail, Avatar avatar) throws Exception
    {
        validateUserData(username, name, surname, teacherEmail);
        this.name = name;
        this.surname = surname;
        this.teacherEmail = teacherEmail;
        this.avatar = avatar;
        saveToFile();
    }

    public static User registerUser(String username,
                                    String name,
                                    String surname,
                                    String teacherEmail,
                                    Avatar avatar,
                                    boolean saveToFile) throws Exception
    {
        if (userList.containsKey(username))
        {
            throw new Exception(Text.get("Profile.UsernameTaken"));
        }

        User user = new User(username, name, surname, teacherEmail, avatar);
        if (saveToFile)
        {
            user.saveToFile();
        }
        userList.put(username, user);
        return user;
    }

    private static void validateUserData(String username, String name, String surname, String teacherEmail) throws Exception
    {
        if (!username.matches("[\\w]+")
            || !name.matches("[\\p{L} ]+")
            || !surname.matches("[\\p{L} ]+")
            || !teacherEmail.matches("^([\\w.%+-]+@[\\w.-]+\\.[a-zA-Z]{2,4})?$"))
        {
            throw new Exception(Text.get("Profile.MissingData"));
        }
    }

    public void delete()
    {
        userList.remove(username);
        (new File(getProfileFilePath())).delete();
    }

    public String toFxullString()
    {
        return String.format("%s %s (%s)", name, surname, username);
    }

    private void saveToFile()
    {
        // appVersion, username, name, surname, teacher's email, avatar
        String userData = String.format("%s:%s:%s:%s:%s:%s", Main.version, username, name, surname, teacherEmail, avatar);

        String profileFilePath = getProfileFilePath();
        File tmpFile = new File(profileFilePath + ".tmp");
        (new File(profileFilePath)).renameTo(tmpFile);
        try
        {
            OutputStream stream = new FileOutputStream(profileFilePath);
            Writer writer = new BufferedWriter(new OutputStreamWriter(stream, "UTF-8"));
            writer.append(userData);
            writer.close();
        }
        catch (Exception e)
        {
            (new File(profileFilePath)).delete();
            tmpFile.renameTo(new File(profileFilePath));
            Main.ExitOnFail("Failed to save user profile: " + username);
        }
        finally
        {
            tmpFile.delete();
        }
    }

    private static void loadProfiles()
    {
        for (File profileFile : new File(userProfileFolderPath).listFiles())
        {
            if (profileFile.isFile() && profileFile.getName().endsWith(PROFILE_EXTENSION))
            {
                try
                {
                    InputStream stream = new FileInputStream(profileFile);
                    Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(stream, "UTF-8")));
                    scanner.useDelimiter(":");
                    // Format: appVersion, username, name, surname, teacher's email, avatar, score
                    scanner.next(); // ignore version
                    User.registerUser(scanner.next(),
                                      scanner.next(),
                                      scanner.next(),
                                      scanner.next(),
                                      Avatar.valueOf(scanner.next()),
                                      false);
                    scanner.close();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                    Main.ExitOnFail("Failed to add user: " + e.getMessage());
                }
            }
        }

    }

    public static String getCurUsername()
    {
        if (User.activeUser == null)
        {
            return "default";
        }
        return User.activeUser.username;
    }
}
