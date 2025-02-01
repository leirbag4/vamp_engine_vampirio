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

int Tilemap::GetTileIdAt(int posX, int posY)
{
    // Ajustar las coordenadas restando los offsets
    int adjustedX = posX - offsetX + localX;
    int adjustedY = posY - offsetY + localY;

    // Convertir coordenadas de píxeles a índices de la matriz
    int tileX = adjustedX / tileSize;
    int tileY = adjustedY / tileSize;

    // Verificar límites
    if (tileX >= 0 && tileX < width && tileY >= 0 && tileY < height) {
        return map[tileY][tileX]; // Devolver el ID del tile en esa posición
    }

    return -1; // Devuelve -1 si está fuera de los límites
}

Tile Tilemap::GetTileAt(int posX, int posY) {
    Tile tile;
    
    // Adjust the coordinates using the offsets and local coordinates
    int adjustedX = posX - offsetX + localX;
    int adjustedY = posY - offsetY + localY;

    // Convert the adjusted pixel coordinates to matrix indices
    int x = adjustedX / tileSize;
    int y = adjustedY / tileSize;

    // Check if the coordinates are within the bounds of the map
    if (x >= 0 && x < width && y >= 0 && y < height) 
    {
        tile.id = map[y][x]; // Get the tile ID from the map
        tile.x = (x * tileSize + offsetX) - localX; // Calculate the tile's x position
        tile.y = (y * tileSize + offsetY) - localY; // Calculate the tile's y position
        tile.width = tileSize; // Assign the tile's width
        tile.height = tileSize; // Assign the tile's height
    } 
    else 
    {
        // If the coordinates are out of bounds, return a default tile
        tile.id = -1; // Invalid ID
        tile.x = 0;
        tile.y = 0;
        tile.width = tileSize;
        tile.height = tileSize;
    }

    return tile;
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
    
    //cout << "localY: " << localY << " col: " << col << endl;
    GFX::FillRect(0xFF00FFFF, offsetX, offsetY, tileSize * viewportWidth, tileSize * viewportHeight);
    
    for(int cy = col; cy < (viewportHeight + col + 1); cy++)
    {
        for(int cx = row; cx < (viewportWidth + row + 1); cx++)
        {
            int tilePosX = (cx * tileSize) - localX;
            int tilePosY = (cy * tileSize) - localY;
        
            tileId = map[cy][cx];
            
            
            
            spritesheet->Paint(tileId, tilePosX + offsetX, tilePosY + offsetY, tileSize, tileSize);
            
        }   
    }
}


