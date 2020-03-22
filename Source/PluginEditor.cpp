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

	_firstPluginBox.addItem("Distortion", 1);
	_firstPluginBox.addItem("Equalizer", 2);
	_firstPluginBox.addItem("Reverb", 3);
	_firstPluginBox.setJustificationType(Justification::centred);
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
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));

	g.setColour(Colours::white);
	g.setFont(15.0f);

	//g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
	if(_firstPluginBox.getSelectedId() == 1)
	{
	g.drawText("Gain", ((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	g.drawText("Range", ((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	g.drawText("Mix", ((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	g.drawText("Volume", ((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2) + 25, 100, 100, Justification::centredBottom, 1);
	}
	else if (_firstPluginBox.getSelectedId() == 2)
	{
		HideDistortionMenu();
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
		HideDistortionMenu();
	}
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

	/*_gainKnob->setBounds(((getWidth() / 5) * 1) - 100 / 2, (getHeight() / 10) - (100 / 2), 100, 100);
	_rangeKnob->setBounds(((getWidth() / 5) * 2) - 100 / 2, (getHeight() / 10) - (100 / 2), 100, 100);
	_mixKnob->setBounds(((getWidth() / 5) * 3) - 100 / 2, (getHeight() / 10) - (100 / 2), 100, 100);
	_volumeKnob->setBounds(((getWidth() / 5) * 4) - 100 / 2, (getHeight() / 10) - (100 / 2), 100, 100);*/
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
		break;
	case 3:
		_distance1 = 2;
		break;
	default:
		break;
	}
	resized();
	DrawDistortionPlugin(0);
	
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
		break;
	case 3:
		_distance2 = 2;
		break;
	default:
		break;
	}
	resized();
	DrawDistortionPlugin(0);
	
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