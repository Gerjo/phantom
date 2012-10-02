#include "Shape.h"

namespace phantom {

    Shape::Shape() :
    _hasFillColor(false),
    _hasLineColor(false) {
        imageData = 0;
    }

    Shape::~Shape() {
    }

    void Shape::setFillColor(Color color) {
        fillColor     = color;
        _hasFillColor = true;
    }

    void Shape::setLineColor(Color color) {
        lineColor     = color;
        _hasLineColor = true;
    }

    void Shape::addVertex(float x, float y, float texX, float texY) {
        VerticeData data;
        data.x = x;
        data.y = y;
        data.texX = texX;
        data.texY = texY;
        vertices.push_back(data);
    }

    bool Shape::hasFillColor(void) {
        return _hasFillColor;
    }

    bool Shape::hasLineColor(void) {
        return _hasLineColor;
    }

} /* namespace phantom */
