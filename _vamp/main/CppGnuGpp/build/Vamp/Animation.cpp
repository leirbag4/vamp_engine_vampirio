#include "Animation.h"


Animation::Animation()
{
    
    this->spritesheet = spritesheet;
    this->currFrame = 0;
    this->timer = new XTimer(500);
}

void Animation::AddFrame(int tileId)
{
    frames.push_back(tileId);
    totalFrames = frames.size();   
}


void Animation::SetFrame(int frameNumber)
{
    currFrame = frameNumber;
}

void Animation::SetSpeed(float speed)
{
    timer->SetSDelay(speed);
}

void Animation::Play()
{
	timer->Start();
    currFrame = 0;
    state = STATE_PLAYING;
}

void Animation::Next()
{
    currFrame++;
    
    if(mode == MODE_LOOP)
    {
        if(currFrame >= totalFrames)
            currFrame = 0;
    }
    else if(mode == MODE_ONCE)
    {
        currFrame = totalFrames - 1;
    }
}

void Animation::Prev()
{
    currFrame--;
    
    if(mode == MODE_LOOP)
    {
        if(currFrame < 0)
            currFrame = totalFrames - 1;
    }
    else if(mode == MODE_ONCE)
    {
        if(currFrame < 0)
            currFrame = 0;
    }
}

void Animation::Pause()
{
    state = STATE_PAUSED;
}

void Animation::Resume()
{
    state = STATE_PLAYING;
}

void Animation::Stop()
{
	currFrame = 0;
    state = STATE_STOPPED;
}

bool Animation::HasFinished()
{
    return (currFrame == (totalFrames - 1));
}

int Animation::GetFrame()
{
    return frames[currFrame];
}

void Animation::Update()
{
    if(state == STATE_PLAYING)
    {
    	if(timer->Update())
    	{
    		timer->Start();
            Next();
        }
    }
}


