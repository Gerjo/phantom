#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>

#include <CompileConfig.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Polygon.h>

using namespace std;

namespace phantom {


class LIBEXPORT Graphics {
public:
	friend class GLUTRenderer;

    Graphics(void);
    ~Graphics(void);

    Graphics& beginPath();
    Graphics& fill();
    Graphics& stroke();

    Graphics& setFillStyle(Color color);
    Graphics& setLineStyle(Color color);

    Graphics& line(float startX, float startY, float endX, float endY);
    Graphics& rect(float x, float y, float width, float height);
    Graphics& arc(float x, float y, float radius, float start, float end);

    Graphics& image(char *fileName, float x, float y, float width, float height);

    Graphics& moveTo(float x, float y);
    Graphics& lineTo(float x, float y);

    Graphics& clear();
private:
    deque<Shape*> _finalizedShapes;
    deque<Shape*> _workspaceShapes;
    Color _fillColor;
    Color _lineColor;

    Polygon* _polygonBuffer;

    void addShape(Shape* shape);
    void finalizePolygon();
    void initializePolygon();
    deque<Shape*> *getShapes() { return &_finalizedShapes; };


    float _polygonLastX;
    float _polygonLastY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
