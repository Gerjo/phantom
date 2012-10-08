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
        _fillColor    = color;
        _hasFillColor = true;
    }

    void Shape::setLineColor(Color color) {
        _lineColor    = color;
        _hasLineColor = true;
    }

    void Shape::addVertex(float x, float y, float texX, float texY) {
        VerticeData data;
        data.x = x;
        data.y = y;
        data.texX = texX;
        data.texY = texY;
        vertices.push_back(data);

        if(x > _bounds.origin.x + _bounds.size.x) _bounds.size.x = x - _bounds.origin.x;
        if(x < _bounds.origin.x) _bounds.origin.x = x;
        if(y > _bounds.origin.y + _bounds.size.y) _bounds.size.y = y - _bounds.origin.y;
        if(y < _bounds.origin.y) _bounds.origin.y = y;
    }

    bool Shape::hasFillColor(void) {
        return _hasFillColor;
    }

    bool Shape::hasLineColor(void) {
        return _hasLineColor;
    }

    const Color& Shape::getLineColor() {
        return _lineColor;
    }

    const Color& Shape::getFillColor() {
        return _fillColor;
    }

    const Box3& Shape::getBounds() {
        return _bounds;
    }
} /* namespace phantom */
