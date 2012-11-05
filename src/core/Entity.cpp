#include "Entity.h"

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <utils/PhantomException.h>

namespace phantom {

    Entity::Entity() {
        mover = 0;
        _health = 100.0f;
    }

    void Entity::addComponent(Composite* component) {
        Composite::addComponent(component);
        Mover* m = dynamic_cast<Mover*> (component);
        if (m != 0) {
            if (mover != 0) {
                mover->destroy();
            }

            mover = m;
        }
    }

    void Entity::update(const Time& time) {
        Composite::update(time);
        if(_health < 1) {
            destroy();
        }
    }

    void Entity::removeHealth(float amount) {
        _health -= amount;
    }

} /* namespace phantom */
