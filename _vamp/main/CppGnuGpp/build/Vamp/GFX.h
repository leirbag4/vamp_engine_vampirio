#ifndef GFX_H
#define GFX_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class GFX
{
    public:
        static SDL_Renderer* renderer;
        static void Init(SDL_Renderer* renderer);
        static void SetColor(unsigned int color);
        static void FillRect(unsigned int color, int x, int y, int width, int height);

};


#endif