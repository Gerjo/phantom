#ifndef SHAPE_H_
#define SHAPE_H_

#include <graphics/Color.h>
namespace phantom {

class Shape
{
public:
	float x, y;
	Color fillColor;
    Color lineColor;
    Shape();
    virtual ~Shape();

    void setFillColor(Color color);
    void setLineColor(Color color);

};

} /* namespace phantom */
#endif /* SHAPE_H_ */
