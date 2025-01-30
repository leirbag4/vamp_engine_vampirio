#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include "Sprite.h"
#include "Tilemap.h"
#include "GFX.h"

class Collider
{
    public:
        Collider(int width, int height);
        bool CollidesTile(Tilemap* tilemap, int tileId);
        int x;
        int y;
        int width;
        int height;
        void Paint();
        
};

#endif