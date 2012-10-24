#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <core/Driver.h>
#include <iostream>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>
#include <graphics/shapes/Image.h>
#include <graphics/shapes/Text.h>
#include <core/Composite.h>
#include <physics/Box3.h>

namespace phantom {

    Graphics::Graphics(phantom::Composite *parent) : _polygonLastX(0), _polygonLastY(0), _rotation(0) {
        _parent = parent;
        _polygonBuffer = 0;
    }

    Graphics::~Graphics() {
        this->clear();
    }

    Graphics& Graphics::beginPath() {
        // Workspace contains non filled or stroked shapes. Destroy!
        deleteShapes(_workspaceShapes);

        // The buffer is moved to the finalized collection. At this point
        // their color can no longer be changed.
        moveShapes(_bufferedShapes, _finalizedShapes);

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

    Graphics& Graphics::fill(void) {
        finalizePolygon();
        moveShapes(_workspaceShapes, _bufferedShapes);
        return *this;
    }

    Graphics& Graphics::stroke(void) {
        finalizePolygon();
        moveShapes(_workspaceShapes, _bufferedShapes);
        return *this;
    }

    Graphics& Graphics::rect(const Box3& box, bool isFilled) {
        return rect(box.origin.x, box.origin.y, box.size.x, box.size.y, isFilled);
    }

    Graphics& Graphics::rect(float x, float y, float width, float height, bool isFilled) {
        Rectangle* rectangle = new Rectangle(x, y, width, height, isFilled);

        addShape(rectangle);
        return *this;
    }

    Graphics& Graphics::arc(float x, float y, float radius, float start, float end) {
        Arc* arc = new Arc(x, y, radius, start, end);

        addShape(arc);
        return *this;
    }

    Graphics& Graphics::image(const string& fileName, float x, float y, float width, float height) {
        Image* image = new Image(fileName, x, y, width, height);

        addShape(image);
        return *this;
    }

    Graphics& Graphics::text(float x, float y, unsigned int size, string *fontname, string *text) {
        return this->text(x, y, size, fontname->c_str(), text);
    }

    Graphics& Graphics::text(float x, float y, unsigned int size, const char *fontname, string *text) {
        Text* txt = new Text(x, y, size, fontname, text->c_str());

        addShape(txt);
        return *this;
    }

    Graphics& Graphics::rotate(float angle) {
        _rotation = angle;

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
        whom->buildShape(_parent->getPhantomGame()->getDriver()->getRenderer());
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

        deleteShapes(_finalizedShapes);
        deleteShapes(_workspaceShapes);
        deleteShapes(_bufferedShapes);

        if(_polygonBuffer != 0) {
            delete _polygonBuffer;
            _polygonBuffer = 0;
        }
        return *this;
    }


    void Graphics::moveShapes(deque<Shape*>& source, deque<Shape*>& target) {
        while(source.size() > 0) {
            Shape* shape = source.front();

            source.pop_front();

            // We're only setting the color at the latest possible moment, in order
            // to comply with the HTML 5 API.
            shape->setLineColor(_lineColor);
            shape->setFillColor(_fillColor);

            target.push_back(shape);
        }
    }

    void Graphics::deleteShapes(deque<Shape*>& source) {
        deque<Shape*>::iterator shIt;

        for(shIt = source.begin(); shIt != source.end(); ++shIt) {
            (*shIt)->destroyShape(_parent->getPhantomGame()->getDriver()->getRenderer());
            delete *shIt;
        }

        source.clear();
    }

    deque<Shape*>& Graphics::getFinalizedShapes() {
        return _finalizedShapes;
    }

    deque<Shape*>& Graphics::getBufferedShapes() {
        return _bufferedShapes;
    }

} /* namespace phantom */
