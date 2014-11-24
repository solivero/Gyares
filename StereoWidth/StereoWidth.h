/*
  ==============================================================================

    StereoWidth.h
    Created: 6 Oct 2014 7:13:15pm
    Author:  oliver

  ==============================================================================
*/

#ifndef STEREOWIDTH_H_INCLUDED
#define STEREOWIDTH_H_INCLUDED

/*Volume-Normalized Stereo Width Control, contributed by Michael Gruhn to the
MusicDSP Source Code Archive: http://musicdsp.org/showArchiveComment.php?ArchiveID=256
'width' is the stretch factor of the stereo field:
width < 1: decrease in stereo width
width = 1: no change
width > 1: increase in stereo width
width = 0: mono*/
class StereoWidth
{
public:
    StereoWidth();
    ~StereoWidth();

    //Parameters
    void setWidth(float width);
    float getWidth(void){return m_width*100;};

    //Use
    void ClockProcess(float* LeftSample, float* RightSample);

private:
    float m_width, sumGain, diffGain;
};



#endif  // STEREOWIDTH_H_INCLUDED
