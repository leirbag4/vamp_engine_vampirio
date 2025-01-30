#include "GFX.h"

SDL_Renderer* GFX::renderer = nullptr;

// static
void GFX::SetColor(unsigned int color)
{	
	unsigned int red =      (color >> 24)   & 0xFF;
	unsigned int green =    (color >> 16)   & 0xFF;
	unsigned int blue =     (color >> 8)    & 0xFF;
	unsigned int alpha =    (color)         & 0xFF;
	
    SDL_SetRenderDrawColor(GFX::renderer, red, green, blue, alpha);
}

// static
void GFX::FillRect(unsigned int color, int x, int y, int width, int height)
{
    GFX::SetColor(color);
    SDL_Rect rect;
    rect.x = x; rect.y = y;
    rect.w = width; rect.h = height;
    SDL_RenderFillRect(renderer, &rect);
}