#ifndef TILEDOBJECTLAYER_H
#define TILEDOBJECTLAYER_H

#include <deque>
#include "ObjectLayer.h"
#include <physics/Tile.h>

namespace phantom{
    class LIBEXPORT TiledObjectLayer: public ObjectLayer{
    public:
        void createTiles(unsigned int tileSize, unsigned int x, unsigned int y);
    private: 
        unsigned int _tileSize, _tilesX, _tilesY;
        std::deque<Tile*> _tileList;
        std::deque<Tile*>::iterator _tileIt;
    };
}/*namespace phantom*/

#endif /*TILEDOBJECTLAYER_H*/