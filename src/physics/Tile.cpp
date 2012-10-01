#include "Tile.h"
namespace phantom {
    Tile::Tile(){}
    Tile::Tile(TiledObjectLayer* layer) {
        this->layer = layer;
    }
    void Tile::addEntity(phantom::Entity* entity) {
        objectList.push_back(entity);
        entity->setTile(this);
    }

    void Tile::onEntityChange(Entity* entity) {
        cout << "Updating entity position" << endl;
    }
}