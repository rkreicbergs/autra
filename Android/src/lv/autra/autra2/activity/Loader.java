
package lv.autra.autra2.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import lv.autra.autra2.AutraJni;
import lv.autra.autra2.R;
import lv.autra.autra2.game.Game;
import lv.autra.autra2.tools.Midi;

public class Loader extends Activity
{
    private static final String username = "profile";
    private static boolean dataLoaded = false;

    private static int SPLASH_TIME_OUT = 3000;
 
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        setContentView(R.layout.loader);
        
        super.onCreate(savedInstanceState);
        if (!dataLoaded)
        {
            String dataFolder = getFilesDir().toString();
            
            Midi.Init(dataFolder);
            AutraJni.loadJniLibrary(dataFolder, username);
            Game.registerGames();
            
            dataLoaded = true;
        }

        new Handler().postDelayed(new Runnable() {

            @Override
            public void run() {
                Intent i = new Intent(Loader.this, GameSelect.class);
                finish();
                startActivity(i);
            }
        }, SPLASH_TIME_OUT);
    }
}
