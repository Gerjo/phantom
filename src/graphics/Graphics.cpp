#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <iostream>

namespace phantom {

Graphics::Graphics(void) : _moveToX(0), _moveToY(0) {

}

Graphics::~Graphics(void) {
    deque<Shape*>::iterator shIt;
    deque<Shape*>& handle = _finalizedShapes;

    for(int i = 0; i < 2; ++i) {
        for(shIt = handle.begin(); shIt != handle.end(); ++shIt) {
            delete *shIt;
        }

        handle = _workspaceShapes;
    }
}

Graphics& Graphics::beginPath() {
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

    return *this;
}

Graphics& Graphics::setFillStyle(Color color) {
    _fillColor = color;
    return *this;
}

Graphics& Graphics::setLineStyle(Color color) {
    _lineColor = color;
    return *this;
}

Graphics& Graphics::fill() {
    return *this;
}

Graphics& Graphics::stroke() {
    return *this;
}

Graphics& Graphics::rect(float x, float y, float width, float height) {
    Rectangle* rectangle = new Rectangle(x, y, width, height);

    addShape(rectangle);
    return *this;
}

Graphics& Graphics::arc(float x, float y, float radius, float start, float end) {
    Arc* arc = new Arc(x, y, radius, start, end);

    addShape(arc);
    return *this;
}

Graphics& Graphics::line(float startX, float startY, float endX, float endY) {
    Line* line = new Line(startX, startY, endX, endY);

    addShape(line);
    return *this;
}

Graphics& Graphics::moveTo(float x, float y) {
    _moveToX = x;
    _moveToY = y;
    return *this;
}

Graphics& Graphics::lineTo(float x, float y) {
    Line* line = new Line(_moveToX, _moveToY, x, y);

    addShape(line);

    moveTo(x, y);
    return *this;
}

void Graphics::addShape(Shape* whom) {
    _workspaceShapes.push_back(whom);
}

} /* namespace phantom */
