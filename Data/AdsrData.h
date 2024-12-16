/*
  ==============================================================================

    AdsrData.h
    Created: 2 Dec 2024 7:38:55pm
    Author:  majab

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);


private:
    juce::ADSR::Parameters adsrParams;
};