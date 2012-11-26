#include "Entity.h"

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <utils/PhantomException.h>

namespace phantom {

    Entity::Entity() : solidState(SolidStateBits::NOT_SOLID) {
        mover = 0;
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

    void Entity::update(const PhantomTime& time) {
        Composite::update(time);
    }
} /* namespace phantom */
