#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include "Sprite.h"
#include "Tilemap.h"
#include "GFX.h"

class Collider
{
    public:
        int x;
        int y;
        int width;
        int height;
        int offsetX = 0;
        int offsetY = 0;
        bool debug = false;
        Collider(int width, int height);
        bool Collides(Tilemap* tilemap, int tileId);
        bool Collides(Sprite* sprite);
        int GetX();
        int GetY();
        void SetOffset(int offsetX, int offsetY);
        void Paint();
        
};

#endif