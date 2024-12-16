/*
  ==============================================================================

    SynthSound.h
    Created: 3 Oct 2024 12:08:26pm
    Author:  Radek

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }
};