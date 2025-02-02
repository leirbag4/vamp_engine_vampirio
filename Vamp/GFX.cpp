#include "GFX.h"
#include <cmath>

SDL_Renderer* GFX::renderer = nullptr;

// static
void GFX::SetRenderTarget(Texture* texture)
{
    SDL_SetRenderTarget(GFX::renderer, texture->tex);
}

void GFX::ResetRenderTarget()
{
    SDL_SetRenderTarget(GFX::renderer, NULL);
}

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

void GFX::DrawRect(unsigned int color, int x, int y, int width, int height)
{
    GFX::SetColor(color);
    SDL_Rect rect;
    rect.x = x; rect.y = y;
    rect.w = width; rect.h = height;
    SDL_RenderDrawRect(renderer, &rect);
}

void GFX::DrawRect(unsigned int color, int size, int x, int y, int width, int height)
{
    GFX::SetColor(color);

    GFX::FillRect(color, x, y, width, size);                    // Up
    GFX::FillRect(color, x, y + height - size, width, size);    // Down
    GFX::FillRect(color, x, y, size, height);                   // Left
    GFX::FillRect(color, x + width - size, y, size, height);    // Right
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

void GFX::FillCircle(unsigned int color, int centerX, int centerY, int radius, int segments)
{
    //GFX::SetColor(color);
    /*Uint8 red =      (color >> 24)   & 0xFF;
	Uint8 green =    (color >> 16)   & 0xFF;
	Uint8 blue =     (color >> 8)    & 0xFF;
	Uint8 alpha =    (color)         & 0xFF;


    std::vector<SDL_Vertex> vertices(segments + 2); // dynamic vector
    vertices[0] = { {(float)centerX, (float)centerY}, {red, green, blue, alpha}, {0, 0} }; // Centro

    float angleStep = (2.0f * M_PI) / segments; 
    for (int i = 1; i <= segments + 1; i++) 
    {
        float angle = angleStep * (i - 1);
        float x = centerX + cos(angle) * radius;
        float y = centerY + sin(angle) * radius;
        vertices[i] = { {x, y}, {red, green, blue, alpha}, {0, 0} };
    }

    std::vector<int> indices(segments * 3); 
    for (int i = 0; i < segments; i++)
    {
        indices[i * 3] = 0;
        indices[i * 3 + 1] = i + 1;
        indices[i * 3 + 2] = i + 2;
    }

    SDL_RenderGeometry(GFX::renderer, nullptr, vertices.data(), vertices.size(), indices.data(), indices.size());*/
}

void GFX::DrawCircle(unsigned int color, int centerX, int centerY, int radius, int segments) 
{
    GFX::SetColor(color);

    float angleStep = (2.0f * M_PI) / segments;

    for (int i = 0; i < segments; i++) 
    {
        float angle1 = angleStep * i;
        float angle2 = angleStep * (i + 1);

        int x1 = centerX + cos(angle1) * radius;
        int y1 = centerY + sin(angle1) * radius;
        int x2 = centerX + cos(angle2) * radius;
        int y2 = centerY + sin(angle2) * radius;

        SDL_RenderDrawLine(GFX::renderer, x1, y1, x2, y2);
    }
}

void GFX::DrawString(const char* str, Font* font, unsigned int color, int x, int y)
{
    //SDL_Surface* textSurface;
    //SDL_Texture* textTexture;
    
    unsigned int red =      (color >> 24)   & 0xFF;
	unsigned int green =    (color >> 16)   & 0xFF;
	unsigned int blue =     (color >> 8)    & 0xFF;
	unsigned int alpha =    (color)         & 0xFF;
	
	if(!font->IsLoaded())
        return;
    
    SDL_Color textColor = {red, green, blue, alpha}; 
    SDL_Surface* textSurface = TTF_RenderText_Blended(font->GetInternalFont(), str, textColor);
    
    if (!textSurface) 
    {
        std::cerr << "Can't create surface for text: " << TTF_GetError() << std::endl;
        return;
    }
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GFX::renderer, textSurface);
    SDL_FreeSurface(textSurface);
    
    
    
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    SDL_Rect textRect = {x, y, textWidth, textHeight};
    
    SDL_RenderCopy(GFX::renderer, textTexture, nullptr, &textRect);
    
    //SDL_DestroyTexture(textTexture);
    
}

Size GFX::GetFontSize(const char* str, Font* font)
{
    Size size = {0, 0}; 
    
    if(!font->IsLoaded())
        return size;
    
    SDL_Color textColor = {255, 255, 255, 255}; 
    SDL_Surface* textSurface = TTF_RenderText_Blended(font->GetInternalFont(), str, textColor);
    
    if (!textSurface) 
    {
        std::cerr << "Can't create surface for text: " << TTF_GetError() << std::endl;
        return size;
    }
    
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(GFX::renderer, textSurface);
    SDL_FreeSurface(textSurface);
    
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);
    
    size.width =    textWidth;
    size.height =   textHeight;
    
    return size;
}
