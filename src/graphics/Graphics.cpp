#include <graphics/Graphics.h>
#include <core/PhantomGame.h>
#include <iostream>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>
#include <graphics/shapes/PNGImage.h>
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

    Graphics& Graphics::rect(const Box3& box) {
        rect(box.origin.x, box.origin.y, box.size.x, box.size.y);

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

    Graphics& Graphics::image(const string& fileName, float x, float y, float width, float height) {
        PNGImage* image = new PNGImage(fileName, x, y, width, height);

        addShape(image);
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
        //Box3 boundingBox = _parent->getBoundingBox();

        //std::vector<VerticeData>::iterator verticeIter = whom->vertices.begin();
        //while(verticeIter != whom->vertices.end()) {
        //    if((*verticeIter).x < boundingBox.origin.x) {
        //        boundingBox.size.x += boundingBox.origin.x - (*verticeIter).x;
        //        boundingBox.origin.x = (*verticeIter).x;
        //    }

        //    else if((*verticeIter).x > boundingBox.origin.x + boundingBox.size.x) {
        //        boundingBox.size.x = (*verticeIter).x - boundingBox.origin.x;
        //    }

        //    if((*verticeIter).y < boundingBox.origin.y) {
        //        boundingBox.size.y += boundingBox.origin.y - (*verticeIter).y;
        //        boundingBox.origin.y = (*verticeIter).y;
        //    }

        //    else if((*verticeIter).y > boundingBox.origin.y + boundingBox.size.y) {
        //        boundingBox.size.y = (*verticeIter).y - boundingBox.origin.y;
        //    }

        //    if((*verticeIter).z < boundingBox.origin.z) {
        //        boundingBox.size.z += boundingBox.origin.z - (*verticeIter).z;
        //        boundingBox.origin.z = (*verticeIter).z;
        //    }
        //    else if((*verticeIter).z > boundingBox.origin.z + boundingBox.size.z) {
        //        boundingBox.size.z = (*verticeIter).z - boundingBox.origin.z;
        //    }
        //    verticeIter++;
        //}

        //_parent->setBoundingBox(boundingBox);
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
