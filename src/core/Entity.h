#ifndef ENTITY_H_
#define ENTITY_H_

#include <core/Composite.h>
#include <physics/Box3.h>

namespace phantom {
    class EntityLayer;
    class Mover;

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        EntityLayer* objectLayer;

        virtual void addComponent(Composite *component);

        virtual void setX(float x);
        virtual void setY(float y);

        Box3& getBoundingBox();
    protected:
        Mover* mover;
        Box3 _boundingBox;
    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
