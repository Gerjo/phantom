#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <iostream>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>
#include <graphics/shapes/PNGImage.h>

namespace phantom {

    Graphics::Graphics(void) : _polygonLastX(0), _polygonLastY(0) {
        _polygonBuffer = 0;
    }

    Graphics::~Graphics(void) {
        this->clear();
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
        finalizePolygon();
        return *this;
    }

    Graphics& Graphics::stroke() {
        finalizePolygon();
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

    Graphics& Graphics::image(char *fileName, float x, float y, float width, float height) {
        PNGImage* image = new PNGImage(fileName, x, y, width, height);

        addShape(image);
        return *this;
    }


    Graphics& Graphics::line(float startX, float startY, float endX, float endY) {
        Line* line = new Line(startX, startY, endX, endY);

        addShape(line);
        return *this;
    }

    Graphics& Graphics::moveTo(float x, float y) {
        finalizePolygon();

        _polygonLastX = x;
        _polygonLastY = y;

        initializePolygon();

        return *this;
    }

    Graphics& Graphics::lineTo(float x, float y) {
        initializePolygon();
        _polygonBuffer->addPoint(x, y);

        return *this;
    }

    void Graphics::addShape(Shape* whom) {
        _workspaceShapes.push_back(whom);
    }

    void Graphics::finalizePolygon() {
        if(_polygonBuffer != 0) {
            addShape(_polygonBuffer);
            _polygonBuffer = 0;
        }
    }

    void Graphics::initializePolygon() {
        if(_polygonBuffer == 0) {
            _polygonBuffer = new Polygon();
            _polygonBuffer->addPoint(_polygonLastX, _polygonLastY);
        }
    }

    Graphics& Graphics::clear() {

        deque<Shape*>::iterator shIt;
        deque<Shape*>& handle = _finalizedShapes;

        for(int i = 0; i < 2; ++i) {
            for(shIt = handle.begin(); shIt != handle.end(); ++shIt) {
                delete *shIt;
            }

            handle.clear();
            handle = _workspaceShapes;
        }

        if(_polygonBuffer != 0) {
            delete _polygonBuffer;
            _polygonBuffer = 0;
        }
        return *this;
    }


} /* namespace phantom */
