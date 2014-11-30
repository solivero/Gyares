/*
  ==============================================================================

    StereoWidth.cpp
    Created: 6 Oct 2014 7:13:15pm
    Author:  oliver

  ==============================================================================
*/

#include "StereoWidth.h"

StereoWidth::StereoWidth(){setWidth(100.0f);}
StereoWidth::~StereoWidth(){}

void StereoWidth::setWidth(float width)
{
    width=width/100;
    m_width=width;
    float tmp;
    if(1.0f+width>2.0f)
        tmp=1.0f/(1.0f+m_width);
    else
        tmp=1.0f/2.0f;

    diffGain=m_width*tmp;
    sumGain=tmp;
}

void StereoWidth::ClockProcess(float* LeftSample, float* RightSample)
{
    float m = sumGain*(*LeftSample+*RightSample);
    float s = diffGain*(*RightSample-*LeftSample);
    *LeftSample=m-s;
    *RightSample=m+s;
}
