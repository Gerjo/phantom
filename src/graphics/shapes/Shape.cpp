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
void Shape::addVertex(float x, float y){
        Eigen::Vector2f v(x, y);
        vertices.push_back(v);
    }
} /* namespace phantom */
