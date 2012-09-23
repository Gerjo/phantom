/*
 * Entity.cpp
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#include "Entity.h"

namespace phantom {

Entity::Entity()
{
#ifndef NDEBUG
    //this->addComponent(new MessageVisualizer());
#endif /* NDEBUG */
}

Entity::~Entity()
{
}

void Entity::addComponent( Composite *component )
{
    Composite::addComponent(component);
    Mover *m = dynamic_cast<Mover*>(component);
    if( m != NULL )
    {
        if( this->mover != NULL )
            this->destroyComponent(this->mover);
        this->mover = m;
    }
    /*
    Shape *s = dynamic_cast<Shape*>(component);
    if( s != NULL )
    {
        if( this->shape != NULL )
            this->destroyComponent(this->shape);
        this->shape = s;
    }*/
}

} /* namespace phantom */
