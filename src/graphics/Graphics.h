#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>
#include <string>

#include <CompileConfig.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Polygon.h>

using namespace std;

namespace phantom {

class Composite;

class LIBEXPORT Graphics {
public:
	friend class GLUTRenderer;

    Graphics(phantom::Composite *parent);

    ~Graphics();

    Graphics& clear();
    Graphics& beginPath();
    Graphics& fill();
    Graphics& stroke();

    Graphics& setFillStyle(Color color);
    Graphics& setLineStyle(Color color);

    Graphics& line(float startX, float startY, float endX, float endY);
    Graphics& rect(float x, float y, float width, float height, bool isFilled = true);
    Graphics& rect(const Box3& box, bool isFilled = true);
    Graphics& arc(float x, float y, float radius, float start, float end);

    Graphics& image(const string& fileName, float x, float y, float width, float height);
    Graphics& text(float x, float y, void *font, string text);

    Graphics& rotate(float angle);

    Graphics& moveTo(float x, float y);
    Graphics& lineTo(float x, float y);

    float getRotation() { return _rotation; }

private:
    Graphics(Graphics& orig) {
        // Thou shalt not copy.
    }

    deque<Shape*> _finalizedShapes;
    deque<Shape*> _workspaceShapes;
    deque<Shape*> _bufferedShapes;

    Composite *_parent;
    Color _fillColor;
    Color _lineColor;

    Polygon* _polygonBuffer;

    void deleteShapes(deque<Shape*>& source);
    void moveShapes(deque<Shape*>& source, deque<Shape*>& target);
    void addShape(Shape* shape);
    void finalizePolygon();
    void initializePolygon();

    deque<Shape*>& getFinalizedShapes();
    deque<Shape*>& getBufferedShapes();

    float _rotation;

    float _polygonLastX;
    float _polygonLastY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
