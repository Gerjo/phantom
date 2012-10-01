#include "TiledObjectLayer.h"
#include <physics/Tile.h>
using namespace std;

namespace phantom{
    TiledObjectLayer::TiledObjectLayer():_tileSize(0), _tilesX(0),_tilesY(0){
        _tileList = 0;
    }
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
    Tile* TiledObjectLayer::getTileAt(Eigen::Vector3f position){
        int x = max(0, min(_tilesX -1, floorf(position.x() / _tileSize)));
        int y = max(0, min(_tilesY -1, floorf(position.y() / _tileSize)));
        if(_tileList == 0){
            cout << "tiles not initialized!" << endl;
            return 0;
        }
        return &_tileList[y][x];
    }
    void TiledObjectLayer::addComponent(Entity* entity){
        Composite::addComponent(entity);
        Tile* t = getTileAt(entity->getPosition());
        if(t == 0){
            cout << "tile does not exist!" << endl;
            return;
        }
        t->addEntity(entity);
    }
    int TiledObjectLayer::getRowSize(){
        return _tilesX;
    }
    int TiledObjectLayer::getColumnSize(){
        return _tilesY;
    }
    int TiledObjectLayer::getSize(){
        return (_tilesX * _tilesY);
    }
}