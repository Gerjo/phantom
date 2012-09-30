#ifndef TILE_H
#define TILE_H

#include <vector>
#include <phantom.h>
#include <core/Entity.h>
#include <iostream>
#include <layer/TiledObjectLayer.h>

using namespace std;


namespace phantom {

    class Tile {
    public: //variables
        std::vector<phantom::Entity*> objectList;
        int index, tileX, tileY;
        TiledObjectLayer* layer;
    public: //functions
        Tile();
        Tile(TiledObjectLayer* layer);
        void addEntity(phantom::Entity* entity);
        void removeEntity(phantom::Entity* entity);

        void onEntityChange(Entity* entity);
    };
}

#endif /* TILE_H */