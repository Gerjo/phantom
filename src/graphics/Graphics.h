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

using namespace std;

namespace phantom {


class LIBEXPORT Graphics {
public:
	friend class GLUTRenderer;

    Graphics(void);
    ~Graphics(void);

    void beginPath();
    void fill();
    void stroke();

    void setFillStyle(Color color);
    void setLineStyle(Color color);

    void line(float startX, float startY, float endX, float endY);
    void rect(float x, float y, float width, float height);
    void arc(float x, float y, float radius, float start, float end);



    void moveTo(float x, float y);
    void lineTo(float x, float y);

private:
    deque<Shape*> _finalizedShapes;
    deque<Shape*> _workspaceShapes;
    Color _fillColor;
    Color _lineColor;

    void addShape(Shape* shape);
	deque<Shape*> *getShapes() { return &_finalizedShapes; };

    float _moveToX;
    float _moveToY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
