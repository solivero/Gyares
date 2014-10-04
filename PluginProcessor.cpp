/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GyaresAudioProcessor::GyaresAudioProcessor()
{
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
}

void GyaresAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void GyaresAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
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
}

void GyaresAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GyaresAudioProcessor();
}
