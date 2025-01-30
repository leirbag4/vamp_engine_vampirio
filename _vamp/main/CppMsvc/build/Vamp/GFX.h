#ifndef GFX_H
#define GFX_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

// Forward declaration to solve circular dependency
class Texture;

using namespace std;

class GFX
{
    public:
        static SDL_Renderer* renderer;
        static void Init(SDL_Renderer* renderer);
        static void SetColor(unsigned int color);
        static void FillRect(unsigned int color, int x, int y, int width, int height);
        static void DrawRect(unsigned int color, int x, int y, int width, int height);
        static void DrawRect(unsigned int color, int x, int y, int width, int height, int size);
        static void DrawTexture(Texture* texture, int x, int y);
        static void DrawTexture(Texture* texture, int x, int y, int width, int height);
        static void DrawTexture(Texture* texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight);
        static void DrawTexture(Texture* texture, int x, int y, int clipX, int clipY, int clipWidth, int clipHeight);

};


#endif