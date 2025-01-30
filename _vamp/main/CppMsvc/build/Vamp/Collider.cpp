#include "Collider.h"

Collider::Collider(int width, int height)
{
    this->width =   width;
    this->height =  height;
}

void Collider::Paint()
{
    
    GFX::DrawRect(0xFF00FFFF, x, y, width, height);
    
}