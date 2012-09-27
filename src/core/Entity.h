#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>
#include <core/Composite.h>


namespace phantom {
    class Tile;
    class ObjectLayer;
    class Mover;
    class Shape;

    class Entity : public Composite {
    public:
        ObjectLayer* objectLayer;
        Entity();

        virtual void addComponent(Composite *component);

        void setX(float x);
        void setY(float y);

        bool hasTile();

    protected:
        Mover *mover;
        Shape *shape;
        Tile* _tile;

    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
