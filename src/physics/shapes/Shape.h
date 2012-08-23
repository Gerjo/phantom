/*
 * Shape.h
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <core/Composite.h>

namespace phantom {

class Shape: public phantom::Composite
{
public:
    Shape();
    virtual ~Shape();
};

} /* namespace phantom */
#endif /* SHAPE_H_ */
