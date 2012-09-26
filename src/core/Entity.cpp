#include "Entity.h"

#include <physics/Tile.h>

namespace phantom {

    Entity::Entity() {
        
    }

    Entity::~Entity() {

    }

    void Entity::addComponent(Composite *component) {
        Composite::addComponent(component);
        Mover *m = dynamic_cast<Mover*> (component);
        if (m != NULL) {
            if (this->mover != NULL)
                this->destroyComponent(this->mover);
            this->mover = m;
        }
    }

} /* namespace phantom */
