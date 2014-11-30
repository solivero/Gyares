/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "StereoWidth.h"
#include "Sinewave.h"
#include "Delay.h"

AudioProcessor* JUCE_CALLTYPE createPluginFilter();
 //==============================================================================
/** A demo synth sound that's just a basic sine wave.. */


//==============================================================================
GyaresAudioProcessor::GyaresAudioProcessor()
{
    UserParams[stereoWidth]=100.0f;
    UserParams[gainParam] = 1.0f;
    UserParams[delayTime] = 1.0f;
    UserParams[delayFeedback] = 50.0f;
    UserParams[delayBypass] = 0.0f;
    UserParams[delayPan] = 0.0f;
    delayControl.setTime(UserParams[delayTime]);
    delayControl.setFeedback(UserParams[delayFeedback]);
    delayControl.setBypass(UserParams[delayBypass]);
    widthControl.setWidth(UserParams[stereoWidth]);
    UIUpdateFlag = true;

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
    return totalNumParam;
}

float GyaresAudioProcessor::getParameter (int index)
{
    switch(index) {
        case stereoWidth:
            UserParams[stereoWidth] = widthControl.getWidth();
            return UserParams[stereoWidth];
        case delayFeedback:
            UserParams[delayFeedback] = delayControl.getFeedback();
            return UserParams[delayFeedback];
        case delayTime:
            UserParams[delayTime] = delayControl.getTime();
            return UserParams[delayTime];
        case delayBypass:
            UserParams[delayBypass] = delayControl.isBypassed();
            return UserParams[delayBypass];
        case delayPan:
            UserParams[delayPan] = delayControl.getPan();
            return UserParams[delayPan];
        case gainParam:
            return UserParams[gainParam];
        default: return 0.0f;
    }
}

void GyaresAudioProcessor::setParameter (int index, float newValue)
{
    switch(index) {
        case stereoWidth:
            UserParams[stereoWidth] = newValue;
            widthControl.setWidth(UserParams[stereoWidth]);
            break;
        case delayFeedback:
            UserParams[delayFeedback] = newValue;
            delayControl.setFeedback(UserParams[delayFeedback]);
            break;
        case delayTime:
            UserParams[delayTime] = newValue;
            delayControl.setTime(UserParams[delayTime]);
            break;
        case delayBypass:
            UserParams[delayBypass] = newValue;
            delayControl.setBypass(UserParams[delayBypass]);
            break;
        case delayPan:
            UserParams[delayPan] = newValue;
            delayControl.setPan(UserParams[delayPan]);
            break;
        case gainParam:
            UserParams[gainParam] = newValue;
            break;
        default: return;
    }
    UIUpdateFlag=true;
}

const String GyaresAudioProcessor::getParameterName (int index)
{
    switch(index) {
        case stereoWidth:
            return "StereoWidth Factor";
        case gainParam:
            return "Gain Factor";
        case delayFeedback:
            return "Delay Feedback";
        case delayTime:
            return "Delay Time";
        case delayBypass:
            return "Delay Bypass";
        case delayPan:
            return "Delay Pan";
        default: return String::empty;
    }
}

const String GyaresAudioProcessor::getParameterText (int index)
{
    if(index>=0 && index<totalNumParam)
        return String(UserParams[index]);//return parameter value as string
    else return String::empty;
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
    delayControl.getBuffer().clear();
}

void GyaresAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    keyboardState.reset();
}

void GyaresAudioProcessor::reset()
{
    // Use this method as the place to clear any delay lines, buffers, etc, as it
    // means there's been a break in the audio's continuity.
    delayControl.getBuffer().clear();
}

void GyaresAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numSamples = buffer.getNumSamples();
    int channel = 0;
    AudioSampleBuffer& delayBuffer = delayControl.getBuffer();
    // Now pass any incoming midi messages to our keyboard state object, and let it
    // add messages to the buffer if the user is clicking on the on-screen keys
    keyboardState.processNextMidiBuffer (midiMessages, 0, numSamples, true);

    // and now get the synth to process these midi events and generate its output.
    synth.renderNextBlock (buffer, midiMessages, 0, numSamples);

        // Go through the incoming data, and apply our gain to it...
    for (channel = 0; channel < getNumInputChannels(); ++channel)
        buffer.applyGain (channel, 0, buffer.getNumSamples(), UserParams[gainParam]);
        delayBuffer.applyGain(channel, 0, delayBuffer.getNumSamples(), UserParams[gainParam]);

    float* leftData = buffer.getWritePointer(0);
    float* rightData = buffer.getWritePointer(1);
    float* leftDelay = delayBuffer.getWritePointer(0);
    float* rightDelay = delayBuffer.getWritePointer(1);

    delayControl.applyDelay(buffer);

    for (long i = 0; i < numSamples; i++) {
        widthControl.ClockProcess(&leftData[i], &rightData[i]);
        widthControl.ClockProcess(&leftDelay[i], &rightDelay[i]);
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
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

    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("Gain");
    el->addTextElement(String(UserParams[gainParam]));
    el = root.createNewChildElement("Width");
    el->addTextElement(String(UserParams[stereoWidth]));
    el = root.createNewChildElement("Delay Feedback");
    el->addTextElement(String(UserParams[delayFeedback]));
    el = root.createNewChildElement("Delay Time");
    el->addTextElement(String(UserParams[delayTime]));
    el = root.createNewChildElement("Delay Panning");
    el->addTextElement(String(UserParams[delayPan]));
    el = root.createNewChildElement("Delay Bypass");
    el->addTextElement(String(UserParams[delayBypass]));
    copyXmlToBinary(root,destData);
}

void GyaresAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    XmlElement* pRoot = getXmlFromBinary(data,sizeInBytes);
    if(pRoot!=NULL)
    {
        forEachXmlChildElement((*pRoot),pChild)
        {
            if(pChild->hasTagName("Gain")) {
                String text = pChild->getAllSubText();
                setParameter(gainParam,text.getFloatValue());
            } else if(pChild->hasTagName("Width")) {
                String text = pChild->getAllSubText();
                setParameter(stereoWidth,text.getFloatValue());
            } else if(pChild->hasTagName("Delay Feedback")) {
                String text = pChild->getAllSubText();
                setParameter(delayFeedback, text.getFloatValue());
            } else if(pChild->hasTagName("Delay Time")) {
                String text = pChild->getAllSubText();
                setParameter(delayTime, text.getFloatValue());
            } else if(pChild->hasTagName("Delay Panning")) {
                String text = pChild->getAllSubText();
                setParameter(delayPan, text.getFloatValue());
            } else if(pChild->hasTagName("Delay Bypass")) {
                String text = pChild->getAllSubText();
                setParameter(delayBypass, text.getFloatValue());
            }
        }
        delete pRoot;
        UIUpdateFlag=true;//Request UI update
    }
}

String FloatArrayToString(float* fData, int numFloat)
{//Return String of multiple float values separated by commas
    String result="";
    if(numFloat<1)
    return result;
    for(int i=0; i<(numFloat-1); i++)
    result<<String(fData[i])<<",";//Use juce::String initializer for each value
    result<<String(fData[numFloat-1]);
    return result;
}
int StringToFloatArray(String sFloatCSV, float* fData, int maxNumFloat)
{//Return is number of floats copied to the fData array
//-1 if there were more in the string than maxNumFloat
    StringArray Tokenizer;
    int TokenCount=Tokenizer.addTokens(sFloatCSV,",","");
    int resultCount=(maxNumFloat<=TokenCount)?maxNumFloat:TokenCount;
    for(int i=0; i<resultCount; i++)//only go as far as resultCount for valid data
    fData[i]=Tokenizer[i].getFloatValue();//fill data using String class float conversion
    return ((TokenCount<=maxNumFloat)?resultCount:-1);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GyaresAudioProcessor();
}
