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

    private:
        std::deque<Entity*> entityList;
    };
#endif /*OBJECTLAYER_H*/