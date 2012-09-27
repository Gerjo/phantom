#include "ObjectLayer.h"

namespace phantom{
    void ObjectLayer::addEntity(Entity* entity, Eigen::Vector2f position){
        entity->position = position;
        if(entity->objectLayer != 0){
            entity->objectLayer->removeEntity(entity);
        }
        entity->objectLayer = this;

        entityList.push_back(entity);
    }
    void ObjectLayer::addEntityAt(Entity* entity, Eigen::Vector2f position, unsigned int index){
        entity->position = position;
        if(entity->objectLayer != 0){
            entity->objectLayer->removeEntity(entity);
        }
        entity->objectLayer = this;

        entityIt = entityList.begin()+index;
        entityList.insert(entityIt,entity);
    }
    void ObjectLayer::removeEntity(Entity* entity){
        entityIt = entityList.begin();
        while(entityIt != entityList.end()){
            if((*entityIt) == entity){
                entityList.erase(entityIt);
                break;
            }
            ++entityIt;
        }
    }
}/*namespace phantom*/