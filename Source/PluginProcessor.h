/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class VstpluginManagerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    VstpluginManagerAudioProcessor();
    ~VstpluginManagerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	AudioProcessorValueTreeState& getState();
	void Distortion(AudioBuffer<float>&, int totalNumInputChannels);
	void Equalizer(AudioBuffer<float>&, int totalNumInputChannels);
	void Reverb(AudioBuffer<float>&, int totalNumInputChannels);
	float* combFilter(AudioBuffer<float>& buffer, float decayFactor, int delayInS, int numSamples, int channel);
	float* allPassFilter(float* data, float sampleRate, int numSamples);
	void FillReverbBuffer(AudioBuffer<float>& buffer, int totalNumInputChannels, int bufferLength, int reverbBufferLength);
	void FillChorusBuffer(AudioBuffer<float>& buffer, int totalNumInputChannels, int bufferLength, int chorusBufferLength);
	void Chorus(AudioBuffer<float>&, int totalNumInputChannels);
private:

	ScopedPointer<AudioProcessorValueTreeState> _state;
	AudioBuffer<float> _ReverbBuffer;
	int _writePos{ 0 };
	float _sampleRate{ 44100.f };

	AudioBuffer<float> _ChorusBuffer;
	int _writePosChorus{ 0 };

	

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstpluginManagerAudioProcessor)
};
