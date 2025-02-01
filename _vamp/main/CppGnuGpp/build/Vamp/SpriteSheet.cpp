#include "SpriteSheet.h"


SpriteSheet::SpriteSheet(Texture* texture, int tileWidth, int tileHeight)
{
    this->texture =     texture;
    this->tileWidth =   tileWidth;
    this->tileHeight =  tileHeight;
    
    this->width =       texture->width;
    this->height =      texture->height;
    this->totalTilesX = width / tileWidth;
    this->totalTilesY = height / tileHeight;
}

int SpriteSheet::GetTileWidth()
{
    return tileWidth;
}

int SpriteSheet::GetTileHeight()
{
    return tileHeight;
}

void SpriteSheet::Paint(int tileId, int x, int y)
{	
    int clipY = tileId / totalTilesX;           // row
    int clipX = tileId - (clipY * totalTilesX); // column

    // convert to pixels
    clipX *= tileWidth;
    clipY *= tileHeight;
	
    GFX::DrawTexture(texture, x, y, tileWidth, tileHeight, clipX, clipY, tileWidth, tileHeight);
}

void SpriteSheet::Paint(int tileId, int x, int y, int w, int h)
{
    int clipY = tileId / totalTilesX;           // row
    int clipX = tileId - (clipY * totalTilesX); // column

    // convert to pixels
    clipX *= tileWidth;
    clipY *= tileHeight;
	
    GFX::DrawTexture(texture, x, y, w, h, clipX, clipY, tileWidth, tileHeight);
}

