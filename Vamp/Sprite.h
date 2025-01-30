#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <unordered_map>
#include "Animation.h"
#include "Animator.h"

using namespace std;

class Sprite
{

    public:
        int x = 0;
        int y = 0;
        int width = 1;
        int height = 1;
        float scaleX = 1.0;
        float scaleY = 1.0;
        Sprite();
        void SetPos(int x, int y);
        int GetFullWidth();
        int GetFullHeight();
        SpriteSheet* spritesheet = nullptr;
        Animator* animator = nullptr;
        void Play(string animName, bool restart = false);
        void Pause();
        void Resume();
        void Stop();
        void SetFrame(int frame);
        int GetFrame();
        void SetAnimator(Animator* animator);
        Animator* GetAnimator();
        void SetSpriteSheet(SpriteSheet* spritesheet);
        SpriteSheet* GetSpriteSheet();
        void Update();
        void Paint();
        
    private:
        int currFrame = 0;
};

#endif