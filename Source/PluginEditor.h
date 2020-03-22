/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class VstpluginManagerAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    VstpluginManagerAudioProcessorEditor (VstpluginManagerAudioProcessor&);
    ~VstpluginManagerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void FirstPluginBoxChanged();
	void SecondPluginBoxChanged();
	void DrawDistortionPlugin(int plugin);
	void HideDistortionMenu();

private:
	int _distance1;
	int _distance2;
	ComboBox _firstPluginBox;
	ComboBox _secondPluginBox;
	ComboBox _thirdPluginBox;

	ScopedPointer<Slider> _gainKnob;
	ScopedPointer<Slider> _rangeKnob;
	ScopedPointer<Slider> _mixKnob;
	ScopedPointer<Slider> _volumeKnob;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _gainAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _rangeAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _mixAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _volumeAttachment;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstpluginManagerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstpluginManagerAudioProcessorEditor)
};
