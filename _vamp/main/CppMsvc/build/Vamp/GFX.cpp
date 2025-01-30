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

// static
void GFX::DrawTexture(Texture* texture, int x, int y)
{
    //SDL_Rect srcRect = {0, 0, 64, 64};  
    //int w = texture->tex->width;
  
    SDL_Rect destRect = {x, y, texture->width, texture->height}; // x, y, width, height
    SDL_RenderCopy(GFX::renderer, texture->tex, nullptr, &destRect);
}

// static
void GFX::DrawTexture(Texture* texture, int x, int y, int width, int height)
{
    //SDL_Rect srcRect = {0, 0, 64, 64};  
    //int w = texture->tex->width;
  
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(GFX::renderer, texture->tex, nullptr, &destRect);
}

void GFX::DrawTexture(Texture* texture, int x, int y, int width, int height, int clipX, int clipY, int clipWidth, int clipHeight)
{
    SDL_Rect srcRect = {clipX, clipY, clipWidth, clipHeight};  
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(GFX::renderer, texture->tex, &srcRect, &destRect);
}

void GFX::DrawTexture(Texture* texture, int x, int y, int clipX, int clipY, int clipWidth, int clipHeight)
{
    SDL_Rect srcRect = {clipX, clipY, clipWidth, clipHeight};
    SDL_Rect destRect = {x, y, clipWidth, clipHeight};
    SDL_RenderCopy(GFX::renderer, texture->tex, &srcRect, &destRect);
}




