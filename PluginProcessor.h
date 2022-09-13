/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>

//==============================================================================
/**
*/
class NewProjectAudioProcessor : public juce::AudioProcessor,private juce::Slider::Listener     // [2]
    //dd the inheritance [2] and the default callback function [3] 
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor() override;

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;


    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    
    //class effectParameters:juce::AudioProcessorParameter
    //{
    //public:
    //    float volume;
    //};
    ////juce::AudioProcessorParameter effectParameters = new juce::AudioProcessorParameter;
    //effectParameters parameters = new effectParameters();
private:                //parameters can be declared here. parameters can be defined here. and set get processes can be done in PluginProcessor.cpp / void NewProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)   void NewProjectAudioProcessor::setStateInformation (juce::MemoryBlock& destData)
    //==============================================================================
    juce::AudioParameterFloat* volume;
    int sampleCountDown;

    
    void sliderValueChanged(juce::Slider* slider) override;  
   

    //==================================================================
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    //juce::Slider Volume;
    //slider normalde bu scope icinde tanimliydi , PluginEditor.cpp ta global scope da tanimlandi. bunun bir sakincais var midir ki?

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewProjectAudioProcessor)
  
};