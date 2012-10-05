#include "EntityLayer.h"
#include <iostream>

namespace phantom{
    void EntityLayer::addEntity(Entity* entity, Vector3 position){
        addComponent(entity);
    }
    void EntityLayer::removeEntity(Entity* entity){
        removeComponent(entity);
    }
    void EntityLayer::collideWith(EntityLayer* layer){
        collisionList.push_back(layer);

    }
    void EntityLayer::collision(EntityLayer* other){
        std::vector<Composite*>::iterator it;
        std::vector<Composite*>::iterator it2;
        std::vector<Composite*>* compList = getComponents();
        std::vector<Composite*>* otherList = other->getComponents();

        for (it = compList->begin(); it != compList->end(); ++it){
            for (it2 = otherList->begin(); it2 != otherList->end(); ++it2){
                if((*it) != (*it2)){
                    if((*it)->canCollideWith((*it2))){
                        (*it)->afterCollision((*it2));
                    }
                }
            }
        }
    }
    void EntityLayer::update(const float &elapsed){
        Composite::update(elapsed);
        if(collisionList.size() > 0){
            std::vector<EntityLayer*>::iterator it;
            it = collisionList.begin();
            while(it != collisionList.end()){
                collision((*it));
                ++it;
            }
        }
    }
}/*namespace phantom*/