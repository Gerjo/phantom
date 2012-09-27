#include "Tile.h"
namespace phantom {

    Tile::Tile() {
    }

    Tile::~Tile() {
    }

    void Tile::addEntity(phantom::Entity* entity) {
        objectList.push_back(entity);
    }

    void Tile::onEntityChange(Entity* entity) {

    }
}