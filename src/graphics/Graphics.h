#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>

#include <CompileConfig.h>
#include <graphics/Graphics.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>
#include <graphics/shapes/Line.h>
#include <graphics/shapes/Polygon.h>

using namespace std;

namespace phantom {


class LIBEXPORT Graphics {
public:
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



    Graphics& moveTo(float x, float y);
    Graphics& lineTo(float x, float y);

private:
    deque<Shape*> _finalizedShapes;
    deque<Shape*> _workspaceShapes;
    Color _fillColor;
    Color _lineColor;

    Polygon* _polygonBuffer;

    void addShape(Shape* shape);
    void finalizePolygon();
    void initializePolygon();

    float _polygonLastX;
    float _polygonLastY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
