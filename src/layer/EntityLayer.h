#ifndef ENTITYLAYER_H
#define ENTITYLAYER_H

#include <core/Entity.h>
#include <layer/Layer.h>
#include <CompileConfig.h>
#include <physics/Box3.h>

namespace phantom{
    class LIBEXPORT EntityLayer: public Layer {
    public:
        virtual void update(const float &elapsed);
        virtual void addComponent(Composite* component);

    protected:
        bool calculateCollision(Entity* a, Entity* b);
    };
}
#endif /*ENTITYLAYER_H*/