//#define SDL_main main

#include <iostream>
#include "Vamp/VampEngine.h"
#include "Vamp/Key.h"
#include "Vamp/Keyboard.h"
#include "Vamp/GFX.h"
#include <SDL2/SDL_image.h>

using namespace std;

void OnUpdate();
void OnPaint();

VampEngine* engine;
SDL_Texture* texture;

int main(int argc, char* argv[])
{
	std::cout << "argv[0]: " << argv[0] << std::endl;
	
	
    engine = new VampEngine();
    engine->OnUpdate =  OnUpdate;
    engine->OnPaint =   OnPaint;
    engine->Init();
    
    
    
    engine->Run();
    
    cout << "start" << endl;
    return 0;
}

int y = 0;
int state = 0;

void OnUpdate()
{
    if(Keyboard::IsDown(Key::UP))
        y--;
    else if(Keyboard::IsDown(Key::DOWN))
        y++;
    
    
    if(state == 0)
    {
        state++;
        
        
    }
    
}

void OnPaint()
{
    GFX::FillRect(0xFF0000FF, 200, y, 40, 40);
    
    SDL_Rect destRect = {100, 100, 200, 150}; // x, y, width, height
    SDL_RenderCopy(engine->GetWindow()->GetRenderer(), texture, nullptr, &destRect);
    
    
}