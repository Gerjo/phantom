#ifndef SHAPE_H_
#define SHAPE_H_

#include <core/Composite.h>
#include <graphics/Color.h>
namespace phantom {

class Shape: public phantom::Composite
{
public:
	float x, y;
	color fillColor;	
    Shape();
    virtual ~Shape();
};

} /* namespace phantom */
#endif /* SHAPE_H_ */
