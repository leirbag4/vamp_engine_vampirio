#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

class Font
{
    public:
        Font(const char* fontPath, int fontSize);
        TTF_Font* GetInternalFont();
        bool IsLoaded();

    private:
        bool loaded;
        TTF_Font* _font;
};

#endif