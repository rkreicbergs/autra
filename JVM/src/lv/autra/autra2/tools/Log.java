
package lv.autra.autra2.tools;

import java.io.File;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;

import lv.autra.autra2.Main;

public class Log
{
    private static final String LOG_FOLDER_NAME = "Log";
    //private static final String FILE_LOG = "autralog.log";
    private static final Level logLevel = Level.WARNING;

    public static Logger createLogger()
    {
        String logFolder = Paths.get(Main.appDataFolder, LOG_FOLDER_NAME).toString(); 
        File folder = new File(logFolder);
        if (!folder.exists() && !folder.mkdir())
        {
            System.out.println("Failed to create log folder!");
            System.exit(-1);
        }

        final Logger logger = Logger.getLogger("AutraLogger");
        logger.setLevel(logLevel);
        try
        {
//            String logFile = String.format("%s\\%s", logFolder, FILE_LOG);
//            FileHandler fh = new FileHandler(logFile, true);
//            fh.setFormatter(new SimpleFormatter());
//            logger.addHandler(fh);
//            fh.close();
            //TODO: FIX THIS CRAP
        }
        catch (Exception e)
        {
            e.printStackTrace();
            System.exit(-1);
        }

        return logger;
    }
}
