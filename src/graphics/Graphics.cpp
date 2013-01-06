#include <pch.h>
#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <core/Driver.h>
#include <iostream>
#include <graphics/FreeTypeLibrary.h>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>
#include <graphics/shapes/Image.h>
#include <graphics/shapes/Text.h>
#include <core/Composite.h>
#include <physics/Box3.h>

namespace phantom {

    Graphics::Graphics(phantom::Composite *parent) : _polygonLastX(0), _polygonLastY(0), _rotation(0), _polygonBuffer(0) {
        _parent = parent;
        _polygonBuffer = nullptr;
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

    Graphics& Graphics::rect(const Box3& box, bool isFilled, float thickness) {
        return rect(box.origin.x, box.origin.y, box.size.x, box.size.y, isFilled, thickness);
    }

    Graphics& Graphics::rect(float x, float y, float width, float height, bool isFilled, float thickness) {
        Rectangle* rectangle = new Rectangle(x, y, width, height, isFilled, thickness);

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

    Graphics& Graphics::text(float x, float y, unsigned int size, const string& fontname, const string& text) {
        return this->text(x, y, size, fontname.c_str(), text);
    }

    Graphics& Graphics::text(float x, float y, unsigned int size, const char* fontname, const string& text) {
        Text* txt = new Text(x, y, size, fontname, text.c_str());
        txt->ftfont = _parent->getPhantomGame()->getDriver()->getFontLibrary()->getFont(txt);

        addShape(txt);
        return *this;
    }

    Graphics& Graphics::rotate(float angle) {
        _rotation = angle;

        return *this;
    }

    Graphics& Graphics::line(const float& startX, const float& startY, const float& endX, const float& endY) {
        Line* line = new Line(startX, startY, endX, endY);

        addShape(line);
        return *this;
    }

    Graphics& Graphics::line(const Line2& line) {
        return this->line(line.a.x, line.a.y, line.b.x, line.b.y);
    }

    Graphics& Graphics::line(const Vector3& start, const Vector3& end) {
        return this->line(start.x, start.y, end.x, end.y);
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
            for(unsigned int i = 0; i < _polygonBuffer->collection.size() - 1; ++i) {
                const vector<Vertice>& v = _polygonBuffer->collection;
                line(v[i].x, v[i].y, v[i+1].x, v[i+1].y);
            }
            _polygonBuffer = 0;
        }
    }

    void Graphics::initializePolygon() {
        if(_polygonBuffer == nullptr) {
            _polygonBuffer = new Polygon();
            _polygonBuffer->addPoint(_polygonLastX, _polygonLastY);
        }
    }

    Graphics& Graphics::clear() {

        deleteShapes(_finalizedShapes);
        deleteShapes(_workspaceShapes);
        deleteShapes(_bufferedShapes);

        delete _polygonBuffer;
        _polygonBuffer = nullptr;

        return *this;
    }


    void Graphics::moveShapes(vector<Shape*>& source, vector<Shape*>& target) {
        while(source.size() > 0) {
            Shape* shape = (*source.begin());



            // We're only setting the color at the latest possible moment, in order
            // to comply with the HTML 5 API.
            shape->setLineColor(_lineColor);
            shape->setFillColor(_fillColor);

            target.push_back(shape);
            source.erase(source.begin());
        }
    }

    void Graphics::deleteShapes(vector<Shape*>& source) {
        vector<Shape*>::iterator shIt;

        for(shIt = source.begin(); shIt != source.end(); ++shIt) {
            (*shIt)->destroyShape(_parent->getPhantomGame()->getDriver()->getRenderer());
            delete *shIt;
            *shIt = 0;
        }

        source.clear();
    }

    vector<Shape*>& Graphics::getFinalizedShapes() {
        return _finalizedShapes;
    }

    vector<Shape*>& Graphics::getBufferedShapes() {
        return _bufferedShapes;
    }

} /* namespace phantom */
