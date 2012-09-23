#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <iostream>

namespace phantom {

Graphics::Graphics(void) {

}

Graphics::~Graphics(void) {
    Shapes& handle = _finalizedShapes;

    for(int i = 0; i < 2; ++i) {
        for(ShapeIterator it = handle.begin(); it != handle.end(); ++it) {
            delete *it;
        }

        handle = _workspaceShapes;
    }
}

void Graphics::beginPath() {
    // Move all shapes from the workspace to the finalized collection.
    while(_workspaceShapes.size() > 0) {
        Shape* shape = _workspaceShapes.front();
        _workspaceShapes.pop_front();

        // We're only setting the color at the latest possible moment, in order
        // to comply with the HTML 5 API.

        shape->setLineColor(_lineColor);
        shape->setFillColor(_fillColor);

        _finalizedShapes.push_back(shape);
    }
}

void Graphics::setFillStyle(Color color) {
    _fillColor = color;
}

void Graphics::setLineStyle(Color color) {
    _lineColor = color;
}

void Graphics::fill() {

}

void Graphics::stroke() {

}

} /* namespace phantom */
