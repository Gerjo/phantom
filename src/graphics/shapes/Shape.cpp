#include <pch.h>
#include "Shape.h"
#include <core/Renderer.h>

namespace phantom {
    const float Shape::TEX_COORD_UNUSED = -999.0f;
    unsigned int Shape::shapecount = 0;

    Shape::Shape() :
    _hasFillColor(false),
    _hasLineColor(false),
    isImage(false),
    isText(false),
    verticesArray(nullptr),
    texCoordsArray(nullptr),
    vboTexCoords(0),
    vboVertices(0),
    verticesCount(0),
    x(0.0f),
    y(0.0f)
    {
        shapecount++;
    }

    Shape::~Shape() {
        if(verticesArray != nullptr)
            delete [] verticesArray;
        if(texCoordsArray != nullptr)
            delete [] texCoordsArray;
        shapecount--;
    }

    unsigned Shape::getShapecount() {
        return shapecount;
    }

    void Shape::setFillColor(Color color) {
        _fillColor    = color;
        _hasFillColor = true;
    }

    void Shape::setLineColor(Color color) {
        _lineColor    = color;
        _hasLineColor = true;
    }

    void Shape::addVertex(float x, float y, float u, float v) {
        Vertice vertice;
        TexCoord tex;
        vertice.x = x;
        vertice.y = y;
        vertice.z = 0.0f;
        tex.u = u;
        tex.v = v;

        vertices.push_back(vertice);
        if(u != TEX_COORD_UNUSED && v != TEX_COORD_UNUSED)
            texCoords.push_back(tex);

        if(x < _bounds.origin.x) {
            _bounds.origin.x = x;
        }
        else if(x > _bounds.origin.x + _bounds.size.x) {
            _bounds.size.x = x - _bounds.origin.x;
        }        
        if(y < _bounds.origin.y) {
            _bounds.origin.y = y;
        }
        else if(y > _bounds.origin.y + _bounds.size.y) {
            _bounds.size.y = y - _bounds.origin.y;
        }        
        /*if(z < _bounds.origin.z) {
            _bounds.origin.z = z;
        }
        else if(z > _bounds.origin.z + _bounds.size.z) {
            _bounds.size.z = z - _bounds.origin.z;
        }*/
    }

    void Shape::buildShape(Renderer *renderer) {
        renderer->buildShape(this);
    }

    void Shape::destroyShape(Renderer *renderer) {
        renderer->destroyShape(this);
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
