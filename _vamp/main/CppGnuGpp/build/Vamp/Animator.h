#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <iostream>
#include <unordered_map>
#include "Animation.h"

using namespace std;

class Animator
{

    public:
        Animator();
        Animation* animation = nullptr; // current animation
        string currAnimName = "";
        void AddAnim(string animName, Animation* anim);
        void Play(string animName, bool restart = false);
        void Pause();
        void Resume();
        void Stop();
        Animation* GetAnim();
        void Update();
        
    private:
        unordered_map<string, Animation*> animations;
};

#endif