/*
  ==============================================================================

    Sinewave.h
    Created: 12 Oct 2014 6:41:35pm
    Author:  oliver

  ==============================================================================
*/

#ifndef SINEWAVE_H_INCLUDED
#define SINEWAVE_H_INCLUDED

/*
  ==============================================================================

    Sinewave.cpp
    Created: 12 Oct 2014 6:41:35pm
    Author:  oliver

  ==============================================================================
*/

#include "Sinewave.h"
#include "../PluginProcessor.h"

class SineWaveSound : public SynthesiserSound
{
public:
    SineWaveSound() {}

    bool appliesToNote (int /*midiNoteNumber*/) override  { return true; }
    bool appliesToChannel (int /*midiChannel*/) override  { return true; }
};

//==============================================================================
/** A simple demo synth voice that just plays a sine wave.. */
class SineWaveVoice  : public SynthesiserVoice
{
public:
    SineWaveVoice();

    bool canPlaySound (SynthesiserSound* sound);

    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound* /*sound*/,
                    int /*currentPitchWheelPosition*/);

    void stopNote (float velocity, bool allowTailOff);

    void pitchWheelMoved (int /*newValue*/) override;
    
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/);

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

private:
    double currentAngle, angleDelta, level, tailOff;
};



#endif  // SINEWAVE_H_INCLUDED
