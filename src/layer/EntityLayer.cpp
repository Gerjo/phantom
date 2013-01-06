#include <pch.h>
#include "EntityLayer.h"
#include <iostream>
#include <physics/CollisionData.h>

namespace phantom{
    void EntityLayer::update(const PhantomTime &time){
        Composite::update(time);

        vector<Composite*>& entities = getComponents();
        vector<Composite*>::iterator itA;

        // A premature halt, should avoid odd errors later on, in case an
        // EntityLayer only contains 1 entity.
        if(entities.size() < 2) {
            return;
        }

        int offset = 1;

        for(itA = entities.begin(); itA != entities.end(); ++itA, ++offset) {
            Entity* entityA = static_cast<Entity*>(*itA);

            vector<Composite*>& subEntities = getComponents();
            vector<Composite*>::iterator itB = subEntities.begin();

            // If we have tested A against B, there is no need
            // to test B against A, henceforth this offset.
            std::advance(itB, offset);

            CollisionData collisionData;

            for(; itB != subEntities.end(); ++itB) {
                Entity* entityB = static_cast<Entity*>(*itB);

                if(entityA->canCollideWith(entityB)) {
                    if(calculateCollision(entityA, entityB)) {
                        entityA->onCollision(*itB, collisionData);
                        entityB->onCollision(*itA, collisionData);
                    }
                }
            }
        }

    }

    bool EntityLayer::calculateCollision(Entity* a, Entity* b) {
        // TODO: fancier shape testing, please!
        return a->getBoundingBox().intersect(b->getBoundingBox());;
    }

    void EntityLayer::addComponent(Composite* component) {
        Entity* e = dynamic_cast<Entity*>(component);
        if(e == 0) {
            throw PhantomException(
                    "Only phantom::Entity derivatives "
                    "can be added to an entitylayer."
            );
        }

        Layer::addComponent(component);
    }

}/*namespace phantom*/