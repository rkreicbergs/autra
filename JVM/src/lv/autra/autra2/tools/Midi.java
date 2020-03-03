
package lv.autra.autra2.tools;

import java.io.File;
import java.net.URL;
import java.nio.file.Paths;

import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.midi.Soundbank;
import javax.sound.midi.Synthesizer;

import lv.autra.autra2.AutraJni;
import lv.autra.autra2.Main;

public class Midi
{
    private static final String[] SOUNDBANKS = {
        "/soundbank.gm", "/soundbank.dls",
    };

    private static Synthesizer synthesizer;
    private static Sequencer sequencer;
    private static String midiFilePath;

    private static void loadSoundBank()
    {
        for (String bankFile : SOUNDBANKS)
        {
            try
            {
                URL in = Midi.class.getResource(bankFile);
                Soundbank bank = MidiSystem.getSoundbank(in);
                synthesizer.loadAllInstruments(bank);
                return;
            }
            catch (Exception e)
            {
                continue;
            }
        }
        throw new RuntimeException("Failed to load a soundbank");
    }

    public static void init(String appDataFolder)
    {
        midiFilePath = Paths.get(appDataFolder, AutraJni.MIDI_FILE_NAME).toString();
        try
        {
            synthesizer = MidiSystem.getSynthesizer();
            loadSoundBank();

            sequencer = MidiSystem.getSequencer();
            sequencer.getTransmitter().setReceiver(synthesizer.getReceiver());

            // This creates the ugly WARNING about registry entries for Windows...
            synthesizer.open();
            sequencer.open();
        }
        catch (Exception e)
        {
            Main.ExitOnFail(e.getMessage());
        }
    }

    public static int loadAndStart()
    {
        try
        {
            Sequence sequence = MidiSystem.getSequence(new File(midiFilePath));
            sequencer.setSequence(sequence);
        }
        catch (Exception e)
        {
            throw new RuntimeException("Failed to load a soundbank");
        }
        sequencer.start();
        return (int)(sequencer.getMicrosecondLength() / 1000);
    }
    
    public static void stop()
    {
        sequencer.stop();
    }
    
    public static int getPassedTime()
    {
        return (int)(sequencer.getMicrosecondPosition() / 1000);
    }
}
