
#ifndef DELAY_H_INCLUDED
#define DELAY_H_INCLUDED

#include "../../JuceLibraryCode/JuceHeader.h"
class Delay
{
public:
    Delay();
    ~Delay();

    //Parameters
    void setPan(float pan);
    float getPan(void){return m_pan;};

    void setFeedback(float feedback);
    float getFeedback(void){return m_feedback;};

    void setTime(float time);
    float getTime(void){return m_time;};

    void setBypass(float bypass);
    bool isBypassed(void){return m_bypass;};

    AudioSampleBuffer& getBuffer(void){return delayBuffer;};
    //Use
    void applyDelay(AudioSampleBuffer& buffer);

private:
    float m_pan, m_feedback, m_time, m_bypass;
    AudioSampleBuffer delayBuffer;
    int delayPosition;
};



#endif
