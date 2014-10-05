/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_248D6E157FF5962A__
#define __JUCE_HEADER_248D6E157FF5962A__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GyaresAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Timer,
                                    public SliderListener
{
public:
    //==============================================================================
    GyaresAudioProcessorEditor (GyaresAudioProcessor* ownerFilter);
    ~GyaresAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    GyaresAudioProcessor* getProcessor() const
        {return static_cast <GyaresAudioProcessor*>(getAudioProcessor());}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<MidiKeyboardComponent> keyboard;
    ScopedPointer<Slider> gainSlider;
    ScopedPointer<Slider> delaySlider;
    ScopedPointer<Label> gainLabel;
    ScopedPointer<Label> delayLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GyaresAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_248D6E157FF5962A__
