#include "Tilemap.h"

Tilemap::Tilemap(const char* path, int tileSize, int width, int height, int viewportWidth, int viewportHeight)
{
    this->texture =         new Texture(path);
    this->spritesheet =     new SpriteSheet(texture, tileSize, tileSize);
    this->tileSize =        tileSize;
    this->width =           width; 
    this->height =          height; 
    this->viewportWidth =   viewportWidth; 
    this->viewportHeight =  viewportHeight;
    this->map.resize(height, std::vector<int>(width, 0));
    
    
}

void Tilemap::FillRect(int tileId, int x, int y, int width, int height)
{
    
    for(int cy = y; cy < (y + height); cy++)
    {
    	for(int cx = x; cx < (x + width); cx++)
    	{
            map[cy][cx] = tileId;
        }
    }
    
}

void Tilemap::SetTile(int tileId, int x, int y)
{
    if((x >= 0) && (x < width) && (y >= 0) && (y < height))
        map[y][x] = tileId;
}

void Tilemap::Update()
{
    if(localX < 0)
        localX = 0;
    if(localY < 0)
        localY = 0;
}

void Tilemap::Paint()
{
	//Paint(int tileId, int x, int y, int w, int h)
    
    
    int row = localX / tileSize;
    int col = localY / tileSize;
    int tileId;
    
    //if(row > 0)
    //    row--;
    //if(col > 0)
    //    col--;
    
    cout << "localY: " << localY << " col: " << col << endl;
    GFX::FillRect(0xFF00FFFF, 150, 150, tileSize * viewportWidth, tileSize * viewportHeight);
    
    for(int cy = col; cy < (viewportHeight + col + 1); cy++)
    {
        for(int cx = row; cx < (viewportWidth + row + 1); cx++)
        {
            int tilePosX = (cx * tileSize) - localX;
            int tilePosY = (cy * tileSize) - localY;
        
            tileId = map[cy][cx];
            
            
            
            spritesheet->Paint(tileId, tilePosX + 150, tilePosY + 150, tileSize, tileSize);
            
        }   
    }
}


