#include "TiledObjectLayer.h"
#include <physics/Tile.h>
using namespace std;

namespace phantom{
    void TiledObjectLayer::createTiles(unsigned int tileSize, unsigned int x, unsigned int y){
        _tileSize = tileSize;
        _tilesX = x;
        _tilesY = y;

        width = x * tileSize;
        height = y * tileSize;

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
    Tile* TiledObjectLayer::getTileAt(Eigen::Vector2f position){
        int x = max(0, min(_tilesX -1, floorf(position.x / _tileSize)));
        int y = max(0, min(_tilesY -1, floorf(position.y / _tileSize)));
        return &_tileList[y][x];
    }
}