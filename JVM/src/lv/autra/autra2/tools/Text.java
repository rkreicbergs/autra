
package lv.autra.autra2.tools;

import java.util.Locale;
import java.util.ResourceBundle;

public class Text
{
    public static enum Language
    {
        LV,
        EN,
        RU
    };

    private static Language language;
    private static ResourceBundle messageBundle;

    public static Language getLanguage()
    {
        return language;
    }

    public static void setLanguage(Language newLanguage)
    {
        language = newLanguage;
        Locale locale = new Locale(language.toString());
        messageBundle = ResourceBundle.getBundle("GuiBundle", locale);
    }

    public static String getLatvian(String key)
    {
        return ResourceBundle.getBundle("GuiBundle", new Locale(Language.LV.toString())).getString(key);
    }
    
    public static String get(Object msgObject)
    {
        if (!messageBundle.containsKey(msgObject.toString()))
        {
            System.out.println(String.format("%s = %s", msgObject, msgObject));
            return msgObject.toString();
        }
        /*
        return "XXXX";
        /*/
        return messageBundle.getString(msgObject.toString());
        //*/
    }
}
