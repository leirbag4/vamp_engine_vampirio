#include "Sprite.h"

// Constructor
Sprite::Sprite()
{
    cout << "new sprite" << endl;
}

void Sprite::SetPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Sprite::GetFullWidth()
{
    return width * scaleX;
}

int Sprite::GetFullHeight()
{
    return height * scaleY;
}

void Sprite::Play(string animName, bool restart)
{
    if(animator != nullptr)
        animator->Play(animName, restart);
}

void Sprite::Pause()
{
    if(animator != nullptr)
        animator->Pause();    
}

void Sprite::Resume()
{
    if(animator != nullptr)
        animator->Resume();
}

void Sprite::Stop()
{
    if(animator != nullptr)
        animator->Stop();
}

void Sprite::SetFrame(int frame)
{
    currFrame = frame;
}

int Sprite::GetFrame()
{
    return currFrame;
}

void Sprite::SetAnimator(Animator* animator)
{
    this->animator = animator;
}

Animator* Sprite::GetAnimator()
{
	return animator;
}

void Sprite::SetSpriteSheet(SpriteSheet* spritesheet)
{
    this->spritesheet = spritesheet;
    this->width =   spritesheet->GetTileWidth();
    this->height =  spritesheet->GetTileHeight();
}

SpriteSheet* Sprite::GetSpriteSheet()
{
    return spritesheet;
}

void Sprite::Update()
{
    if(animator != nullptr)
    {
        animator->Update();
        animator->GetAnim()->Update();
        currFrame = animator->GetAnim()->GetFrame();
    }
}

void Sprite::Paint()
{
    if((animator != nullptr) && (spritesheet != nullptr))
    {
        spritesheet->Paint(currFrame, x, y, width * scaleX, height * scaleY);
    }
    else if(spritesheet != nullptr)
    {
        spritesheet->Paint(currFrame, x, y, width * scaleX, height * scaleY);
    }
}




