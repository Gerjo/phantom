#ifndef TILEDOBJECTLAYER_H
#define TILEDOBJECTLAYER_H

#include <deque>
#include <vector>
#include "ObjectLayer.h"

class Tile;
namespace phantom{
    class LIBEXPORT TiledObjectLayer: public ObjectLayer{
    public:
        void createTiles(unsigned int tileSize, unsigned int x, unsigned int y);
        Tile* getTileAt(Eigen::Vector2f position);
    private: 
        unsigned int _tileSize, _tilesX, _tilesY;
        Tile** _tileList;
    };
}/*namespace phantom*/

#endif /*TILEDOBJECTLAYER_H*/