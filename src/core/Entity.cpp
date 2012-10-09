#include "Entity.h"

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <utils/PhantomException.h>

namespace phantom {

    Entity::Entity() {
        mover = 0;
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
        _position.x = x;
    }

    void Entity::setY(float y) {
        _position.y = y;
    }

} /* namespace phantom */
