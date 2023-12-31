/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ShapeButtonAudioProcessorEditor : public juce::AudioProcessorEditor, public juce::Button::Listener 
{
public:
    ShapeButtonAudioProcessorEditor (ShapeButtonAudioProcessor&);
    ~ShapeButtonAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ShapeButtonAudioProcessor& audioProcessor;

    juce::ShapeButton  shapeButton; 

    void buttonClicked (juce::Button *button) override; 
    void buttonStateChanged (juce::Button *button) override;
    int prevButtonState;
   
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShapeButtonAudioProcessorEditor)
};
