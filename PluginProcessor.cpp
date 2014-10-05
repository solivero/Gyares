/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
 //==============================================================================
/** A demo synth sound that's just a basic sine wave.. */
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
    SineWaveVoice()
        : angleDelta (0.0),
          tailOff (0.0)
    {
    }

    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SineWaveSound*> (sound) != nullptr;
    }

    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound* /*sound*/,
                    int /*currentPitchWheelPosition*/) override
    {
        currentAngle = 0.0;
        level = velocity * 0.15;
        tailOff = 0.0;

        double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
        double cyclesPerSample = cyclesPerSecond / getSampleRate();

        angleDelta = cyclesPerSample * 2.0 * double_Pi;
    }

    void stopNote (float velocity, bool allowTailOff) override
    {
        if (allowTailOff)
        {
            // start a tail-off by setting this flag. The render callback will pick up on
            // this and do a fade out, calling clearCurrentNote() when it's finished.

            if (tailOff == 0.0) // we only need to begin a tail-off if it's not already doing so - the
                                // stopNote method could be called more than once.
                tailOff = 1.0;
        }
        else
        {
            // we're being told to stop playing immediately, so reset everything..

            clearCurrentNote();
            angleDelta = 0.0;
        }
    }

    void pitchWheelMoved (int /*newValue*/) override
    {
        // can't be bothered implementing this for the demo!
    }

    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override
    {
        // not interested in controllers in this case.
    }

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override
    {
        if (angleDelta != 0.0)
        {
            if (tailOff > 0)
            {
                while (--numSamples >= 0)
                {
                    const float currentSample = (float) (sin (currentAngle) * level * tailOff);

                    for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                        outputBuffer.addSample (i, startSample, currentSample);

                    currentAngle += angleDelta;
                    ++startSample;

                    tailOff *= 0.99;

                    if (tailOff <= 0.005)
                    {
                        clearCurrentNote();

                        angleDelta = 0.0;
                        break;
                    }
                }
            }
            else
            {
                while (--numSamples >= 0)
                {
                    const float currentSample = (float) (sin (currentAngle) * level);

                    for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                        outputBuffer.addSample (i, startSample, currentSample);

                    currentAngle += angleDelta;
                    ++startSample;
                }
            }
        }
    }

private:
    double currentAngle, angleDelta, level, tailOff;
};

const float defaultGain = 1.0f;
const float defaultDelay = 0.0f;

//==============================================================================
GyaresAudioProcessor::GyaresAudioProcessor()
    : delayBuffer (2, 12000)
{
    // Set up some default values..
    gain = defaultGain;
    delay = defaultDelay;

    lastUIWidth = 400;
    lastUIHeight = 200;

    lastPosInfo.resetToDefault();
    delayPosition = 0;

    // Initialise the synth...
    for (int i = 4; --i >= 0;)
        synth.addVoice (new SineWaveVoice());   // These voices will play our custom sine-wave sounds..

    synth.addSound (new SineWaveSound());
}

GyaresAudioProcessor::~GyaresAudioProcessor()
{
}

//==============================================================================
const String GyaresAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int GyaresAudioProcessor::getNumParameters()
{
    return 0;
}

float GyaresAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void GyaresAudioProcessor::setParameter (int index, float newValue)
{
}

const String GyaresAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String GyaresAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String GyaresAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String GyaresAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool GyaresAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool GyaresAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool GyaresAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GyaresAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool GyaresAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double GyaresAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GyaresAudioProcessor::getNumPrograms()
{
    return 0;
}

int GyaresAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GyaresAudioProcessor::setCurrentProgram (int index)
{
}

const String GyaresAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void GyaresAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GyaresAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synth.setCurrentPlaybackSampleRate (sampleRate);
    keyboardState.reset();
    delayBuffer.clear();
}

void GyaresAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    delayBuffer.clear();
}

void GyaresAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numSamples = buffer.getNumSamples();
    int channel, dp = 0;

    // Go through the incoming data, and apply our gain to it...
    for (channel = 0; channel < getNumInputChannels(); ++channel)
        buffer.applyGain (channel, 0, buffer.getNumSamples(), gain);

    // Now pass any incoming midi messages to our keyboard state object, and let it
    // add messages to the buffer if the user is clicking on the on-screen keys
    keyboardState.processNextMidiBuffer (midiMessages, 0, numSamples, true);

    // and now get the synth to process these midi events and generate its output.
    synth.renderNextBlock (buffer, midiMessages, 0, numSamples);

    // Apply our delay effect to the new output..
    for (channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
        float* delayData = delayBuffer.getWritePointer (jmin (channel, delayBuffer.getNumChannels() - 1));
        dp = delayPosition;

        for (int i = 0; i < numSamples; ++i)
        {
            const float in = channelData[i];
            channelData[i] += delayData[dp];
            delayData[dp] = (delayData[dp] + in) * delay;
            if (++dp >= delayBuffer.getNumSamples())
                dp = 0;
        }
    }

    delayPosition = dp;

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // ask the host for the current time so we can display it...
    AudioPlayHead::CurrentPositionInfo newTime;

    if (getPlayHead() != nullptr && getPlayHead()->getCurrentPosition (newTime))
    {
        // Successfully got the current time from the host..
        lastPosInfo = newTime;
    }
    else
    {
        // If the host fails to fill-in the current time, we'll just clear it to a default..
        lastPosInfo.resetToDefault();
    }
}

//==============================================================================
bool GyaresAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GyaresAudioProcessor::createEditor()
{
    return new GyaresAudioProcessorEditor (this);
}

//==============================================================================
void GyaresAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    // Create an outer XML element..
    XmlElement xml ("MYPLUGINSETTINGS");

    // add some attributes to it..
    xml.setAttribute ("uiWidth", lastUIWidth);
    xml.setAttribute ("uiHeight", lastUIHeight);
    xml.setAttribute ("gain", gain);
    xml.setAttribute ("delay", delay);

    // then use this helper function to stuff it into the binary blob and return it..
    copyXmlToBinary (xml, destData);
}

void GyaresAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));

    if (xmlState != nullptr)
    {
        // make sure that it's actually our type of XML object..
        if (xmlState->hasTagName ("MYPLUGINSETTINGS"))
        {
            // ok, now pull out our parameters..
            lastUIWidth  = xmlState->getIntAttribute ("uiWidth", lastUIWidth);
            lastUIHeight = xmlState->getIntAttribute ("uiHeight", lastUIHeight);

            gain  = (float) xmlState->getDoubleAttribute ("gain", gain);
            delay = (float) xmlState->getDoubleAttribute ("delay", delay);
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GyaresAudioProcessor();
}
