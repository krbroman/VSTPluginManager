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
	using Parameter = AudioProcessorValueTreeState::Parameter;
	

	_state = new AudioProcessorValueTreeState(*this, nullptr);
	
	//Parameters for Distortion
	_state->createAndAddParameter("gain", "Gain", "Gain", NormalisableRange<float>(0.f, 1.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("range", "Range", "Range", NormalisableRange<float>(0.f, 3000.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("mix", "Mix", "Mix", NormalisableRange<float>(0.f, 1.f, 0.0001), 0.f, nullptr, nullptr);
	_state->createAndAddParameter("volume", "Volume", "Volume", NormalisableRange<float>(0.f, 3.f, 0.0001), 1.f, nullptr, nullptr);

	//Parameters for EQ
	_state->createAndAddParameter("freq1", "Frequency1", "Frequency1", NormalisableRange<float>(20.f, 20000.f, 0.001), 20.f, nullptr, nullptr);
	_state->createAndAddParameter("q1", "Q1", "Q1", NormalisableRange<float>(0.10, 12.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("gain1", "Gain1", "Gain1", NormalisableRange<float>(0.f, 6.f, 0.0001), 0.f, nullptr, nullptr);

	_state->createAndAddParameter("freq2", "Frequency2", "Frequency2", NormalisableRange<float>(20.f, 20000.f, 0.001), 20.f, nullptr, nullptr);
	_state->createAndAddParameter("q2", "Q2", "Q2", NormalisableRange<float>(0.10, 12.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("gain2", "Gain2", "Gain2", NormalisableRange<float>(0.f, 6.f, 0.0001), 0.f, nullptr, nullptr);

	_state->createAndAddParameter("freq3", "Frequency3", "Frequency3", NormalisableRange<float>(20.f, 20000.f, 0.001), 20.f, nullptr, nullptr);
	_state->createAndAddParameter("q3", "Q3", "Q3", NormalisableRange<float>(0.10, 12.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("gain3", "Gain3", "Gain3", NormalisableRange<float>(0.f, 6.f, 0.0001), 0.f, nullptr, nullptr);

	_state->createAndAddParameter("freq4", "Frequency4", "Frequency4", NormalisableRange<float>(20.f, 20000.f, 0.001), 20.f, nullptr, nullptr);
	_state->createAndAddParameter("q4", "Q4", "Q4", NormalisableRange<float>(0.10, 12.f, 0.0001), 1.f, nullptr, nullptr);
	_state->createAndAddParameter("gain4", "Gain4", "Gain4", NormalisableRange<float>(0.f, 6.f, 0.0001), 0.f, nullptr, nullptr);

	//Parameters for Reverb
	_state->createAndAddParameter("delay", "Delay", "Delay", NormalisableRange<float>(80.f, 3000.f, 1.f), 80.f, nullptr, nullptr);
	_state->createAndAddParameter("decay", "Decay", "Decay", NormalisableRange<float>(0.f, 1.f, 0.0001), 0.f, nullptr, nullptr);
	_state->createAndAddParameter("mixR", "MixR", "MixR", NormalisableRange<float>(0.f, 1.f, 0.0001), 0.f, nullptr, nullptr);
	_state->createAndAddParameter("wet", "Wet", "Wet", NormalisableRange<float>(0.f, 1.f, 0.0001), 0.f, nullptr, nullptr);

	//Parameters for ComboBoxes
	_state->createAndAddParameter(std::make_unique<Parameter>("firstPluginID", "FirstPluginID", "FirstPluginID", NormalisableRange<float>(1.f, 3.f, 1.f), 3.f, nullptr, nullptr));
	_state->createAndAddParameter(std::make_unique<Parameter>("secondPluginID", "SecondPluginID", "SecondPluginID", NormalisableRange<float>(1.f, 3.f, 1.f), 3.f, nullptr, nullptr));
	_state->createAndAddParameter(std::make_unique<Parameter>("thirdPluginID", "ThirdPluginID", "ThirdPluginID", NormalisableRange<float>(1.f, 3.f, 1.f), 3.f, nullptr, nullptr));
	//_state->createAndAddParameter("firstPluginID", "FirstPluginID", "FirstPluginID", NormalisableRange<float>(0.f, 3.f, 1.f), 0.f, nullptr, nullptr);

	//ValueTrees for Distortion
	_state->state = ValueTree("drive");
	_state->state = ValueTree("range");
	_state->state = ValueTree("mix");
	_state->state = ValueTree("volume");

	//ValueTrees for EQ
	_state->state = ValueTree("freq1");
	_state->state = ValueTree("q1");
	_state->state = ValueTree("gain1");
	
	_state->state = ValueTree("freq2");
	_state->state = ValueTree("q2");
	_state->state = ValueTree("gain2");

	_state->state = ValueTree("freq3");
	_state->state = ValueTree("q3");
	_state->state = ValueTree("gain3");

	_state->state = ValueTree("freq4");
	_state->state = ValueTree("q4");
	_state->state = ValueTree("gain4");

	//ValueTrees for Reverb
	_state->state = ValueTree("delay");
	_state->state = ValueTree("decay");
	_state->state = ValueTree("mixR");
	_state->state = ValueTree("wet");

	//ValueTrees for Comboboxes
	_state->state = ValueTree("firstPluginID");
	_state->state = ValueTree("secondPluginID");
	_state->state = ValueTree("thirdPluginID");
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

	const int numInputChannels = getTotalNumInputChannels();
	const int reverbBufferSize = 3 * (sampleRate + samplesPerBlock);
	const int chorusBufferSize = sampleRate + samplesPerBlock;

	_sampleRate = sampleRate;

	_ReverbBuffer.setSize(numInputChannels, reverbBufferSize);
	_ChorusBuffer.setSize(numInputChannels, chorusBufferSize);
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

	const int bufferLength = buffer.getNumSamples();
	const int reverbBufferLength = _ReverbBuffer.getNumSamples();
	const int chorusBufferLength = _ChorusBuffer.getNumSamples();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


	FillReverbBuffer(buffer, totalNumInputChannels, bufferLength, reverbBufferLength);
	FillChorusBuffer(buffer, totalNumInputChannels, bufferLength, chorusBufferLength);

	
	float rf = *_state->getRawParameterValue("firstPluginID");
	
	switch ((int)rf)
	{
	case 1:
		Distortion(buffer, totalNumInputChannels);
		break;
	case 2:
		Equalizer(buffer, totalNumInputChannels);
		break;
	case 3:
		Reverb(buffer, totalNumInputChannels);
		break;
	default:
		break;
	}
	
	rf = *_state->getRawParameterValue("secondPluginID");

	switch ((int)rf)
	{
	case 1:
		Distortion(buffer, totalNumInputChannels);
		break;
	case 2:
		Equalizer(buffer, totalNumInputChannels);
		break;
	case 3:
		Reverb(buffer, totalNumInputChannels);
		break;
	default:
		break;
	}

	rf = *_state->getRawParameterValue("thirdPluginID");

	switch ((int)rf)
	{
	case 1:
		Distortion(buffer, totalNumInputChannels);
		break;
	case 2:
		Equalizer(buffer, totalNumInputChannels);
		break;
	case 3:
		Reverb(buffer, totalNumInputChannels);
		break;
	default:
		break;
	}
}

void VstpluginManagerAudioProcessor::FillReverbBuffer(AudioBuffer<float>& buffer, int totalNumInputChannels, int bufferLength, int reverbBufferLength)
{
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		const float* bufferData = buffer.getReadPointer(channel);
		const float* reverbBufferData = _ReverbBuffer.getReadPointer(channel);

		if (reverbBufferLength > bufferLength + _writePos)
			_ReverbBuffer.copyFromWithRamp(channel, _writePos, bufferData, bufferLength, 0.81, 0.81);
		else {
			const int bufferRem = reverbBufferLength - _writePos;
			_ReverbBuffer.copyFromWithRamp(channel, _writePos, bufferData, bufferRem, 0.81, 0.81);
			_ReverbBuffer.copyFromWithRamp(channel, 0, bufferData, bufferLength - bufferRem, 0.81, 0.81);
		}
	}
	_writePos += bufferLength;
	_writePos %= reverbBufferLength;
}

void VstpluginManagerAudioProcessor::FillChorusBuffer(AudioBuffer<float>& buffer, int totalNumInputChannels, int bufferLength, int chorusBufferLength)
{
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		const float* bufferData = buffer.getReadPointer(channel);
		const float* chorusBufferData = _ChorusBuffer.getReadPointer(channel);

		if (chorusBufferLength > bufferLength + _writePosChorus)
			_ChorusBuffer.copyFromWithRamp(channel, _writePosChorus, bufferData, bufferLength, 0.81, 0.81);
		else {
			const int bufferRem = chorusBufferLength - _writePosChorus;
			_ChorusBuffer.copyFromWithRamp(channel, _writePosChorus, bufferData, bufferRem, 0.81, 0.81);
			_ChorusBuffer.copyFromWithRamp(channel, 0, bufferData, bufferLength - bufferRem, 0.81, 0.81);
		}
	}
	_writePosChorus += bufferLength;
	_writePosChorus %= chorusBufferLength;
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

void VstpluginManagerAudioProcessor::Equalizer(AudioBuffer<float>& buffer, int totalNumInputChannels)
{
	return;
	float freq[4];
	float q[4];
	float gain[4];

	freq[0] = *_state->getRawParameterValue("freq1");
	q[0] = *_state->getRawParameterValue("q1");
	gain[0] = *_state->getRawParameterValue("gain1");

	/*freq[1] = *_state->getRawParameterValue("freq2");
	q[1] = *_state->getRawParameterValue("q2");
	gain[1] = *_state->getRawParameterValue("gain2");

	freq[2] = *_state->getRawParameterValue("freq3");
	q[2] = *_state->getRawParameterValue("q3");
	gain[2] = *_state->getRawParameterValue("gain3");

	freq[3] = *_state->getRawParameterValue("freq4");
	q[3] = *_state->getRawParameterValue("q4");
	gain[3] = *_state->getRawParameterValue("gain4");*/

	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);

		for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
		{
			float cleanSignal = *channelData;

			for (int i = 0; i < 4; ++i)
			{
				if (i != 0)
					return;
				float N = (2.0 / log(2)) * asinh(1.0 / (2. * q[i]));
				float bandwidth = freq[i] / q[i];
				if (true)//(*channelData > freq[i] - bandwidth && *channelData < freq[i] + bandwidth)
				{
					float G = gain[i];
					float B = bandwidth;
					float w = freq[i];
					float w2 = pow(w, 2);
					float w4 = pow(w2, 2);
					float B2 = pow(B, 2);
					float s2 = sqrt(2);
					/*float fs = 41000;
					float c = 1 / tan(double_Pi * freq[i] / fs);
					float cs = pow(c, 2);
					float csp1 = cs + 1;
					float Bc = (bandwidth / fs) * c;
					float gBc = gain[i] * Bc;
					float nrm = 1 / (csp1 + Bc);
					float b0 = (csp1 + gBc) * nrm;
					float b1 = 2 * (1 - cs) * nrm;
					float b2 = (csp1 - gBc) * nrm;
					float a0 = 1;
					float a1 = b1;
					float a2 = (csp1 - Bc) * nrm;

					*/
					float a0 = 16 + w4 + 8 * w2 + 8 * s2 * G * B + 2 * s2 * G * B * w2 + 4 * G * B2;
					float a1 = -64 + 4 * w4 - 16 * s2 * G * B + 4 * s2 * G * B * w2;
					float a2 = 96 + 6 * w4 - 16 * w2 - 8 * G * B2;
					float a3 = -64 + 4 * w4 + 16 * s2 * G * B - 4 * s2 * G * B * w2;
					float a4 = 16 + w4 + 8 * w2 + 2 * s2 * G * B * (-4 - w2) + 4 * G * B2;

					float b0 = 16 + w4 + 8 * w2 + 8 * s2 * B + 2 * s2 * B * w2 + 4 * B2;
					float b1 = -64 + 4 * w4 - 16 * s2 * B + 4 * s2 * B * w2;
					float b2 = 96 + 6 * w4 - 16 * w2 - 8 * B2;
					float b3 = -64 + 4 * w4 + 16 * s2 * B - 4 * s2 * B * w2;
					float b4 = 16 + w4 + 8 * w2 + 2 * s2 * B * (-4 - w2) + 4 * B2;

					float s = *channelData;
					float z = -(s + 2) / (s - 2);
					*channelData = (a0 + a1 * pow(z, -1) + a2 * pow(z, -2) + a3 * pow(z, -3) + a4 * pow(z, -4)) / (b0 + b1 * pow(z, -1) + b2 * pow(z, -2) + b3 * pow(z, -3) + b4 * pow(z, -4));
					//*channelData = (s * s + gain[i] * bandwidth * s + 1) / (s * s + bandwidth * s + 1);
					//++channelData;
				}
			}


			++channelData;
		}
	}
}

void VstpluginManagerAudioProcessor::Reverb(AudioBuffer<float>& buffer, int totalNumInputChannels)
{
	float delay = *_state->getRawParameterValue("delay");
	float decay = *_state->getRawParameterValue("decay");
	float mixR = *_state->getRawParameterValue("mixR");
	float wet = *_state->getRawParameterValue("wet");
	float sampleRate = getSampleRate();
	int numSamples = buffer.getNumSamples();
	
	
	

	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);

		/*float* data = new float[numSamples];
		for (int i = 0; i < numSamples; ++i)
		{
			data[i] = *channelData;
			++channelData;
		}
		channelData = buffer.getWritePointer(channel);*/
		
		//float a = *channelData;
		float* comb1 = combFilter(buffer, decay, delay, numSamples, channel);
		//channelData = buffer.getWritePointer(channel);
		float* comb2 = combFilter(buffer, decay - 0.1313f, delay - 11.73f, numSamples, channel);
		//channelData = buffer.getWritePointer(channel);
		float* comb3 = combFilter(buffer, decay - 0.2743f, delay + 19.31f, numSamples, channel);
		//channelData = buffer.getWritePointer(channel);
		float* comb4 = combFilter(buffer, decay - 0.31f, delay - 7.97f, numSamples, channel);
		//channelData = buffer.getWritePointer(channel);

		float* combOut = new float[numSamples];
		for (int sample = 0; sample < numSamples; ++sample)
		{
			combOut[sample] = comb1[sample] + comb2[sample] + comb3[sample] + comb4[sample];
			float a = 1.f;
		}

		delete[] comb1;
		delete[] comb2;
		delete[] comb3;
		delete[] comb4;
		
		float* output = new float[numSamples];
		wet *= 100;
		for (int sample = 0; sample < numSamples; ++sample)
		{
			output[sample] = (channelData[sample] * (100.f - wet) + combOut[sample] * wet);
			//output[sample] = channelData[sample];
			float a = 1.f;
		}

		delete[] combOut;

		float* allPass = allPassFilter(output, sampleRate, numSamples);
		float* final = allPassFilter(allPass, sampleRate, numSamples);

		for (int sample = 0; sample < numSamples; ++sample)
		{
			
			*channelData = final[sample] * mixR / 10 + *channelData * (1.f - mixR);
			
			//*channelData = combOut[sample];

			
			++channelData;
		}
		delete[] output;
		delete[] allPass;
		delete[] final;
	}
}

float* VstpluginManagerAudioProcessor::combFilter(AudioBuffer<float>& buffer, float decayFactor, int delayInMS, int numSamples, int channel)
{
	int delayInS = (int)(delayInMS * (_sampleRate / 1000));
	float* combFilter = new float[numSamples];
	const float* data = buffer.getReadPointer(channel);
	const int bufferLength = buffer.getNumSamples();
	const int reverbBufferLenth = _ReverbBuffer.getNumSamples();
	//if(numSamples - delayInS > 0)
	//	for (int i = 0; i < numSamples - delayInS; ++i)
	//	{
	//		combFilter[i] = *(data + i);
	//		combFilter[i + delayInS] = *(data + i + delayInS) + combFilter[i] * decayFactor;
	//		//combFilter[i] = data[i];
	//		//combFilter[i + delayInS] = data[i + delayInS] + combFilter[i] * decayFactor;
	//	}
	//else {
	//	int delay = numSamples - delayInS;

	//}

	const float* revBufferData = _ReverbBuffer.getReadPointer(channel);
	//float* revBufferData = _ReverbBuffer.getWritePointer(channel);

	//long minus = _ReverbBuffer.getNumSamples() - delayInS - 1;
	//revBufferData += minus;
	int readPos = (int)(reverbBufferLenth + _writePos - delayInS) % reverbBufferLenth;
	revBufferData += readPos;


	for (int i = 0; i < numSamples; ++i)
	{
		if (i - delayInS <= 0)
		{
			if (reverbBufferLenth > bufferLength + readPos)
			{
				//revBufferData += readPos;

				//combFilter[i] = *(data + i) + *(revBufferData + _ReverbBuffer.getNumSamples() + i - delayInS) * decayFactor;
				if (abs(*revBufferData) < 100)
					combFilter[i] = (*data + *revBufferData) * decayFactor;
				else combFilter[i] = *data;

				++data;
				++revBufferData;
			}
			else
			{
				const int bufferRem = reverbBufferLenth - readPos;

				if (i < bufferRem)
				{
					//revBufferData += readPos;

					if (abs(*revBufferData) < 100)
						combFilter[i] = *data + *revBufferData * decayFactor;
					else combFilter[i] = *data;

					++data;
					++revBufferData;
				}
				else
				{
					if(i == bufferRem)
						revBufferData = _ReverbBuffer.getReadPointer(channel);

					if (abs(*revBufferData) < 100)
						combFilter[i] = *data + *revBufferData * decayFactor;
					else combFilter[i] = *data;

					++data;
					++revBufferData;
				}
			}
			

			
		}
		else
		{
			combFilter[i] = *(data + i);
			combFilter[i] += *(data + i - delayInS) * decayFactor;
			//++data;
		}
	}
	
	float* erevBufferData = _ReverbBuffer.getWritePointer(channel);
	for (int i = 0; i < numSamples; ++i)
	{
		if (_writePos - bufferLength >= 0)
		{
			*(erevBufferData + _writePos + i - bufferLength) = combFilter[i];
		}
		else
		{
			if(_writePos + i - bufferLength < 0)
				*(erevBufferData + reverbBufferLenth + _writePos + i - bufferLength) = combFilter[i];
			else
			{
				if(_writePos + i == bufferLength)
					erevBufferData = _ReverbBuffer.getWritePointer(channel);
				*erevBufferData = combFilter[i];
				++erevBufferData;
			}
		}
	}

	return combFilter;
}

float* VstpluginManagerAudioProcessor::allPassFilter(float* data, float sampleRate, int numSamples)
{
	int delayInS = (int)((float)50.f * (sampleRate / 1000)); //89.27f
	float* allPassFilter = new float[numSamples];
	float decay = 0.131f;
	float max = 0.f;

	for (int i = 0; i < numSamples; ++i)
	{
		allPassFilter[i] = data[i];

		if (i - delayInS >= 0)
			allPassFilter[i] += -decay * allPassFilter[i - delayInS];

		if (i - delayInS >= 1)
			allPassFilter[i] += decay * allPassFilter[i + 20 - delayInS];

		if (abs(allPassFilter[i]) > max)
			max = abs(allPassFilter[i]);
	}

	for (int i = 0; i < numSamples; i++)
	{
		allPassFilter[i] /= max;
	}
	return allPassFilter;
}

void VstpluginManagerAudioProcessor::Chorus(AudioBuffer<float>& buffer, int totalNumInputChannels)
{
	int delay = 50;
	float freqShift = 3.f;
	float mix = 1.f;

	int delayInS = (int)(delay * (_sampleRate / 1000));
	const int chorusBufferLength = _ChorusBuffer.getNumSamples();
	const int bufferLength = buffer.getNumSamples();
	

	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		auto* channelData = buffer.getWritePointer(channel);
		const float* chorusBufferData = _ChorusBuffer.getReadPointer(channel);
		//float waveLength = 0.f;
		//float signal;
		//int last = -1;
		//int quan = 0;
		//float lengths = 0.f;

		//for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
		//{
		//	//float cleanSignal = *channelData;
		//	if (*channelData * signal < 0)
		//		if (last == -1)
		//			last = sample;
		//		else
		//		{
		//			lengths += sample - last;
		//			++quan;
		//			last = sample;
		//		}
		//	

		//	//*channelData *= gain * range;
		//	//*channelData = ((((2.0 / float_Pi) * atan(*channelData)) * mix + cleanSignal * (1.0 - mix)) / 2) * volume;

		//	signal = *channelData;
		//	++channelData;
		//}

		//waveLength = lengths / quan;
		//float freq = 343.2 / waveLength;
		//float a = 1.f;
		for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
		{
			if (sample - delayInS <= 0)
			{
				//float x = asin(*(chorusBufferData + (_writePosChorus + sample - delay + chorusBufferLength) % chorusBufferLength));
				//*channelData += sin(x * freqShift);

				if(abs(*(chorusBufferData + (_writePosChorus + sample - delayInS + chorusBufferLength) % chorusBufferLength)) < 100)
					*channelData += *(chorusBufferData + (_writePosChorus + sample - delayInS + chorusBufferLength) % chorusBufferLength) * 0.9;
				
				//if (_writePosChorus - delay > 0)
				//{
				//	float x = asin(*(chorusBufferData + _writePosChorus + sample - delay));
				//	*channelData += sin(x * freqShift);
				//	//++chorusBufferData;
				//}
				//else
				//{

				//}
			}
			else
			{
				//float x = asin(*(channelData - delay));
				//*channelData += sin(x * 0.9);
				*channelData += *(channelData - delayInS) * 0.9;
			}
			++channelData;
		}
	}
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