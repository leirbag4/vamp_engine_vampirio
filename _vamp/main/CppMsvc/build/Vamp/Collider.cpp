#include "Collider.h"

Collider::Collider(int width, int height)
{
    this->width =   width;
    this->height =  height;
}

bool Collider::Collides(Tilemap* tilemap, int tileId)
{
	Tile tile = tilemap->GetTileAt(GetX(), GetY());
	
	return (tile.id == tileId);
}

bool Collider::Collides(Sprite* sprite)
{
    int spriteWidth = sprite->GetFullWidth();
    int spriteHeight = sprite->GetFullHeight();

    // check if rects are over themselve
    if (GetX() < sprite->x + spriteWidth && GetX() + width > sprite->x && 
        GetY() < sprite->y + spriteHeight && GetY() + height > sprite->y)
    {
        return true; // collides
    }
    
    return false;
}

int Collider::GetX()
{
    return x + offsetX;
}

int Collider::GetY()
{
    return y + offsetY;
}

void Collider::SetOffset(int offsetX, int offsetY)
{
    this->offsetX = offsetX;
    this->offsetY = offsetY;
}

void Collider::Paint()
{
    
    GFX::DrawRect(0xFF00FFFF, GetX(), GetY(), width, height);
    
}