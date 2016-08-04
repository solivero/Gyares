# Yaled
![alt text](http://i.imgur.com/p5iIPuN.png "Synth rendered in Tracktion 5")

*Yaled* is a software synth. It acts as a plugin to a host which supports either VST on Windows or Linux, and AudioUnit on OS X. It is not a standalone executable. It can within the host program get midi as input and process the midi signals into a stream of samples which the host uses to create sound with the underlying audio system on the operating system.

The synth can be played on freely without prerecorded input by using the computer keyboard or an external midi keyboard, depending on the host capabilities, and with the cursor on the graphical keyboard. The sound generated can be modified with knobs and buttons which control delay (time, feeback, pan, bypass), stereo width and gain. These controls help the user achieve sounds as needed. The parameters can also be controlled by most hosts using automation, which allows parameters to change over time.

Functions:
* Delay
  * Time - Time until feedback given in seconds
  * Feedback - Amount of feedback per pulse in percent
  * Pan - Speed for panning to max width
  * Bypass - Bypasses all delay
* Stereo Width - Maximum difference in channels in percent
* Gain - Signal gain, volume 

