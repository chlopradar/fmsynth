/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FM_SYNTHAudioProcessorEditor::FM_SYNTHAudioProcessorEditor (FM_SYNTHAudioProcessor& p)
    : AudioProcessorEditor (&p), 
    audioProcessor (p), 
    osc(audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"),
    adsr("Amp Envelope", audioProcessor.apvts, "ATTACK", "DECAY", "SUSTAIN", "RELEASE"),
    filter (audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES"),
    modAdsr("Mod Envelope", audioProcessor.apvts, "MODATTACK", "MODDECAY", "MODSUSTAIN", "MODRELEASE")
{
    setSize (800, 600);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filter);
    addAndMakeVisible(modAdsr);
}

FM_SYNTHAudioProcessorEditor::~FM_SYNTHAudioProcessorEditor()
{
}

//==============================================================================
void FM_SYNTHAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void FM_SYNTHAudioProcessorEditor::resized()
{
    const auto width = 300;
    const auto height = 160;

    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 230;

    osc.setBounds(paddingX, paddingY, width, height);
    adsr.setBounds(osc.getRight(), paddingY, width, height);
    filter.setBounds(paddingX, paddingY2, width, height);
    modAdsr.setBounds(filter.getRight(), paddingY2, width, height);
}
