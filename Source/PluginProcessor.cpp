/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstpluginManagerAudioProcessor::VstpluginManagerAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	
	

	_state = new AudioProcessorValueTreeState(*this, nullptr);

	_state->createAndAddParameter("gain", "Gain", "Gain", NormalisableRange<float>(0.f, 1.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("range", "Range", "Range", NormalisableRange<float>(0.f, 3000.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("mix", "Mix", "Mix", NormalisableRange<float>(0.f, 1.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("volume", "Volume", "Volume", NormalisableRange<float>(0.f, 3.f, 0.0001), 1.f, nullptr, nullptr);

	_state->state = ValueTree("drive");
	_state->state = ValueTree("range");
	_state->state = ValueTree("mix");
	_state->state = ValueTree("volume");
}

VstpluginManagerAudioProcessor::~VstpluginManagerAudioProcessor()
{
}

//==============================================================================
const String VstpluginManagerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VstpluginManagerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VstpluginManagerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VstpluginManagerAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VstpluginManagerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VstpluginManagerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VstpluginManagerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VstpluginManagerAudioProcessor::setCurrentProgram (int index)
{
}

const String VstpluginManagerAudioProcessor::getProgramName (int index)
{
    return {};
}

void VstpluginManagerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VstpluginManagerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void VstpluginManagerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VstpluginManagerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void VstpluginManagerAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
	Distortion(buffer, totalNumInputChannels);
}

void VstpluginManagerAudioProcessor::Distortion(AudioBuffer<float>& buffer, int totalNumInputChannels)
{
	float gain = *_state->getRawParameterValue("gain");
	float range = *_state->getRawParameterValue("range");
	float mix = *_state->getRawParameterValue("mix");
	float volume = *_state->getRawParameterValue("volume");

	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);

		for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
		{
			float cleanSignal = *channelData;

			*channelData *= gain * range;
			*channelData = ((((2.0 / float_Pi) * atan(*channelData)) * mix + cleanSignal * (1.0 - mix)) / 2) * volume;


			++channelData;
		}
	}
}

void VstpluginManagerAudioProcessor::Equalizer(AudioBuffer<float>&, int totalNumInputChannels)
{

}

//==============================================================================
bool VstpluginManagerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VstpluginManagerAudioProcessor::createEditor()
{
    return new VstpluginManagerAudioProcessorEditor (*this);
}

//==============================================================================
void VstpluginManagerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	MemoryOutputStream stream(destData, false);
	_state->state.writeToStream(stream);
}

void VstpluginManagerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

	ValueTree tree = ValueTree::readFromData(data, sizeInBytes);

	if (tree.isValid())
		_state->state = tree;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VstpluginManagerAudioProcessor();
}

AudioProcessorValueTreeState& VstpluginManagerAudioProcessor::getState()
{
	return *_state;
}