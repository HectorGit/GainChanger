/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GainChangerAudioProcessorEditor::GainChangerAudioProcessorEditor (GainChangerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	setSize(200, 200);

	// these define the parameters of our slider object
	gainSlider.setSliderStyle(Slider::LinearBarVertical);
	gainSlider.setRange(0.0, 1.0, 0.1);
	gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	gainSlider.setPopupDisplayEnabled(true, this);
	gainSlider.setTextValueSuffix(" GAIN");
	gainSlider.setValue(1.0);

	// this function adds the slider to the editor
	gainSlider.addListener(this);

	addAndMakeVisible(&gainSlider);


}

GainChangerAudioProcessorEditor::~GainChangerAudioProcessorEditor()
{
}

//==============================================================================
void GainChangerAudioProcessorEditor::paint (Graphics& g)
{

	// fill the whole window white
	g.fillAll(Colours::white);

	// set the current drawing colour to black
	g.setColour(Colours::black);

	// set the font size and draw text to the screen
	g.setFont(15.0f);

	g.drawFittedText("THIS HAS TO WORK", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void GainChangerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	gainSlider.setBounds(40, 30, 20, getHeight() - 60);


}


void GainChangerAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.gain = gainSlider.getValue();
}