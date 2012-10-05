#ifndef ENTITYLAYER_H
#define ENTITYLAYER_H

#include <core/Entity.h>
#include <layer/Layer.h>
#include <CompileConfig.h>

namespace phantom{
    class LIBEXPORT EntityLayer: public Layer {
    public:
        void addEntity(Entity* entity, Vector3 yomamma);
        void removeEntity(Entity* entity);
        virtual void collideWith(EntityLayer* layer);
        virtual void update(const float &elapsed);
    protected:
        virtual void collision(EntityLayer* layer);
        std::vector<EntityLayer*> collisionList;
    };
}
#endif /*ENTITYLAYER_H*/