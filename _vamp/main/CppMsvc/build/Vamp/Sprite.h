#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include "Animation.h"
#include "Animator.h"
#include "Object2D.h"
#include "Scene.h"
//#include "Collider.h"

using namespace std;

class Collider;

class Sprite : public Object2D
{

    public:
        int x = 0;
        int y = 0;
        int width = 1;
        int height = 1;
        float scaleX = 1.0;
        float scaleY = 1.0;
        SpriteSheet* spritesheet = nullptr;
        Animator* animator = nullptr;
        vector<Collider*> colliders;
        Sprite();
        void SetPos(int x, int y);
        int GetFullWidth();
        int GetFullHeight();
        void Play(string animName, bool restart = false);
        void Play();
        void Pause();
        void Resume();
        void Stop();
        void AddFrame(const char* imgPath);
        void SetFrame(int frame);
        int GetFrame();
        void SetAnimator(Animator* animator);
        Animator* GetAnimator();
        void SetSpriteSheet(SpriteSheet* spritesheet);
        SpriteSheet* GetSpriteSheet();
        int GetIndex() override;
        void AttachCollider(Collider* collider);
        void DettachCollider(Collider* collider);
        void Update() override;
        void Paint() override;
        
    private:
        int currFrame = 0;
        bool simpleMode = false;
        vector<Texture*> frameImgs;
        Animation* animImgs;
        void UpdateColliders(int x, int y);
        void DebugColliders();
};

#endif