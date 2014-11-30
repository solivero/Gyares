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
    addAndMakeVisible (generalBox = new GroupComponent ("General",
                                                        TRANS("General")));
    generalBox->setTextLabelPosition (Justification::centredLeft);
    generalBox->setColour (GroupComponent::outlineColourId, Colour (0x66c4c4c4));
    generalBox->setColour (GroupComponent::textColourId, Colour (0xffbfbfbf));

    addAndMakeVisible (delayBox = new GroupComponent ("Delay",
                                                      TRANS("Delay")));
    delayBox->setTextLabelPosition (Justification::centredLeft);
    delayBox->setColour (GroupComponent::outlineColourId, Colour (0x66c4c4c4));
    delayBox->setColour (GroupComponent::textColourId, Colour (0xffbfbfbf));

    addAndMakeVisible (keyboard = new MidiKeyboardComponent (ownerFilter->keyboardState, MidiKeyboardComponent::horizontalKeyboard));
    keyboard->setName ("Midi Keyboard");

    addAndMakeVisible (gainSlider = new Slider ("Gain Knob"));
    gainSlider->setRange (0, 2, 0.1);
    gainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    gainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0092c9));
    gainSlider->setColour (Slider::textBoxTextColourId, Colour (0xffbfbfbf));
    gainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff626262));
    gainSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40626262));
    gainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    gainSlider->addListener (this);

    addAndMakeVisible (delayFeedbackSlider = new Slider ("Delay Knob"));
    delayFeedbackSlider->setRange (0, 100, 1);
    delayFeedbackSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayFeedbackSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    delayFeedbackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0092c9));
    delayFeedbackSlider->setColour (Slider::textBoxTextColourId, Colour (0xffbfbfbf));
    delayFeedbackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff626262));
    delayFeedbackSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40626262));
    delayFeedbackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayFeedbackSlider->addListener (this);

    addAndMakeVisible (gainLabel = new Label ("Gain Label",
                                              TRANS("Gain")));
    gainLabel->setFont (Font ("Ubuntu", 20.00f, Font::plain));
    gainLabel->setJustificationType (Justification::centred);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (Label::textColourId, Colour (0xffbfbfbf));
    gainLabel->setColour (TextEditor::textColourId, Colours::black);
    gainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayFeedbackLabel = new Label ("Delay Feedback",
                                                       TRANS("Feedback")));
    delayFeedbackLabel->setFont (Font ("Ubuntu", 20.00f, Font::plain));
    delayFeedbackLabel->setJustificationType (Justification::centred);
    delayFeedbackLabel->setEditable (false, false, false);
    delayFeedbackLabel->setColour (Label::textColourId, Colour (0xffbfbfbf));
    delayFeedbackLabel->setColour (TextEditor::textColourId, Colours::black);
    delayFeedbackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (widthSlider = new Slider ("Stereo Width Knob"));
    widthSlider->setRange (0, 100, 1);
    widthSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    widthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    widthSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0092c9));
    widthSlider->setColour (Slider::textBoxTextColourId, Colour (0xffbfbfbf));
    widthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff626262));
    widthSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40626262));
    widthSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    widthSlider->addListener (this);

    addAndMakeVisible (widthLabel = new Label ("Stereo Width",
                                               TRANS("Width")));
    widthLabel->setFont (Font ("Ubuntu", 20.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centred);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (Label::textColourId, Colour (0xffbfbfbf));
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayTimeSlider = new Slider ("Delay Time"));
    delayTimeSlider->setRange (0, 3, 0.1);
    delayTimeSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayTimeSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    delayTimeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0092c9));
    delayTimeSlider->setColour (Slider::textBoxTextColourId, Colour (0xffbfbfbf));
    delayTimeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff626262));
    delayTimeSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40626262));
    delayTimeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayTimeSlider->addListener (this);

    addAndMakeVisible (delayTimeLabel = new Label ("Delay Time",
                                                   TRANS("Time")));
    delayTimeLabel->setFont (Font ("Ubuntu", 20.00f, Font::plain));
    delayTimeLabel->setJustificationType (Justification::centred);
    delayTimeLabel->setEditable (false, false, false);
    delayTimeLabel->setColour (Label::textColourId, Colour (0xffbfbfbf));
    delayTimeLabel->setColour (TextEditor::textColourId, Colours::black);
    delayTimeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayBypass = new TextButton ("Bypass Delay"));
    delayBypass->setButtonText (TRANS("Bypass"));
    delayBypass->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight | Button::ConnectedOnTop | Button::ConnectedOnBottom);
    delayBypass->addListener (this);
    delayBypass->setColour (TextButton::buttonColourId, Colour (0xff282828));
    delayBypass->setColour (TextButton::buttonOnColourId, Colour (0xffe1113a));
    delayBypass->setColour (TextButton::textColourOnId, Colour (0xffbfbfbf));
    delayBypass->setColour (TextButton::textColourOffId, Colour (0xffbfbfbf));

    addAndMakeVisible (delayPanSlider = new Slider ("Delay Panning"));
    delayPanSlider->setRange (-1, 1, 0.1);
    delayPanSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    delayPanSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    delayPanSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0092c9));
    delayPanSlider->setColour (Slider::textBoxTextColourId, Colour (0xffbfbfbf));
    delayPanSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff626262));
    delayPanSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayPanSlider->addListener (this);

    addAndMakeVisible (delayPanLabel = new Label ("Delay Pan Label",
                                                  TRANS("Pan")));
    delayPanLabel->setFont (Font ("Ubuntu", 20.00f, Font::plain));
    delayPanLabel->setJustificationType (Justification::centred);
    delayPanLabel->setEditable (false, false, false);
    delayPanLabel->setColour (Label::textColourId, Colour (0xffbfbfbf));
    delayPanLabel->setColour (TextEditor::textColourId, Colours::black);
    delayPanLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (seconds = new Label ("Seconds",
                                            TRANS("s")));
    seconds->setFont (Font (15.00f, Font::plain));
    seconds->setJustificationType (Justification::centredLeft);
    seconds->setEditable (false, false, false);
    seconds->setColour (Label::textColourId, Colour (0xffbfbfbf));
    seconds->setColour (TextEditor::textColourId, Colours::black);
    seconds->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (seconds2 = new Label ("Seconds",
                                             TRANS("%")));
    seconds2->setFont (Font (14.00f, Font::plain));
    seconds2->setJustificationType (Justification::centredLeft);
    seconds2->setEditable (false, false, false);
    seconds2->setColour (Label::textColourId, Colour (0xffbfbfbf));
    seconds2->setColour (TextEditor::textColourId, Colours::black);
    seconds2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (right = new Label ("Right",
                                          TRANS("R")));
    right->setFont (Font (15.00f, Font::plain));
    right->setJustificationType (Justification::centredLeft);
    right->setEditable (false, false, false);
    right->setColour (Label::textColourId, Colour (0xffbfbfbf));
    right->setColour (TextEditor::textColourId, Colours::black);
    right->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (right2 = new Label ("Right",
                                           TRANS("L")));
    right2->setFont (Font (15.00f, Font::plain));
    right2->setJustificationType (Justification::centredLeft);
    right2->setEditable (false, false, false);
    right2->setColour (Label::textColourId, Colour (0xffbfbfbf));
    right2->setColour (TextEditor::textColourId, Colours::black);
    right2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (seconds3 = new Label ("Seconds",
                                             TRANS("%")));
    seconds3->setFont (Font (14.00f, Font::plain));
    seconds3->setJustificationType (Justification::centredLeft);
    seconds3->setEditable (false, false, false);
    seconds3->setColour (Label::textColourId, Colour (0xffbfbfbf));
    seconds3->setColour (TextEditor::textColourId, Colours::black);
    seconds3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 350);


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

    generalBox = nullptr;
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
    seconds = nullptr;
    seconds2 = nullptr;
    right = nullptr;
    right2 = nullptr;
    seconds3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GyaresAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff7a7a7a));

    g.setColour (Colour (0xff303030));
    g.fillRect (0, 0, 600, 69);

    g.setColour (Colour (0xffbfbfbf));
    g.setFont (Font ("Andale Mono", 42.00f, Font::plain));
    g.drawText (TRANS("Yaled"),
                0, 1, proportionOfWidth (1.0000f), 63,
                Justification::centred, true);

    g.setColour (Colour (0xff626262));
    g.fillRoundedRectangle (8.0f, 240.0f, 584.0f, 103.0f, 10.000f);

    g.setColour (Colour (0xff626262));
    g.fillRoundedRectangle (384.0f, 89.0f, 208.0f, 142.0f, 10.000f);

    g.setColour (Colour (0xff626262));
    g.fillRoundedRectangle (8.0f, 89.0f, 362.0f, 142.0f, 10.000f);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GyaresAudioProcessorEditor::resized()
{
    generalBox->setBounds (392, 88, 192, 136);
    delayBox->setBounds (16, 88, 344, 136);
    keyboard->setBounds ((getWidth() / 2) - (proportionOfWidth (0.9500f) / 2), getHeight() - 16 - 88, proportionOfWidth (0.9500f), 88);
    gainSlider->setBounds (496, 131, 64, 68);
    delayFeedbackSlider->setBounds ((16 + 16) + 0, (88 + 24) + 20, 64, 68);
    gainLabel->setBounds (408 + 88, ((88 + 24) + 0) + 0, roundFloatToInt (64 * 1.0000f), 20);
    delayFeedbackLabel->setBounds (16 + 16, 88 + 24, roundFloatToInt (64 * 1.0000f), 20);
    widthSlider->setBounds (408 + 0, ((88 + 24) + 0) + 20, 64, 68);
    widthLabel->setBounds (408, (88 + 24) + 0, roundFloatToInt (64 * 1.0000f), 20);
    delayTimeSlider->setBounds (((16 + 16) + 88) + 0, ((88 + 24) + 0) + 20, 64, 68);
    delayTimeLabel->setBounds ((16 + 16) + 88, (88 + 24) + 0, roundFloatToInt (64 * 1.0000f), 20);
    delayBypass->setBounds (288, 128, 56, 56);
    delayPanSlider->setBounds (((16 + 16) + 88) + 86, ((88 + 24) + 0) + 20, 64, 68);
    delayPanLabel->setBounds ((16 + 16) + 174, (88 + 24) + 0, roundFloatToInt (64 * 1.0000f), 20);
    seconds->setBounds (160, 178, 16, 24);
    seconds2->setBounds (73, 178, 24, 24);
    right->setBounds (255, 160, 16, 24);
    right2->setBounds (207, 160, 16, 24);
    seconds3->setBounds (450, 178, 22, 24);
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
                 fixedSize="1" initialWidth="600" initialHeight="350">
  <BACKGROUND backgroundColour="ff7a7a7a">
    <RECT pos="0 0 600 69" fill="solid: ff303030" hasStroke="0"/>
    <TEXT pos="0 1 100% 63" fill="solid: ffbfbfbf" hasStroke="0" text="Yaled"
          fontname="Andale Mono" fontsize="42" bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="8 240 584 103" cornerSize="10" fill="solid: ff626262" hasStroke="0"/>
    <ROUNDRECT pos="384 89 208 142" cornerSize="10" fill="solid: ff626262" hasStroke="0"/>
    <ROUNDRECT pos="8 89 362 142" cornerSize="10" fill="solid: ff626262" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="General" id="1f9d721cdc9b1fe3" memberName="generalBox"
                  virtualName="" explicitFocusOrder="0" pos="392 88 192 136" outlinecol="66c4c4c4"
                  textcol="ffbfbfbf" title="General" textpos="33"/>
  <GROUPCOMPONENT name="Delay" id="af7d91e63e52af8a" memberName="delayBox" virtualName=""
                  explicitFocusOrder="0" pos="16 88 344 136" outlinecol="66c4c4c4"
                  textcol="ffbfbfbf" title="Delay" textpos="33"/>
  <GENERICCOMPONENT name="Midi Keyboard" id="f5075a7affac6f2c" memberName="keyboard"
                    virtualName="" explicitFocusOrder="0" pos="0Cc 16Rr 95% 88" class="MidiKeyboardComponent"
                    params="ownerFilter-&gt;keyboardState, MidiKeyboardComponent::horizontalKeyboard"/>
  <SLIDER name="Gain Knob" id="f8aa0ecfccaae384" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="496 131 64 68" posRelativeX="ee0bf05f7eaaf830"
          posRelativeY="ee0bf05f7eaaf830" rotarysliderfill="7f0092c9" textboxtext="ffbfbfbf"
          textboxbkgd="ff626262" textboxhighlight="40626262" textboxoutline="808080"
          min="0" max="2" int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Delay Knob" id="fb8f9070b59f739d" memberName="delayFeedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0R 64 68" posRelativeX="4dcb6fdb53d8ae77"
          posRelativeY="4dcb6fdb53d8ae77" rotarysliderfill="7f0092c9" textboxtext="ffbfbfbf"
          textboxbkgd="ff626262" textboxhighlight="40626262" textboxoutline="808080"
          min="0" max="100" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Gain Label" id="c5ae65335904ba58" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="88 0 100% 20" posRelativeX="7ff928a589097772"
         posRelativeY="7ff928a589097772" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ffbfbfbf" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Ubuntu" fontsize="20" bold="0"
         italic="0" justification="36"/>
  <LABEL name="Delay Feedback" id="4dcb6fdb53d8ae77" memberName="delayFeedbackLabel"
         virtualName="" explicitFocusOrder="0" pos="16 24 100% 20" posRelativeX="af7d91e63e52af8a"
         posRelativeY="af7d91e63e52af8a" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ffbfbfbf" edTextCol="ff000000"
         edBkgCol="0" labelText="Feedback" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Ubuntu" fontsize="20" bold="0"
         italic="0" justification="36"/>
  <SLIDER name="Stereo Width Knob" id="508a79197f48cedb" memberName="widthSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0R 64 68" posRelativeX="7ff928a589097772"
          posRelativeY="7ff928a589097772" rotarysliderfill="7f0092c9" textboxtext="ffbfbfbf"
          textboxbkgd="ff626262" textboxhighlight="40626262" textboxoutline="808080"
          min="0" max="100" int="1" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Stereo Width" id="7ff928a589097772" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="408 0 100% 20" posRelativeY="4dcb6fdb53d8ae77"
         posRelativeW="f8aa0ecfccaae384" posRelativeH="f8aa0ecfccaae384"
         textCol="ffbfbfbf" edTextCol="ff000000" edBkgCol="0" labelText="Width"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Ubuntu" fontsize="20" bold="0" italic="0" justification="36"/>
  <SLIDER name="Delay Time" id="e917c0629ce1ab84" memberName="delayTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="0 0R 64 68" posRelativeX="9f2658e4281ef29b"
          posRelativeY="9f2658e4281ef29b" rotarysliderfill="7f0092c9" textboxtext="ffbfbfbf"
          textboxbkgd="ff626262" textboxhighlight="40626262" textboxoutline="808080"
          min="0" max="3" int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Delay Time" id="9f2658e4281ef29b" memberName="delayTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="88 0 100% 20" posRelativeX="4dcb6fdb53d8ae77"
         posRelativeY="4dcb6fdb53d8ae77" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ffbfbfbf" edTextCol="ff000000"
         edBkgCol="0" labelText="Time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Ubuntu" fontsize="20" bold="0"
         italic="0" justification="36"/>
  <TEXTBUTTON name="Bypass Delay" id="76c6b2fdf2fb64a6" memberName="delayBypass"
              virtualName="" explicitFocusOrder="0" pos="288 128 56 56" bgColOff="ff282828"
              bgColOn="ffe1113a" textCol="ffbfbfbf" textColOn="ffbfbfbf" buttonText="Bypass"
              connectedEdges="15" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Delay Panning" id="8c0952746a572f56" memberName="delayPanSlider"
          virtualName="" explicitFocusOrder="0" pos="86 0R 64 68" posRelativeX="9f2658e4281ef29b"
          posRelativeY="9f2658e4281ef29b" rotarysliderfill="7f0092c9" textboxtext="ffbfbfbf"
          textboxbkgd="ff626262" textboxoutline="808080" min="-1" max="1"
          int="0.10000000000000000555" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Delay Pan Label" id="de543589889a88e8" memberName="delayPanLabel"
         virtualName="" explicitFocusOrder="0" pos="174 0 100% 20" posRelativeX="4dcb6fdb53d8ae77"
         posRelativeY="4dcb6fdb53d8ae77" posRelativeW="f8aa0ecfccaae384"
         posRelativeH="f8aa0ecfccaae384" textCol="ffbfbfbf" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Ubuntu" fontsize="20" bold="0"
         italic="0" justification="36"/>
  <LABEL name="Seconds" id="cadaa63c017de721" memberName="seconds" virtualName=""
         explicitFocusOrder="0" pos="160 178 16 24" textCol="ffbfbfbf"
         edTextCol="ff000000" edBkgCol="0" labelText="s" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="Seconds" id="4afa4a68a9c40971" memberName="seconds2" virtualName=""
         explicitFocusOrder="0" pos="73 178 24 24" textCol="ffbfbfbf"
         edTextCol="ff000000" edBkgCol="0" labelText="%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="Right" id="59a50b0b22c69b36" memberName="right" virtualName=""
         explicitFocusOrder="0" pos="255 160 16 24" textCol="ffbfbfbf"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="Right" id="655ed03820f4dbb7" memberName="right2" virtualName=""
         explicitFocusOrder="0" pos="207 160 16 24" textCol="ffbfbfbf"
         edTextCol="ff000000" edBkgCol="0" labelText="L" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="Seconds" id="6c737c281b28b2b0" memberName="seconds3" virtualName=""
         explicitFocusOrder="0" pos="450 178 22 24" textCol="ffbfbfbf"
         edTextCol="ff000000" edBkgCol="0" labelText="%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="14" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
