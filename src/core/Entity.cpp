#include "Entity.h"

#include <physics/Tile.h>
#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>


namespace phantom {

    Entity::Entity() {
        _tile = 0;
    }

    void Entity::addComponent(Composite* component) {
        Composite::addComponent(component);
        Mover* m = dynamic_cast<Mover*> (component);
        if (m != 0) {
            if (this->mover != 0)
                this->destroyComponent(this->mover);
            this->mover = m;
        }
    }

    void Entity::setX(float x) {
        _position.x() = x;

        if(hasTile()) {
            _tile->onEntityChange(this);
        }
    }

    void Entity::setY(float y) {
        _position.y() = y;

        if(hasTile()) {
            _tile->onEntityChange(this);
        }
    }
    void Entity::setTile(Tile* tile){
        _tile = tile;
    }
    bool Entity::hasTile() {
        return _tile != 0;
    }

} /* namespace phantom */
