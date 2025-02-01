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

Texture::Texture(int width, int height)
{
    tex = SDL_CreateTexture(GFX::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    if (!tex) {
        cout << "SDL_CreateTexture error: " << SDL_GetError() << endl;
    }
}

void Texture::Render()
{
    SDL_RenderPresent(GFX::renderer);
}