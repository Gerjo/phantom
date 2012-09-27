#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <deque>
#include <core/Entity.h>
#include <core/Layer.h>
#include <CompileConfig.h>
#include <Eigen/Geometry>

namespace phantom{
    class LIBEXPORT ObjectLayer: public Layer{
    public:
        void addEntity(Entity* entity, Eigen::Vector2f);
        void addEntityAt(Entity* entity, Eigen::Vector2f, unsigned int index);
        void removeEntity(Entity* entity);

    private:
        std::deque<Entity*> entityList;
        deque<Entity*>::iterator entityIt =0;
    };
#endif /*OBJECTLAYER_H*/