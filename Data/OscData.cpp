/*
  ==============================================================================

    OscData.cpp
    Created: 2 Dec 2024 11:47:42pm
    Author:  majab

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    fmOsc.prepare(spec);
    prepare(spec);

}
void OscData::setWaveType(const int choice)
{
    switch (choice)
    {
    case 0:
        initialise([](float x) {return std::sin(x); }); //sine 
        break;
    case 1:
        initialise([](float x) {return x / juce::MathConstants<float>::pi; }); //saw
        break;
    case 2:
        initialise([](float x) {return x  < 0.0f ? -1.0f : 1.0f; }); //sqaure
        break;
    case 3:
        initialise([](float x) {
            float normalized = x / juce::MathConstants<float>::pi; // normalize x to [-1, 1]
            return 2.0f * std::abs(normalized - std::floor(normalized + 0.5f)) - 1.0f;
            }); // triangle
        break;
    default:
        jassertfalse; //error
        break;
    }
} 

void OscData::setWaveFrequency(const int midiNoteNumber)
{
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{
    for (int ch = 0; ch < block.getNumChannels(); ++ch)
    {
        for (int s = 0; s < block.getNumSamples(); ++s)
        {
            fmMod = fmOsc.processSample(block.getSample(ch, s)) * fmDepth;
        }
    }

    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setFmParams(const float depth, const float freq)
{
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    auto currentFreq = juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod;
    setFrequency(currentFreq >= 0 ? currentFreq : currentFreq * -1.0f);
}