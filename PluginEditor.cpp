/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
juce::Slider Volume;

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    // these define the parameters of our slider object
    Volume.setSliderStyle(juce::Slider::LinearBarVertical);
    Volume.setRange(0.0, 1.0, 0.001);
    Volume.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    Volume.setPopupDisplayEnabled(true, false, this);
    Volume.setTextValueSuffix(" Volume");
    Volume.setValue(1.0);
    //Volume.addListener(Volume);
    // this function adds the slider to the editor
    addAndMakeVisible(&Volume);
    
    
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("volume", getLocalBounds(), juce::Justification::centred, 1);
    
}


void AudioProcesseorParameter(juce::AudioParameterFloat& p) {
    
    
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    Volume.setBounds(40, 30, 20, getHeight() - 60);
}
