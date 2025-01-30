#include "Sprite.h"

// Constructor
Sprite::Sprite()
{
    cout << "new sprite" << endl;
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
        animator->Update();
}

void Sprite::Paint()
{
    if((animator != nullptr) && (spritesheet != nullptr))
    {
        animator->GetAnim()->Update();
        int frame = animator->GetAnim()->GetFrame();
        
        //cout << "frame: " << frame << endl;
        spritesheet->Paint(frame, x, y, width * scaleX, height * scaleY);
    }
}




