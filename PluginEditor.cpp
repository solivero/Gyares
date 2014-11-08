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
    addAndMakeVisible (delayBox = new GroupComponent ("Delay",
                                                      TRANS("Delay")));
    delayBox->setTextLabelPosition (Justification::centredLeft);

    addAndMakeVisible (keyboard = new MidiKeyboardComponent (ownerFilter->keyboardState, MidiKeyboardComponent::horizontalKeyboard));
    keyboard->setName ("Midi Keyboard");

    addAndMakeVisible (gainSlider = new Slider ("Gain Knob"));
    gainSlider->setRange (0, 2, 0.1);
    gainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::NoTextBox, false, 40, 20);
    gainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff030072));
    gainSlider->addListener (this);

    addAndMakeVisible (delayFeedbackSlider = new Slider ("Delay Knob"));
    delayFeedbackSlider->setRange (0, 100, 1);
    delayFeedbackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayFeedbackSlider->setTextBoxStyle (Slider::NoTextBox, false, 40, 20);
    delayFeedbackSlider->addListener (this);

    addAndMakeVisible (gainLabel = new Label ("Gain Label",
                                              TRANS("Gain")));
    gainLabel->setFont (Font (20.00f, Font::plain));
    gainLabel->setJustificationType (Justification::centred);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayFeedbackLabel = new Label ("Delay Feedback",
                                                       TRANS("Feedback")));
    delayFeedbackLabel->setFont (Font (20.00f, Font::plain));
    delayFeedbackLabel->setJustificationType (Justification::centred);
    delayFeedbackLabel->setEditable (false, false, false);
    delayFeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    delayFeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (widthSlider = new Slider ("Stereo Width Knob"));
    widthSlider->setRange (0, 1, 0.1);
    widthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    widthSlider->setTextBoxStyle (Slider::NoTextBox, false, 40, 20);
    widthSlider->addListener (this);

    addAndMakeVisible (widthLabel = new Label ("Stereo Width",
                                               TRANS("Width")));
    widthLabel->setFont (Font (20.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centred);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayTimeSlider = new Slider ("Delay Time"));
    delayTimeSlider->setRange (0, 20, 0.1);
    delayTimeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayTimeSlider->setTextBoxStyle (Slider::NoTextBox, true, 40, 20);
    delayTimeSlider->addListener (this);

    addAndMakeVisible (delayTimeLabel = new Label ("Delay Time",
                                                   TRANS("Time")));
    delayTimeLabel->setFont (Font (20.00f, Font::plain));
    delayTimeLabel->setJustificationType (Justification::centred);
    delayTimeLabel->setEditable (false, false, false);
    delayTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    delayTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayBypass = new TextButton ("Bypass Delay"));
    delayBypass->setButtonText (TRANS("Bypass"));
    delayBypass->addListener (this);
    delayBypass->setColour (TextButton::buttonColourId, Colours::white);
    delayBypass->setColour (TextButton::buttonOnColourId, Colour (0xffe1113a));

    addAndMakeVisible (delayPanSlider = new Slider ("Delay Panning"));
    delayPanSlider->setRange (-1, 1, 0);
    delayPanSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayPanSlider->setTextBoxStyle (Slider::NoTextBox, true, 40, 20);
    delayPanSlider->addListener (this);

    addAndMakeVisible (delayPanLabel = new Label ("Delay Panning",
                                                  TRANS("Pan")));
    delayPanLabel->setFont (Font (20.00f, Font::plain));
    delayPanLabel->setJustificationType (Justification::centred);
    delayPanLabel->setEditable (false, false, false);
    delayPanLabel->setColour (TextEditor::textColourId, Colours::black);
    delayPanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    getProcessor()->RequestUIUpdate();
    startTimer(200);
    delayBypass->setClickingTogglesState(true);
    //[/Constructor]
}

GyaresAudioProcessorEditor::~GyaresAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    delayBox = nullptr;
    keyboard = nullptr;
    gainSlider = nullptr;
    delayFeedbackSlider = nullptr;
    gainLabel = nullptr;
    delayFeedbackLabel = nullptr;
    widthSlider = nullptr;
    widthLabel = nullptr;
    delayTimeSlider = nullptr;
    delayTimeLabel = nullptr;
    delayBypass = nullptr;
    delayPanSlider = nullptr;
    delayPanLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GyaresAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffababab));

    g.setColour (Colours::black);
    g.setFont (Font (30.00f, Font::plain));
    g.drawText (TRANS("Petri Soundmaker"),
                0, 0, proportionOfWidth (1.0000f), 36,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GyaresAudioProcessorEditor::resized()
{
    delayBox->setBounds (32, 176, 344, 110);
    keyboard->setBounds ((getWidth() / 2) - (proportionOfWidth (0.9500f) / 2), getHeight() - 16 - 88, proportionOfWidth (0.9500f), 88);
    gainSlider->setBounds (408, 248, 64, 48);
    delayFeedbackSlider->setBounds ((32 + 16) + 0, (176 + 24) + 20, 64, 48);
    gainLabel->setBounds (408 + 0, 248 + -24, roundFloatToInt (64 * 1.0000f), roundFloatToInt (48 * 0.5000f));
    delayFeedbackLabel->setBounds (32 + 16, 176 + 24, roundFloatToInt (64 * 1.0000f), 20);
    widthSlider->setBounds (408 + 0, 184, 64, 48);
    widthLabel->setBounds (408, 160, roundFloatToInt (64 * 1.0000f), 20);
    delayTimeSlider->setBounds (((32 + 16) + 88) + 0, ((176 + 24) + 0) + 20, 64, 48);
    delayTimeLabel->setBounds ((32 + 16) + 88, (176 + 24) + 0, roundFloatToInt (64 * 1.0000f), 20);
    delayBypass->setBounds (296, 200, 64, 64);
    delayPanSlider->setBounds (((32 + 16) + 88) + 86, ((176 + 24) + 0) + 20, 64, 48);
    delayPanLabel->setBounds ((32 + 16) + 174, (176 + 24) + 0, roundFloatToInt (64 * 1.0000f), 20);
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
    else if (sliderThatWasMoved == delayFeedbackSlider)
    {
        //[UserSliderCode_delayFeedbackSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::delayFeedback, (float)delayFeedbackSlider->getValue());
        //[/UserSliderCode_delayFeedbackSlider]
    }
    else if (sliderThatWasMoved == widthSlider)
    {
        //[UserSliderCode_widthSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::stereoWidth, (float)widthSlider->getValue());
        //[/UserSliderCode_widthSlider]
    }
    else if (sliderThatWasMoved == delayTimeSlider)
    {
        //[UserSliderCode_delayTimeSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::delayTime, (float)delayTimeSlider->getValue());
        //[/UserSliderCode_delayTimeSlider]
    }
    else if (sliderThatWasMoved == delayPanSlider)
    {
        //[UserSliderCode_delayPanSlider] -- add your slider handling code here..
        ourProcessor->setParameter(GyaresAudioProcessor::delayPan, (float)delayPanSlider->getValue());
        //[/UserSliderCode_delayPanSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GyaresAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    GyaresAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == delayBypass)
    {
        //[UserButtonCode_delayBypass] -- add your button handler code here..
        ourProcessor->setParameter(GyaresAudioProcessor::delayBypass, (float)delayBypass->getToggleState());
        //[/UserButtonCode_delayBypass]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GyaresAudioProcessorEditor::timerCallback()
{
    GyaresAudioProcessor* ourProcessor = getProcessor();
    //exchange any data you want between UI elements and the Plugin "ourProcessor"
    if(ourProcessor->NeedsUIUpdate()) {
        gainSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::gainParam), dontSendNotification);
        delayFeedbackSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::delayFeedback), dontSendNotification);
        delayTimeSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::delayTime), dontSendNotification);
        widthSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::stereoWidth), dontSendNotification);
        delayPanSlider->setValue(ourProcessor->getParameter(GyaresAudioProcessor::delayPan), dontSendNotification);
        delayBypass->setToggleState(1.0f == ourProcessor->getParameter(GyaresAudioProcessor::delayBypass), dontSendNotification);
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
  <BACKGROUND backgroundColour="ffababab">
    <TEXT pos="0 0 100% 36" fill="solid: ff000000" hasStroke="0" text="Gyares Muchnicer Synthesizer"
          fontname="Default font" fontsize="30" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="Delay" id="af7d91e63e52af8a" memberName="delayBox" virtualName=""
                  explicitFocusOrder="0" pos="32 176 344 110" title="Delay" textpos="33"/>
  <GENERICCOMPONENT name="Midi Keyboard" id="f5075a7affac6f2c" memberName="keyboard"
                    virtualName="" explicitFocusOrder="0" pos="0Cc 16Rr 95% 88" class="MidiKeyboardComponent"
                    params="ownerFilter-&gt;keyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
  <SLIDER name="Gain Knob" id="f8aa0ecfccaae384" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="408 248 64 48" posRelativeX="ee0bf05f7eaaf830"
          posRelativeY="ee0bf05f7eaaf830" textboxtext="ff030072" min="0"
          max="2" int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Delay Knob" id="fb8f9070b59f739d" memberName="delayFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0R 64 48" posRelativeX="4dcb6fdb53d8ae77"
          posRelativeY="4dcb6fdb53d8ae77" min="0" max="100" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Gain Label" id="c5ae65335904ba58" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -24 100% 50%" posRelativeX="f8aa0ecfccaae384"
         posRelativeY="f8aa0ecfccaae384" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" edTextCol="ff000000" edBkgCol="0"
         labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Delay Feedback" id="4dcb6fdb53d8ae77" memberName="delayFeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="16 24 100% 20" posRelativeX="af7d91e63e52af8a"
         posRelativeY="af7d91e63e52af8a" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" edTextCol="ff000000" edBkgCol="0"
         labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Stereo Width Knob" id="508a79197f48cedb" memberName="widthSlider"
          virtualName="" explicitFocusOrder="0" pos="0 184 64 48" posRelativeX="7ff928a589097772"
          min="0" max="5" int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Stereo Width" id="7ff928a589097772" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="408 160 100% 20" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" edTextCol="ff000000" edBkgCol="0"
         labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Delay Time" id="e917c0629ce1ab84" memberName="delayTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0R 64 48" posRelativeX="9f2658e4281ef29b"
          posRelativeY="9f2658e4281ef29b" min="0" max="20" int="0.10000000000000000555"
          style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Delay Time" id="9f2658e4281ef29b" memberName="delayTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="88 0 100% 20" posRelativeX="4dcb6fdb53d8ae77"
         posRelativeY="4dcb6fdb53d8ae77" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" edTextCol="ff000000" edBkgCol="0"
         labelText="Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Bypass Delay" id="76c6b2fdf2fb64a6" memberName="delayBypass"
              virtualName="" explicitFocusOrder="0" pos="296 200 64 64" bgColOff="ffffffff"
              bgColOn="ffe1113a" buttonText="Bypass" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="Delay Panning" id="8c0952746a572f56" memberName="delayPanSlider"
          virtualName="" explicitFocusOrder="0" pos="86 0R 64 48" posRelativeX="9f2658e4281ef29b"
          posRelativeY="9f2658e4281ef29b" min="-1" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Delay Pan Label" id="de543589889a88e8" memberName="delayPanLabel"
         virtualName="" explicitFocusOrder="0" pos="174 0 100% 20" posRelativeX="4dcb6fdb53d8ae77"
         posRelativeY="4dcb6fdb53d8ae77" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" edTextCol="ff000000" edBkgCol="0"
         labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
