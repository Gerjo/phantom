#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>


#include <CompileConfig.h>

#include "shapes/Shape.h"




using namespace std;

namespace phantom {

typedef deque<Shape*> Shapes;
typedef Shapes::iterator ShapeIterator;

class LIBEXPORT Graphics {
public:
    Graphics(void);
    ~Graphics(void);

private:
    Shapes _finalizedShapes;
    Shapes _workspaceShapes;

    void beginPath();
    void fill();
    void stroke();

    void setFillStyle();
    void setLineStyle();
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
