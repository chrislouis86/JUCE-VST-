/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ShapeButtonAudioProcessorEditor::ShapeButtonAudioProcessorEditor(ShapeButtonAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p), shapeButton("Shape Button", juce::Colours::red, juce::Colours::blue, juce::Colours::white), 
    prevButtonState(0)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(400, 300);


    float buttonSize = 50.0f;
    juce::Path buttonShape;
    buttonShape.addRectangle(0, 0, buttonSize, buttonSize);

    shapeButton.setShape(buttonShape, true, true, false);
    addAndMakeVisible(&shapeButton); 
    buttonShape.addEllipse(0, 0, buttonSize, buttonSize);

    shapeButton.addListener(this);

}

ShapeButtonAudioProcessorEditor::~ShapeButtonAudioProcessorEditor()
{

}

//==============================================================================
void ShapeButtonAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    // g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ShapeButtonAudioProcessorEditor::resized()
{
    shapeButton.setTopLeftPosition(getWidth() / 2, getHeight() / 2);

}

void ShapeButtonAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    // juce::Logger::writeToLog("buttonClicked");
}

void  ShapeButtonAudioProcessorEditor::buttonStateChanged (juce::Button *button)
{
      juce::Logger::writeToLog("button state : " + std::to_string(button->getState()));
      prevButtonState = button->getState();

      if (button->getState() == 2)
      {

          auto message = juce::MidiMessage::noteOn (1, 49, (juce::uint8) 100);

          message.setTimeStamp(juce::Time::getMillisecondCounterHiRes() * 0.001 - 0.0);
          audioProcessor.getMidiMessageCollector().addMessageToQueue(message);
      }
    

}
