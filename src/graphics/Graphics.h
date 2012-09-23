#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>


#include <CompileConfig.h>

#include <graphics/Graphics.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>

using namespace std;

namespace phantom {

typedef deque<Shape*> Shapes;
typedef Shapes::iterator ShapeIterator;

class LIBEXPORT Graphics {
public:
    Graphics(void);
    ~Graphics(void);

    void beginPath();
    void fill();
    void stroke();

    void setFillStyle();
    void setLineStyle();
private:
    Shapes _finalizedShapes;
    Shapes _workspaceShapes;
    Color _fillColor;
    Color _lineColor;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
