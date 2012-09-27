#include "TiledObjectLayer.h"

namespace phantom{
    void TiledObjectLayer::createTiles(unsigned int tileSize, unsigned int x, unsigned int y){
        _tileSize = tileSize;
        _tilesX = x;
        _tilesY = y; 

        this->width = static_cast<float>(x * _tilesX);
        this->height = static_cast<float>(y* _tilesY);
        
        int t = x*y;
        while(_tileList.size() < t){
            _tileList.push_back(new Tile());
        }
    }
}