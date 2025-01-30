#include "Collider.h"

Collider::Collider(int width, int height)
{
    this->width =   width;
    this->height =  height;
}

bool Collider::Collides(Tilemap* tilemap, int tileId)
{
	Tile tile = tilemap->GetTileAt(x, y);
	
	return (tile.id == tileId);
}

bool Collider::Collides(Sprite* sprite)
{
    int spriteWidth = sprite->GetFullWidth();
    int spriteHeight = sprite->GetFullHeight();

    // check if rects are over themselve
    if (x < sprite->x + spriteWidth && x + width > sprite->x && 
        y < sprite->y + spriteHeight && y + height > sprite->y)
    {
        return true; // collides
    }
    
    return false;
}
void Collider::Paint()
{
    
    GFX::DrawRect(0xFF00FFFF, x, y, width, height);
    
}