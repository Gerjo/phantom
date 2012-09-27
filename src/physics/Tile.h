#ifndef TILE_H
#define TILE_H

#include <vector>
#include <phantom.h>
#include <core/Entity.h>
#include <layer/TiledObjectLayer.h>

using namespace std;


namespace phantom {

    class Tile {
    public: //variables
        std::vector<phantom::Entity*> objectList;
        int index, tileX, tileY;
        TiledObjectLayer* layer;
    public: //functions
        Tile(TiledObjectLayer* layer);
        void addEntity(phantom::Entity* entity);
        void removeEntity(phantom::Entity* entity);


    };
}

#endif /* TILE_H */