#include "Tile.h"
namespace phantom {

    Tile::Tile(TiledObjectLayer* layer) {
        this->layer = layer;
    }
    void Tile::addEntity(phantom::Entity* entity) {
        objectList.push_back(entity);
    }
}