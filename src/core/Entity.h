#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <core/Composite.h>

class Tile;
class ObjectLayer;
namespace phantom {

    class LIBEXPORT Entity : public Composite {
    public:
        ObjectLayer* objectLayer;

        virtual void addComponent(Composite *component);

    protected:
        Mover *mover;
        Shape *shape;
        Tile* _tile;
    };

} /* namespace phantom */
#endif /* ENTITY_H_ */
