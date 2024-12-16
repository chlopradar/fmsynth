/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/AdsrComponent.h"
#include "UI/OscComponent.h"
#include "UI/FilterComponent.h"

//==============================================================================
/**
*/
class FM_SYNTHAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    FM_SYNTHAudioProcessorEditor (FM_SYNTHAudioProcessor&);
    ~FM_SYNTHAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    FM_SYNTHAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;
    FilterComponent filter;
    AdsrComponent modAdsr;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FM_SYNTHAudioProcessorEditor)
};
