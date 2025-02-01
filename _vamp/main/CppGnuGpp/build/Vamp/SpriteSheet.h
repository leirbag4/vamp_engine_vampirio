#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "Texture.h"
#include "GFX.h"

class SpriteSheet
{
    public:
        SpriteSheet(Texture* texture, int tileWidth, int tileHeight);
        int GetTileWidth();
        int GetTileHeight();
        void Paint(int tileId, int x, int y);
        void Paint(int tileId, int x, int y, int width, int height);
        
        
    private:
        int width;
        int height;
        int tileWidth;
        int tileHeight;
        int totalTilesX;
        int totalTilesY;
        Texture* texture;
    
};


#endif