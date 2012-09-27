#include "ObjectLayer.h"

namespace phantom{
    void ObjectLayer::addEntity(Entity* entity, Eigen::Vector2f position){
        addComponent(entity);
    }
    void ObjectLayer::removeEntity(Entity* entity){
        removeComponent(entity);
    }
}/*namespace phantom*/