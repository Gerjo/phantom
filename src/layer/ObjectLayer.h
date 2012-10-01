#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <core/Entity.h>
#include <layer/Layer.h>
#include <CompileConfig.h>
#include <Eigen/Geometry>

namespace phantom{
    class LIBEXPORT ObjectLayer: public Layer{
    public:
        void addEntity(Entity* entity, Eigen::Vector2f);
        void removeEntity(Entity* entity);
    };
}
#endif /*OBJECTLAYER_H*/