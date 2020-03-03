
package lv.autra.autra2.tools;

import java.nio.file.Paths;

public class Platform
{
    private static boolean isWin()
    {
        String osName = (System.getProperty("os.name")).toUpperCase();
        return osName.contains("WIN");
    }

    public static String getAppDataFolder(String applicationName)
    {
        String rootFolder;
        if (isWin())
        {
            rootFolder = System.getenv("AppData");
        }
        else
        {
            rootFolder = System.getProperty("user.home") + "/Library/Application Support"; // MAC
        }
        return Paths.get(rootFolder, applicationName).toString();
    }
}
