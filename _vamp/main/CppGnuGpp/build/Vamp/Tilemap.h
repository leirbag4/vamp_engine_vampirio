#ifndef TILEMAP_H
#define TILEMAP_H

#include <iostream>
#include <vector>
#include "Texture.h"
#include "SpriteSheet.h"
#include "GFX.h"

using namespace std;

struct Tile 
{
    int id;
    int x;
    int y;
    int width;
    int height;
};
        
class Tilemap
{
    public:
        
    
        vector<vector<int>> map;
        SpriteSheet* spritesheet;
        int localX = 0;
        int localY = 0;
        int offsetX = 0;
        int offsetY = 0;
        int tileSize;
        int width; 
        int height; 
        int viewportWidth; 
        int viewportHeight;
        Tilemap(const char* path, int tileSize, int width, int height, int viewportWidth, int viewportHeight);
        void FillRect(int tileId, int x, int y, int width, int height);
        void SetTile(int tileId, int x, int y);
        int GetTileIdAt(int posX, int posY);
        Tile GetTileAt(int posX, int posY);
        void Update();
        void Paint();
        
    private:
        Texture* texture;
};

#endif