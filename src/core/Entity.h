/*
 * Entity.h
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <Eigen/Geometry>

#include <physics/Mover.h>
#include <physics/shapes/Shape.h>
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
