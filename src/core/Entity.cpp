#include "Entity.h"

#include <physics/Tile.h>

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

    void Entity::setX(float n) {
        if(hasTile()) {
            //_tile->onEntityChange(this);
        }
    }

    void Entity::setY(float y) {
        if(hasTile()) {
           // _tile->onEntityChange(this);
        }
    }

    bool Entity::hasTile() {
        return _tile != 0;
    }

} /* namespace phantom */
