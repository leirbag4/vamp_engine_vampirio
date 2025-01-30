#include "Animator.h"

// Constructor
Animator::Animator()
{
    cout << "new animator" << endl;
}

void Animator::AddAnim(string animName, Animation* anim)
{
    animations[animName] = anim;
    animation =  animations[animName];
}

void Animator::Play(string animName, bool restart)
{
    animation = animations[animName];
    
    if(restart)
        animation->Play();
    else if(currAnimName != animName)
        animation->Play();
    
    currAnimName = animName;
}

void Animator::Pause()
{
	if(animation != nullptr)
        animation->Pause();
}

void Animator::Resume()
{
	if(animation != nullptr)
        animation->Resume();
}

void Animator::Stop()
{
	if(animation != nullptr)
        animation->Stop();
        
    currAnimName = "";
}

Animation* Animator::GetAnim()
{
    return animation;
}

void Animator::Update()
{
	if(animation != nullptr)
        animation->Update();
}

