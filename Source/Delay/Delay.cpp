#include "Delay.h"
Delay::Delay() {
    delayBuffer = AudioSampleBuffer(2, 44100);
    delayPosition = 0;
}

Delay::~Delay() {};

void Delay::applyDelay(AudioSampleBuffer& buffer) {
    // Apply our delay effect to the new output..
    // Panning, inte bara volymskillnad. Panning reglerar delaypulsernas avtagande så att även en konstant feedback kan avta på ena kanalen med panning. Feedback pan!
    // Skapar illusion av att ljudet förflyttar sig succesivt mot höger eller vänster. SÅ JÄVLA COOLT
    int dp, channel = 0;
    if (!isBypassed()) {
        for (channel; channel < 2; ++channel)
        {
            float pan = 1;
            if (m_pan < 0 && channel == 1)
                pan = 1 - (-1) * m_pan;
            else if (m_pan > 0 && channel == 0)
                pan = 1 - m_pan;
            float* channelData = buffer.getWritePointer (channel);
            float* delayData = delayBuffer.getWritePointer (jmin (channel, delayBuffer.getNumChannels() - 1));
            dp = delayPosition;

            for (int i = 0; i < buffer.getNumSamples(); ++i)
            {
                const float in = channelData[i];
                channelData[i] += delayData[dp];
                delayData[dp] = (delayData[dp] + in) * (m_feedback/100.0) * pan;
                if (++dp >= delayBuffer.getNumSamples())
                dp = 0;
            }
        }
    }

    delayPosition = dp;
}

void Delay::setPan(float pan) {
    m_pan = pan;
}

void Delay::setFeedback(float feedback) {
    m_feedback = feedback;
}

void Delay::setTime(float time) {
    m_time = time;
    delayBuffer.setSize(2, (int) (time*44100), false, true, true);
}

void Delay::setBypass(float bypass) {
    m_bypass = bypass;
}

