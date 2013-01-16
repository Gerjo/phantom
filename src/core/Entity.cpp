#include <pch.h>
#include "Entity.h"

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <utils/PhantomException.h>
#include <physics/InertiaMover.h>
namespace phantom {

    Entity::Entity() : inertia(nullptr), solidState(SolidStateBits::NOT_SOLID), solidType(0), mover(nullptr) {

    }

    void Entity::addComponent(Composite* component) {
        Composite::addComponent(component);

        if(dynamic_cast<Mover*>(component)) {
            if (mover != nullptr) {
                mover->destroy();
            }

            mover = static_cast<Mover*>(component);
            
        } else if(dynamic_cast<InertiaMover*>(component)) {
            if (inertia != nullptr) {
                inertia->destroy();
            }

            inertia = static_cast<InertiaMover*>(component);
        }
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
