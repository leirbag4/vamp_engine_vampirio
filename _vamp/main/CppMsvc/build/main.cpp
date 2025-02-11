//#define SDL_main main

#include <iostream>
#include <chrono>
#include <unordered_map>
#include "Vamp/Vamp.h"

using namespace std;
using namespace std::chrono;
void OnInit();
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
Sprite* sprite2;
Sprite* sprite3;
Tilemap* tilemap;
Collider* colliderLeft;
Collider* colliderRight;
Collider* colliderUp;
Collider* colliderDown;
Collider* colliderUpLeft;
Collider* colliderUpRight;
Collider* collider;
SDL_Surface* textSurface;
SDL_Texture* textTexture;
TTF_Font* font;
Font* font2;
Button* button;

int main(int argc, char* argv[])
{
	std::cout << "argv[0]: " << argv[0] << std::endl;
	
	unordered_map<string, Animation*> mapp;
	
	mapp["down"] = animDown;
	
	
    engine = new VampEngine();
    engine->OnInit =    OnInit;
    engine->OnUpdate =  OnUpdate;
    engine->OnPaint =   OnPaint;
    
    engine->Init();
    engine->Run();
    
    cout << "start" << endl;
    return 0;
}

int x = 0;
int y = 0;
int state = 0;
int counter = 0;
Tile tile;
bool allowLeft = true;
bool allowRight = true;
bool allowUp = true;
bool allowDown = true;

void OnButtonPressed()
{
    cout << "pressed" << endl;
}

void OnInit()
{
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
    
    tilemap = new Tilemap("res/tileset.png", 24, 200, 200, 10, 10);
    tilemap->FillRect(17, 0, 0, 200, 200);
    tilemap->FillRect(16, 4, 4, 8, 8);
    tilemap->FillRect(32, 6, 10, 6, 5);
    tilemap->FillRect(34, 8, 9, 5, 2);
    tilemap->SetTile(34, 5, 5);
    //tilemap->offsetX = 100;
    engine->AddChild(tilemap);
    
    sprite = new Sprite();
    sprite->SetSpriteSheet(spritesheet);
    sprite->SetAnimator(animator);
    engine->AddChild(sprite);
    
    collider = new Collider(10, 10);
    collider->SetOffset(-5, -5);
    collider->debug = true;
    
    sprite2 = new Sprite();
    sprite2->SetSpriteSheet(spritesheet);
    sprite2->SetPos(140, 140);
    sprite2->SetFrame(3);
    engine->AddChild(sprite2);
    
    
    
    colliderLeft =  new Collider(10, 10);
    colliderRight = new Collider(10, 10);
    colliderUp =    new Collider(10, 10);
    colliderDown =  new Collider(10, 10);
    
    colliderUpLeft = new Collider(8, 8);
    colliderUpRight = new Collider(8, 8);
    colliderUpLeft->debug = true;
    colliderUpRight->debug = true;
    colliderUpLeft->SetOffset(-5, -5);
    colliderUpRight->SetOffset(19, -5);
    sprite->AttachCollider(colliderUpLeft);
    sprite->AttachCollider(colliderUpRight);
    
    font2 = new Font("res/cascadia_code.ttf", 28);
    
    sprite3 = new Sprite();
    sprite3->AddFrame("res/player_01.png");
    sprite3->AddFrame("res/player_02.png");
    sprite3->AddFrame("res/player_03.png");
    sprite3->AddFrame("res/player_04.png");
    sprite3->SetPos(300, 130);
    sprite3->Play();
    engine->AddChild(sprite3);
    
    sprite3->AttachCollider(collider);
    
    button = new Button("res/cascadia_code.ttf", 12);
    button->SetText("tester");
    button->SetPos(40, 200);
    button->SetSize(100, 30);
    button->OnPressed = OnButtonPressed;
    engine->AddChild(button);
    
    //XConsole::SetFont(font2);
    XConsole::CreateFont("res/cascadia_code.ttf", 12);
    XConsole::SetActive(true);
}

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
        
    int speed = 80 * deltaTime;
        
    if(Keyboard::IsDown(Key::W) && allowUp)
    {
        sprite->y -= speed;
        sprite->Play("walk_up");
        tilemap->localY--;
        pressed = true;
    }
    else if(Keyboard::IsDown(Key::S) && allowDown)
    {
        sprite->y += speed;
        sprite->Play("walk_down");
        tilemap->localY++;
        pressed = true;
    }
    if(Keyboard::IsDown(Key::A) && allowLeft)
    {
        sprite->x -= speed;
        sprite->Play("walk_left");
        tilemap->localX--;
        pressed = true;
    }
    else if(Keyboard::IsDown(Key::D) && allowRight)
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
    
    //tilemap->Update();
    //sprite->Update();
    //sprite2->Update();
    
    // Colliders
    colliderLeft->x = sprite->x - 6;
    colliderLeft->y = sprite->y + 9;
    
    colliderRight->x = sprite->x + 20;
    colliderRight->y = sprite->y + 9;
    
    colliderUp->x = sprite->x + 6;
    colliderUp->y = sprite->y - 5;
    
    colliderDown->x = sprite->x + 6;
    colliderDown->y = sprite->y + 20;
    
    
    //cout << "tileID: " << tilemap->GetTileIdAt(sprite->x, sprite->y) << endl;
    
    tile = tilemap->GetTileAt(colliderLeft->x, colliderLeft->y);
    
    int blockTile = 34;
    
    allowLeft = !colliderLeft->Collides(tilemap, blockTile);
    allowRight =!colliderRight->Collides(tilemap, blockTile); 
    allowUp =   !colliderUp->Collides(tilemap, blockTile);
    allowDown = !colliderDown->Collides(tilemap, blockTile); 
    
    
    //cout << "col " << collider->CollidesTile(tilemap, 34) << endl;
    
    //cout << "id: " << tile.id << ", x: " << tile.x << ", y: " << tile.y << endl;
    
    if(colliderLeft->Collides(sprite2))
    {
        cout << "collides" << endl;
        cout << "indexA: " << sprite->GetIndex() << ", indexB: " << sprite2->GetIndex() << endl;
        //engine->GetScene()->SetIndex(sprite, sprite2->GetIndex());
        engine->RemoveChild(sprite2);
    }
    //sprite3->Update();
    //auto now = high_resolution_clock::now();
    //long long time = duration_cast<nanoseconds>(now.time_since_epoch()).count();
    //cout << time << endl;
    
    XConsole::PrintError("start");
    XConsole::PrintError("test 99");
    XConsole::Println("end 123");
    
}

void OnPaint()
{
    GFX::FillRect(0xFF0000FF, 200, y, 40, 40);
    
    //SDL_Rect srcRect = {0, 0, 64, 64};  
    //SDL_Rect destRect = {100, 100, 64, 64}; // x, y, width, height
    //SDL_RenderCopy(GFX::renderer, texture, &srcRect, &destRect);

    //tilemap->Paint();
            
    //GFX::DrawTexture(texture2, x, y, 0, 0, 19, 25);
    
    //cout << counter << endl;
    spritesheet->Paint(counter, 1, 0, 100, 70);

    GFX::DrawRect(0x0000FFFF, 10, 50, 50, 25, 40);

    GFX::DrawRect(0x00FFFFFF, tile.x, tile.y, tile.width, tile.height);

    //sprite->Paint();
    //sprite2->Paint();
    
    colliderLeft->Paint();
    colliderRight->Paint();
    colliderUp->Paint();
    colliderDown->Paint();
    
    
    //GFX::FillCircle(0xFF00FFFF, 100, 100, 100, 36);


    GFX::DrawString("something", font2, 0xFF0000FF, 60, 100);


    //sprite3->Paint();
}
