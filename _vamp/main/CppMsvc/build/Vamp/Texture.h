#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL_image.h>
#include <iostream>
#include "GFX.h"

using namespace std;

class Texture
{
    public:
        int width;
        int height;
        SDL_Texture* tex;     
        Texture(const char* path);
        Texture(int width, int height);
        void Render();
};

#endif