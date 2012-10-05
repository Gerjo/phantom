#ifndef ENTITY_H_
#define ENTITY_H_

#include <core/Composite.h>


namespace phantom {
    class ObjectLayer;
    class Mover;
    class Shape;

    class LIBEXPORT Entity : public Composite {
    public:
        Entity();
        ObjectLayer* objectLayer;

        virtual void addComponent(Composite *component);

        virtual void setX(float x);
        virtual void setY(float y);
    protected:
        Mover *mover;
        Shape *shape;
    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
