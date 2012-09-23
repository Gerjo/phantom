#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>

#include <CompileConfig.h>
#include <graphics/Graphics.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Rectangle.h>
#include <graphics/shapes/Arc.h>

using namespace std;

namespace phantom {


class LIBEXPORT Graphics {
public:
    Graphics(void);
    ~Graphics(void);

    void beginPath();
    void fill();
    void stroke();

    void setFillStyle(Color color);
    void setLineStyle(Color color);

    void rect(float x, float y, float width, float height);
    void arc(float x, float y, float radius, float start, float end);

private:
    deque<Shape*> _finalizedShapes;
    deque<Shape*> _workspaceShapes;
    Color _fillColor;
    Color _lineColor;

    void addShape(Shape* shape);
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
