#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>

/*
 * TMRpcm audio;
    audio.play("filename");    plays a file
    audio.play("filename",30); plays a file starting at 30 seconds into the track
    audio.speakerPin = 11;     set to 5,6,11 or 46 for Mega, 9 for Uno, Nano, etc.
    audio.disable();           disables the timer on output pin and stops the music
    audio.stopPlayback();      stops the music, but leaves the timer running
    audio.isPlaying();         returns 1 if music playing, 0 if not
    audio.pause();             pauses/unpauses playback
    audio.quality(1);          Set 1 for 2x oversampling
    audio.volume(0);           1(up) or 0(down) to control volume
    audio.setVolume(0);        0 to 7. Set volume level
    audio.loop(1);             0 or 1. Can be changed during playback for full control of looping.

    The isPlaying() disable() or noInterrupts()
    functions can be used to prevent parallel code execution.
 */
 TMRpcm audioSD;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(9,OUTPUT);
  audioSD.speakerPin = 9;

  audioSD.setVolume(4);
  audioSD.play("GTR.wav");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
