#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <vector>
#include "SpriteSheet.h"
#include "XTimer.h"

using namespace std;

class Animation
{
    public:
        Animation();
        void AddFrame(int tileId);
        void SetFrame(int frameNumber);
        void SetSpeed(float speed);
        void Play();
        void Next();
        void Prev();
        void Pause();
        void Resume();
        void Stop();
        bool HasFinished();
        int GetFrame();
        void Update();
    
    private:
        const int STATE_PLAYING = 0;
        const int STATE_PAUSED =  1;
        const int STATE_STOPPED = 2;
        const int MODE_LOOP =     0;
        const int MODE_ONCE =     1;
        SpriteSheet* spritesheet;
        XTimer* timer;
        vector<int> frames;
        int currFrame =  0;
        int totalFrames= 0;
        int state = STATE_STOPPED;
        int mode =  MODE_LOOP;
};

#endif