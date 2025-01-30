#include "Collider.h"

Collider::Collider(int width, int height)
{
    this->width =   width;
    this->height =  height;
}

bool Collider::CollidesTile(Tilemap* tilemap, int tileId)
{
	Tile tile = tilemap->GetTileAt(x, y);
	
	return (tile.id == tileId);
}

void Collider::Paint()
{
    
    GFX::DrawRect(0xFF00FFFF, x, y, width, height);
    
}