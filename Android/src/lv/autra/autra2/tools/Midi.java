
package lv.autra.autra2.tools;

import java.io.File;
import java.io.FileInputStream;

import android.media.AudioManager;
import android.media.MediaPlayer;
import android.util.Log;
import lv.autra.autra2.AutraJni;

public class Midi
{
    private static String folder;
    private static FileInputStream fStream;
    private static MediaPlayer mediaPlayer = new MediaPlayer();

    public static void Init(String storageFolder)
    {
        folder = storageFolder;
    }

    public static int loadAndStart()
    {
        String midiFile = (new File(folder, AutraJni.MIDI_FILE_NAME)).getAbsolutePath();
        try
        {
            fStream = new FileInputStream(midiFile);
            mediaPlayer.reset();
            mediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);
            mediaPlayer.setDataSource(fStream.getFD());
            mediaPlayer.prepare();
            mediaPlayer.start();
        }
        catch (Exception e)
        {
            Log.e("AUTRA", "Bummer: " + e.getMessage());
        }
        return mediaPlayer.getDuration();
    }
    
    public static void stop()
    {
        try
        {
            if (mediaPlayer.isPlaying())
            {
                mediaPlayer.stop();
            }
            if (fStream != null)
            {
                fStream.close();
            }
        }
        catch (Exception e)
        {
            Log.e("AUTRA", "failed to close: " + e.getMessage());
        }
    }

    public static int getPassedTime()
    {
        return mediaPlayer.getCurrentPosition();
    }
}
