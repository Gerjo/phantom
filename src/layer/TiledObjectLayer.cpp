#include "TiledObjectLayer.h"
#include <physics/Tile.h>
namespace phantom{
    void TiledObjectLayer::createTiles(unsigned int tileSize, unsigned int x, unsigned int y){
        _tileSize = tileSize;
        _tilesX = x;
        _tilesY = y; 
        
        this->width = static_cast<float>(x * _tilesX);
        this->height = static_cast<float>(y* _tilesY);

        int t = x*y;
        _tileList = new Tile*[_tilesY];
        for(y = 0; y < _tilesY; ++y){
            _tileList[y] = new Tile[_tilesX];
            for(x = 0; x < _tilesX; ++x){
                _tileList[y][x] = Tile(this);
            }
        }
    }
}