#include "Texture.h"

Texture::Texture(const char* path)
{
    tex = IMG_LoadTexture(GFX::renderer, path);
    
    if (!tex) 
    {
        std::cerr << "Can't Load Image: " << IMG_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
    }
    
    SDL_QueryTexture(tex, nullptr, nullptr, &width, &height);
}