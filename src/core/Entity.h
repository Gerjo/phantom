#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>

#include <physics/Mover.h>
#include <graphics/shapes/Shape.h>
#include <core/Composite.h>

namespace phantom {

class Entity: public phantom::Composite
{
public:
    Entity();
    virtual ~Entity();

    virtual void addComponent( Composite *component );

protected:
    Eigen::Vector3f position;
    Mover *mover;
    Shape *shape;
};

} /* namespace phantom */
#endif /* ENTITY_H_ */
