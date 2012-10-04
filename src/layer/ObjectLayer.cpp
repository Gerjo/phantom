#include "ObjectLayer.h"

namespace phantom{
    void ObjectLayer::addEntity(Entity* entity, Eigen::Vector2f position){
        addComponent(entity);
    }
    void ObjectLayer::removeEntity(Entity* entity){
        removeComponent(entity);
    }
    void ObjectLayer::collideWith(ObjectLayer* layer){
        collisionList.push_back(layer);

    }
    void ObjectLayer::collision(ObjectLayer* other){
        std::vector<Composite*>::iterator it;
        std::vector<Composite*>::iterator it2;
        std::vector<Composite*>* compList = getComponents();
        std::vector<Composite*>* otherList = other->getComponents();
        it = compList->begin();


        for (int i = 0; i > compList->size(); i++){
            for (int j = 0; j < otherList->size(); j++){
                if((*it)->canCollideWith(*it2)){
                    (*it)->afterCollision(*it2);
                }
                ++it2;
            }
            ++it;
        }
    }
    void ObjectLayer::update(const float &elapsed){
        if(collisionList.size() > 0){
            std::vector<ObjectLayer*>::iterator it;
            it = collisionList.begin();
            while(it != collisionList.end()){
                collision((*it));
                ++it;
            }
        }
    }
}/*namespace phantom*/