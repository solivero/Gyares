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
    addAndMakeVisible (keyboard = new MidiKeyboardComponent (ownerFilter->keyboardState, MidiKeyboardComponent::horizontalKeyboard));
    keyboard->setName ("Midi Keyboard");

    addAndMakeVisible (gainSlider = new Slider ("Gain Knob"));
    gainSlider->setRange (0, 10, 1);
    gainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    gainSlider->setColour (Slider::backgroundColourId, Colour (0xff1e9029));
    gainSlider->setColour (Slider::thumbColourId, Colour (0xff2020b2));
    gainSlider->setColour (Slider::trackColourId, Colour (0xff191b9a));
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colours::aqua);
    gainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffac17b7));
    gainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff030072));
    gainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffaeaeae));
    gainSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff8000ff));
    gainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xb2ff0065));
    gainSlider->addListener (this);

    addAndMakeVisible (delaySlider = new Slider ("Delay Knob"));
    delaySlider->setRange (0, 100, 1);
    delaySlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delaySlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    delaySlider->setColour (Slider::backgroundColourId, Colour (0xff1e9029));
    delaySlider->setColour (Slider::thumbColourId, Colour (0xff2020b2));
    delaySlider->setColour (Slider::trackColourId, Colour (0xff191b9a));
    delaySlider->setColour (Slider::rotarySliderFillColourId, Colours::aqua);
    delaySlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffac17b7));
    delaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff030072));
    delaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffaeaeae));
    delaySlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff8000ff));
    delaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0xb2ff0065));
    delaySlider->addListener (this);

    addAndMakeVisible (gainLabel = new Label ("Gain Label",
                                              TRANS("Gain")));
    gainLabel->setFont (Font (20.00f, Font::plain));
    gainLabel->setJustificationType (Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (Label::textColourId, Colour (0xff7c09b9));
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayLabel = new Label ("Delay Label",
                                               TRANS("Delay")));
    delayLabel->setFont (Font (20.00f, Font::plain));
    delayLabel->setJustificationType (Justification::centredLeft);
    delayLabel->setEditable (false, false, false);
    delayLabel->setColour (Label::textColourId, Colour (0xff7c09b9));
    delayLabel->setColour (TextEditor::textColourId, Colours::black);
    delayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (widthSlider = new Slider ("Stereo Width Knob"));
    widthSlider->setRange (0, 5, 0);
    widthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    widthSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    widthSlider->setColour (Slider::backgroundColourId, Colour (0xff1e9029));
    widthSlider->setColour (Slider::thumbColourId, Colour (0xff2020b2));
    widthSlider->setColour (Slider::trackColourId, Colour (0xff191b9a));
    widthSlider->setColour (Slider::rotarySliderFillColourId, Colours::aqua);
    widthSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffac17b7));
    widthSlider->setColour (Slider::textBoxTextColourId, Colour (0xff030072));
    widthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xffaeaeae));
    widthSlider->setColour (Slider::textBoxHighlightColourId, Colour (0xff8000ff));
    widthSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xb2ff0065));
    widthSlider->addListener (this);

    addAndMakeVisible (widthLabel = new Label ("Stereo Width",
                                               TRANS("Width")));
    widthLabel->setFont (Font (20.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centredLeft);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (Label::textColourId, Colour (0xff7c09b9));
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    getProcessor()->RequestUIUpdate();
    startTimer(200);
    //[/Constructor]
}

GyaresAudioProcessorEditor::~GyaresAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    keyboard = nullptr;
    gainSlider = nullptr;
    delaySlider = nullptr;
    gainLabel = nullptr;
    delayLabel = nullptr;
    widthSlider = nullptr;
    widthLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GyaresAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff000850));

    g.setColour (Colour (0xff821768));
    g.setFont (Font (30.00f, Font::plain));
    g.drawText (TRANS("Gyares Muchnicer Synthesizer"),
                0, 0, proportionOfWidth (1.0000f), 36,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GyaresAudioProcessorEditor::resized()
{
    keyboard->setBounds ((getWidth() / 2) - (proportionOfWidth (0.7000f) / 2), getHeight() - 16 - 88, proportionOfWidth (0.7000f), 88);
    gainSlider->setBounds (96, 248, 96, 40);
    delaySlider->setBounds (96 + 96, 248 + 0, 96, 40);
    gainLabel->setBounds (96 + 0, 248 + -24, roundFloatToInt (96 * 1.0000f), roundFloatToInt (40 * 0.5000f));
    delayLabel->setBounds ((96 + 96) + 0, 248 + -24, roundFloatToInt (96 * 1.0000f), roundFloatToInt (40 * 0.5000f));
    widthSlider->setBounds ((96 + 96) + 96, 248 + 0, 96, 40);
    widthLabel->setBounds (((96 + 96) + 96) + 0, 248 + -24, roundFloatToInt (96 * 1.0000f), roundFloatToInt (40 * 0.5000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GyaresAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    GyaresAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::gainParam, (float)gainSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == delaySlider)
    {
        //[UserSliderCode_delaySlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::delayParam, (float)delaySlider->getValue());
        //[/UserSliderCode_delaySlider]
    }
    else if (sliderThatWasMoved == widthSlider)
    {
        //[UserSliderCode_widthSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::stereoWidth, (float)widthSlider->getValue());
        //[/UserSliderCode_widthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GyaresAudioProcessorEditor::timerCallback()
{
    GyaresAudioProcessor* ourProcessor = getProcessor();
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
    if(ourProcessor->NeedsUIUpdate()) {
        gainSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::gainParam), dontSendNotification);
        delaySlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::delayParam), dontSendNotification);
        widthSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::stereoWidth), dontSendNotification);
        ourProcessor->ClearUIUpdateFlag();
    }
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
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff000850">
    <TEXT pos="0 0 100% 36" fill="solid: ff821768" hasStroke="0" text="Gyares Muchnicer Synthesizer"
          fontname="Default font" fontsize="30" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="Midi Keyboard" id="f5075a7affac6f2c" memberName="keyboard"
                    virtualName="" explicitFocusOrder="0" pos="0Cc 16Rr 70% 88" class="MidiKeyboardComponent"
                    params="ownerFilter-&gt;keyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
  <SLIDER name="Gain Knob" id="f8aa0ecfccaae384" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="96 248 96 40" posRelativeX="ee0bf05f7eaaf830"
          posRelativeY="ee0bf05f7eaaf830" bkgcol="ff1e9029" thumbcol="ff2020b2"
          trackcol="ff191b9a" rotarysliderfill="ff00ffff" rotaryslideroutline="ffac17b7"
          textboxtext="ff030072" textboxbkgd="ffaeaeae" textboxhighlight="ff8000ff"
          textboxoutline="b2ff0065" min="0" max="10" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Delay Knob" id="fb8f9070b59f739d" memberName="delaySlider"
          virtualName="" explicitFocusOrder="0" pos="0R 0 96 40" posRelativeX="f8aa0ecfccaae384"
          posRelativeY="f8aa0ecfccaae384" bkgcol="ff1e9029" thumbcol="ff2020b2"
          trackcol="ff191b9a" rotarysliderfill="ff00ffff" rotaryslideroutline="ffac17b7"
          textboxtext="ff030072" textboxbkgd="ffaeaeae" textboxhighlight="ff8000ff"
          textboxoutline="b2ff0065" min="0" max="100" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Gain Label" id="c5ae65335904ba58" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -24 100% 50%" posRelativeX="f8aa0ecfccaae384"
         posRelativeY="f8aa0ecfccaae384" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ff7c09b9" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Delay Label" id="4dcb6fdb53d8ae77" memberName="delayLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -24 100% 50%" posRelativeX="fb8f9070b59f739d"
         posRelativeY="f8aa0ecfccaae384" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ff7c09b9" edTextCol="ff000000"
         edBkgCol="0" labelText="Delay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Stereo Width Knob" id="508a79197f48cedb" memberName="widthSlider"
          virtualName="" explicitFocusOrder="0" pos="0R 0 96 40" posRelativeX="fb8f9070b59f739d"
          posRelativeY="f8aa0ecfccaae384" bkgcol="ff1e9029" thumbcol="ff2020b2"
          trackcol="ff191b9a" rotarysliderfill="ff00ffff" rotaryslideroutline="ffac17b7"
          textboxtext="ff030072" textboxbkgd="ffaeaeae" textboxhighlight="ff8000ff"
          textboxoutline="b2ff0065" min="0" max="5" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Stereo Width" id="7ff928a589097772" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -24 100% 50%" posRelativeX="508a79197f48cedb"
         posRelativeY="f8aa0ecfccaae384" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ff7c09b9" edTextCol="ff000000"
         edBkgCol="0" labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
