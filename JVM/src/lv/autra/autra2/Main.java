
package lv.autra.autra2;

import java.io.File;
import java.util.logging.Logger;

import lv.autra.autra2.game.Game;
import lv.autra.autra2.tools.Log;
import lv.autra.autra2.tools.Midi;
import lv.autra.autra2.tools.Platform;
import lv.autra.autra2.tools.Text;
import lv.autra.autra2.tools.Text.Language;
import lv.autra.autra2.ui.GuiManager;

public class Main
{
    private static final String applicationName = "Autra";
    public static final String version = "1.0";
    public static final String appDataFolder = Platform.getAppDataFolder(applicationName);

    public static boolean enableAllLevels = true;
    public static double intervalLengthCoef = 1.0;

    private static Logger logger;

    public static void main(String[] args)
    {
        initialize();
        GuiManager.RegisterGui();
    }

    private static void prepareAppDataFolder()
    {
        File folder = new File(appDataFolder);
        if (!folder.exists() && !folder.mkdir())
        {
            System.out.println("Failed to create data folder!");
            System.exit(-1);
        }
    }

    private static void initialize()
    {
        prepareAppDataFolder();
        logger = Log.createLogger();
        User.init();

        Midi.init(appDataFolder);
        AutraJni.loadJniLibrary(appDataFolder, User.getCurUsername());
        Game.registerGames();

        Text.setLanguage(Language.LV);
    }

    public static void ExitOnFail(String message)
    {
        System.err.println(message);
        logger.severe(message);
        System.exit(-1);
    }
}
