#include "Line.h"

namespace phantom{
    Line::Line(float x, float y, float toX, float toY){
        this->x = x;
        this->y = y;
        this->toX = toX;
        this->toY = toY;

        addVertex(x,y);
        addVertex(toX,toY);
    }
} /* namespace phantom */