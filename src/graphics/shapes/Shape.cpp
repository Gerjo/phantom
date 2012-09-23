#include "Shape.h"

namespace phantom {

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::setFillColor(Color color) {
    fillColor = color;
}

void Shape::setLineColor(Color color) {
    lineColor = color;
}

} /* namespace phantom */
