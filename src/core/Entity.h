#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <core/Composite.h>

class Tile;
class ObjectLayer;
namespace phantom {

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
