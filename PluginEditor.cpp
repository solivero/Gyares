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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GyaresAudioProcessorEditor::GyaresAudioProcessorEditor (GyaresAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    slider->addListener (this);

    addAndMakeVisible (keyboard = new MidiKeyboardComponent (ownerFilter->keyboardState, MidiKeyboardComponent::horizontalKeyboard));
    keyboard->setName ("Midi Keyboard");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    //[/Constructor]
}

GyaresAudioProcessorEditor::~GyaresAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    keyboard = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GyaresAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff252e7b));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GyaresAudioProcessorEditor::resized()
{
    slider->setBounds (32, 40, 150, 24);
    keyboard->setBounds (16, 72, 272, 56);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GyaresAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GyaresAudioProcessorEditor::timerCallback()
{
    GyaresAudioProcessor* ourProcessor = getProcessor();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GyaresAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GyaresAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff252e7b"/>
  <SLIDER name="new slider" id="ee0bf05f7eaaf830" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="32 40 150 24" min="0" max="10" int="0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="Midi Keyboard" id="f5075a7affac6f2c" memberName="keyboard"
                    virtualName="" explicitFocusOrder="0" pos="16 72 272 56" class="MidiKeyboardComponent"
                    params="ownerFilter-&gt;keyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
