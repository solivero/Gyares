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
                                    public SliderListener,
                                    public ButtonListener
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
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> generalBox;
    ScopedPointer<GroupComponent> delayBox;
    ScopedPointer<MidiKeyboardComponent> keyboard;
    ScopedPointer<Slider> gainSlider;
    ScopedPointer<Slider> delayFeedbackSlider;
    ScopedPointer<Label> gainLabel;
    ScopedPointer<Label> delayFeedbackLabel;
    ScopedPointer<Slider> widthSlider;
    ScopedPointer<Label> widthLabel;
    ScopedPointer<Slider> delayTimeSlider;
    ScopedPointer<Label> delayTimeLabel;
    ScopedPointer<TextButton> delayBypass;
    ScopedPointer<Slider> delayPanSlider;
    ScopedPointer<Label> delayPanLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GyaresAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_248D6E157FF5962A__
