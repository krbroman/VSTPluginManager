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
	void ThirdPluginBoxChanged();
	void DrawDistortionPlugin(int plugin);
	void HideDistortionMenu();
	void DrawEQPlugin(int plugin);
	void HideEQMenu();
	void DrawReverbPlugin(int plugin);
	void HideReverbMenu();
	int* GetPluginOrder();

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

	ScopedPointer<Slider> _freq1Knob;
	ScopedPointer<Slider> _q1Knob;
	ScopedPointer<Slider> _gain1Knob;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _freq1Attachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _q1Attachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _gain1Attachment;

	ScopedPointer<Slider> _delayKnob;
	ScopedPointer<Slider> _decayKnob;
	ScopedPointer<Slider> _mixRKnob;
	ScopedPointer<Slider> _wetKnob;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _delayAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _decayAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _mixRAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _wetAttachment;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> _firstPluginAttachment;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> _secondPluginAttachment;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> _thirdPluginAttachment;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VstpluginManagerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstpluginManagerAudioProcessorEditor)
};
