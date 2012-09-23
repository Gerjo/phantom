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

        // Apply the colors:
        //shape.setLineColor();
        //shape.setFillColor();
        _finalizedShapes.push_back(shape);
    }
}

void Graphics::setFillStyle() {

}

void Graphics::setLineStyle() {

}

void Graphics::fill() {

}

void Graphics::stroke() {

}

} /* namespace phantom */
