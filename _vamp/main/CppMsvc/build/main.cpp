//#define SDL_main main

#include <iostream>
#include <chrono>
#include <unordered_map>
#include "Vamp/VampEngine.h"
#include "Vamp/Key.h"
#include "Vamp/Keyboard.h"
#include "Vamp/GFX.h"
#include <SDL2/SDL_image.h>
#include "Vamp/Texture.h"
#include "Vamp/XTimer.h"
#include "Vamp/SpriteSheet.h"
#include "Vamp/Animation.h"
#include "Vamp/Sprite.h"
#include "Vamp/Animator.h"
#include "Vamp/Tilemap.h"

using namespace std;
using namespace std::chrono;
void OnUpdate(float deltaTime);
void OnPaint();

VampEngine* engine;
SDL_Texture* texture;
Texture* texture2;
XTimer* timer;
SpriteSheet* spritesheet;
Animation* animation;
Animation* animDown;
Animation* animRight;
Animation* animLeft;
Animation* animUp;
Animator* animator;
Sprite* sprite;
Tilemap* tilemap;


int main(int argc, char* argv[])
{
	std::cout << "argv[0]: " << argv[0] << std::endl;
	
	unordered_map<string, Animation*> mapp;
	
	mapp["down"] = animDown;
	
	
    engine = new VampEngine();
    engine->OnUpdate =  OnUpdate;
    engine->OnPaint =   OnPaint;
    engine->Init();
    
    texture = IMG_LoadTexture(GFX::renderer, "res/player_sprite.png");
    if (!texture) {
        std::cerr << "Error al cargar la imagen PNG: " << IMG_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
        return -1;
    }
    
    texture2 = new Texture("res/player_sprite.png");
    spritesheet = new SpriteSheet(texture2, 19, 25);
    animation = new Animation();
    animation->AddFrame(0);
    animation->AddFrame(1);
    animation->AddFrame(2);
    animation->AddFrame(3);
    animation->Play();
    
    timer = new XTimer(1000);
    timer->Start();
    
    animDown = new Animation();
    animRight = new Animation();
    animLeft = new Animation();
    animUp = new Animation();
        
    animDown->AddFrame(0);  animDown->AddFrame(1);  animDown->AddFrame(2);
    animRight->AddFrame(3); animRight->AddFrame(4); animRight->AddFrame(5);
    animLeft->AddFrame(6);  animLeft->AddFrame(7);  animLeft->AddFrame(8);
    animUp->AddFrame(9);    animUp->AddFrame(10);   animUp->AddFrame(11);
    
    animator = new Animator();
    animator->AddAnim("walk_left",    animLeft);
    animator->AddAnim("walk_right",   animRight);
    animator->AddAnim("walk_up",      animUp);
    animator->AddAnim("walk_down",    animDown);
    
    //animator->Play("walk_left");
    
    sprite = new Sprite();
    sprite->SetSpriteSheet(spritesheet);
    sprite->SetAnimator(animator);
    
    tilemap = new Tilemap("res/tileset.png", 24, 200, 200, 10, 10);
    tilemap->FillRect(16, 4, 4, 8, 8);
    tilemap->FillRect(32, 6, 10, 6, 5);
    
    engine->Run();
    
    cout << "start" << endl;
    return 0;
}

int x = 0;
int y = 0;
int state = 0;
int counter = 0;

void OnUpdate(float deltaTime)
{
    if(Keyboard::IsDown(Key::UP))
        y--;
    else if(Keyboard::IsDown(Key::DOWN))
        y++;
    if(Keyboard::IsDown(Key::LEFT))
        x--;
    else if(Keyboard::IsDown(Key::RIGHT))
        x++;
        
    bool pressed = false;
        
    int speed = 130 * deltaTime;
        
    if(Keyboard::IsDown(Key::W))
    {
        sprite->y -= speed;
        sprite->Play("walk_up");
        tilemap->localY--;
        pressed = true;
    }
    else if(Keyboard::IsDown(Key::S))
    {
        sprite->y += speed;
        sprite->Play("walk_down");
        tilemap->localY++;
        pressed = true;
    }
    if(Keyboard::IsDown(Key::A))
    {
        sprite->x -= speed;
        sprite->Play("walk_left");
        tilemap->localX--;
        pressed = true;
    }
    else if(Keyboard::IsDown(Key::D))
    {
        sprite->x += speed;
        sprite->Play("walk_right");
        tilemap->localX++;
        pressed = true;
    }
    
    if(!pressed)
        sprite->Stop();
    
    //int an = animator->GetAnim()->GetFrame();
    
    animator->Update();
   
    
    //int id = animator->id;
    
    //cout << "an: " << an << endl;
           
    //cout << "mouse x:" << Mouse::x << ", y" << Mouse::y << ", lclick: " << Mouse::leftClick << ", rightClick: " << Mouse::rightClick << endl;
    
    if(state == 0)
    {
    	
        state++;
    }
    
    animation->Update();
    
    
    if(timer->Update())
    {
        //cout << "time" << endl;
        timer->Start();
        counter++;
        
        //cout << "anim: " << animation->GetFrame() << endl;
    }
    
    tilemap->Update();
    sprite->Update();
    
    
    //auto now = high_resolution_clock::now();
    //long long time = duration_cast<nanoseconds>(now.time_since_epoch()).count();
    //cout << time << endl;
}

void OnPaint()
{
    GFX::FillRect(0xFF0000FF, 200, y, 40, 40);
    
    SDL_Rect srcRect = {0, 0, 64, 64};  
    SDL_Rect destRect = {100, 100, 64, 64}; // x, y, width, height
    SDL_RenderCopy(GFX::renderer, texture, &srcRect, &destRect);

    tilemap->Paint();
            
    GFX::DrawTexture(texture2, x, y, 0, 0, 19, 25);
    
    //cout << counter << endl;
    spritesheet->Paint(counter, 1, 0, 100, 70);

    sprite->Paint();

}
