#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <core/Entity.h>
#include <layer/Layer.h>
#include <CompileConfig.h>

namespace phantom{
    class LIBEXPORT ObjectLayer: public Layer{
    public:
        void addEntity(Entity* entity, Vector3 yomamma);
        void removeEntity(Entity* entity);
        virtual void collideWith(ObjectLayer* layer);
        virtual void update(const float &elapsed);
    protected:
        virtual void collision(ObjectLayer* layer);
        std::vector<ObjectLayer*> collisionList;
    };
}
#endif /*OBJECTLAYER_H*/