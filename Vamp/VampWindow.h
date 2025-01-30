#ifndef VAMP_WINDOW_H
#define VAMP_WINDOW_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GFX.h"
#include "Key.h"
#include "Keyboard.h"
#include "Mouse.h"

using namespace std;

class VampWindow
{
    public:
        void Init();
        void PollEvents();
        void Clear();
        void BeginRender();
        void SwapBuffer();
        bool CloseNeeded();
        SDL_Renderer* GetRenderer();
        void Destroy();
        
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool _closeNeeded = false;
};

#endif