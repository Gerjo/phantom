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


    float Entity::distanceTo(Entity* gob) {
        return _position.distanceTo(gob->_position);
    }

    float Entity::distanceToSq(Entity* gob) {
        return _position.distanceToSq(gob->_position);
    }

    Vector3 Entity::directionTo(Entity* gob) {
        Vector3 direction = (gob->_position + Vector3(gob->_boundingBox.size.x / 2, gob->_boundingBox.size.y / 2)) - (_position + Vector3(_boundingBox.size.x / 2, _boundingBox.size.y / 2));
        direction.normalize();
        return direction;
    }
} /* namespace phantom */
