#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>
#include <string>

#include <CompileConfig.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Polygon.h>
#include <physics/Line2.h>

using namespace std;

namespace phantom {

class Composite;

class LIBEXPORT Graphics {
public:
	friend class GLRenderer;

    Graphics(phantom::Composite *parent);

    ~Graphics();

    Graphics& clear();
    Graphics& beginPath();
    Graphics& fill();
    Graphics& stroke();

    Graphics& setFillStyle(Color color);
    Graphics& setLineStyle(Color color);

    Graphics& line(const float& startX, const float& startY, const float& endX, const float& endY);
    Graphics& line(const Line2& line);
    Graphics& line(const Vector3& start, const Vector3& end);
    Graphics& rect(float x, float y, float width, float height, bool isFilled = true, float thickness = 3.0f);
    Graphics& rect(const Box3& box, bool isFilled = true, float thickness = 3.0f);
    Graphics& arc(float x, float y, float radius, float start, float end);

    Graphics& image(const string& fileName, float x, float y, float width, float height);
    Graphics& text(float x, float y, unsigned int size, const string& fontname, const string& text);
    Graphics& text(float x, float y, unsigned int size, const char* fontname, const string& text);

    Graphics& rotate(float angle);

    Graphics& moveTo(float x, float y);
    Graphics& lineTo(float x, float y);

    float getRotation() { return _rotation; }

private:
    Graphics(Graphics& orig) : _parent(nullptr), _polygonLastX(0), _polygonLastY(0), _rotation(0), _polygonBuffer(0) {
        // Thou shalt not copy.
    }

    vector<Shape*> _finalizedShapes;
    vector<Shape*> _workspaceShapes;
    vector<Shape*> _bufferedShapes;

    Composite *_parent;
    Color _fillColor;
    Color _lineColor;

    Polygon* _polygonBuffer;

    void deleteShapes(vector<Shape*>& source);
    void moveShapes(vector<Shape*>& source, vector<Shape*>& target);
    void addShape(Shape* shape);
    void finalizePolygon();
    void initializePolygon();

    vector<Shape*>& getFinalizedShapes();
    vector<Shape*>& getBufferedShapes();

    float _rotation;

    float _polygonLastX;
    float _polygonLastY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
