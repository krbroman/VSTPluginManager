/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VstpluginManagerAudioProcessorEditor::VstpluginManagerAudioProcessorEditor (VstpluginManagerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	_distance1 = 0;
	_distance2 = 0;

#pragma region ComboBoxes
	_firstPluginAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "firstPluginID", _firstPluginBox);
	_secondPluginAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "secondPluginID", _secondPluginBox);
	_thirdPluginAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "thirdPluginID", _thirdPluginBox);

	
	_firstPluginBox.addItem("Distortion", 1);
	_firstPluginBox.addItem("Equalizer", 2);
	_firstPluginBox.addItem("Reverb", 3);
	_firstPluginBox.setJustificationType(Justification::centred);
	//_firstPluginBox.setSelectedId(0, true);
	_firstPluginBox.onChange = [this] {FirstPluginBoxChanged(); };
	addAndMakeVisible(_firstPluginBox);

	_secondPluginBox.addItem("Distortion", 1);
	_secondPluginBox.addItem("Equalizer", 2);
	_secondPluginBox.addItem("Reverb", 3);
	_secondPluginBox.setJustificationType(Justification::centred);
	_secondPluginBox.onChange = [this] {SecondPluginBoxChanged(); };
	

	_thirdPluginBox.addItem("Distortion", 1);
	_thirdPluginBox.addItem("Equalizer", 2);
	_thirdPluginBox.addItem("Reverb", 3);
	_thirdPluginBox.setJustificationType(Justification::centred);
	_thirdPluginBox.onChange = [this] {ThirdPluginBoxChanged(); };
#pragma endregion

#pragma region Distortion



	//addAndMakeVisible(_gainKnob = new Slider("Gain"));
	_gainKnob = new Slider("Gain");
	_gainKnob->setSliderStyle(Slider::Rotary);
	_gainKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_gainAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "gain", *_gainKnob);
	

	//addAndMakeVisible(_rangeKnob = new Slider("Range"));
	_rangeKnob = new Slider("Range");
	_rangeKnob->setSliderStyle(Slider::Rotary);
	_rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *_rangeKnob);

	//addAndMakeVisible(_mixKnob = new Slider("Mix"));
	_mixKnob = new Slider("Mix");
	_mixKnob->setSliderStyle(Slider::Rotary);
	_mixKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_mixAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "mix", *_mixKnob);

	//addAndMakeVisible(_volumeKnob = new Slider("Volume"));
	_volumeKnob = new Slider("Volume");
	_volumeKnob->setSliderStyle(Slider::Rotary);
	_volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *_volumeKnob);

#pragma endregion

#pragma region EQ
	_freq1Knob = new Slider("Freq");
	_freq1Knob->setSliderStyle(Slider::Rotary);
	_freq1Knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_freq1Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "freq1", *_freq1Knob);

	_q1Knob = new Slider("Q");
	_q1Knob->setSliderStyle(Slider::Rotary);
	_q1Knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_q1Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "q1", *_q1Knob);

	_gain1Knob = new Slider("Gain");
	_gain1Knob->setSliderStyle(Slider::Rotary);
	_gain1Knob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_gain1Attachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "gain1", *_gain1Knob);
#pragma endregion

#pragma region Reverb
	_delayKnob = new Slider("Delay");
	_delayKnob->setSliderStyle(Slider::Rotary);
	_delayKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_delayAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "delay", *_delayKnob);

	_decayKnob = new Slider("Decay");
	_decayKnob->setSliderStyle(Slider::Rotary);
	_decayKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_decayAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "decay", *_decayKnob);

	_mixRKnob = new Slider("MixR");
	_mixRKnob->setSliderStyle(Slider::Rotary);
	_mixRKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_mixRAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "mixR", *_mixRKnob);

	_wetKnob = new Slider("wet");
	_wetKnob->setSliderStyle(Slider::Rotary);
	_wetKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	_wetAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "wet", *_wetKnob);
#pragma endregion


	//_firstPluginAttachment = new AudioProcessorValueTreeState::ComboBoxAttachment(p.getState(), "firstPluginID", _firstPluginBox);

	//_firstPluginBox.setSelectedId(0, true);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 600);
}

VstpluginManagerAudioProcessorEditor::~VstpluginManagerAudioProcessorEditor()
{
}

//==============================================================================
void VstpluginManagerAudioProcessorEditor::paint(Graphics& g)
{
	
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	g.setColour(Colours::white);
	g.setFont(15.0f);

	
	if(_firstPluginBox.getSelectedId() == 1)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Range", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Mix", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Volume", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	}
	else if (_firstPluginBox.getSelectedId() == 2)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 80, 80, Justification::centredBottom, 1);
		g.drawText("Freq", ((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) - (100 / 2) + 25 + 70, 80, 80, Justification::centredBottom, 1);
		g.drawText("Q", ((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) - (100 / 2) + 25 + 70, 80, 80, Justification::centredBottom, 1);
	}
	else if (_firstPluginBox.getSelectedId() == 3)
	{
		g.drawText("Delay", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Decay", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Dry/Wet", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
		g.drawText("Mix", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	}

	if (_secondPluginBox.getSelectedId() == 1)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Range", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Mix", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Volume", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10)  + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
	}
	else if (_secondPluginBox.getSelectedId() == 2)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + _secondPluginBox.getY(), 80, 80, Justification::centred, 1);
		g.drawText("Freq", ((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) + 70 + _secondPluginBox.getY(), 80, 80, Justification::centred, 1);
		g.drawText("Q", ((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) + 70 + _secondPluginBox.getY(), 80, 80, Justification::centred, 1);
	}
	else if (_secondPluginBox.getSelectedId() == 3)
	{
		g.drawText("Delay", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Decay", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Dry/Wet", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Mix", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) + 40 + _secondPluginBox.getY(), 100, 40, Justification::centred, 1);
	}

	if (_thirdPluginBox.getSelectedId() == 1)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Range", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Mix", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Volume", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
	}
	else if (_thirdPluginBox.getSelectedId() == 2)
	{
		g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + _thirdPluginBox.getY(), 80, 80, Justification::centred, 1);
		g.drawText("Freq", ((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) + 70 + _thirdPluginBox.getY(), 80, 80, Justification::centred, 1);
		g.drawText("Q", ((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) + 70 + _thirdPluginBox.getY(), 80, 80, Justification::centred, 1);
	}
	else if (_thirdPluginBox.getSelectedId() == 3)
	{
		g.drawText("Delay", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Decay", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Dry/Wet", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
		g.drawText("Mix", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) + 40 + _thirdPluginBox.getY(), 100, 40, Justification::centred, 1);
	}

	HideDistortionMenu();
	HideEQMenu();
	HideReverbMenu();
}

void VstpluginManagerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	Rectangle<int> area1 = Rectangle<int>(0, getHeight() / 100, getWidth(), 20);
	Rectangle<int> area2 = Rectangle<int>(0, getHeight() / 10 * _distance1 + 30, getWidth(), 20);
	Rectangle<int> area3 = Rectangle<int>(0, getHeight() / 10 * (_distance1 + _distance2) + 54, getWidth(), 20);

	//_firstPluginBox.getSelectedId
	_firstPluginBox.setBounds(area1);
	_secondPluginBox.setBounds(area2);
	_thirdPluginBox.setBounds(area3);

	addAndMakeVisible(_secondPluginBox);
	addAndMakeVisible(_thirdPluginBox);

	
}

void VstpluginManagerAudioProcessorEditor::FirstPluginBoxChanged()
{
	
	switch (_firstPluginBox.getSelectedId())
	{
		
	case 1:
		_distance1 = 2;
		DrawDistortionPlugin(1);
		break;
	case 2:
		_distance1 = 4;
		DrawEQPlugin(1);
		break;
	case 3:
		_distance1 = 2;
		DrawReverbPlugin(1);
		break;
	default:
		break;
	}
	
	DrawDistortionPlugin(0);
	DrawEQPlugin(0);
	DrawReverbPlugin(0);
	resized();
}

void VstpluginManagerAudioProcessorEditor::SecondPluginBoxChanged()
{

	switch (_secondPluginBox.getSelectedId())
	{
	case 1:
		_distance2 = 2;
		DrawDistortionPlugin(2);
		break;
	case 2:
		_distance2 = 4;
		DrawEQPlugin(2);
		break;
	case 3:
		_distance2 = 2;
		DrawReverbPlugin(2);
		break;
	default:
		break;
	}
	
	DrawDistortionPlugin(0);
	DrawEQPlugin(0);
	DrawReverbPlugin(0);
	resized();
}

void VstpluginManagerAudioProcessorEditor::ThirdPluginBoxChanged()
{
	switch (_thirdPluginBox.getSelectedId())
	{
	case 1:
		DrawDistortionPlugin(3);
		break;
	case 2:
		DrawEQPlugin(3);
		break;
	case 3:
		DrawReverbPlugin(3);
		break;
	default:
		break;
	}
	
	DrawDistortionPlugin(0);
	DrawEQPlugin(0);
	DrawReverbPlugin(0);
	resized();
}

void VstpluginManagerAudioProcessorEditor::DrawDistortionPlugin(int plugin)
{
	if (plugin == 0)
		if (_firstPluginBox.getSelectedId() == 1)
			plugin = 1;
		else if (_secondPluginBox.getSelectedId() == 1)
			plugin = 2;
		else if (_thirdPluginBox.getSelectedId() == 1)
			plugin = 3;

	

	switch (plugin)
	{
	case 1:
		if (_secondPluginBox.getSelectedId() == 1)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}
			
		if (_thirdPluginBox.getSelectedId() == 1)
			_thirdPluginBox.setSelectedId(0, true);

		_gainKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_rangeKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_mixKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_volumeKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		break;
	case 2:
		if (_firstPluginBox.getSelectedId() == 1)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_thirdPluginBox.getSelectedId() == 1)
			_thirdPluginBox.setSelectedId(0, true);

		_gainKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_rangeKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_mixKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_volumeKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		break;
	case 3:
		if (_firstPluginBox.getSelectedId() == 1)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_secondPluginBox.getSelectedId() == 1)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}
		_gainKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_rangeKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_mixKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_volumeKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		break;
	}

	addAndMakeVisible(_gainKnob);
	addAndMakeVisible(_rangeKnob);
	addAndMakeVisible(_mixKnob);
	addAndMakeVisible(_volumeKnob);
	
	resized();
}
void VstpluginManagerAudioProcessorEditor::HideDistortionMenu()
{
	if (_firstPluginBox.getSelectedId() != 1 && _secondPluginBox.getSelectedId() != 1 && _thirdPluginBox.getSelectedId() != 1)
	{
		_gainKnob->setVisible(false);
		_rangeKnob->setVisible(false);
		_mixKnob->setVisible(false);
		_volumeKnob->setVisible(false);
	}
	resized();
}

void VstpluginManagerAudioProcessorEditor::DrawEQPlugin(int plugin)
{
	if (plugin == 0)
		if (_firstPluginBox.getSelectedId() == 2)
			plugin = 1;
		else if (_secondPluginBox.getSelectedId() == 2)
			plugin = 2;
		else if (_thirdPluginBox.getSelectedId() == 2)
			plugin = 3;

	switch (plugin)
	{
	case 1:
		if (_secondPluginBox.getSelectedId() == 2)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}

		if (_thirdPluginBox.getSelectedId() == 2)
			_thirdPluginBox.setSelectedId(0, true);

		_gain1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 80, 80);
		_freq1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) - (100 / 2) + 90 + _firstPluginBox.getY(), 80, 80);
		_q1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) - (100 / 2) + 90 + _firstPluginBox.getY(), 80, 80);

		break;
	case 2:
		if (_firstPluginBox.getSelectedId() == 2)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_thirdPluginBox.getSelectedId() == 2)
			_thirdPluginBox.setSelectedId(0, true);

		_gain1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 80, 80);
		_freq1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) - (100 / 2) + 90 + _secondPluginBox.getY(), 80, 80);
		_q1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) - (100 / 2) + 90 + _secondPluginBox.getY(), 80, 80);
		break;
	case 3:
		if (_firstPluginBox.getSelectedId() == 2)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_secondPluginBox.getSelectedId() == 2)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}

		_gain1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 80, 80);
		_freq1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 - 40, (getHeight() / 10) - (100 / 2) + 90 + _thirdPluginBox.getY(), 80, 80);
		_q1Knob->setBounds(((getWidth() / 5) * 1) - 100 / 2 + 40, (getHeight() / 10) - (100 / 2) + 90 + _thirdPluginBox.getY(), 80, 80);
		break;
	}

	addAndMakeVisible(_gain1Knob);
	addAndMakeVisible(_freq1Knob);
	addAndMakeVisible(_q1Knob);
	resized();
}

void VstpluginManagerAudioProcessorEditor::DrawReverbPlugin(int plugin)
{
	if (plugin == 0)
		if (_firstPluginBox.getSelectedId() == 3)
			plugin = 1;
		else if (_secondPluginBox.getSelectedId() == 3)
			plugin = 2;
		else if (_thirdPluginBox.getSelectedId() == 3)
			plugin = 3;

	switch (plugin)
	{
	case 1:
		if (_secondPluginBox.getSelectedId() == 3)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}

		if (_thirdPluginBox.getSelectedId() == 3)
			_thirdPluginBox.setSelectedId(0, true);

		_delayKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_decayKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_wetKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		_mixRKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _firstPluginBox.getY(), 100, 100);
		break;
	case 2:
		if (_firstPluginBox.getSelectedId() == 3)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_thirdPluginBox.getSelectedId() == 3)
			_thirdPluginBox.setSelectedId(0, true);

		_delayKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_decayKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_wetKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		_mixRKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _secondPluginBox.getY(), 100, 100);
		break;
	case 3:
		if (_firstPluginBox.getSelectedId() == 3)
		{
			_firstPluginBox.setSelectedId(0, true);
			_distance1 = 0;
			resized();
		}
		if (_secondPluginBox.getSelectedId() == 3)
		{
			_secondPluginBox.setSelectedId(0, true);
			_distance2 = 0;
			resized();
		}

		_delayKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_decayKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_wetKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		_mixRKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 20 + _thirdPluginBox.getY(), 100, 100);
		break;

	default:
		break;
	}

	addAndMakeVisible(_delayKnob);
	addAndMakeVisible(_decayKnob);
	addAndMakeVisible(_mixRKnob);
	addAndMakeVisible(_wetKnob);

	resized();
}

void VstpluginManagerAudioProcessorEditor::HideEQMenu()
{
	
	if (_firstPluginBox.getSelectedId() != 2 && _secondPluginBox.getSelectedId() != 2 && _thirdPluginBox.getSelectedId() != 2)
	{
		_gain1Knob->setVisible(false);
		_freq1Knob->setVisible(false);
		_q1Knob->setVisible(false);
		
	}
	resized();
}

void VstpluginManagerAudioProcessorEditor::HideReverbMenu()
{
	if (_firstPluginBox.getSelectedId() != 3 && _secondPluginBox.getSelectedId() != 3 && _thirdPluginBox.getSelectedId() != 3)
	{
		_delayKnob->setVisible(false);
		_decayKnob->setVisible(false);
		_mixRKnob->setVisible(false);
		_wetKnob->setVisible(false);
	}
	resized();
}

int* VstpluginManagerAudioProcessorEditor::GetPluginOrder()
{
	return new int[3]{ _firstPluginBox.getSelectedId(), _secondPluginBox.getSelectedId(), _thirdPluginBox.getSelectedId(), };
}