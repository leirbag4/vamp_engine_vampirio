#include "Sprite.h"

#include "Collider.h"

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

void Sprite::Play()
{
	if(simpleMode)
	{
        animImgs->Play();
	}
}

void Sprite::Pause()
{
	if(simpleMode)
	{
        animImgs->Pause();
        return;
	}
	
    if(animator != nullptr)
        animator->Pause();    
}

void Sprite::Resume()
{
	if(simpleMode)
	{
        animImgs->Resume();
        return;
	}
	
    if(animator != nullptr)
        animator->Resume();
}

void Sprite::Stop()
{
	if(simpleMode)
	{
        animImgs->Stop();
        return;
	}
	
    if(animator != nullptr)
        animator->Stop();
}

void Sprite::AddFrame(const char* imgPath)
{
    Texture* tex = new Texture(imgPath);
    
    if(frameImgs.empty())
    {
    	animImgs = new Animation();
    	animImgs->AddFrame(0);
    	width =  tex->width;
    	height = tex->height;
        simpleMode = true;
    }
    
    animImgs->AddFrame(frameImgs.size());
    
    frameImgs.push_back(tex);
}

void Sprite::SetFrame(int frame)
{
    currFrame = frame;
        
    if(simpleMode)
	{
		animImgs->SetFrame(currFrame);
		return;
	}
	
	if(animator != nullptr)
        animator->GetAnim()->SetFrame(currFrame);
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

int Sprite::GetIndex()
{
    return parentScene->GetIndex(this);
}

void Sprite::AttachCollider(Collider* collider)
{
	if(collider)
        colliders.push_back(collider);
}

void Sprite::DettachCollider(Collider* collider) 
{
    colliders.erase(std::remove(colliders.begin(), colliders.end(), collider), colliders.end());
}

void Sprite::UpdateColliders(int x, int y)
{
    for (auto collider : colliders) 
    {
        collider->x = x;
        collider->y = y;
    }
}

void Sprite::DebugColliders()
{
    for (auto collider : colliders) 
    {
    	if(collider->debug)
            collider->Paint();
    }
}

void Sprite::Update()
{
	Texture* tex;
	
	if(simpleMode)
	{
		tex = frameImgs[animImgs->GetFrame()];
		
        width =  tex->width;
    	height = tex->height;
        animImgs->Update();
	}
	else
	{
        if(animator != nullptr)
        {
            animator->Update();
            animator->GetAnim()->Update();
            currFrame = animator->GetAnim()->GetFrame();
        }
    }
    
    UpdateColliders(x, y);
    
}

void Sprite::Paint()
{
	if(simpleMode)
	{
        GFX::DrawTexture(frameImgs[animImgs->GetFrame()], x, y, width * scaleX, height * scaleY);
	}
	else
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
    
    DebugColliders();
}




